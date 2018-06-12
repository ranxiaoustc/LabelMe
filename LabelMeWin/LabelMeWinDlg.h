
// LabelMeWinDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "BtnST.h"
#include "afxcmn.h"
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <opencv2/opencv.hpp>

#define MIN_NEIGBOR 5
#define POINT_CIRCLE_R 3
#define POINT_LINE_R 1

#define COLOR_GREEN (cv::Scalar(0,255,0))
#define COLOR_BLUE (cv::Scalar(255,0,0))


// CLabelMeWinDlg 对话框
class CLabelMeWinDlg : public CDialogEx
{
// 构造
public:
	CLabelMeWinDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LABELMEWIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//文件路径
	CString mCurrentFile;
	std::vector<std::string> mvFiles;
	int mCurrentIndex;
	CString mRootDir;

	//标签
	std::set<std::string> msLabels;
	

	//图像显示
	cv::Mat mSrc;
	cv::Mat mShow;
	CImage mCimg;
	CRect mRectShow;

	//
	bool mbLButtonDown;
	cv::Point mptStart;
	cv::Point mptEnd;
	std::vector<cv::Point> mvRoi;
	std::vector<std::pair<std::string, std::vector<cv::Point>>> mvPolys;

public:

	CString SelectFolder();
	void RefreshFileLists();
	void ItemHighLight(int idx_no, int idx_yes, CListCtrl& list);

	//图片显示
	void LoadImageAndShow();
	void ConvertMatToCImage(cv::Mat & src, CImage & cimg);
	void MakeShowingImage(cv::Mat & src, cv::Mat & dst, UINT id);
	void DrawCImageCenter(ATL::CImage& image, CWnd* pwnd, CRect& dstRect, COLORREF bkColor = RGB(105, 105, 105));
	void DrawRect();
	void DrawPolys(cv::Mat& canvas);
	void DrawCurrentPoly(cv::Mat& canvas);

	//
	float GetPtDistI2(cv::Point& p1, cv::Point& p2);

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnOpen();
	CButtonST mBtnOpen;
	CButtonST mBtnOpenDir;
	CButtonST mBtnNextImage;
	CButtonST mBtnPrevImage;
	CButtonST mBtnSave;
	CButtonST mBtnCreatePoly;
	CButtonST mBtnDeletePoly;
	CButtonST mBtnEditPoly;
	CButtonST mBtnLoadLabel;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CListCtrl mListFiles;
	CListCtrl mListROIs;
	CListCtrl mListLabels;
	afx_msg void OnBnClickedBtnOpenDir();
	afx_msg void OnBnClickedBtnNextImage();
	afx_msg void OnBnClickedBtnPrevImage();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnCreatePoly();
	afx_msg void OnBnClickedBtnDeletePoly();
	afx_msg void OnBnClickedBtnEditPoly();
	afx_msg void OnNMClickListFiles(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnLoadLabel();
};
