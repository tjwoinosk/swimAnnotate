#ifndef KEYPOINTANNOTATORDIALOG_H
#define KEYPOINTANNOTATORDIALOG_H

#include "wx/dialog.h"

class KeyPointAnnotatorDialog : public wxDialog
{
public:
	KeyPointAnnotatorDialog(wxWindow* parent);
	~KeyPointAnnotatorDialog() {}

private:

	void BindCtrls();

	wxTextCtrl* m_logPtr{};
	void SetupLogger();

	void LoadPoolImage();

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

	void PaintEvent(wxPaintEvent& evt);
	void PaintNow();
	void OnSize(wxSizeEvent& event);
	void Render(wxDC& dc);


	wxImage m_image{};
	wxBitmap m_resized{};
	wxScrolledWindow* m_imageWindowPtr{};
	int m_imgW{}, m_imgH{};
};

#endif // !KEYPOINTANNOTATORDIALOG_H

