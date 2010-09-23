// PocketDlg.cpp
// Copyright (c) 2010, Dan Heeks
// This program is released under the BSD license. See the file COPYING for details.

#include "stdafx.h"
#include "PocketDlg.h"
#include "interface/PictureFrame.h"
#include "interface/NiceTextCtrl.h"
#include "Pocket.h"

enum
{
    ID_SKETCHES = 100,
	ID_STEP_OVER,
	ID_MATERIAL_ALLOWANCE,
	ID_STARTING_PLACE,
	ID_KEEP_TOOL_DOWN,
	ID_USE_ZIG_ZAG,
	ID_ZIG_ANGLE,
	ID_ABS_MODE,
	ID_CLEARANCE_HEIGHT,
	ID_RAPID_DOWN_TO_HEIGHT,
	ID_START_DEPTH,
	ID_FINAL_DEPTH,
	ID_STEP_DOWN,
	ID_HFEED,
	ID_VFEED,
	ID_SPINDLE_SPEED,
	ID_COMMENT,
	ID_ACTIVE,
	ID_TITLE,
};

BEGIN_EVENT_TABLE(PocketDlg, wxDialog)
    EVT_CHILD_FOCUS(PocketDlg::OnChildFocus)
    EVT_COMBOBOX(ID_STARTING_PLACE,PocketDlg::OnComboStartingPlace)
    EVT_CHECKBOX(ID_KEEP_TOOL_DOWN, PocketDlg::OnCheckKeepToolDown)
    EVT_CHECKBOX(ID_USE_ZIG_ZAG, PocketDlg::OnCheckUseZigZag)
END_EVENT_TABLE()

PocketDlg::PocketDlg(wxWindow *parent, CPocket* object)
             : wxDialog(parent, wxID_ANY, wxString(_T("Pocket Operation")))
{
	m_ignore_event_functions = true;
    wxBoxSizer *sizerMain = new wxBoxSizer(wxHORIZONTAL);

	m_general_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/general.png"), wxBITMAP_TYPE_PNG));
	m_step_over_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/step over.png"), wxBITMAP_TYPE_PNG));
	m_material_allowance_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/material allowance.png"), wxBITMAP_TYPE_PNG));
	m_starting_center_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/starting center.png"), wxBITMAP_TYPE_PNG));
	m_starting_boundary_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/starting boundary.png"), wxBITMAP_TYPE_PNG));
	m_tool_down_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/tool down.png"), wxBITMAP_TYPE_PNG));
	m_not_tool_down_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/not tool down.png"), wxBITMAP_TYPE_PNG));
	m_use_zig_zag_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/use zig zag.png"), wxBITMAP_TYPE_PNG));
	m_zig_angle_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/zig angle.png"), wxBITMAP_TYPE_PNG));
	m_clearnce_height_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/clearance height.png"), wxBITMAP_TYPE_PNG));
	m_rapid_down_to_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/rapid down height.png"), wxBITMAP_TYPE_PNG));
	m_start_depth_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/start depth.png"), wxBITMAP_TYPE_PNG));
	m_final_depth_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/final depth.png"), wxBITMAP_TYPE_PNG));
	m_step_down_bitmap = wxBitmap(wxImage(theApp.GetResFolder() + _T("/bitmaps/pocket/step down.png"), wxBITMAP_TYPE_PNG));

	// add left sizer
    wxBoxSizer *sizerLeft = new wxBoxSizer(wxVERTICAL);
    sizerMain->Add( sizerLeft, 0, wxALL, 5 );

	// add right sizer
    wxBoxSizer *sizerRight = new wxBoxSizer(wxVERTICAL);
    sizerMain->Add( sizerRight, 0, wxALL, 5 );

	// add picture to right side
	m_picture = new PictureWindow(this, m_general_bitmap);
	wxBoxSizer *pictureSizer = new wxBoxSizer(wxVERTICAL);
	pictureSizer->Add(m_picture, 1, wxGROW);
    sizerRight->Add( pictureSizer, 0, wxALL, 5 );

	// add OK and Cancel to right side
    wxBoxSizer *sizerOKCancel = new wxBoxSizer(wxVERTICAL);
	sizerRight->Add( sizerOKCancel, 0, wxALL | wxALIGN_RIGHT | wxALIGN_BOTTOM, 5 );
    wxButton* buttonOK = new wxButton(this, wxID_OK, _("OK"));
	sizerOKCancel->Add( buttonOK, 0, wxALL | wxDOWN, 5 );
    wxButton* buttonCancel = new wxButton(this, wxID_CANCEL, _("Cancel"));
	sizerOKCancel->Add( buttonCancel, 0, wxALL | wxUP, 5 );
    buttonOK->SetDefault();

	// add all the controls to the left side
	AddLabelAndControl(sizerLeft, _("sketches"), m_idsSketches = new CObjectIdsCtrl(this, ID_SKETCHES));
	AddLabelAndControl(sizerLeft, _("step over"), m_lgthStepOver = new CLengthCtrl(this, ID_STEP_OVER));
	AddLabelAndControl(sizerLeft, _("material allowance"), m_lgthMaterialAllowance = new CLengthCtrl(this, ID_MATERIAL_ALLOWANCE));

	wxString starting_place_choices[] = {_("boundary"), _("center")};
	AddLabelAndControl(sizerLeft, _("starting place"), m_cmbStartingPlace = new wxComboBox(this, ID_STARTING_PLACE, _T(""), wxDefaultPosition, wxDefaultSize, 2, starting_place_choices));

	sizerLeft->Add( m_chkUseZigZag = new wxCheckBox( this, ID_USE_ZIG_ZAG, _("use zig zag") ), 0, wxALL, 5 );
	sizerLeft->Add( m_chkKeepToolDown = new wxCheckBox( this, ID_KEEP_TOOL_DOWN, _("keep tool down") ), 0, wxALL, 5 );

	wxString abs_mode_choices[] = {_("absolute"), _("incremental")};
	AddLabelAndControl(sizerLeft, _("absolute mode"), m_cmbAbsMode = new wxComboBox(this, ID_ABS_MODE, _T(""), wxDefaultPosition, wxDefaultSize, 2, abs_mode_choices));

	AddLabelAndControl(sizerLeft, _("clearance height"), m_lgthClearanceHeight = new CLengthCtrl(this, ID_CLEARANCE_HEIGHT));
	AddLabelAndControl(sizerLeft, _("rapid safety space"), m_lgthRapidDownToHeight = new CLengthCtrl(this, ID_RAPID_DOWN_TO_HEIGHT));
	AddLabelAndControl(sizerLeft, _("start depth"), m_lgthStartDepth = new CLengthCtrl(this, ID_START_DEPTH));
	AddLabelAndControl(sizerLeft, _("final depth"), m_lgthFinalDepth = new CLengthCtrl(this, ID_FINAL_DEPTH));
	AddLabelAndControl(sizerLeft, _("step down"), m_lgthStepDown = new CLengthCtrl(this, ID_STEP_DOWN));
	AddLabelAndControl(sizerLeft, _("horizontal feedrate"), m_lgthHFeed = new CLengthCtrl(this, ID_HFEED));
	AddLabelAndControl(sizerLeft, _("vertical feedrate"), m_lgthVFeed = new CLengthCtrl(this, ID_VFEED));
	AddLabelAndControl(sizerLeft, _("spindle speed"), m_dblSpindleSpeed = new CDoubleCtrl(this, ID_SPINDLE_SPEED));

	AddLabelAndControl(sizerLeft, _("comment"), m_txtComment = new wxTextCtrl(this, ID_COMMENT));
	sizerLeft->Add( m_chkActive = new wxCheckBox( this, ID_ACTIVE, _("active") ), 0, wxALL, 5 );
	AddLabelAndControl(sizerLeft, _("title"), m_txtTitle = new wxTextCtrl(this, ID_TITLE));

	SetFromData(object);

    SetSizer( sizerMain );
    sizerMain->SetSizeHints(this);
	sizerMain->Fit(this);

    m_idsSketches->SetFocus();

	m_ignore_event_functions = false;

	SetPicture();
}

