#ifndef KEYPOINTANNOTATORDIALOG_H
#define KEYPOINTANNOTATORDIALOG_H

#include "wx/dialog.h"

class KeyPointAnnotatorDialog : public wxDialog
{
public:
	KeyPointAnnotatorDialog(wxWindow* parent);
	~KeyPointAnnotatorDialog() {}

private:

	void OnAnnotationUndo(wxCommandEvent& event);
	void OnImgZoomIn(wxCommandEvent& event);
	void OnImgZoomOut(wxCommandEvent& event);
	void OnLastImage(wxCommandEvent& event);
	void OnNextImage(wxCommandEvent& event);
	void OnBumpersPressed(wxCommandEvent& event);
	void OnBulkheadPressed(wxCommandEvent& event);

	void OnChangePoolLength(wxCommandEvent& event);
	void OnChangeNumberLanes(wxCommandEvent& event);
	void OnChangeFileName(wxCommandEvent& event);
	void OnChangeKeyPointClass(wxCommandEvent& event);

	void OnMouseMoveInImage(wxMouseEvent& event);
	void OnMouseClick(wxMouseEvent& event);

	wxTextCtrl* m_logPtr{};
};

#endif // !KEYPOINTANNOTATORDIALOG_H

