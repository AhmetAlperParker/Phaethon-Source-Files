#pragma once
#include "stdafx.h"
#include "Section.h"
#include "Element.h"
#include "Algorithm.h"
#include "F_LongReinf.h"
#include "f_about.h"
#include "guiInput.h"
#include "mcContainer.h"
#include "F_SolvProgress.h"
#include "f_start.h"


namespace Phaethon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for F_Main
	/// </summary>
	public ref class F_Main : public System::Windows::Forms::Form
	{
	public:
		F_Main(void)
		{
			InitializeComponent();
			//
			cmbIntTypSec->SelectedItem = "Midpoint"; 
			cmbIntTypElem->SelectedItem = "Gauss-Lobatto";
			//
			f_start ^ fstart = gcnew f_start();
			fstart->ShowDialog();
			delete fstart;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~F_Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnPushoverSolve;
	protected: 


	private: System::Windows::Forms::RadioButton^  rbCirc;
	private: System::Windows::Forms::RadioButton^  rbRect;
	private: System::Windows::Forms::GroupBox^  grbSectionType;

	private: System::Windows::Forms::GroupBox^  grbGeometry;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::MenuStrip^  mnu;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^  lblb;

	private: System::Windows::Forms::Label^  lblh;
	private: System::Windows::Forms::TextBox^  txtd;
	private: System::Windows::Forms::TextBox^  txth;
	private: System::Windows::Forms::Label^  lbld;
	private: System::Windows::Forms::TextBox^  txtb;
	private: System::Windows::Forms::GroupBox^  grbConcrete;
	private: System::Windows::Forms::TextBox^  txtConcFc;

	private: System::Windows::Forms::Label^  lblConcFc;

	private: System::Windows::Forms::TextBox^  txtConcEpc;

	private: System::Windows::Forms::Label^  lblConcEpc;
	private: System::Windows::Forms::TextBox^  txtConcFcr;
	private: System::Windows::Forms::Label^  lblConcFcr;




	private: System::Windows::Forms::Label^  lblConcEcr;
	private: System::Windows::Forms::TextBox^  txtConcFyy;

	private: System::Windows::Forms::TextBox^  txtConcRsy;

	private: System::Windows::Forms::TextBox^  txtConcEcr;



	private: System::Windows::Forms::TextBox^  txtSteelEh;

	private: System::Windows::Forms::Label^  lblSteelEh;
	private: System::Windows::Forms::TextBox^  txtSteelFy;


	private: System::Windows::Forms::Label^  lblSteelFy;
	private: System::Windows::Forms::TextBox^  txtSteelEs;



private: System::Windows::Forms::Label^  lblSteelEs;
private: System::Windows::Forms::GroupBox^  grbReinforcement;
private: System::Windows::Forms::Label^  lblNIPSec;
private: System::Windows::Forms::Label^  lblIntTypSec;
private: System::Windows::Forms::ComboBox^  cmbIntTypSec;
	private: System::Windows::Forms::TabControl^  tabControlInput;
	private: System::Windows::Forms::TabPage^  tbPPOInp;
	private: System::Windows::Forms::TabPage^  tbPMCInp;




private: System::Windows::Forms::NumericUpDown^  nmrNIPSec;

private: System::Windows::Forms::Button^  btnMCSolve;
private: System::Windows::Forms::TextBox^  txtPOLs;
private: System::Windows::Forms::Label^  lblPOLs;
private: System::Windows::Forms::NumericUpDown^  nmrNIPLs;




private: System::Windows::Forms::SplitContainer^  splitContainer3;
private: System::Windows::Forms::SplitContainer^  splitContainer4;
private: System::Windows::Forms::SplitContainer^  splitContainer5;
private: System::Windows::Forms::GroupBox^  grbReinfLong;

private: System::Windows::Forms::GroupBox^  grbReinfTrans;
private: System::Windows::Forms::Button^  btnAreaOfReinfLayers;

private: System::Windows::Forms::NumericUpDown^  nmrCircNSB;

private: System::Windows::Forms::Label^  lblCircNSB;
private: System::Windows::Forms::NumericUpDown^  nmrNMid;

private: System::Windows::Forms::Label^  lblNMid;
private: System::Windows::Forms::TextBox^  txtCircDbar;

private: System::Windows::Forms::Label^  lblCircDbar;
private: System::Windows::Forms::TextBox^  txtStirrDt;
private: System::Windows::Forms::Label^  lblStirrDt;
private: System::Windows::Forms::TextBox^  txtNumStirLegs;
private: System::Windows::Forms::TextBox^  txtSp;
private: System::Windows::Forms::Label^  lblNumStirLegs;
private: System::Windows::Forms::Label^  lblSp;
private: System::Windows::Forms::Label^  lblConcFyy;
private: System::Windows::Forms::Label^  lblConcRsy;
private: System::Windows::Forms::TextBox^  txtCov;
private: System::Windows::Forms::Label^  lblCov;
private: System::Windows::Forms::GroupBox^  grbSolvers;
private: System::Windows::Forms::RadioButton^  rbNaxComp;
private: System::Windows::Forms::RadioButton^  rbNaxTens;



private: System::Windows::Forms::TextBox^  txtNaxial;
private: System::Windows::Forms::Label^  lblNaxial;
private: System::Windows::Forms::Label^  lblIntTypElem;
private: System::Windows::Forms::Label^  lblNIPLs;


private: System::Windows::Forms::NumericUpDown^  nmrNPO;

private: System::Windows::Forms::Label^  lblNPO;
private: System::Windows::Forms::SplitContainer^  splitContainer6;
private: System::Windows::Forms::TextBox^  txtPushStep;

private: System::Windows::Forms::Label^  lblPushStep;
private: System::Windows::Forms::GroupBox^  grbAnch;
private: System::Windows::Forms::CheckBox^  ckbAnch;
private: System::Windows::Forms::TextBox^  txtAnchLb;
private: System::Windows::Forms::Label^  lblAnchLb;


private: System::Windows::Forms::TextBox^  txtAnchDb;

private: System::Windows::Forms::TextBox^  txtAnchFc;
private: System::Windows::Forms::Label^  lblAnchDb;


private: System::Windows::Forms::Label^  lblAnchFc;
private: System::Windows::Forms::Label^  lblNStepsMC;


private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TextBox^  txtGammaIncr;

private: System::Windows::Forms::Label^  lblPhiIncr;
private: System::Windows::Forms::TextBox^  txtPhiIncr;


private: System::Windows::Forms::ComboBox^  cmbIntTypElem;
private: System::Windows::Forms::NumericUpDown^  nmrNStepsMC;
private: System::Windows::Forms::GroupBox^  grbNumRes;
private: System::Windows::Forms::ToolTip^  myToolTip;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::TabControl^  tabControlPORes;
private: System::Windows::Forms::TabPage^  tbPP0General;

private: System::Windows::Forms::SplitContainer^  splitContainer7;
private: System::Windows::Forms::TabPage^  tbPPOAnchor;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartPushoverGeneral;

private: System::Windows::Forms::TabControl^  tabControlResults;
private: System::Windows::Forms::TabPage^  tbPPORes;
private: System::Windows::Forms::TabPage^  tbPMCRes;
private: System::Windows::Forms::Button^  btnSavePOGen;
private: System::Windows::Forms::Button^  btnSavePOAnch;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartPushoverContr;
private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartAnchorage;
private: System::Windows::Forms::Label^  lblChartAnchStep;
private: System::Windows::Forms::ComboBox^  cmbChartAnch;
private: System::Windows::Forms::Button^  btnSaveMC;
private: System::Windows::Forms::SplitContainer^  splitContainer8;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartMC;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartMCFS;







private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(F_Main::typeid));
			System::Windows::Forms::DataVisualization::Charting::VerticalLineAnnotation^  verticalLineAnnotation1 = (gcnew System::Windows::Forms::DataVisualization::Charting::VerticalLineAnnotation());
			System::Windows::Forms::DataVisualization::Charting::HorizontalLineAnnotation^  horizontalLineAnnotation1 = (gcnew System::Windows::Forms::DataVisualization::Charting::HorizontalLineAnnotation());
			System::Windows::Forms::DataVisualization::Charting::TextAnnotation^  textAnnotation1 = (gcnew System::Windows::Forms::DataVisualization::Charting::TextAnnotation());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint1 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(10, 
				10));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint2 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(20, 
				20));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint3 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(30, 
				30));
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint4 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(1, 
				1));
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint5 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(1, 
				5));
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint6 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(1, 
				7));
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^  title4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea7 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint7 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(10, 
				10));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint8 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(20, 
				20));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint9 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(30, 
				30));
			System::Windows::Forms::DataVisualization::Charting::Title^  title5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea8 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint10 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(10, 
				10));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint11 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(20, 
				20));
			System::Windows::Forms::DataVisualization::Charting::DataPoint^  dataPoint12 = (gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint(30, 
				30));
			System::Windows::Forms::DataVisualization::Charting::Title^  title6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->btnPushoverSolve = (gcnew System::Windows::Forms::Button());
			this->rbRect = (gcnew System::Windows::Forms::RadioButton());
			this->rbCirc = (gcnew System::Windows::Forms::RadioButton());
			this->grbSectionType = (gcnew System::Windows::Forms::GroupBox());
			this->grbGeometry = (gcnew System::Windows::Forms::GroupBox());
			this->txtd = (gcnew System::Windows::Forms::TextBox());
			this->txth = (gcnew System::Windows::Forms::TextBox());
			this->lbld = (gcnew System::Windows::Forms::Label());
			this->lblb = (gcnew System::Windows::Forms::Label());
			this->lblh = (gcnew System::Windows::Forms::Label());
			this->txtb = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->grbConcrete = (gcnew System::Windows::Forms::GroupBox());
			this->lblConcEcr = (gcnew System::Windows::Forms::Label());
			this->txtConcEcr = (gcnew System::Windows::Forms::TextBox());
			this->txtConcFcr = (gcnew System::Windows::Forms::TextBox());
			this->lblConcFcr = (gcnew System::Windows::Forms::Label());
			this->txtConcEpc = (gcnew System::Windows::Forms::TextBox());
			this->lblConcEpc = (gcnew System::Windows::Forms::Label());
			this->txtConcFc = (gcnew System::Windows::Forms::TextBox());
			this->lblConcFc = (gcnew System::Windows::Forms::Label());
			this->grbReinforcement = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer5 = (gcnew System::Windows::Forms::SplitContainer());
			this->grbReinfLong = (gcnew System::Windows::Forms::GroupBox());
			this->txtCov = (gcnew System::Windows::Forms::TextBox());
			this->lblCov = (gcnew System::Windows::Forms::Label());
			this->txtCircDbar = (gcnew System::Windows::Forms::TextBox());
			this->lblCircDbar = (gcnew System::Windows::Forms::Label());
			this->nmrCircNSB = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblCircNSB = (gcnew System::Windows::Forms::Label());
			this->nmrNMid = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblNMid = (gcnew System::Windows::Forms::Label());
			this->btnAreaOfReinfLayers = (gcnew System::Windows::Forms::Button());
			this->lblSteelFy = (gcnew System::Windows::Forms::Label());
			this->txtSteelEh = (gcnew System::Windows::Forms::TextBox());
			this->lblSteelEs = (gcnew System::Windows::Forms::Label());
			this->lblSteelEh = (gcnew System::Windows::Forms::Label());
			this->txtSteelEs = (gcnew System::Windows::Forms::TextBox());
			this->txtSteelFy = (gcnew System::Windows::Forms::TextBox());
			this->grbReinfTrans = (gcnew System::Windows::Forms::GroupBox());
			this->txtStirrDt = (gcnew System::Windows::Forms::TextBox());
			this->lblStirrDt = (gcnew System::Windows::Forms::Label());
			this->txtNumStirLegs = (gcnew System::Windows::Forms::TextBox());
			this->txtSp = (gcnew System::Windows::Forms::TextBox());
			this->lblNumStirLegs = (gcnew System::Windows::Forms::Label());
			this->lblSp = (gcnew System::Windows::Forms::Label());
			this->txtConcFyy = (gcnew System::Windows::Forms::TextBox());
			this->txtConcRsy = (gcnew System::Windows::Forms::TextBox());
			this->lblConcFyy = (gcnew System::Windows::Forms::Label());
			this->lblConcRsy = (gcnew System::Windows::Forms::Label());
			this->grbSolvers = (gcnew System::Windows::Forms::GroupBox());
			this->rbNaxComp = (gcnew System::Windows::Forms::RadioButton());
			this->rbNaxTens = (gcnew System::Windows::Forms::RadioButton());
			this->txtNaxial = (gcnew System::Windows::Forms::TextBox());
			this->lblNaxial = (gcnew System::Windows::Forms::Label());
			this->tabControlInput = (gcnew System::Windows::Forms::TabControl());
			this->tbPPOInp = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer6 = (gcnew System::Windows::Forms::SplitContainer());
			this->cmbIntTypElem = (gcnew System::Windows::Forms::ComboBox());
			this->lblPOLs = (gcnew System::Windows::Forms::Label());
			this->txtPushStep = (gcnew System::Windows::Forms::TextBox());
			this->lblIntTypElem = (gcnew System::Windows::Forms::Label());
			this->nmrNIPLs = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblPushStep = (gcnew System::Windows::Forms::Label());
			this->txtPOLs = (gcnew System::Windows::Forms::TextBox());
			this->lblNIPLs = (gcnew System::Windows::Forms::Label());
			this->nmrNPO = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblNPO = (gcnew System::Windows::Forms::Label());
			this->grbAnch = (gcnew System::Windows::Forms::GroupBox());
			this->ckbAnch = (gcnew System::Windows::Forms::CheckBox());
			this->txtAnchLb = (gcnew System::Windows::Forms::TextBox());
			this->lblAnchLb = (gcnew System::Windows::Forms::Label());
			this->txtAnchDb = (gcnew System::Windows::Forms::TextBox());
			this->txtAnchFc = (gcnew System::Windows::Forms::TextBox());
			this->lblAnchDb = (gcnew System::Windows::Forms::Label());
			this->lblAnchFc = (gcnew System::Windows::Forms::Label());
			this->tbPMCInp = (gcnew System::Windows::Forms::TabPage());
			this->nmrNStepsMC = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblNStepsMC = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtGammaIncr = (gcnew System::Windows::Forms::TextBox());
			this->lblPhiIncr = (gcnew System::Windows::Forms::Label());
			this->txtPhiIncr = (gcnew System::Windows::Forms::TextBox());
			this->btnMCSolve = (gcnew System::Windows::Forms::Button());
			this->nmrNIPSec = (gcnew System::Windows::Forms::NumericUpDown());
			this->cmbIntTypSec = (gcnew System::Windows::Forms::ComboBox());
			this->lblIntTypSec = (gcnew System::Windows::Forms::Label());
			this->lblNIPSec = (gcnew System::Windows::Forms::Label());
			this->btnSaveMC = (gcnew System::Windows::Forms::Button());
			this->grbNumRes = (gcnew System::Windows::Forms::GroupBox());
			this->tabControlResults = (gcnew System::Windows::Forms::TabControl());
			this->tbPPORes = (gcnew System::Windows::Forms::TabPage());
			this->btnSavePOAnch = (gcnew System::Windows::Forms::Button());
			this->btnSavePOGen = (gcnew System::Windows::Forms::Button());
			this->tabControlPORes = (gcnew System::Windows::Forms::TabControl());
			this->tbPP0General = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer7 = (gcnew System::Windows::Forms::SplitContainer());
			this->chartPushoverGeneral = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartPushoverContr = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tbPPOAnchor = (gcnew System::Windows::Forms::TabPage());
			this->lblChartAnchStep = (gcnew System::Windows::Forms::Label());
			this->cmbChartAnch = (gcnew System::Windows::Forms::ComboBox());
			this->chartAnchorage = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tbPMCRes = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer8 = (gcnew System::Windows::Forms::SplitContainer());
			this->chartMC = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartMCFS = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->mnu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->myToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->grbSectionType->SuspendLayout();
			this->grbGeometry->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer4))->BeginInit();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
			this->grbConcrete->SuspendLayout();
			this->grbReinforcement->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer5))->BeginInit();
			this->splitContainer5->Panel1->SuspendLayout();
			this->splitContainer5->Panel2->SuspendLayout();
			this->splitContainer5->SuspendLayout();
			this->grbReinfLong->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrCircNSB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNMid))->BeginInit();
			this->grbReinfTrans->SuspendLayout();
			this->grbSolvers->SuspendLayout();
			this->tabControlInput->SuspendLayout();
			this->tbPPOInp->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer6))->BeginInit();
			this->splitContainer6->Panel1->SuspendLayout();
			this->splitContainer6->Panel2->SuspendLayout();
			this->splitContainer6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNIPLs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNPO))->BeginInit();
			this->grbAnch->SuspendLayout();
			this->tbPMCInp->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNStepsMC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNIPSec))->BeginInit();
			this->grbNumRes->SuspendLayout();
			this->tabControlResults->SuspendLayout();
			this->tbPPORes->SuspendLayout();
			this->tabControlPORes->SuspendLayout();
			this->tbPP0General->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer7))->BeginInit();
			this->splitContainer7->Panel1->SuspendLayout();
			this->splitContainer7->Panel2->SuspendLayout();
			this->splitContainer7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartPushoverGeneral))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartPushoverContr))->BeginInit();
			this->tbPPOAnchor->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartAnchorage))->BeginInit();
			this->tbPMCRes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer8))->BeginInit();
			this->splitContainer8->Panel1->SuspendLayout();
			this->splitContainer8->Panel2->SuspendLayout();
			this->splitContainer8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartMC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartMCFS))->BeginInit();
			this->mnu->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnPushoverSolve
			// 
			this->btnPushoverSolve->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnPushoverSolve->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(161)));
			this->btnPushoverSolve->Location = System::Drawing::Point(5, 112);
			this->btnPushoverSolve->Name = L"btnPushoverSolve";
			this->btnPushoverSolve->Size = System::Drawing::Size(75, 23);
			this->btnPushoverSolve->TabIndex = 0;
			this->btnPushoverSolve->Text = L"Solve";
			this->btnPushoverSolve->UseVisualStyleBackColor = true;
			this->btnPushoverSolve->Click += gcnew System::EventHandler(this, &F_Main::btnPushoverSolve_Click);
			// 
			// rbRect
			// 
			this->rbRect->AutoSize = true;
			this->rbRect->Checked = true;
			this->rbRect->Location = System::Drawing::Point(20, 16);
			this->rbRect->Name = L"rbRect";
			this->rbRect->Size = System::Drawing::Size(83, 17);
			this->rbRect->TabIndex = 0;
			this->rbRect->TabStop = true;
			this->rbRect->Text = L"Rectangular";
			this->rbRect->UseVisualStyleBackColor = true;
			// 
			// rbCirc
			// 
			this->rbCirc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->rbCirc->AutoSize = true;
			this->rbCirc->Location = System::Drawing::Point(144, 16);
			this->rbCirc->Name = L"rbCirc";
			this->rbCirc->Size = System::Drawing::Size(60, 17);
			this->rbCirc->TabIndex = 1;
			this->rbCirc->Text = L"Circular";
			this->rbCirc->UseVisualStyleBackColor = true;
			this->rbCirc->CheckedChanged += gcnew System::EventHandler(this, &F_Main::rbCirc_CheckedChanged);
			// 
			// grbSectionType
			// 
			this->grbSectionType->Controls->Add(this->rbRect);
			this->grbSectionType->Controls->Add(this->rbCirc);
			this->grbSectionType->Dock = System::Windows::Forms::DockStyle::Top;
			this->grbSectionType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbSectionType->Location = System::Drawing::Point(5, 16);
			this->grbSectionType->Name = L"grbSectionType";
			this->grbSectionType->Size = System::Drawing::Size(219, 43);
			this->grbSectionType->TabIndex = 2;
			this->grbSectionType->TabStop = false;
			this->grbSectionType->Text = L"Cross-Section Type";
			// 
			// grbGeometry
			// 
			this->grbGeometry->Controls->Add(this->txtd);
			this->grbGeometry->Controls->Add(this->grbSectionType);
			this->grbGeometry->Controls->Add(this->txth);
			this->grbGeometry->Controls->Add(this->lbld);
			this->grbGeometry->Controls->Add(this->lblb);
			this->grbGeometry->Controls->Add(this->lblh);
			this->grbGeometry->Controls->Add(this->txtb);
			this->grbGeometry->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbGeometry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbGeometry->Location = System::Drawing::Point(0, 0);
			this->grbGeometry->Name = L"grbGeometry";
			this->grbGeometry->Padding = System::Windows::Forms::Padding(5, 3, 5, 3);
			this->grbGeometry->Size = System::Drawing::Size(229, 119);
			this->grbGeometry->TabIndex = 3;
			this->grbGeometry->TabStop = false;
			this->grbGeometry->Text = L"Geometry";
			// 
			// txtd
			// 
			this->txtd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtd->Enabled = false;
			this->txtd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtd->Location = System::Drawing::Point(173, 65);
			this->txtd->Name = L"txtd";
			this->txtd->Size = System::Drawing::Size(49, 20);
			this->txtd->TabIndex = 8;
			this->txtd->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtd, L"Diameter of Circular Section");
			// 
			// txth
			// 
			this->txth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txth->Location = System::Drawing::Point(58, 65);
			this->txth->Name = L"txth";
			this->txth->Size = System::Drawing::Size(49, 20);
			this->txth->TabIndex = 5;
			this->txth->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txth, L"Section Depth");
			// 
			// lbld
			// 
			this->lbld->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lbld->AutoSize = true;
			this->lbld->Enabled = false;
			this->lbld->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lbld->Location = System::Drawing::Point(122, 68);
			this->lbld->Name = L"lbld";
			this->lbld->Size = System::Drawing::Size(49, 13);
			this->lbld->TabIndex = 7;
			this->lbld->Text = L"D (mm) =";
			this->myToolTip->SetToolTip(this->lbld, L"Diameter of Circular Section");
			// 
			// lblb
			// 
			this->lblb->AutoSize = true;
			this->lblb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblb->Location = System::Drawing::Point(7, 94);
			this->lblb->Name = L"lblb";
			this->lblb->Size = System::Drawing::Size(47, 13);
			this->lblb->TabIndex = 4;
			this->lblb->Text = L"b (mm) =";
			this->myToolTip->SetToolTip(this->lblb, L"Section Width");
			// 
			// lblh
			// 
			this->lblh->AutoSize = true;
			this->lblh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblh->Location = System::Drawing::Point(7, 68);
			this->lblh->Name = L"lblh";
			this->lblh->Size = System::Drawing::Size(47, 13);
			this->lblh->TabIndex = 3;
			this->lblh->Text = L"h (mm) =";
			this->myToolTip->SetToolTip(this->lblh, L"Section Depth");
			// 
			// txtb
			// 
			this->txtb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtb->Location = System::Drawing::Point(57, 91);
			this->txtb->Name = L"txtb";
			this->txtb->Size = System::Drawing::Size(50, 20);
			this->txtb->TabIndex = 6;
			this->txtb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtb, L"Section Width");
			// 
			// splitContainer1
			// 
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			this->splitContainer1->Panel1->Padding = System::Windows::Forms::Padding(3, 0, 3, 3);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->btnSaveMC);
			this->splitContainer1->Panel2->Controls->Add(this->grbNumRes);
			this->splitContainer1->Panel2->Padding = System::Windows::Forms::Padding(5, 0, 5, 3);
			this->splitContainer1->Size = System::Drawing::Size(1201, 546);
			this->splitContainer1->SplitterDistance = 547;
			this->splitContainer1->TabIndex = 2;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer2->IsSplitterFixed = true;
			this->splitContainer2->Location = System::Drawing::Point(3, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->splitContainer3);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->grbSolvers);
			this->splitContainer2->Size = System::Drawing::Size(537, 539);
			this->splitContainer2->SplitterDistance = 300;
			this->splitContainer2->TabIndex = 1;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer3->IsSplitterFixed = true;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->splitContainer4);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->grbReinforcement);
			this->splitContainer3->Size = System::Drawing::Size(537, 300);
			this->splitContainer3->SplitterDistance = 119;
			this->splitContainer3->TabIndex = 0;
			// 
			// splitContainer4
			// 
			this->splitContainer4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer4->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer4->IsSplitterFixed = true;
			this->splitContainer4->Location = System::Drawing::Point(0, 0);
			this->splitContainer4->Name = L"splitContainer4";
			// 
			// splitContainer4.Panel1
			// 
			this->splitContainer4->Panel1->Controls->Add(this->grbGeometry);
			// 
			// splitContainer4.Panel2
			// 
			this->splitContainer4->Panel2->Controls->Add(this->grbConcrete);
			this->splitContainer4->Size = System::Drawing::Size(537, 119);
			this->splitContainer4->SplitterDistance = 229;
			this->splitContainer4->TabIndex = 0;
			// 
			// grbConcrete
			// 
			this->grbConcrete->Controls->Add(this->lblConcEcr);
			this->grbConcrete->Controls->Add(this->txtConcEcr);
			this->grbConcrete->Controls->Add(this->txtConcFcr);
			this->grbConcrete->Controls->Add(this->lblConcFcr);
			this->grbConcrete->Controls->Add(this->txtConcEpc);
			this->grbConcrete->Controls->Add(this->lblConcEpc);
			this->grbConcrete->Controls->Add(this->txtConcFc);
			this->grbConcrete->Controls->Add(this->lblConcFc);
			this->grbConcrete->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbConcrete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbConcrete->Location = System::Drawing::Point(0, 0);
			this->grbConcrete->Name = L"grbConcrete";
			this->grbConcrete->Size = System::Drawing::Size(304, 119);
			this->grbConcrete->TabIndex = 0;
			this->grbConcrete->TabStop = false;
			this->grbConcrete->Text = L"Concrete";
			// 
			// lblConcEcr
			// 
			this->lblConcEcr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblConcEcr->AutoSize = true;
			this->lblConcEcr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblConcEcr->Location = System::Drawing::Point(167, 83);
			this->lblConcEcr->Name = L"lblConcEcr";
			this->lblConcEcr->Size = System::Drawing::Size(31, 13);
			this->lblConcEcr->TabIndex = 20;
			this->lblConcEcr->Text = L"ecr =";
			this->myToolTip->SetToolTip(this->lblConcEcr, L"Strain at Tensile Concrete Strength");
			// 
			// txtConcEcr
			// 
			this->txtConcEcr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtConcEcr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtConcEcr->Location = System::Drawing::Point(207, 80);
			this->txtConcEcr->Name = L"txtConcEcr";
			this->txtConcEcr->Size = System::Drawing::Size(79, 20);
			this->txtConcEcr->TabIndex = 13;
			this->txtConcEcr->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtConcEcr, L"Strain at Tensile Concrete Strength");
			// 
			// txtConcFcr
			// 
			this->txtConcFcr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtConcFcr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtConcFcr->Location = System::Drawing::Point(228, 30);
			this->txtConcFcr->Name = L"txtConcFcr";
			this->txtConcFcr->Size = System::Drawing::Size(58, 20);
			this->txtConcFcr->TabIndex = 11;
			this->txtConcFcr->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtConcFcr, L"Tensile Concrete Strength");
			// 
			// lblConcFcr
			// 
			this->lblConcFcr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblConcFcr->AutoSize = true;
			this->lblConcFcr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblConcFcr->Location = System::Drawing::Point(167, 33);
			this->lblConcFcr->Name = L"lblConcFcr";
			this->lblConcFcr->Size = System::Drawing::Size(59, 13);
			this->lblConcFcr->TabIndex = 10;
			this->lblConcFcr->Text = L"fcr (MPa) =";
			this->myToolTip->SetToolTip(this->lblConcFcr, L"Tensile Concrete Strength");
			// 
			// txtConcEpc
			// 
			this->txtConcEpc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtConcEpc->Location = System::Drawing::Point(69, 80);
			this->txtConcEpc->Name = L"txtConcEpc";
			this->txtConcEpc->Size = System::Drawing::Size(58, 20);
			this->txtConcEpc->TabIndex = 9;
			this->txtConcEpc->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtConcEpc, L"Strain at Concrete Cylinder Compressive Strength");
			// 
			// lblConcEpc
			// 
			this->lblConcEpc->AutoSize = true;
			this->lblConcEpc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblConcEpc->Location = System::Drawing::Point(12, 83);
			this->lblConcEpc->Name = L"lblConcEpc";
			this->lblConcEpc->Size = System::Drawing::Size(40, 13);
			this->lblConcEpc->TabIndex = 8;
			this->lblConcEpc->Text = L"epc0 =";
			this->myToolTip->SetToolTip(this->lblConcEpc, L"Strain at Concrete Cylinder Compressive Strength");
			// 
			// txtConcFc
			// 
			this->txtConcFc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtConcFc->Location = System::Drawing::Point(69, 30);
			this->txtConcFc->Name = L"txtConcFc";
			this->txtConcFc->Size = System::Drawing::Size(58, 20);
			this->txtConcFc->TabIndex = 7;
			this->txtConcFc->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtConcFc, L"Concrete Cylinder Compressive Strength");
			this->txtConcFc->Leave += gcnew System::EventHandler(this, &F_Main::txtConcFc_Leave);
			// 
			// lblConcFc
			// 
			this->lblConcFc->AutoSize = true;
			this->lblConcFc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblConcFc->Location = System::Drawing::Point(12, 33);
			this->lblConcFc->Name = L"lblConcFc";
			this->lblConcFc->Size = System::Drawing::Size(56, 13);
			this->lblConcFc->TabIndex = 6;
			this->lblConcFc->Text = L"fc (MPa) =";
			this->myToolTip->SetToolTip(this->lblConcFc, L"Concrete Cylinder Compressive Strength");
			// 
			// grbReinforcement
			// 
			this->grbReinforcement->Controls->Add(this->splitContainer5);
			this->grbReinforcement->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbReinforcement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbReinforcement->Location = System::Drawing::Point(0, 0);
			this->grbReinforcement->Name = L"grbReinforcement";
			this->grbReinforcement->Padding = System::Windows::Forms::Padding(5, 3, 5, 3);
			this->grbReinforcement->Size = System::Drawing::Size(537, 177);
			this->grbReinforcement->TabIndex = 4;
			this->grbReinforcement->TabStop = false;
			this->grbReinforcement->Text = L"Reinforcement";
			// 
			// splitContainer5
			// 
			this->splitContainer5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer5->Location = System::Drawing::Point(5, 16);
			this->splitContainer5->Name = L"splitContainer5";
			// 
			// splitContainer5.Panel1
			// 
			this->splitContainer5->Panel1->Controls->Add(this->grbReinfLong);
			// 
			// splitContainer5.Panel2
			// 
			this->splitContainer5->Panel2->Controls->Add(this->grbReinfTrans);
			this->splitContainer5->Size = System::Drawing::Size(527, 158);
			this->splitContainer5->SplitterDistance = 370;
			this->splitContainer5->TabIndex = 0;
			// 
			// grbReinfLong
			// 
			this->grbReinfLong->Controls->Add(this->txtCov);
			this->grbReinfLong->Controls->Add(this->lblCov);
			this->grbReinfLong->Controls->Add(this->txtCircDbar);
			this->grbReinfLong->Controls->Add(this->lblCircDbar);
			this->grbReinfLong->Controls->Add(this->nmrCircNSB);
			this->grbReinfLong->Controls->Add(this->lblCircNSB);
			this->grbReinfLong->Controls->Add(this->nmrNMid);
			this->grbReinfLong->Controls->Add(this->lblNMid);
			this->grbReinfLong->Controls->Add(this->btnAreaOfReinfLayers);
			this->grbReinfLong->Controls->Add(this->lblSteelFy);
			this->grbReinfLong->Controls->Add(this->txtSteelEh);
			this->grbReinfLong->Controls->Add(this->lblSteelEs);
			this->grbReinfLong->Controls->Add(this->lblSteelEh);
			this->grbReinfLong->Controls->Add(this->txtSteelEs);
			this->grbReinfLong->Controls->Add(this->txtSteelFy);
			this->grbReinfLong->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbReinfLong->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbReinfLong->Location = System::Drawing::Point(0, 0);
			this->grbReinfLong->Name = L"grbReinfLong";
			this->grbReinfLong->Size = System::Drawing::Size(370, 158);
			this->grbReinfLong->TabIndex = 1;
			this->grbReinfLong->TabStop = false;
			this->grbReinfLong->Text = L"Longitudinal";
			// 
			// txtCov
			// 
			this->txtCov->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtCov->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtCov->Location = System::Drawing::Point(306, 101);
			this->txtCov->Name = L"txtCov";
			this->txtCov->Size = System::Drawing::Size(58, 20);
			this->txtCov->TabIndex = 26;
			this->txtCov->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtCov, L"Clear Concrete Cover of Reinforcing Steel");
			// 
			// lblCov
			// 
			this->lblCov->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblCov->AutoSize = true;
			this->lblCov->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblCov->Location = System::Drawing::Point(244, 104);
			this->lblCov->Name = L"lblCov";
			this->lblCov->Size = System::Drawing::Size(60, 13);
			this->lblCov->TabIndex = 25;
			this->lblCov->Text = L"Cov (mm) =";
			this->myToolTip->SetToolTip(this->lblCov, L"Clear Concrete Cover of Reinforcing Steel");
			// 
			// txtCircDbar
			// 
			this->txtCircDbar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtCircDbar->Enabled = false;
			this->txtCircDbar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtCircDbar->Location = System::Drawing::Point(144, 73);
			this->txtCircDbar->Name = L"txtCircDbar";
			this->txtCircDbar->Size = System::Drawing::Size(45, 20);
			this->txtCircDbar->TabIndex = 24;
			this->txtCircDbar->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtCircDbar, L"Diameter of the Longitudinal Steel Bars");
			// 
			// lblCircDbar
			// 
			this->lblCircDbar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblCircDbar->AutoSize = true;
			this->lblCircDbar->Enabled = false;
			this->lblCircDbar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblCircDbar->Location = System::Drawing::Point(141, 55);
			this->lblCircDbar->Name = L"lblCircDbar";
			this->lblCircDbar->Size = System::Drawing::Size(55, 13);
			this->lblCircDbar->TabIndex = 23;
			this->lblCircDbar->Text = L"Dbar (mm)";
			this->myToolTip->SetToolTip(this->lblCircDbar, L"Diameter of the Longitudinal Steel Bars");
			// 
			// nmrCircNSB
			// 
			this->nmrCircNSB->Enabled = false;
			this->nmrCircNSB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->nmrCircNSB->Location = System::Drawing::Point(169, 24);
			this->nmrCircNSB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->nmrCircNSB->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->nmrCircNSB->Name = L"nmrCircNSB";
			this->nmrCircNSB->Size = System::Drawing::Size(45, 20);
			this->nmrCircNSB->TabIndex = 22;
			this->nmrCircNSB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->nmrCircNSB, L"Total Number of Longitudinal Steel Bars");
			this->nmrCircNSB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			// 
			// lblCircNSB
			// 
			this->lblCircNSB->AutoSize = true;
			this->lblCircNSB->Enabled = false;
			this->lblCircNSB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblCircNSB->Location = System::Drawing::Point(128, 27);
			this->lblCircNSB->Name = L"lblCircNSB";
			this->lblCircNSB->Size = System::Drawing::Size(34, 13);
			this->lblCircNSB->TabIndex = 21;
			this->lblCircNSB->Text = L"nBars";
			this->myToolTip->SetToolTip(this->lblCircNSB, L"Total Number of Longitudinal Steel Bars");
			// 
			// nmrNMid
			// 
			this->nmrNMid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->nmrNMid->Location = System::Drawing::Point(44, 24);
			this->nmrNMid->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nmrNMid->Name = L"nmrNMid";
			this->nmrNMid->Size = System::Drawing::Size(45, 20);
			this->nmrNMid->TabIndex = 20;
			this->nmrNMid->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->nmrNMid, L"Number of Intermediate Reinforcing Steel Bars on One Section Side Parallel to Loa" 
				L"d (Equally-Spaced Bars are considered)");
			// 
			// lblNMid
			// 
			this->lblNMid->AutoSize = true;
			this->lblNMid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblNMid->Location = System::Drawing::Point(7, 27);
			this->lblNMid->Name = L"lblNMid";
			this->lblNMid->Size = System::Drawing::Size(33, 13);
			this->lblNMid->TabIndex = 19;
			this->lblNMid->Text = L"n.Mid";
			this->myToolTip->SetToolTip(this->lblNMid, L"Number of Intermediate Reinforcing Steel Bars on One Section Side Parallel to Loa" 
				L"d (Equally-Spaced Bars are considered)");
			// 
			// btnAreaOfReinfLayers
			// 
			this->btnAreaOfReinfLayers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(161)));
			this->btnAreaOfReinfLayers->Location = System::Drawing::Point(7, 50);
			this->btnAreaOfReinfLayers->Name = L"btnAreaOfReinfLayers";
			this->btnAreaOfReinfLayers->Size = System::Drawing::Size(83, 61);
			this->btnAreaOfReinfLayers->TabIndex = 18;
			this->btnAreaOfReinfLayers->Text = L"Area of section reinforcement layers";
			this->btnAreaOfReinfLayers->UseVisualStyleBackColor = true;
			this->btnAreaOfReinfLayers->Click += gcnew System::EventHandler(this, &F_Main::btnAreaOfReinfLayers_Click);
			// 
			// lblSteelFy
			// 
			this->lblSteelFy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblSteelFy->AutoSize = true;
			this->lblSteelFy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblSteelFy->Location = System::Drawing::Point(244, 50);
			this->lblSteelFy->Name = L"lblSteelFy";
			this->lblSteelFy->Size = System::Drawing::Size(55, 13);
			this->lblSteelFy->TabIndex = 14;
			this->lblSteelFy->Text = L"fy (MPa) =";
			this->myToolTip->SetToolTip(this->lblSteelFy, L"Yielding Strength of Longitudinal Reinforcement");
			// 
			// txtSteelEh
			// 
			this->txtSteelEh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtSteelEh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtSteelEh->Location = System::Drawing::Point(306, 74);
			this->txtSteelEh->Name = L"txtSteelEh";
			this->txtSteelEh->Size = System::Drawing::Size(58, 20);
			this->txtSteelEh->TabIndex = 17;
			this->txtSteelEh->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtSteelEh, L"Steel Hardening Modulus");
			// 
			// lblSteelEs
			// 
			this->lblSteelEs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblSteelEs->AutoSize = true;
			this->lblSteelEs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblSteelEs->Location = System::Drawing::Point(244, 23);
			this->lblSteelEs->Name = L"lblSteelEs";
			this->lblSteelEs->Size = System::Drawing::Size(59, 13);
			this->lblSteelEs->TabIndex = 12;
			this->lblSteelEs->Text = L"Es (MPa) =";
			this->myToolTip->SetToolTip(this->lblSteelEs, L"Steel Elastic Modulus");
			// 
			// lblSteelEh
			// 
			this->lblSteelEh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblSteelEh->AutoSize = true;
			this->lblSteelEh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblSteelEh->Location = System::Drawing::Point(244, 77);
			this->lblSteelEh->Name = L"lblSteelEh";
			this->lblSteelEh->Size = System::Drawing::Size(60, 13);
			this->lblSteelEh->TabIndex = 16;
			this->lblSteelEh->Text = L"Eh (MPa) =";
			this->myToolTip->SetToolTip(this->lblSteelEh, L"Steel Hardening Modulus");
			// 
			// txtSteelEs
			// 
			this->txtSteelEs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtSteelEs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtSteelEs->Location = System::Drawing::Point(306, 20);
			this->txtSteelEs->Name = L"txtSteelEs";
			this->txtSteelEs->Size = System::Drawing::Size(58, 20);
			this->txtSteelEs->TabIndex = 13;
			this->txtSteelEs->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtSteelEs, L"Steel Elastic Modulus");
			// 
			// txtSteelFy
			// 
			this->txtSteelFy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtSteelFy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtSteelFy->Location = System::Drawing::Point(306, 47);
			this->txtSteelFy->Name = L"txtSteelFy";
			this->txtSteelFy->Size = System::Drawing::Size(58, 20);
			this->txtSteelFy->TabIndex = 15;
			this->txtSteelFy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtSteelFy, L"Yielding Strength of Longitudinal Reinforcement");
			// 
			// grbReinfTrans
			// 
			this->grbReinfTrans->Controls->Add(this->txtStirrDt);
			this->grbReinfTrans->Controls->Add(this->lblStirrDt);
			this->grbReinfTrans->Controls->Add(this->txtNumStirLegs);
			this->grbReinfTrans->Controls->Add(this->txtSp);
			this->grbReinfTrans->Controls->Add(this->lblNumStirLegs);
			this->grbReinfTrans->Controls->Add(this->lblSp);
			this->grbReinfTrans->Controls->Add(this->txtConcFyy);
			this->grbReinfTrans->Controls->Add(this->txtConcRsy);
			this->grbReinfTrans->Controls->Add(this->lblConcFyy);
			this->grbReinfTrans->Controls->Add(this->lblConcRsy);
			this->grbReinfTrans->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbReinfTrans->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbReinfTrans->Location = System::Drawing::Point(0, 0);
			this->grbReinfTrans->Name = L"grbReinfTrans";
			this->grbReinfTrans->Size = System::Drawing::Size(153, 158);
			this->grbReinfTrans->TabIndex = 1;
			this->grbReinfTrans->TabStop = false;
			this->grbReinfTrans->Text = L"Transversal";
			// 
			// txtStirrDt
			// 
			this->txtStirrDt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtStirrDt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtStirrDt->Location = System::Drawing::Point(82, 128);
			this->txtStirrDt->Name = L"txtStirrDt";
			this->txtStirrDt->Size = System::Drawing::Size(58, 20);
			this->txtStirrDt->TabIndex = 26;
			this->txtStirrDt->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtStirrDt, L"Diameter of Stirrups");
			// 
			// lblStirrDt
			// 
			this->lblStirrDt->AutoSize = true;
			this->lblStirrDt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblStirrDt->Location = System::Drawing::Point(8, 131);
			this->lblStirrDt->Name = L"lblStirrDt";
			this->lblStirrDt->Size = System::Drawing::Size(52, 13);
			this->lblStirrDt->TabIndex = 25;
			this->lblStirrDt->Text = L"Dt (mm) =";
			this->myToolTip->SetToolTip(this->lblStirrDt, L"Diameter of Stirrups");
			// 
			// txtNumStirLegs
			// 
			this->txtNumStirLegs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtNumStirLegs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtNumStirLegs->Location = System::Drawing::Point(82, 101);
			this->txtNumStirLegs->Name = L"txtNumStirLegs";
			this->txtNumStirLegs->Size = System::Drawing::Size(58, 20);
			this->txtNumStirLegs->TabIndex = 24;
			this->txtNumStirLegs->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtNumStirLegs, L"Number of Transverse Shear Bars in Cross Section");
			// 
			// txtSp
			// 
			this->txtSp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtSp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtSp->Location = System::Drawing::Point(82, 74);
			this->txtSp->Name = L"txtSp";
			this->txtSp->Size = System::Drawing::Size(58, 20);
			this->txtSp->TabIndex = 23;
			this->txtSp->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtSp, L"Spacing of Stirrups or Spiral");
			// 
			// lblNumStirLegs
			// 
			this->lblNumStirLegs->AutoSize = true;
			this->lblNumStirLegs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblNumStirLegs->Location = System::Drawing::Point(8, 104);
			this->lblNumStirLegs->Name = L"lblNumStirLegs";
			this->lblNumStirLegs->Size = System::Drawing::Size(49, 13);
			this->lblNumStirLegs->TabIndex = 22;
			this->lblNumStirLegs->Text = L"n.StLegs";
			this->myToolTip->SetToolTip(this->lblNumStirLegs, L"Number of Transverse Shear Bars in Cross Section");
			// 
			// lblSp
			// 
			this->lblSp->AutoSize = true;
			this->lblSp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblSp->Location = System::Drawing::Point(8, 77);
			this->lblSp->Name = L"lblSp";
			this->lblSp->Size = System::Drawing::Size(54, 13);
			this->lblSp->TabIndex = 21;
			this->lblSp->Text = L"Sp (mm) =";
			this->myToolTip->SetToolTip(this->lblSp, L"Spacing of Stirrups or Spiral");
			// 
			// txtConcFyy
			// 
			this->txtConcFyy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtConcFyy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtConcFyy->Location = System::Drawing::Point(82, 47);
			this->txtConcFyy->Name = L"txtConcFyy";
			this->txtConcFyy->Size = System::Drawing::Size(58, 20);
			this->txtConcFyy->TabIndex = 19;
			this->txtConcFyy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtConcFyy, L"Yielding Strength of Transverse Reinforcement");
			// 
			// txtConcRsy
			// 
			this->txtConcRsy->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtConcRsy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtConcRsy->Location = System::Drawing::Point(82, 20);
			this->txtConcRsy->Name = L"txtConcRsy";
			this->txtConcRsy->Size = System::Drawing::Size(58, 20);
			this->txtConcRsy->TabIndex = 17;
			this->txtConcRsy->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtConcRsy, L"Transverse Steel Reinforcement Ratio");
			// 
			// lblConcFyy
			// 
			this->lblConcFyy->AutoSize = true;
			this->lblConcFyy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblConcFyy->Location = System::Drawing::Point(8, 50);
			this->lblConcFyy->Name = L"lblConcFyy";
			this->lblConcFyy->Size = System::Drawing::Size(60, 13);
			this->lblConcFyy->TabIndex = 20;
			this->lblConcFyy->Text = L"fyy (MPa) =";
			this->myToolTip->SetToolTip(this->lblConcFyy, L"Yielding Strength of Transverse Reinforcement");
			// 
			// lblConcRsy
			// 
			this->lblConcRsy->AutoSize = true;
			this->lblConcRsy->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblConcRsy->Location = System::Drawing::Point(8, 23);
			this->lblConcRsy->Name = L"lblConcRsy";
			this->lblConcRsy->Size = System::Drawing::Size(29, 13);
			this->lblConcRsy->TabIndex = 18;
			this->lblConcRsy->Text = L"rsy =";
			this->myToolTip->SetToolTip(this->lblConcRsy, L"Transverse Steel Reinforcement Ratio");
			// 
			// grbSolvers
			// 
			this->grbSolvers->Controls->Add(this->rbNaxComp);
			this->grbSolvers->Controls->Add(this->rbNaxTens);
			this->grbSolvers->Controls->Add(this->txtNaxial);
			this->grbSolvers->Controls->Add(this->lblNaxial);
			this->grbSolvers->Controls->Add(this->tabControlInput);
			this->grbSolvers->Controls->Add(this->nmrNIPSec);
			this->grbSolvers->Controls->Add(this->cmbIntTypSec);
			this->grbSolvers->Controls->Add(this->lblIntTypSec);
			this->grbSolvers->Controls->Add(this->lblNIPSec);
			this->grbSolvers->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbSolvers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbSolvers->Location = System::Drawing::Point(0, 0);
			this->grbSolvers->Name = L"grbSolvers";
			this->grbSolvers->Size = System::Drawing::Size(537, 235);
			this->grbSolvers->TabIndex = 0;
			this->grbSolvers->TabStop = false;
			this->grbSolvers->Text = L"Solution Procedures";
			// 
			// rbNaxComp
			// 
			this->rbNaxComp->AutoSize = true;
			this->rbNaxComp->Checked = true;
			this->rbNaxComp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->rbNaxComp->Location = System::Drawing::Point(432, 16);
			this->rbNaxComp->Name = L"rbNaxComp";
			this->rbNaxComp->Size = System::Drawing::Size(99, 17);
			this->rbNaxComp->TabIndex = 20;
			this->rbNaxComp->TabStop = true;
			this->rbNaxComp->Text = L"Compressive N ";
			this->rbNaxComp->UseVisualStyleBackColor = true;
			// 
			// rbNaxTens
			// 
			this->rbNaxTens->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->rbNaxTens->AutoSize = true;
			this->rbNaxTens->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->rbNaxTens->Location = System::Drawing::Point(432, 39);
			this->rbNaxTens->Name = L"rbNaxTens";
			this->rbNaxTens->Size = System::Drawing::Size(70, 17);
			this->rbNaxTens->TabIndex = 21;
			this->rbNaxTens->Text = L"Tensile N";
			this->rbNaxTens->UseVisualStyleBackColor = true;
			// 
			// txtNaxial
			// 
			this->txtNaxial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtNaxial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtNaxial->Location = System::Drawing::Point(367, 24);
			this->txtNaxial->Name = L"txtNaxial";
			this->txtNaxial->Size = System::Drawing::Size(58, 20);
			this->txtNaxial->TabIndex = 19;
			this->txtNaxial->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtNaxial, L"Absolute value of column axial load");
			// 
			// lblNaxial
			// 
			this->lblNaxial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblNaxial->AutoSize = true;
			this->lblNaxial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblNaxial->Location = System::Drawing::Point(317, 27);
			this->lblNaxial->Name = L"lblNaxial";
			this->lblNaxial->Size = System::Drawing::Size(47, 13);
			this->lblNaxial->TabIndex = 18;
			this->lblNaxial->Text = L"N (kN) =";
			this->myToolTip->SetToolTip(this->lblNaxial, L"Absolute value of column axial load");
			// 
			// tabControlInput
			// 
			this->tabControlInput->Controls->Add(this->tbPPOInp);
			this->tabControlInput->Controls->Add(this->tbPMCInp);
			this->tabControlInput->HotTrack = true;
			this->tabControlInput->Location = System::Drawing::Point(3, 62);
			this->tabControlInput->Multiline = true;
			this->tabControlInput->Name = L"tabControlInput";
			this->tabControlInput->SelectedIndex = 0;
			this->tabControlInput->Size = System::Drawing::Size(531, 170);
			this->tabControlInput->TabIndex = 11;
			this->tabControlInput->SelectedIndexChanged += gcnew System::EventHandler(this, &F_Main::tabControlInput_SelectedIndexChanged);
			// 
			// tbPPOInp
			// 
			this->tbPPOInp->BackColor = System::Drawing::Color::Silver;
			this->tbPPOInp->Controls->Add(this->splitContainer6);
			this->tbPPOInp->Location = System::Drawing::Point(4, 22);
			this->tbPPOInp->Name = L"tbPPOInp";
			this->tbPPOInp->Padding = System::Windows::Forms::Padding(3);
			this->tbPPOInp->Size = System::Drawing::Size(523, 144);
			this->tbPPOInp->TabIndex = 0;
			this->tbPPOInp->Text = L"Pushover";
			// 
			// splitContainer6
			// 
			this->splitContainer6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer6->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer6->Location = System::Drawing::Point(3, 3);
			this->splitContainer6->Name = L"splitContainer6";
			// 
			// splitContainer6.Panel1
			// 
			this->splitContainer6->Panel1->Controls->Add(this->cmbIntTypElem);
			this->splitContainer6->Panel1->Controls->Add(this->btnPushoverSolve);
			this->splitContainer6->Panel1->Controls->Add(this->lblPOLs);
			this->splitContainer6->Panel1->Controls->Add(this->txtPushStep);
			this->splitContainer6->Panel1->Controls->Add(this->lblIntTypElem);
			this->splitContainer6->Panel1->Controls->Add(this->nmrNIPLs);
			this->splitContainer6->Panel1->Controls->Add(this->lblPushStep);
			this->splitContainer6->Panel1->Controls->Add(this->txtPOLs);
			this->splitContainer6->Panel1->Controls->Add(this->lblNIPLs);
			this->splitContainer6->Panel1->Controls->Add(this->nmrNPO);
			this->splitContainer6->Panel1->Controls->Add(this->lblNPO);
			// 
			// splitContainer6.Panel2
			// 
			this->splitContainer6->Panel2->Controls->Add(this->grbAnch);
			this->splitContainer6->Size = System::Drawing::Size(517, 138);
			this->splitContainer6->SplitterDistance = 360;
			this->splitContainer6->TabIndex = 0;
			// 
			// cmbIntTypElem
			// 
			this->cmbIntTypElem->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cmbIntTypElem->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIntTypElem->Enabled = false;
			this->cmbIntTypElem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->cmbIntTypElem->FormattingEnabled = true;
			this->cmbIntTypElem->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"Gauss-Lobatto"});
			this->cmbIntTypElem->Location = System::Drawing::Point(243, 39);
			this->cmbIntTypElem->Name = L"cmbIntTypElem";
			this->cmbIntTypElem->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->cmbIntTypElem->Size = System::Drawing::Size(105, 21);
			this->cmbIntTypElem->TabIndex = 30;
			this->myToolTip->SetToolTip(this->cmbIntTypElem, L"Element Integration Type");
			// 
			// lblPOLs
			// 
			this->lblPOLs->AutoSize = true;
			this->lblPOLs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblPOLs->Location = System::Drawing::Point(10, 11);
			this->lblPOLs->Name = L"lblPOLs";
			this->lblPOLs->Size = System::Drawing::Size(55, 13);
			this->lblPOLs->TabIndex = 20;
			this->lblPOLs->Text = L"Ls (mm) = ";
			this->myToolTip->SetToolTip(this->lblPOLs, L"Shear Span of the Cantilever Column");
			// 
			// txtPushStep
			// 
			this->txtPushStep->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtPushStep->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtPushStep->Location = System::Drawing::Point(101, 62);
			this->txtPushStep->Name = L"txtPushStep";
			this->txtPushStep->Size = System::Drawing::Size(58, 20);
			this->txtPushStep->TabIndex = 29;
			this->txtPushStep->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtPushStep, L"Pushover Load Increment");
			// 
			// lblIntTypElem
			// 
			this->lblIntTypElem->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblIntTypElem->AutoSize = true;
			this->lblIntTypElem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblIntTypElem->Location = System::Drawing::Point(190, 42);
			this->lblIntTypElem->Name = L"lblIntTypElem";
			this->lblIntTypElem->Size = System::Drawing::Size(51, 13);
			this->lblIntTypElem->TabIndex = 24;
			this->lblIntTypElem->Text = L"IntTyp.Ls";
			this->myToolTip->SetToolTip(this->lblIntTypElem, L"Element Integration Type");
			// 
			// nmrNIPLs
			// 
			this->nmrNIPLs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->nmrNIPLs->Location = System::Drawing::Point(303, 8);
			this->nmrNIPLs->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nmrNIPLs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->nmrNIPLs->Name = L"nmrNIPLs";
			this->nmrNIPLs->Size = System::Drawing::Size(45, 20);
			this->nmrNIPLs->TabIndex = 23;
			this->nmrNIPLs->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->nmrNIPLs, L"Amount of Integration Points on the Element");
			this->nmrNIPLs->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// lblPushStep
			// 
			this->lblPushStep->AutoSize = true;
			this->lblPushStep->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblPushStep->Location = System::Drawing::Point(10, 65);
			this->lblPushStep->Name = L"lblPushStep";
			this->lblPushStep->Size = System::Drawing::Size(85, 13);
			this->lblPushStep->TabIndex = 28;
			this->lblPushStep->Text = L"PushStep (kN) =";
			this->myToolTip->SetToolTip(this->lblPushStep, L"Pushover Load Increment");
			// 
			// txtPOLs
			// 
			this->txtPOLs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtPOLs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtPOLs->Location = System::Drawing::Point(101, 8);
			this->txtPOLs->Name = L"txtPOLs";
			this->txtPOLs->Size = System::Drawing::Size(58, 20);
			this->txtPOLs->TabIndex = 21;
			this->txtPOLs->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtPOLs, L"Shear Span of the Cantilever Column");
			// 
			// lblNIPLs
			// 
			this->lblNIPLs->AutoSize = true;
			this->lblNIPLs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblNIPLs->Location = System::Drawing::Point(262, 11);
			this->lblNIPLs->Name = L"lblNIPLs";
			this->lblNIPLs->Size = System::Drawing::Size(37, 13);
			this->lblNIPLs->TabIndex = 22;
			this->lblNIPLs->Text = L"nIP.Ls";
			this->myToolTip->SetToolTip(this->lblNIPLs, L"Amount of Integration Points on the Element");
			// 
			// nmrNPO
			// 
			this->nmrNPO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->nmrNPO->Location = System::Drawing::Point(101, 35);
			this->nmrNPO->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrNPO->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nmrNPO->Name = L"nmrNPO";
			this->nmrNPO->Size = System::Drawing::Size(58, 20);
			this->nmrNPO->TabIndex = 27;
			this->nmrNPO->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->nmrNPO, L"Total Number of Pushover Load Steps");
			this->nmrNPO->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// lblNPO
			// 
			this->lblNPO->AutoSize = true;
			this->lblNPO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblNPO->Location = System::Drawing::Point(10, 38);
			this->lblNPO->Name = L"lblNPO";
			this->lblNPO->Size = System::Drawing::Size(72, 13);
			this->lblNPO->TabIndex = 26;
			this->lblNPO->Text = L"NoPushSteps";
			this->myToolTip->SetToolTip(this->lblNPO, L"Total Number of Pushover Load Steps");
			// 
			// grbAnch
			// 
			this->grbAnch->Controls->Add(this->ckbAnch);
			this->grbAnch->Controls->Add(this->txtAnchLb);
			this->grbAnch->Controls->Add(this->lblAnchLb);
			this->grbAnch->Controls->Add(this->txtAnchDb);
			this->grbAnch->Controls->Add(this->txtAnchFc);
			this->grbAnch->Controls->Add(this->lblAnchDb);
			this->grbAnch->Controls->Add(this->lblAnchFc);
			this->grbAnch->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbAnch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbAnch->Location = System::Drawing::Point(0, 0);
			this->grbAnch->Name = L"grbAnch";
			this->grbAnch->Size = System::Drawing::Size(153, 138);
			this->grbAnch->TabIndex = 2;
			this->grbAnch->TabStop = false;
			this->grbAnch->Text = L"Anchorage     ";
			// 
			// ckbAnch
			// 
			this->ckbAnch->AutoSize = true;
			this->ckbAnch->Checked = true;
			this->ckbAnch->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ckbAnch->Location = System::Drawing::Point(74, 1);
			this->ckbAnch->Name = L"ckbAnch";
			this->ckbAnch->Size = System::Drawing::Size(15, 14);
			this->ckbAnch->TabIndex = 27;
			this->ckbAnch->UseVisualStyleBackColor = true;
			this->ckbAnch->CheckedChanged += gcnew System::EventHandler(this, &F_Main::ckbAnch_CheckedChanged);
			// 
			// txtAnchLb
			// 
			this->txtAnchLb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtAnchLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtAnchLb->Location = System::Drawing::Point(82, 74);
			this->txtAnchLb->Name = L"txtAnchLb";
			this->txtAnchLb->Size = System::Drawing::Size(58, 20);
			this->txtAnchLb->TabIndex = 23;
			this->txtAnchLb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtAnchLb, L"Equivalent Straight Anchorage Length of Extreme Longitudinal Steel Bar");
			// 
			// lblAnchLb
			// 
			this->lblAnchLb->AutoSize = true;
			this->lblAnchLb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblAnchLb->Location = System::Drawing::Point(8, 77);
			this->lblAnchLb->Name = L"lblAnchLb";
			this->lblAnchLb->Size = System::Drawing::Size(53, 13);
			this->lblAnchLb->TabIndex = 21;
			this->lblAnchLb->Text = L"Lb (mm) =";
			this->myToolTip->SetToolTip(this->lblAnchLb, L"Equivalent Straight Anchorage Length of Extreme Longitudinal Steel Bar");
			// 
			// txtAnchDb
			// 
			this->txtAnchDb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtAnchDb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtAnchDb->Location = System::Drawing::Point(82, 47);
			this->txtAnchDb->Name = L"txtAnchDb";
			this->txtAnchDb->Size = System::Drawing::Size(58, 20);
			this->txtAnchDb->TabIndex = 19;
			this->txtAnchDb->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtAnchDb, L"Extreme Steel Bar Diameter of Longitudinal Reinforcement");
			// 
			// txtAnchFc
			// 
			this->txtAnchFc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtAnchFc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtAnchFc->Location = System::Drawing::Point(82, 20);
			this->txtAnchFc->Name = L"txtAnchFc";
			this->txtAnchFc->Size = System::Drawing::Size(58, 20);
			this->txtAnchFc->TabIndex = 17;
			this->txtAnchFc->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtAnchFc, L"Concrete Cylinder Compressive Strength in the Anchorage");
			// 
			// lblAnchDb
			// 
			this->lblAnchDb->AutoSize = true;
			this->lblAnchDb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblAnchDb->Location = System::Drawing::Point(8, 50);
			this->lblAnchDb->Name = L"lblAnchDb";
			this->lblAnchDb->Size = System::Drawing::Size(55, 13);
			this->lblAnchDb->TabIndex = 20;
			this->lblAnchDb->Text = L"Db (mm) =";
			this->myToolTip->SetToolTip(this->lblAnchDb, L"Extreme Steel Bar Diameter of Longitudinal Reinforcement");
			// 
			// lblAnchFc
			// 
			this->lblAnchFc->AutoSize = true;
			this->lblAnchFc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblAnchFc->Location = System::Drawing::Point(8, 23);
			this->lblAnchFc->Name = L"lblAnchFc";
			this->lblAnchFc->Size = System::Drawing::Size(56, 13);
			this->lblAnchFc->TabIndex = 18;
			this->lblAnchFc->Text = L"fc (MPa) =";
			this->myToolTip->SetToolTip(this->lblAnchFc, L"Concrete Cylinder Compressive Strength in the Anchorage");
			// 
			// tbPMCInp
			// 
			this->tbPMCInp->BackColor = System::Drawing::Color::Gainsboro;
			this->tbPMCInp->Controls->Add(this->nmrNStepsMC);
			this->tbPMCInp->Controls->Add(this->lblNStepsMC);
			this->tbPMCInp->Controls->Add(this->label2);
			this->tbPMCInp->Controls->Add(this->txtGammaIncr);
			this->tbPMCInp->Controls->Add(this->lblPhiIncr);
			this->tbPMCInp->Controls->Add(this->txtPhiIncr);
			this->tbPMCInp->Controls->Add(this->btnMCSolve);
			this->tbPMCInp->Location = System::Drawing::Point(4, 22);
			this->tbPMCInp->Name = L"tbPMCInp";
			this->tbPMCInp->Padding = System::Windows::Forms::Padding(3);
			this->tbPMCInp->Size = System::Drawing::Size(523, 144);
			this->tbPMCInp->TabIndex = 1;
			this->tbPMCInp->Text = L"Moment - Curvature";
			// 
			// nmrNStepsMC
			// 
			this->nmrNStepsMC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->nmrNStepsMC->Location = System::Drawing::Point(111, 81);
			this->nmrNStepsMC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nmrNStepsMC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->nmrNStepsMC->Name = L"nmrNStepsMC";
			this->nmrNStepsMC->Size = System::Drawing::Size(58, 20);
			this->nmrNStepsMC->TabIndex = 28;
			this->nmrNStepsMC->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->nmrNStepsMC, L"Total Number of Analysis Steps");
			this->nmrNStepsMC->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// lblNStepsMC
			// 
			this->lblNStepsMC->AutoSize = true;
			this->lblNStepsMC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblNStepsMC->Location = System::Drawing::Point(15, 84);
			this->lblNStepsMC->Name = L"lblNStepsMC";
			this->lblNStepsMC->Size = System::Drawing::Size(48, 13);
			this->lblNStepsMC->TabIndex = 26;
			this->lblNStepsMC->Text = L"NoSteps";
			this->myToolTip->SetToolTip(this->lblNStepsMC, L"Total Number of Analysis Steps");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->label2->Location = System::Drawing::Point(15, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 24;
			this->label2->Text = L"gamma Incr. =";
			this->myToolTip->SetToolTip(this->label2, L"Shear Strain Increment");
			// 
			// txtGammaIncr
			// 
			this->txtGammaIncr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtGammaIncr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtGammaIncr->Location = System::Drawing::Point(111, 51);
			this->txtGammaIncr->Name = L"txtGammaIncr";
			this->txtGammaIncr->Size = System::Drawing::Size(68, 20);
			this->txtGammaIncr->TabIndex = 25;
			this->txtGammaIncr->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtGammaIncr, L"Shear Strain Increment");
			// 
			// lblPhiIncr
			// 
			this->lblPhiIncr->AutoSize = true;
			this->lblPhiIncr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblPhiIncr->Location = System::Drawing::Point(15, 24);
			this->lblPhiIncr->Name = L"lblPhiIncr";
			this->lblPhiIncr->Size = System::Drawing::Size(90, 13);
			this->lblPhiIncr->TabIndex = 22;
			this->lblPhiIncr->Text = L"phi Incr. (1/mm) =";
			this->myToolTip->SetToolTip(this->lblPhiIncr, L"Curvature Increment");
			// 
			// txtPhiIncr
			// 
			this->txtPhiIncr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtPhiIncr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->txtPhiIncr->Location = System::Drawing::Point(111, 21);
			this->txtPhiIncr->Name = L"txtPhiIncr";
			this->txtPhiIncr->Size = System::Drawing::Size(68, 20);
			this->txtPhiIncr->TabIndex = 23;
			this->txtPhiIncr->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->txtPhiIncr, L"Curvature Increment");
			// 
			// btnMCSolve
			// 
			this->btnMCSolve->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnMCSolve->Location = System::Drawing::Point(6, 115);
			this->btnMCSolve->Name = L"btnMCSolve";
			this->btnMCSolve->Size = System::Drawing::Size(75, 23);
			this->btnMCSolve->TabIndex = 1;
			this->btnMCSolve->Text = L"Solve";
			this->btnMCSolve->UseVisualStyleBackColor = true;
			this->btnMCSolve->Click += gcnew System::EventHandler(this, &F_Main::btnMCSolve_Click);
			// 
			// nmrNIPSec
			// 
			this->nmrNIPSec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->nmrNIPSec->Location = System::Drawing::Point(58, 24);
			this->nmrNIPSec->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			this->nmrNIPSec->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			this->nmrNIPSec->Name = L"nmrNIPSec";
			this->nmrNIPSec->Size = System::Drawing::Size(45, 20);
			this->nmrNIPSec->TabIndex = 10;
			this->nmrNIPSec->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->myToolTip->SetToolTip(this->nmrNIPSec, L"Number of Integration Concrete Layers per Section");
			this->nmrNIPSec->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// cmbIntTypSec
			// 
			this->cmbIntTypSec->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cmbIntTypSec->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbIntTypSec->Enabled = false;
			this->cmbIntTypSec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->cmbIntTypSec->FormattingEnabled = true;
			this->cmbIntTypSec->Items->AddRange(gcnew cli::array< System::Object^  >(1) {L"Midpoint"});
			this->cmbIntTypSec->Location = System::Drawing::Point(186, 23);
			this->cmbIntTypSec->Name = L"cmbIntTypSec";
			this->cmbIntTypSec->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->cmbIntTypSec->Size = System::Drawing::Size(75, 21);
			this->cmbIntTypSec->TabIndex = 9;
			this->myToolTip->SetToolTip(this->cmbIntTypSec, L"Section Integration Type");
			// 
			// lblIntTypSec
			// 
			this->lblIntTypSec->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblIntTypSec->AutoSize = true;
			this->lblIntTypSec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblIntTypSec->Location = System::Drawing::Point(125, 27);
			this->lblIntTypSec->Name = L"lblIntTypSec";
			this->lblIntTypSec->Size = System::Drawing::Size(59, 13);
			this->lblIntTypSec->TabIndex = 8;
			this->lblIntTypSec->Text = L"IntTyp.Sec";
			this->myToolTip->SetToolTip(this->lblIntTypSec, L"Section Integration Type");
			// 
			// lblNIPSec
			// 
			this->lblNIPSec->AutoSize = true;
			this->lblNIPSec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblNIPSec->Location = System::Drawing::Point(10, 27);
			this->lblNIPSec->Name = L"lblNIPSec";
			this->lblNIPSec->Size = System::Drawing::Size(45, 13);
			this->lblNIPSec->TabIndex = 6;
			this->lblNIPSec->Text = L"nIP.Sec";
			this->myToolTip->SetToolTip(this->lblNIPSec, L"Number of Integration Concrete Layers per Section");
			// 
			// btnSaveMC
			// 
			this->btnSaveMC->Enabled = false;
			this->btnSaveMC->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnSaveMC.Image")));
			this->btnSaveMC->Location = System::Drawing::Point(196, 16);
			this->btnSaveMC->Name = L"btnSaveMC";
			this->btnSaveMC->Size = System::Drawing::Size(23, 24);
			this->btnSaveMC->TabIndex = 5;
			this->myToolTip->SetToolTip(this->btnSaveMC, L"Download Moment - Curvature Results");
			this->btnSaveMC->UseVisualStyleBackColor = true;
			this->btnSaveMC->Click += gcnew System::EventHandler(this, &F_Main::btnSaveMC_Click);
			// 
			// grbNumRes
			// 
			this->grbNumRes->Controls->Add(this->tabControlResults);
			this->grbNumRes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grbNumRes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->grbNumRes->Location = System::Drawing::Point(5, 0);
			this->grbNumRes->Name = L"grbNumRes";
			this->grbNumRes->Padding = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->grbNumRes->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->grbNumRes->Size = System::Drawing::Size(636, 539);
			this->grbNumRes->TabIndex = 1;
			this->grbNumRes->TabStop = false;
			this->grbNumRes->Text = L"Numerical Results";
			// 
			// tabControlResults
			// 
			this->tabControlResults->Controls->Add(this->tbPPORes);
			this->tabControlResults->Controls->Add(this->tbPMCRes);
			this->tabControlResults->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlResults->ItemSize = System::Drawing::Size(65, 26);
			this->tabControlResults->Location = System::Drawing::Point(3, 13);
			this->tabControlResults->Name = L"tabControlResults";
			this->tabControlResults->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tabControlResults->SelectedIndex = 0;
			this->tabControlResults->Size = System::Drawing::Size(630, 523);
			this->tabControlResults->TabIndex = 2;
			this->tabControlResults->SelectedIndexChanged += gcnew System::EventHandler(this, &F_Main::tabControlResults_SelectedIndexChanged);
			// 
			// tbPPORes
			// 
			this->tbPPORes->BackColor = System::Drawing::Color::Transparent;
			this->tbPPORes->Controls->Add(this->btnSavePOAnch);
			this->tbPPORes->Controls->Add(this->btnSavePOGen);
			this->tbPPORes->Controls->Add(this->tabControlPORes);
			this->tbPPORes->Location = System::Drawing::Point(4, 30);
			this->tbPPORes->Name = L"tbPPORes";
			this->tbPPORes->Padding = System::Windows::Forms::Padding(3);
			this->tbPPORes->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tbPPORes->Size = System::Drawing::Size(622, 489);
			this->tbPPORes->TabIndex = 0;
			this->tbPPORes->Text = L"Pushover";
			// 
			// btnSavePOAnch
			// 
			this->btnSavePOAnch->Enabled = false;
			this->btnSavePOAnch->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnSavePOAnch.Image")));
			this->btnSavePOAnch->Location = System::Drawing::Point(165, 6);
			this->btnSavePOAnch->Name = L"btnSavePOAnch";
			this->btnSavePOAnch->Size = System::Drawing::Size(23, 24);
			this->btnSavePOAnch->TabIndex = 4;
			this->myToolTip->SetToolTip(this->btnSavePOAnch, L"Download Anchorage Distributions on currently chosen Pushover Step");
			this->btnSavePOAnch->UseVisualStyleBackColor = true;
			this->btnSavePOAnch->Click += gcnew System::EventHandler(this, &F_Main::btnSavePOAnch_Click);
			// 
			// btnSavePOGen
			// 
			this->btnSavePOGen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnSavePOGen.Image")));
			this->btnSavePOGen->Location = System::Drawing::Point(69, 6);
			this->btnSavePOGen->Name = L"btnSavePOGen";
			this->btnSavePOGen->Size = System::Drawing::Size(23, 24);
			this->btnSavePOGen->TabIndex = 3;
			this->myToolTip->SetToolTip(this->btnSavePOGen, L"Download Pushover Analysis Results");
			this->btnSavePOGen->UseVisualStyleBackColor = true;
			this->btnSavePOGen->Click += gcnew System::EventHandler(this, &F_Main::btnSavePOGen_Click);
			// 
			// tabControlPORes
			// 
			this->tabControlPORes->Controls->Add(this->tbPP0General);
			this->tabControlPORes->Controls->Add(this->tbPPOAnchor);
			this->tabControlPORes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlPORes->ItemSize = System::Drawing::Size(89, 26);
			this->tabControlPORes->Location = System::Drawing::Point(3, 3);
			this->tabControlPORes->Name = L"tabControlPORes";
			this->tabControlPORes->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tabControlPORes->SelectedIndex = 0;
			this->tabControlPORes->Size = System::Drawing::Size(616, 483);
			this->tabControlPORes->TabIndex = 1;
			this->tabControlPORes->SelectedIndexChanged += gcnew System::EventHandler(this, &F_Main::tabControlPORes_SelectedIndexChanged);
			// 
			// tbPP0General
			// 
			this->tbPP0General->Controls->Add(this->splitContainer7);
			this->tbPP0General->Location = System::Drawing::Point(4, 30);
			this->tbPP0General->Name = L"tbPP0General";
			this->tbPP0General->Padding = System::Windows::Forms::Padding(3);
			this->tbPP0General->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tbPP0General->Size = System::Drawing::Size(608, 449);
			this->tbPP0General->TabIndex = 0;
			this->tbPP0General->Text = L"Pushover      ";
			this->tbPP0General->UseVisualStyleBackColor = true;
			// 
			// splitContainer7
			// 
			this->splitContainer7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer7->Location = System::Drawing::Point(3, 3);
			this->splitContainer7->Name = L"splitContainer7";
			this->splitContainer7->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer7.Panel1
			// 
			this->splitContainer7->Panel1->BackColor = System::Drawing::Color::Beige;
			this->splitContainer7->Panel1->Controls->Add(this->chartPushoverGeneral);
			this->splitContainer7->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			// 
			// splitContainer7.Panel2
			// 
			this->splitContainer7->Panel2->BackColor = System::Drawing::Color::Beige;
			this->splitContainer7->Panel2->Controls->Add(this->chartPushoverContr);
			this->splitContainer7->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer7->Size = System::Drawing::Size(602, 443);
			this->splitContainer7->SplitterDistance = 221;
			this->splitContainer7->TabIndex = 2;
			// 
			// chartPushoverGeneral
			// 
			verticalLineAnnotation1->AnchorDataPointName = L"Series1\\r1";
			verticalLineAnnotation1->ClipToChartArea = L"ChartArea1";
			verticalLineAnnotation1->Height = 500;
			verticalLineAnnotation1->LineColor = System::Drawing::Color::DarkRed;
			verticalLineAnnotation1->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			verticalLineAnnotation1->LineWidth = 2;
			verticalLineAnnotation1->Name = L"VLAyield";
			verticalLineAnnotation1->Width = 0;
			horizontalLineAnnotation1->AnchorDataPointName = L"Series1\\r1";
			horizontalLineAnnotation1->ClipToChartArea = L"ChartArea1";
			horizontalLineAnnotation1->LineColor = System::Drawing::Color::DarkRed;
			horizontalLineAnnotation1->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::DashDot;
			horizontalLineAnnotation1->LineWidth = 2;
			horizontalLineAnnotation1->Name = L"HLAyield";
			horizontalLineAnnotation1->Width = -200;
			textAnnotation1->AnchorDataPointName = L"Series1\\r1";
			textAnnotation1->AnchorOffsetX = -7;
			textAnnotation1->AnchorOffsetY = 1;
			textAnnotation1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			textAnnotation1->ForeColor = System::Drawing::Color::DarkRed;
			textAnnotation1->Name = L"txtYield";
			textAnnotation1->Text = L"Yield Point";
			this->chartPushoverGeneral->Annotations->Add(verticalLineAnnotation1);
			this->chartPushoverGeneral->Annotations->Add(horizontalLineAnnotation1);
			this->chartPushoverGeneral->Annotations->Add(textAnnotation1);
			this->chartPushoverGeneral->BackColor = System::Drawing::Color::Transparent;
			this->chartPushoverGeneral->BorderlineColor = System::Drawing::Color::Black;
			chartArea1->AlignmentOrientation = System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal;
			chartArea1->AxisX->Crossing = 0;
			chartArea1->AxisX->IntervalOffset = 1;
			chartArea1->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->AxisX->Title = L"Displacement (mm)";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea1->AxisY->Crossing = 0;
			chartArea1->AxisY->Interval = 10;
			chartArea1->AxisY->IntervalOffset = 10;
			chartArea1->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->AxisY->Title = L"Shear Force (kN)";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea1->BorderColor = System::Drawing::Color::Transparent;
			chartArea1->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->Name = L"ChartArea1";
			chartArea1->Position->Auto = false;
			chartArea1->Position->Height = 83.91924F;
			chartArea1->Position->Width = 73;
			chartArea1->Position->X = 3;
			chartArea1->Position->Y = 12.98242F;
			chartArea2->AlignmentOrientation = System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal;
			chartArea2->AlignWithChartArea = L"ChartArea1";
			chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea2->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea2->AxisY->LabelStyle->Enabled = false;
			chartArea2->AxisY->LineColor = System::Drawing::Color::Transparent;
			chartArea2->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea2->AxisY->MajorTickMark->Enabled = false;
			chartArea2->Name = L"ChartArea2";
			chartArea2->Position->Auto = false;
			chartArea2->Position->Height = 83.91924F;
			chartArea2->Position->Width = 20;
			chartArea2->Position->X = 76;
			chartArea2->Position->Y = 12.98242F;
			this->chartPushoverGeneral->ChartAreas->Add(chartArea1);
			this->chartPushoverGeneral->ChartAreas->Add(chartArea2);
			this->chartPushoverGeneral->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->DockedToChartArea = L"ChartArea2";
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			legend1->IsTextAutoFit = false;
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Row;
			legend1->Name = L"Legend1";
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->chartPushoverGeneral->Legends->Add(legend1);
			this->chartPushoverGeneral->Location = System::Drawing::Point(0, 0);
			this->chartPushoverGeneral->Name = L"chartPushoverGeneral";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			series1->IsVisibleInLegend = false;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series1->Points->Add(dataPoint1);
			series1->Points->Add(dataPoint2);
			series1->Points->Add(dataPoint3);
			series1->SmartLabelStyle->AllowOutsidePlotArea = System::Windows::Forms::DataVisualization::Charting::LabelOutsidePlotAreaStyle::No;
			series1->SmartLabelStyle->MaxMovingDistance = 50;
			series1->SmartLabelStyle->MovingDirection = static_cast<System::Windows::Forms::DataVisualization::Charting::LabelAlignmentStyles>((System::Windows::Forms::DataVisualization::Charting::LabelAlignmentStyles::Left | System::Windows::Forms::DataVisualization::Charting::LabelAlignmentStyles::TopLeft));
			series1->ToolTip = L"#VALX{N2};#VAL{N2}";
			series2->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea2";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Orange;
			series2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			series2->Legend = L"Legend1";
			series2->LegendText = L"axial failure by Elwood & Moehle (2005)";
			series2->Name = L"Series2";
			series2->SmartLabelStyle->AllowOutsidePlotArea = System::Windows::Forms::DataVisualization::Charting::LabelOutsidePlotAreaStyle::No;
			series2->ToolTip = L"#VALX{N2};#VAL{N2}";
			this->chartPushoverGeneral->Series->Add(series1);
			this->chartPushoverGeneral->Series->Add(series2);
			this->chartPushoverGeneral->Size = System::Drawing::Size(598, 217);
			this->chartPushoverGeneral->TabIndex = 0;
			title1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			title1->Name = L"Title1";
			title1->Text = L"Lateral Load - Lateral Displacement";
			this->chartPushoverGeneral->Titles->Add(title1);
			this->chartPushoverGeneral->Visible = false;
			// 
			// chartPushoverContr
			// 
			this->chartPushoverContr->BackColor = System::Drawing::Color::Transparent;
			chartArea3->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea3->AxisX->Title = L"Pushover Step";
			chartArea3->AxisY->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea3->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea3->AxisY->Title = L"Displacement (mm)";
			chartArea3->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea3->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea3->Name = L"ChartArea1";
			this->chartPushoverContr->ChartAreas->Add(chartArea3);
			this->chartPushoverContr->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->DockedToChartArea = L"ChartArea1";
			legend2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Left;
			legend2->Name = L"Legend1";
			this->chartPushoverContr->Legends->Add(legend2);
			this->chartPushoverContr->Location = System::Drawing::Point(0, 0);
			this->chartPushoverContr->Name = L"chartPushoverContr";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn;
			series3->Legend = L"Legend1";
			series3->Name = L"Flexure";
			series3->Points->Add(dataPoint4);
			series3->ToolTip = L"Step:#VALX; #SERIESNAME:#VAL{N2}";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn;
			series4->Legend = L"Legend1";
			series4->Name = L"Anchorage Slip";
			series4->Points->Add(dataPoint5);
			series4->ToolTip = L"Step:#VALX; #SERIESNAME:#VAL{N2}";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn;
			series5->Legend = L"Legend1";
			series5->Name = L"Shear";
			series5->Points->Add(dataPoint6);
			series5->ToolTip = L"Step:#VALX; #SERIESNAME:#VAL{N2}";
			this->chartPushoverContr->Series->Add(series3);
			this->chartPushoverContr->Series->Add(series4);
			this->chartPushoverContr->Series->Add(series5);
			this->chartPushoverContr->Size = System::Drawing::Size(598, 214);
			this->chartPushoverContr->TabIndex = 0;
			title2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			title2->Name = L"Title1";
			title2->Text = L"Lateral Displacement Contributions";
			this->chartPushoverContr->Titles->Add(title2);
			this->chartPushoverContr->Visible = false;
			// 
			// tbPPOAnchor
			// 
			this->tbPPOAnchor->BackColor = System::Drawing::Color::Beige;
			this->tbPPOAnchor->Controls->Add(this->lblChartAnchStep);
			this->tbPPOAnchor->Controls->Add(this->cmbChartAnch);
			this->tbPPOAnchor->Controls->Add(this->chartAnchorage);
			this->tbPPOAnchor->Location = System::Drawing::Point(4, 30);
			this->tbPPOAnchor->Name = L"tbPPOAnchor";
			this->tbPPOAnchor->Padding = System::Windows::Forms::Padding(3);
			this->tbPPOAnchor->Size = System::Drawing::Size(608, 449);
			this->tbPPOAnchor->TabIndex = 1;
			this->tbPPOAnchor->Text = L"Anchorage      ";
			// 
			// lblChartAnchStep
			// 
			this->lblChartAnchStep->AutoSize = true;
			this->lblChartAnchStep->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(161)));
			this->lblChartAnchStep->Location = System::Drawing::Point(27, 47);
			this->lblChartAnchStep->Name = L"lblChartAnchStep";
			this->lblChartAnchStep->Size = System::Drawing::Size(77, 13);
			this->lblChartAnchStep->TabIndex = 3;
			this->lblChartAnchStep->Text = L"Pushover Step";
			this->lblChartAnchStep->Visible = false;
			// 
			// cmbChartAnch
			// 
			this->cmbChartAnch->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbChartAnch->FormattingEnabled = true;
			this->cmbChartAnch->Location = System::Drawing::Point(107, 44);
			this->cmbChartAnch->Name = L"cmbChartAnch";
			this->cmbChartAnch->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->cmbChartAnch->Size = System::Drawing::Size(63, 21);
			this->cmbChartAnch->TabIndex = 2;
			this->cmbChartAnch->Visible = false;
			this->cmbChartAnch->SelectedIndexChanged += gcnew System::EventHandler(this, &F_Main::cmbChartAnch_SelectedIndexChanged);
			// 
			// chartAnchorage
			// 
			this->chartAnchorage->BackColor = System::Drawing::Color::Transparent;
			this->chartAnchorage->BorderlineColor = System::Drawing::Color::Black;
			chartArea4->AxisX->Crossing = 0;
			chartArea4->AxisX->IntervalOffset = 1;
			chartArea4->AxisX->LabelStyle->Enabled = false;
			chartArea4->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea4->AxisX->MajorTickMark->Enabled = false;
			chartArea4->AxisX->MajorTickMark->TickMarkStyle = System::Windows::Forms::DataVisualization::Charting::TickMarkStyle::None;
			chartArea4->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea4->AxisY->Crossing = 0;
			chartArea4->AxisY->Interval = 10;
			chartArea4->AxisY->IntervalOffset = 10;
			chartArea4->AxisY->LabelStyle->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Auto;
			chartArea4->AxisY->LabelStyle->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Auto;
			chartArea4->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea4->AxisY->Title = L"Strain";
			chartArea4->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea4->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea4->Name = L"caAnchStrain";
			chartArea5->AlignWithChartArea = L"caAnchStrain";
			chartArea5->AxisX->LabelStyle->Enabled = false;
			chartArea5->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea5->AxisX->MajorTickMark->Enabled = false;
			chartArea5->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea5->AxisY->LabelStyle->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Auto;
			chartArea5->AxisY->LabelStyle->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Auto;
			chartArea5->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea5->AxisY->Title = L"Slip (mm)";
			chartArea5->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea5->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea5->Name = L"caAnchSlip";
			chartArea6->AlignWithChartArea = L"caAnchStrain";
			chartArea6->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea6->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea6->AxisY->LabelStyle->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Auto;
			chartArea6->AxisY->LabelStyle->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Auto;
			chartArea6->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea6->AxisY->Title = L"Bond (MPa)";
			chartArea6->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea6->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea6->Name = L"caAnchBond";
			this->chartAnchorage->ChartAreas->Add(chartArea4);
			this->chartAnchorage->ChartAreas->Add(chartArea5);
			this->chartAnchorage->ChartAreas->Add(chartArea6);
			this->chartAnchorage->Dock = System::Windows::Forms::DockStyle::Fill;
			legend3->Alignment = System::Drawing::StringAlignment::Far;
			legend3->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			legend3->IsDockedInsideChartArea = false;
			legend3->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Row;
			legend3->Name = L"Legend1";
			this->chartAnchorage->Legends->Add(legend3);
			this->chartAnchorage->Location = System::Drawing::Point(3, 3);
			this->chartAnchorage->Name = L"chartAnchorage";
			series6->BorderWidth = 2;
			series6->ChartArea = L"caAnchStrain";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series6->Legend = L"Legend1";
			series6->Name = L"Strain";
			series6->ToolTip = L"#VALX;#VAL{N2}";
			series7->BorderWidth = 2;
			series7->ChartArea = L"caAnchSlip";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series7->Legend = L"Legend1";
			series7->Name = L"Slip";
			series7->ToolTip = L"#VALX;#VAL{N2}";
			series8->BorderWidth = 2;
			series8->ChartArea = L"caAnchBond";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series8->Legend = L"Legend1";
			series8->Name = L"Bond";
			series8->ToolTip = L"#VALX;#VAL{N2}";
			this->chartAnchorage->Series->Add(series6);
			this->chartAnchorage->Series->Add(series7);
			this->chartAnchorage->Series->Add(series8);
			this->chartAnchorage->Size = System::Drawing::Size(602, 443);
			this->chartAnchorage->TabIndex = 1;
			title3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			title3->Name = L"Title1";
			title3->Text = L"Anchorage Distributions";
			title4->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			title4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			title4->Name = L"Title2";
			title4->Text = L"Anchorage Length (mm)";
			this->chartAnchorage->Titles->Add(title3);
			this->chartAnchorage->Titles->Add(title4);
			this->chartAnchorage->Visible = false;
			// 
			// tbPMCRes
			// 
			this->tbPMCRes->BackColor = System::Drawing::Color::Transparent;
			this->tbPMCRes->Controls->Add(this->splitContainer8);
			this->tbPMCRes->Location = System::Drawing::Point(4, 30);
			this->tbPMCRes->Name = L"tbPMCRes";
			this->tbPMCRes->Padding = System::Windows::Forms::Padding(3);
			this->tbPMCRes->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tbPMCRes->Size = System::Drawing::Size(622, 489);
			this->tbPMCRes->TabIndex = 1;
			this->tbPMCRes->Text = L"Moment - Curvature      ";
			// 
			// splitContainer8
			// 
			this->splitContainer8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer8->Location = System::Drawing::Point(3, 3);
			this->splitContainer8->Name = L"splitContainer8";
			this->splitContainer8->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer8.Panel1
			// 
			this->splitContainer8->Panel1->BackColor = System::Drawing::Color::Beige;
			this->splitContainer8->Panel1->Controls->Add(this->chartMC);
			this->splitContainer8->Panel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			// 
			// splitContainer8.Panel2
			// 
			this->splitContainer8->Panel2->BackColor = System::Drawing::Color::Beige;
			this->splitContainer8->Panel2->Controls->Add(this->chartMCFS);
			this->splitContainer8->Panel2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->splitContainer8->Size = System::Drawing::Size(616, 483);
			this->splitContainer8->SplitterDistance = 238;
			this->splitContainer8->TabIndex = 3;
			// 
			// chartMC
			// 
			this->chartMC->BackColor = System::Drawing::Color::Transparent;
			this->chartMC->BorderlineColor = System::Drawing::Color::Black;
			chartArea7->AxisX->Crossing = 0;
			chartArea7->AxisX->IntervalOffset = 1;
			chartArea7->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea7->AxisX->Title = L"Curvature (1/mm)";
			chartArea7->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea7->AxisY->Crossing = 0;
			chartArea7->AxisY->Interval = 10;
			chartArea7->AxisY->IntervalOffset = 10;
			chartArea7->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea7->AxisY->Title = L"Moment (kNm)";
			chartArea7->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea7->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea7->Name = L"ChartArea1";
			this->chartMC->ChartAreas->Add(chartArea7);
			this->chartMC->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartMC->Location = System::Drawing::Point(0, 0);
			this->chartMC->Name = L"chartMC";
			series9->BorderWidth = 2;
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series9->IsVisibleInLegend = false;
			series9->Name = L"Series1";
			series9->Points->Add(dataPoint7);
			series9->Points->Add(dataPoint8);
			series9->Points->Add(dataPoint9);
			series9->ToolTip = L"#VALX{N2};#VAL{N2}";
			this->chartMC->Series->Add(series9);
			this->chartMC->Size = System::Drawing::Size(612, 234);
			this->chartMC->TabIndex = 0;
			title5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			title5->Name = L"Title1";
			title5->Text = L"Moment - Curvature";
			this->chartMC->Titles->Add(title5);
			this->chartMC->Visible = false;
			// 
			// chartMCFS
			// 
			this->chartMCFS->BackColor = System::Drawing::Color::Transparent;
			this->chartMCFS->BorderlineColor = System::Drawing::Color::Black;
			chartArea8->AxisX->Crossing = 0;
			chartArea8->AxisX->IntervalOffset = 1;
			chartArea8->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea8->AxisX->Title = L"Shear Strain";
			chartArea8->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea8->AxisY->Crossing = 0;
			chartArea8->AxisY->Interval = 10;
			chartArea8->AxisY->IntervalOffset = 10;
			chartArea8->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea8->AxisY->Title = L"Shear Force(kN)";
			chartArea8->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			chartArea8->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea8->Name = L"ChartArea1";
			this->chartMCFS->ChartAreas->Add(chartArea8);
			this->chartMCFS->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartMCFS->Location = System::Drawing::Point(0, 0);
			this->chartMCFS->Name = L"chartMCFS";
			series10->BorderColor = System::Drawing::Color::OrangeRed;
			series10->BorderWidth = 2;
			series10->ChartArea = L"ChartArea1";
			series10->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series10->Color = System::Drawing::Color::OrangeRed;
			series10->IsVisibleInLegend = false;
			series10->Name = L"Series1";
			series10->Points->Add(dataPoint10);
			series10->Points->Add(dataPoint11);
			series10->Points->Add(dataPoint12);
			series10->ToolTip = L"#VALX{N2};#VAL{N2}";
			this->chartMCFS->Series->Add(series10);
			this->chartMCFS->Size = System::Drawing::Size(612, 237);
			this->chartMCFS->TabIndex = 1;
			title6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			title6->Name = L"Title1";
			title6->Text = L"Shear Force - Shear Strain";
			this->chartMCFS->Titles->Add(title6);
			this->chartMCFS->Visible = false;
			// 
			// mnu
			// 
			this->mnu->GripStyle = System::Windows::Forms::ToolStripGripStyle::Visible;
			this->mnu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, this->aboutToolStripMenuItem});
			this->mnu->Location = System::Drawing::Point(0, 0);
			this->mnu->Margin = System::Windows::Forms::Padding(3);
			this->mnu->Name = L"mnu";
			this->mnu->Padding = System::Windows::Forms::Padding(3, 2, 2, 2);
			this->mnu->Size = System::Drawing::Size(1201, 24);
			this->mnu->TabIndex = 3;
			this->mnu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->newToolStripMenuItem, 
				this->saveToolStripMenuItem, this->openToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &F_Main::newToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->saveToolStripMenuItem->Text = L"Save As...";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &F_Main::saveToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->openToolStripMenuItem->Text = L"Load...";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &F_Main::openToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &F_Main::aboutToolStripMenuItem_Click);
			// 
			// myToolTip
			// 
			this->myToolTip->AutomaticDelay = 750;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// F_Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1201, 570);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->mnu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->mnu;
			this->MinimumSize = System::Drawing::Size(609, 609);
			this->Name = L"F_Main";
			this->Text = L"Phaethon";
			this->Shown += gcnew System::EventHandler(this, &F_Main::F_Main_Shown);
			this->grbSectionType->ResumeLayout(false);
			this->grbSectionType->PerformLayout();
			this->grbGeometry->ResumeLayout(false);
			this->grbGeometry->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->splitContainer4->Panel1->ResumeLayout(false);
			this->splitContainer4->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer4))->EndInit();
			this->splitContainer4->ResumeLayout(false);
			this->grbConcrete->ResumeLayout(false);
			this->grbConcrete->PerformLayout();
			this->grbReinforcement->ResumeLayout(false);
			this->splitContainer5->Panel1->ResumeLayout(false);
			this->splitContainer5->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer5))->EndInit();
			this->splitContainer5->ResumeLayout(false);
			this->grbReinfLong->ResumeLayout(false);
			this->grbReinfLong->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrCircNSB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNMid))->EndInit();
			this->grbReinfTrans->ResumeLayout(false);
			this->grbReinfTrans->PerformLayout();
			this->grbSolvers->ResumeLayout(false);
			this->grbSolvers->PerformLayout();
			this->tabControlInput->ResumeLayout(false);
			this->tbPPOInp->ResumeLayout(false);
			this->splitContainer6->Panel1->ResumeLayout(false);
			this->splitContainer6->Panel1->PerformLayout();
			this->splitContainer6->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer6))->EndInit();
			this->splitContainer6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNIPLs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNPO))->EndInit();
			this->grbAnch->ResumeLayout(false);
			this->grbAnch->PerformLayout();
			this->tbPMCInp->ResumeLayout(false);
			this->tbPMCInp->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNStepsMC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmrNIPSec))->EndInit();
			this->grbNumRes->ResumeLayout(false);
			this->tabControlResults->ResumeLayout(false);
			this->tbPPORes->ResumeLayout(false);
			this->tabControlPORes->ResumeLayout(false);
			this->tbPP0General->ResumeLayout(false);
			this->splitContainer7->Panel1->ResumeLayout(false);
			this->splitContainer7->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer7))->EndInit();
			this->splitContainer7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartPushoverGeneral))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartPushoverContr))->EndInit();
			this->tbPPOAnchor->ResumeLayout(false);
			this->tbPPOAnchor->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartAnchorage))->EndInit();
			this->tbPMCRes->ResumeLayout(false);
			this->splitContainer8->Panel1->ResumeLayout(false);
			this->splitContainer8->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer8))->EndInit();
			this->splitContainer8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartMC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chartMCFS))->EndInit();
			this->mnu->ResumeLayout(false);
			this->mnu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//system event handlers
	private: System::Void btnPushoverSolve_Click(System::Object^  sender, System::EventArgs^  e);	
			 System::Void btnMCSolve_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void rbCirc_CheckedChanged(System::Object^  sender, System::EventArgs^  e); 
			 System::Void ckbAnch_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void btnAreaOfReinfLayers_Click(System::Object^  sender, System::EventArgs^  e); 
			 System::Void txtConcFc_Leave(System::Object^  sender, System::EventArgs^  e);
			 System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void F_Main_Shown(System::Object^  sender, System::EventArgs^  e);
			 System::Void tabControlInput_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void tabControlPORes_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void btnSavePOGen_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void cmbChartAnch_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void btnSavePOAnch_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void tabControlResults_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e); 
			 System::Void btnSaveMC_Click(System::Object^  sender, System::EventArgs^  e);
					
	//mine
	private:
		bool F_Main::inputChecks();
		bool F_Main::inputDoubleFromGui(TextBox^  txtGui, double &num, int saveload);
		bool F_Main::inputIntFromGui(NumericUpDown^  nmrGui, int &inum, int saveload);
		bool F_Main::assignValuesFromGui(bool pushover, int saveload); //-1 gia solver, 1 gia save, 2 gia clear
		bool F_Main::openFile(String ^strFileName);
		void F_Main::GUIClear();

};
}