void PocketDlg::GetData(CPocket* object)
{
	if(m_ignore_event_functions)return;
	m_ignore_event_functions = true;
	object->m_sketches.clear();
	m_idsSketches->GetAddChildren(object, SketchType);
	object->m_pocket_params.m_step_over = m_lgthStepOver->GetValue();
	object->m_pocket_params.m_material_allowance = m_lgthMaterialAllowance->GetValue();
	object->m_pocket_params.m_starting_place = m_cmbStartingPlace->GetValue() ? 1:0;
	object->m_pocket_params.m_keep_tool_down_if_poss = m_chkKeepToolDown->GetValue();
	object->m_pocket_params.m_use_zig_zag = m_chkUseZigZag->GetValue();
	if(object->m_pocket_params.m_use_zig_zag)object->m_pocket_params.m_zig_angle = m_dblZigAngle->GetValue();
	object->m_depth_op_params.m_abs_mode = (m_cmbAbsMode->GetValue().CmpNoCase(_("incremental")) == 0) ? CDepthOpParams::eIncremental : CDepthOpParams::eAbsolute;
	object->m_depth_op_params.m_clearance_height = m_lgthClearanceHeight->GetValue();
	object->m_depth_op_params.m_rapid_down_to_height = m_lgthRapidDownToHeight->GetValue();
	object->m_depth_op_params.m_start_depth = m_lgthStartDepth->GetValue();
	object->m_depth_op_params.m_final_depth = m_lgthFinalDepth->GetValue();
	object->m_depth_op_params.m_step_down = m_lgthStepDown->GetValue();
	object->m_speed_op_params.m_horizontal_feed_rate = m_lgthHFeed->GetValue();
	object->m_speed_op_params.m_vertical_feed_rate = m_lgthVFeed->GetValue();
	object->m_speed_op_params.m_spindle_speed = m_dblSpindleSpeed->GetValue();
	object->m_comment = m_txtComment->GetValue();
	object->m_active = m_chkActive->GetValue();
	object->m_title = m_txtTitle->GetValue();
	m_ignore_event_functions = false;
}

