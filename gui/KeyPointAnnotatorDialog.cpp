#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

#include "KeyPointAnnotatorDialog.h"
#include "wx/textctrl.h"
#include "wx/xrc/xmlres.h" 

KeyPointAnnotatorDialog::KeyPointAnnotatorDialog(wxWindow* parent)
{
	wxXmlResource::Get()->LoadDialog(this, parent, "KeyPointDialog");

	m_logPtr = XRCCTRL(*this,"logTextCtrl", wxTextCtrl);
	if (m_logPtr != nullptr)
		delete wxLog::SetActiveTarget(new wxLogTextCtrl(m_logPtr));

	wxStaticText* fileLocation = XRCCTRL(*this, "m_displayWorkSpaceStaticText", wxStaticText);
	fileLocation->SetLabel("New File Name");

	XRCCTRL(*this, "m_undoAnnotationButton", wxButton)->Bind(wxEVT_BUTTON,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnAnnotationUndo), this, XRCID("m_undoAnnotationButton"));
	XRCCTRL(*this, "m_zoomInButton", wxButton)->Bind(wxEVT_BUTTON,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnImgZoomIn), this, XRCID("m_zoomInButton"));
	XRCCTRL(*this, "m_zoomOutButton", wxButton)->Bind(wxEVT_BUTTON,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnImgZoomOut), this, XRCID("m_zoomOutButton"));
	XRCCTRL(*this, "m_lastImgButton", wxButton)->Bind(wxEVT_BUTTON,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnLastImage), this, XRCID("m_lastImgButton"));
	XRCCTRL(*this, "m_nextImgButton", wxButton)->Bind(wxEVT_BUTTON,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnNextImage), this, XRCID("m_nextImgButton"));
	XRCCTRL(*this, "m_hasBumpersCheckBox", wxCheckBox)->Bind(wxEVT_CHECKBOX,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnBumpersPressed), this, XRCID("m_hasBumpersCheckBox"));
	XRCCTRL(*this, "m_hasBulkheadCheckBox", wxCheckBox)->Bind(wxEVT_CHECKBOX,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnBulkheadPressed), this, XRCID("m_hasBulkheadCheckBox"));
	XRCCTRL(*this, "m_poolLengthChoice", wxChoice)->Bind(wxEVT_CHOICE,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnChangePoolLength), this, XRCID("m_poolLengthChoice"));
	XRCCTRL(*this, "m_numberLanesChoice", wxChoice)->Bind(wxEVT_CHOICE,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnChangeNumberLanes), this, XRCID("m_numberLanesChoice"));
	XRCCTRL(*this, "m_fileNameTextCtrl", wxTextCtrl)->Bind(wxEVT_TEXT_ENTER,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnChangeFileName), this, XRCID("m_fileNameTextCtrl"));
	XRCCTRL(*this, "m_annoationClassComboBox", wxComboBox)->Bind(wxEVT_COMBOBOX,
		wxCommandEventHandler(KeyPointAnnotatorDialog::OnChangeKeyPointClass), this, XRCID("m_annoationClassComboBox"));
	XRCCTRL(*this, "m_imgScrolledWindow", wxScrolledWindow)->Bind(wxEVT_MOTION,
		wxMouseEventHandler(KeyPointAnnotatorDialog::OnMouseMoveInImage), this, XRCID("m_imgScrolledWindow"));
	XRCCTRL(*this, "m_imgScrolledWindow", wxScrolledWindow)->Bind(wxEVT_LEFT_UP,
		wxMouseEventHandler(KeyPointAnnotatorDialog::OnMouseClick), this, XRCID("m_imgScrolledWindow"));
}

void KeyPointAnnotatorDialog::OnAnnotationUndo(wxCommandEvent& event)
{
	wxLogMessage("Annotation Undo Clicked");
}

void KeyPointAnnotatorDialog::OnImgZoomIn(wxCommandEvent& event)
{
	wxLogMessage("Zoom In Clicked");
}

void KeyPointAnnotatorDialog::OnImgZoomOut(wxCommandEvent& event)
{
	wxLogMessage("Zoom Out Clicked");
}

void KeyPointAnnotatorDialog::OnLastImage(wxCommandEvent& event)
{
	wxLogMessage("Last Image Clicked");
}

void KeyPointAnnotatorDialog::OnNextImage(wxCommandEvent& event)
{
	wxLogMessage("Next Image Clicked");
}

void KeyPointAnnotatorDialog::OnBumpersPressed(wxCommandEvent& event)
{
	if(event.IsChecked())
		wxLogMessage("Bumpers checked");
	else
		wxLogMessage("Bumpers unchecked");
}

void KeyPointAnnotatorDialog::OnBulkheadPressed(wxCommandEvent& event)
{
	if (event.IsChecked())
		wxLogMessage("Bulkhead checked");
	else
		wxLogMessage("Bulkhead unchecked");
}

void KeyPointAnnotatorDialog::OnChangePoolLength(wxCommandEvent& event)
{
	wxLogMessage("Pool length changed to " + event.GetString());
}

void KeyPointAnnotatorDialog::OnChangeNumberLanes(wxCommandEvent& event)
{
	//int sel = event.GetSelection();//selection is 0 == 6, 1 == 8, 2 == 10
	wxLogMessage("Number lanes changed to " + event.GetString());
}

void KeyPointAnnotatorDialog::OnChangeFileName(wxCommandEvent& event)
{
	wxLogMessage("File Name Changed");
}

void KeyPointAnnotatorDialog::OnChangeKeyPointClass(wxCommandEvent& event)
{
	wxLogMessage("KeyPoint Class Changed");
}

void KeyPointAnnotatorDialog::OnMouseMoveInImage(wxMouseEvent& event)
{
	//point is relative to the window it is coming from
	//wxPoint point = event.GetPosition();
	//*m_logPtr << "Mouse Event: (" << point.x << "," << point.y << ")\n";
}

void KeyPointAnnotatorDialog::OnMouseClick(wxMouseEvent& event)
{
	wxPoint point = event.GetPosition();
	*m_logPtr << "Mouse Click: (" << point.x << "," << point.y << ")\n";
}