void PocketDlg::SetFromData(CPocket* object)
{
	m_ignore_event_functions = true;
	m_idsSketches->SetFromChildren(object, SketchType);
	m_lgthStepOver->SetValue(object->m_pocket_params.m_step_over);
	m_lgthMaterialAllowance->SetValue(object->m_pocket_params.m_material_allowance);
	m_cmbStartingPlace->SetValue((object->m_pocket_params.m_starting_place == 0) ? _("boundary") : _("center"));
	m_chkKeepToolDown->SetValue(object->m_pocket_params.m_keep_tool_down_if_poss);
	m_chkUseZigZag->SetValue(object->m_pocket_params.m_use_zig_zag);
	if(object->m_pocket_params.m_use_zig_zag)m_dblZigAngle->SetValue(object->m_pocket_params.m_zig_angle);
	m_cmbAbsMode->SetValue((object->m_depth_op_params.m_abs_mode == CDepthOpParams::eAbsolute) ? _("absolute") : _("incremental"));
	m_lgthClearanceHeight->SetValue(object->m_depth_op_params.m_clearance_height);
	m_lgthRapidDownToHeight->SetValue(object->m_depth_op_params.m_rapid_down_to_height);
	m_lgthStartDepth->SetValue(object->m_depth_op_params.m_start_depth);
	m_lgthFinalDepth->SetValue(object->m_depth_op_params.m_final_depth);
	m_lgthStepDown->SetValue(object->m_depth_op_params.m_step_down);
	m_lgthHFeed->SetValue(object->m_speed_op_params.m_horizontal_feed_rate);
	m_lgthVFeed->SetValue(object->m_speed_op_params.m_vertical_feed_rate);
	m_dblSpindleSpeed->SetValue(object->m_speed_op_params.m_spindle_speed);
	m_txtComment->SetValue(object->m_comment);
	m_chkActive->SetValue(object->m_active);
	m_txtTitle->SetValue(object->m_title);
	m_ignore_event_functions = false;
}

void PocketDlg::SetPicture()
{
	wxWindow* w = FindFocus();

	if(w == m_lgthStepOver)m_picture->SetPicture(m_step_over_bitmap);
	else if(w == m_lgthMaterialAllowance)m_picture->SetPicture(m_material_allowance_bitmap);
	else if(w == m_cmbStartingPlace)
	{
		if(m_cmbStartingPlace->GetValue() == _("boundary"))m_picture->SetPicture(m_starting_boundary_bitmap);
		else m_picture->SetPicture(m_starting_center_bitmap);
	}
	else if(w == m_chkKeepToolDown)
	{
		if(m_chkKeepToolDown->IsChecked())m_picture->SetPicture(m_tool_down_bitmap);
		else m_picture->SetPicture(m_not_tool_down_bitmap);
	}
	else if(w == m_chkUseZigZag)
	{
		if(m_chkUseZigZag->IsChecked())m_picture->SetPicture(m_use_zig_zag_bitmap);
		else m_picture->SetPicture(m_general_bitmap);
	}
	else if(w == m_dblZigAngle)m_picture->SetPicture(m_zig_angle_bitmap);
	else if(w == m_lgthClearanceHeight)m_picture->SetPicture(m_clearnce_height_bitmap);
	else if(w == m_lgthRapidDownToHeight)m_picture->SetPicture(m_rapid_down_to_bitmap);
	else if(w == m_lgthStartDepth)m_picture->SetPicture(m_start_depth_bitmap);
	else if(w == m_lgthFinalDepth)m_picture->SetPicture(m_final_depth_bitmap);
	else if(w == m_lgthStepDown)m_picture->SetPicture(m_step_down_bitmap);
	else m_picture->SetPicture(m_general_bitmap);
}

void PocketDlg::OnChildFocus(wxChildFocusEvent& event)
{
	if(m_ignore_event_functions)return;
	if(event.GetWindow())
	{
		SetPicture();
	}
}

void PocketDlg::OnComboStartingPlace( wxCommandEvent& event )
{
	if(m_ignore_event_functions)return;
	SetPicture();
}

void PocketDlg::OnCheckKeepToolDown(wxCommandEvent& event)
{
	if(m_ignore_event_functions)return;
	SetPicture();
}

void PocketDlg::OnCheckUseZigZag(wxCommandEvent& event)
{
	if(m_ignore_event_functions)return;
	SetPicture();
}

void PocketDlg::AddLabelAndControl(wxBoxSizer* sizer, const wxString& label, wxWindow* control)
{
    wxBoxSizer *sizer_horizontal = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *static_label = new wxStaticText(this, wxID_ANY, label);
	sizer_horizontal->Add( static_label, 0, wxRIGHT | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 5 );
	sizer_horizontal->Add( control, 0, wxLEFT | wxALIGN_RIGHT | wxEXPAND | wxALIGN_CENTER_VERTICAL, 5 );
	sizer->Add( sizer_horizontal, 0, wxALL, 5 );
}