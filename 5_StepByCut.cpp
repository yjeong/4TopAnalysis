{
	gROOT->SetStyle("Plain");//"Pub","Plain"
	gStyle->SetOptStat(0);//To display the mean and RMS: SetOptStat("mr"), nemruoi, ;
	gStyle->SetOptDate(1);//display date position
	//---------------------------------------------------

	TLatex lt1;
	lt1.SetTextAlign(12);
	lt1.SetNDC();
	lt1.SetTextFont(132);
	lt1.SetTextAngle(0);
	lt1.SetTextSize(0.045);

	TLatex lt2;
	lt2.SetTextAlign(12);
	lt2.SetNDC();
	lt2.SetTextFont(62);
	lt2.SetTextAngle(0);
	lt2.SetTextSize(0.058);

	TLatex lt3;
	lt3.SetTextAlign(12);
	lt3.SetNDC();
	lt3.SetTextAngle(0);
	lt3.SetTextFont(52);
	lt3.SetTextSize(0.045);

	TLatex lt4;
	lt4.SetTextAlign(32);
	lt4.SetNDC();
	lt4.SetTextAngle(0);
	lt4.SetTextFont(42);
	lt4.SetTextSize(0.05);
	//----------------------------------------------------


	//-----------------------------------Coordinate of CMS Simulation------------------------------------------------------------
	float x_1 = 0.1; //right top side x_1 = 0.73
	const float y_1 = 0.94; //right top side y_1 = 0.84
	float x_2 = x_1+0.095; //right top side y_2 = y_1-0.07
	float y_2 = y_1-0.005;
	//------------------------------------Coordinate of first LatexBox---------------------------------------
	float xx_1 = 0.15;
	float yy_1 = 0.80;
	//--------------------------------------Set Maximum histo_TTTT[NJ][NStep]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.62;
	float ly1 = 0.61;
	float lx2 = 0.94;
	float ly2 = 0.78;

	const int JetStepCut = 7;//Step Num
	const int NJetNum = 1;//Variable
	//int NJet[] = {4,5,6,7,8,9,10};
	int NJet[] = {6};

	TH1F *histo_TTTT[JetStepCut][NJetNum];
	TH1F *histo_TTTT_gen[JetStepCut][NJetNum];

	TH1F *histo_ttbar[JetStepCut][NJetNum];
	TH1F *histo_ttbar_gen[JetStepCut][NJetNum];

	TH1F *histo_DYJets[JetStepCut][NJetNum];
	TH1F *histo_DYJets_gen[JetStepCut][NJetNum];

	TH1F *histo_WJets[JetStepCut][NJetNum];
	TH1F *histo_WJets_gen[JetStepCut][NJetNum];

	//----------------------------QCD samples----------------------------
	TH1F *histo_QCDPt80to120EM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt80to120EM_gen[JetStepCut][NJetNum];
	TH1F *histo_QCDPt80to120Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt80to120Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt1000toInfMu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt1000toInfMu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt120to170EM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt120to170EM_gen[JetStepCut][NJetNum];
	TH1F *histo_QCDPt120to170Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt120to170Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt15to20Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt15to20Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt170to300EM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt170to300EM_gen[JetStepCut][NJetNum];
	TH1F *histo_QCDPt170to300Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt170to300Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt20to30EM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt20to30EM_gen[JetStepCut][NJetNum];
	TH1F *histo_QCDPt20to30Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt20to30Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt300to470Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt300to470Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt300toInfEM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt300toInfEM_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt30to50EM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt30to50EM_gen[JetStepCut][NJetNum];
	TH1F *histo_QCDPt30to50Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt30to50Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt470to600Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt470to600Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt50to80EM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt50to80EM_gen[JetStepCut][NJetNum];
	TH1F *histo_QCDPt50to80Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt50to80Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt600to800Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt600to800Mu_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt800to1000Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt800to1000Mu_gen[JetStepCut][NJetNum];
	//----------------------------------------------------------
	TH1F *histo_QCD[JetStepCut][NJetNum];
	//-----------------------------------------------------------

	TCanvas *canvIso_[JetStepCut][NJetNum];
	TLegend *l_[JetStepCut][NJetNum];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	//PATH_samples = "/cms/scratch/yjeong/";//KISTI
	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";

	TString Cut_base_text;
	TString tttt_Ch_Cut;
	TString ttbar_Ch_Cut;
	TString NBJet;

	TString Variable;
	Variable = "Jet_HT";

	TString Step_1;
	Step_1 = "NJet >= 6 && NBJet >= 2";

	TString Step_2;
	Step_2 = "IsHadronTrig == 1 &&";

	TString Step_3;
	Step_3 = "Jet_Pt[0] > 80 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50 &&";
	TString Step_4;
	Step_4 = "Jet_HT > 500 &&";

	TString Step_5;
	Step_5 = "(NLooseMuon+NLooseElectron)==0 &&";

	TString Step_6;
	Step_6 = "NBJet>=3 &&";

	TString Step_7;
	Step_7 = "NJet>=10 &&";

	TString Step_Cut[] = {Step_1, Step_2+Step_1, Step_2+Step_3+Step_1, Step_2+Step_3+Step_4+Step_1, Step_2+Step_3+Step_4+Step_5+Step_1, Step_2+Step_3+Step_4+Step_5+Step_6+Step_1, Step_2+Step_3+Step_4+Step_5+Step_6+Step_7+Step_1};

	TString Step_txt[] = {"step1","step2","step3","step4","step5","step6","step7"};

	ttttHad_Ch = "nq==8 && nl==0 ";
	ttbarHad_Ch = "nq==4 && nl==0 ";

	NBJet = "&& NBJet &&";

	Cut_base_text = "Hadronic ";

	TFile h1(PATH_samples+"vallot.root");
	TFile h2(PATH_samples+"TT_powheg.root");
	TFile h3(PATH_samples+"DYJets.root");
	TFile h4(PATH_samples+"WJets.root");

	//---------------------------------QCD samples---------------------------------
	TFile h5(PATH_samples+"QCDPt80to120EM.root");
	TFile h6(PATH_samples+"QCDPt80to120Mu.root");
	TFile h7(PATH_samples+"QCDPt1000toInfMu.root");
	TFile h8(PATH_samples+"QCDPt120to170EM.root");
	TFile h9(PATH_samples+"QCDPt120to170Mu.root");
	TFile h10(PATH_samples+"QCDPt15to20Mu.root");
	TFile h11(PATH_samples+"QCDPt170to300EM.root");
	TFile h12(PATH_samples+"QCDPt170to300Mu.root");
	TFile h13(PATH_samples+"QCDPt20to30EM.root");
	TFile h14(PATH_samples+"QCDPt20to30Mu.root");
	TFile h15(PATH_samples+"QCDPt300to470Mu.root");
	TFile h16(PATH_samples+"QCDPt300toInfEM.root");
	TFile h17(PATH_samples+"QCDPt30to50EM.root");
	TFile h18(PATH_samples+"QCDPt30to50Mu.root");
	TFile h19(PATH_samples+"QCDPt470to600Mu.root");
	TFile h20(PATH_samples+"QCDPt50to80EM.root");
	TFile h21(PATH_samples+"QCDPt50to80Mu.root");
	TFile h22(PATH_samples+"QCDPt600to800Mu.root");
	TFile h23(PATH_samples+"QCDPt800to1000Mu.root");
	//---------------------------------------------------------------------------

	TTree *FourTop = (TTree*)h1.Get("TopTree/events");
	TTree *TTbar = (TTree*)h2.Get("TopTree/events");
	TTree *DYJets = (TTree*)h3.Get("TopTree/events");
	TTree *WJets = (TTree*)h4.Get("TopTree/events");

	//----------------------------------QCD samples-----------------------------
	TTree *QCDPt80to120EM = (TTree*)h5.Get("TopTree/events");
	TTree *QCDPt80to120Mu = (TTree*)h6.Get("TopTree/events");
	TTree *QCDPt1000toInfMu = (TTree*)h7.Get("TopTree/events");
	TTree *QCDPt120to170Mu = (TTree*)h8.Get("TopTree/events");
	TTree *QCDPt120to170EM = (TTree*)h9.Get("TopTree/events");
	TTree *QCDPt15to20Mu = (TTree*)h10.Get("TopTree/events");
	TTree *QCDPt170to300EM = (TTree*)h11.Get("TopTree/events");
	TTree *QCDPt170to300Mu = (TTree*)h12.Get("TopTree/events");
	TTree *QCDPt20to30EM = (TTree*)h13.Get("TopTree/events");
	TTree *QCDPt20to30Mu = (TTree*)h14.Get("TopTree/events");
	TTree *QCDPt300to470Mu = (TTree*)h15.Get("TopTree/events");
	TTree *QCDPt300toInfEM = (TTree*)h16.Get("TopTree/events");
	TTree *QCDPt30to50EM = (TTree*)h17.Get("TopTree/events");
	TTree *QCDPt30to50Mu = (TTree*)h18.Get("TopTree/events");
	TTree *QCDPt470to600Mu = (TTree*)h19.Get("TopTree/events");
	TTree *QCDPt50to80EM = (TTree*)h20.Get("TopTree/events");
	TTree *QCDPt50to80Mu = (TTree*)h21.Get("TopTree/events");
	TTree *QCDPt600to800Mu = (TTree*)h22.Get("TopTree/events");
	TTree *QCDPt800to1000Mu = (TTree*)h23.Get("TopTree/events");
	//-------------------------------------------------------------------------

	TH1F *hNJet;
	hNJet = new TH1F(Form("hNJet"),Form(""),16,0,16);
	FourTop->Project(Form("hNJet"),"NJet");
	cout<<"NJet events number"<<endl;

	for(int i = 1; i < 17; i++){
		cout<< hNJet->GetBinContent(i) << endl;
	}

	cout<<"--------------------step definition-------------------"<<endl;
	cout<<""<<endl;
	cout<<"step1: "<<Step_1<<endl;
	cout<<""<<endl;
	cout<<"step2: "<<Step_2<<endl;
	cout<<""<<endl;
	cout<<"step3: "<<Step_3<<endl;
	cout<<""<<endl;
	cout<<"step4: "<<Step_4<<endl;
	cout<<""<<endl;
	cout<<"step5: "<<Step_5<<endl;
	cout<<""<<endl;
	cout<<"step6: "<<Step_6<<endl;
	cout<<""<<endl;
	cout<<"step7: "<<Step_7<<endl;

	for(int NJ = 0; NJ < NJetNum; NJ++){
		for(int NStep = 0; NStep < JetStepCut; NStep++){
			float nbin = 60;
			float xmin = 0;
			float xmax = 2800;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;

			canvIso_[NJ][NStep] = new TCanvas();
			canvIso_[NJ][NStep]->SetLogy();
			canvIso_[NJ][NStep]->SetFillColor(0);
			canvIso_[NJ][NStep]->SetBorderMode(2);
			canvIso_[NJ][NStep]->SetFrameFillStyle(3);
			canvIso_[NJ][NStep]->SetFrameBorderMode(0);
			canvIso_[NJ][NStep]->SetTickx(1);
			canvIso_[NJ][NStep]->SetTicky(1);
			canvIso_[NJ][NStep]->Update();
			canvIso_[NJ][NStep]->RedrawAxis();
			canvIso_[NJ][NStep]->GetFrame()->Draw();

			l_[NJ][NStep] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NJ][NStep]->SetFillColor(0);
			l_[NJ][NStep]->SetLineColor(0);
			l_[NJ][NStep]->SetLineStyle(kSolid);
			l_[NJ][NStep]->SetLineWidth(1);
			l_[NJ][NStep]->SetFillStyle(1);
			l_[NJ][NStep]->SetTextFont(2);
			l_[NJ][NStep]->SetTextSize(0.035);

			histo_DYJets[NJ][NStep] = new TH1F(Form("histo_DYJets_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			DYJets->Project(Form("histo_DYJets_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);
			histo_DYJets[NJ][NStep]->SetLineWidth(2);
			histo_DYJets[NJ][NStep]->SetLineColor(dyjets_c);
			//histo_DYJets[NJ][NStep]->SetFillColor(dyjets_c);
			histo_DYJets[NJ][NStep]->SetMarkerColor(dyjets_c);
			l_[NJ][NStep]->AddEntry(histo_DYJets[NJ][NStep],"DYJets ", "lp");

			histo_DYJets_gen[NJ][NStep] = new TH1F(Form("histo_DYJets_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			DYJets->Project(Form("histo_DYJets_gen_%d_%d",NJ,NStep),Variable);

			//////////////////////////////////////////////QCD/////////////////////////////////////////////////////

			histo_QCDPt80to120EM[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120EM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120EM->Project(Form("histo_QCDPt80to120EM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt80to120EM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120EM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120EM->Project(Form("histo_QCDPt80to120EM_gen_%d_%d",NJ,NStep),Variable);
			//-----

			histo_QCDPt80to120Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120Mu->Project(Form("histo_QCDPt80to120Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt80to120Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120Mu->Project(Form("histo_QCDPt80to120Mu_gen_%d_%d",NJ,NStep),Variable);
			//-----

			histo_QCDPt1000toInfMu[NJ][NStep] = new TH1F(Form("histo_QCDPt1000toInfMu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt1000toInfMu->Project(Form("histo_QCDPt1000toInfMu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt1000toInfMu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt1000toInfMu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt1000toInfMu->Project(Form("histo_QCDPt1000toInfMu_gen_%d_%d",NJ,NStep),Variable);
			//-----

			histo_QCDPt120to170EM[NJ][NStep] = new TH1F(Form("histo_QCDPt120to170EM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt120to170EM->Project(Form("histo_QCDPt120to170EM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt120to170EM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt120to170EM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt120to170EM->Project(Form("histo_QCDPt120to170EM_gen_%d_%d",NJ,NStep),Variable);
			//-----

			histo_QCDPt120to170Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt120to170Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt120to170Mu->Project(Form("histo_QCDPt120to170Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt120to170Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt120to170Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt120to170Mu->Project(Form("histo_QCDPt120to170Mu_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt15to20Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt15to20Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt15to20Mu->Project(Form("histo_QCDPt15to20Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt15to20Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt15to20Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt15to20Mu->Project(Form("histo_QCDPt15to20Mu_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt170to300EM[NJ][NStep] = new TH1F(Form("histo_QCDPt170to300EM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt170to300EM->Project(Form("histo_QCDPt170to300EM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt170to300EM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt170to300EM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt170to300EM->Project(Form("histo_QCDPt170to300EM_gen_%d_%d",NJ,NStep),Variable);
			//-----

			histo_QCDPt170to300Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt170to300Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt170to300Mu->Project(Form("histo_QCDPt170to300Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt170to300Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt170to300Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt170to300Mu->Project(Form("histo_QCDPt170to300Mu_gen_%d_%d",NJ,NStep),Variable);
			//-----

			histo_QCDPt20to30EM[NJ][NStep] = new TH1F(Form("histo_QCDPt20to30EM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt20to30EM->Project(Form("histo_QCDPt20to30EM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt20to30EM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt20to30EM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt20to30EM->Project(Form("histo_QCDPt20to30EM_gen_%d_%d",NJ,NStep),Variable);
			//-----

			histo_QCDPt20to30Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt20to30Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt20to30Mu->Project(Form("histo_QCDPt20to30Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt20to30Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt20to30Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt20to30Mu->Project(Form("histo_QCDPt20to30Mu_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt300to470Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt300to470Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt300to470Mu->Project(Form("histo_QCDPt300to470Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt300to470Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt300to470Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt300to470Mu->Project(Form("histo_QCDPt300to470Mu_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt300toInfEM[NJ][NStep] = new TH1F(Form("histo_QCDPt300toInfEM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt300toInfEM->Project(Form("histo_QCDPt300toInfEM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt300toInfEM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt300toInfEM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt300toInfEM->Project(Form("histo_QCDPt300toInfEM_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt30to50EM[NJ][NStep] = new TH1F(Form("histo_QCDPt30to50EM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt30to50EM->Project(Form("histo_QCDPt30to50EM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt30to50EM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt30to50EM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt30to50EM->Project(Form("histo_QCDPt30to50EM_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt30to50Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt30to50Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt30to50Mu->Project(Form("histo_QCDPt30to50Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt30to50Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt30to50Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt30to50Mu->Project(Form("histo_QCDPt30to50Mu_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt470to600Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt470to600Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt470to600Mu->Project(Form("histo_QCDPt470to600Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt470to600Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt470to600Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt470to600Mu->Project(Form("histo_QCDPt470to600Mu_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt50to80EM[NJ][NStep] = new TH1F(Form("histo_QCDPt50to80EM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt50to80EM->Project(Form("histo_QCDPt50to80EM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt50to80EM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt50to80EM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt50to80EM->Project(Form("histo_QCDPt50to80EM_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt50to80Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt50to80Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt50to80Mu->Project(Form("histo_QCDPt50to80Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

			histo_QCDPt50to80Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt50to80Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt50to80Mu->Project(Form("histo_QCDPt50to80Mu_gen_%d_%d",NJ,NStep),Variable);

			//-----

			histo_QCDPt600to800Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt60to800Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
                        QCDPt600to800Mu->Project(Form("histo_QCDPt600to800Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

                        histo_QCDPt600to800Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt600to800Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
                        QCDPt600to800Mu->Project(Form("histo_QCDPt600to800Mu_gen_%d_%d",NJ,NStep),Variable);

                        //-----

                        histo_QCDPt800to1000Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt800to1000Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
                        QCDPt800to1000Mu->Project(Form("histo_QCDPt800to1000Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);

                        histo_QCDPt800to1000Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt800to1000Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
                        QCDPt800to1000Mu->Project(Form("histo_QCDPt800to1000Mu_gen_%d_%d",NJ,NStep),Variable);

			//////////////////////////////////////////////////////////////////////////////////////

			histo_WJets[NJ][NStep] = new TH1F(Form("histo_WJets_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			WJets->Project(Form("histo_WJets_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);
			histo_WJets[NJ][NStep]->SetLineWidth(2);
			histo_WJets[NJ][NStep]->SetLineColor(wjets_c);
			//histo_WJets[NJ][NStep]->SetFillColor(wjets_c);
			histo_WJets[NJ][NStep]->SetMarkerColor(wjets_c);
			l_[NJ][NStep]->AddEntry(histo_WJets[NJ][NStep],"WJets ", "lp");

			histo_WJets_gen[NJ][NStep] = new TH1F(Form("histo_WJets_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			WJets->Project(Form("histo_WJets_gen_%d_%d",NJ,NStep),Variable);

			//-------------------------------------------------------
			histo_TTTT[NJ][NStep] = new TH1F(Form("histo_TTTT_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			//histo_TTTT[NJ][NStep]->Sumw2();
			FourTop->Project(Form("histo_TTTT_%d_%d",NJ,NStep),Variable,ttttHad_Ch+NBJet+Step_Cut[NStep]);
			histo_TTTT[NJ][NStep]->SetLineWidth(2);
			l_[NJ][NStep]->AddEntry(histo_TTTT[NJ][NStep],"TTTT ", "lp");
			histo_TTTT[NJ][NStep]->SetLineColor(TTTT_c);
			//histo_TTTT[NJ][NStep]->SetFillColor(TTTT_c);
			histo_TTTT[NJ][NStep]->SetMarkerColor(TTTT_c);

			histo_TTTT_gen[NJ][NStep] = new TH1F(Form("histo_TTTT_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			//histo_TTTT_gen[NJ][NStep]->Sumw2();
			FourTop->Project(Form("histo_TTTT_gen_%d_%d",NJ,NStep),Variable,ttttHad_Ch);

			//------------------------------------------------------
			histo_ttbar[NJ][NStep] = new TH1F(Form("histo_ttbar_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			//histo_ttbar[NJ][NStep]->Sumw2();
			TTbar->Project(Form("histo_ttbar_%d_%d",NJ,NStep),Variable,ttbarHad_Ch+NBJet+Step_Cut[NStep]);
			histo_ttbar[NJ][NStep]->SetLineWidth(2);
			l_[NJ][NStep]->AddEntry(histo_ttbar[NJ][NStep],"ttbar ", "lp");
			histo_ttbar[NJ][NStep]->SetLineColor(ttbar_c);
			//histo_ttbar[NJ][NStep]->SetFillColor(ttbar_c);
			histo_ttbar[NJ][NStep]->SetMarkerColor(ttbar_c);
			histo_ttbar[NJ][NStep]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_ttbar[NJ][NStep]->GetXaxis()->SetTitle("Jet_HT");

			histo_ttbar_gen[NJ][NStep] = new TH1F(Form("histo_ttbar_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			//histo_ttbar_gen[NJ][NStep]->Sumw2();
			TTbar->Project(Form("histo_ttbar_gen_%d_%d",NJ,NStep),Variable,ttbarHad_Ch);
			//------------------------------------------------------


			double TTTTS1 = histo_TTTT[NJ][NStep]->GetEntries();
			double TTTTS0 = histo_TTTT_gen[NJ][NStep]->GetEntries();
			double ttbarS1 = histo_ttbar[NJ][NStep]->GetEntries();
			double ttbarS0 = histo_ttbar_gen[NJ][NStep]->GetEntries();
			double DYJetsS1 = histo_DYJets[NJ][NStep]->GetEntries();
			double DYJetsS0 = histo_DYJets_gen[NJ][NStep]->GetEntries();
			double WJetsS1 = histo_WJets[NJ][NStep]->GetEntries();
			double WJetsS0 = histo_WJets_gen[NJ][NStep]->GetEntries();

			//------------------------------QCD----------------------------------
			double QCDPt80to120EMS1 = histo_QCDPt80to120EM[NJ][NStep]->GetEntries();
			double QCDPt80to120EMS0 = histo_QCDPt80to120EM_gen[NJ][NStep]->GetEntries();
			double QCDPt80to120MuS1 = histo_QCDPt80to120Mu[NJ][NStep]->GetEntries();
			double QCDPt80to120MuS0 = histo_QCDPt80to120Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt1000toInfMuS1 = histo_QCDPt1000toInfMu[NJ][NStep]->GetEntries();
			double QCDPt1000toInfMuS0 = histo_QCDPt1000toInfMu_gen[NJ][NStep]->GetEntries();

			double QCDPt120to170EMS1 = histo_QCDPt120to170EM[NJ][NStep]->GetEntries();
			double QCDPt120to170EMS0 = histo_QCDPt120to170EM_gen[NJ][NStep]->GetEntries();
			double QCDPt120to170MuS1 = histo_QCDPt120to170Mu[NJ][NStep]->GetEntries();
			double QCDPt120to170MuS0 = histo_QCDPt120to170Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt15to20MuS1 = histo_QCDPt15to20Mu[NJ][NStep]->GetEntries();
			double QCDPt15to20MuS0 = histo_QCDPt15to20Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt170to300EMS1 = histo_QCDPt170to300EM[NJ][NStep]->GetEntries();
			double QCDPt170to300EMS0 = histo_QCDPt170to300EM_gen[NJ][NStep]->GetEntries();
			double QCDPt170to300MuS1 = histo_QCDPt170to300Mu[NJ][NStep]->GetEntries();
			double QCDPt170to300MuS0 = histo_QCDPt170to300Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt20to30EMS1 = histo_QCDPt20to30EM[NJ][NStep]->GetEntries();
			double QCDPt20to30EMS0 = histo_QCDPt20to30EM_gen[NJ][NStep]->GetEntries();
			double QCDPt20to30MuS1 = histo_QCDPt20to30Mu[NJ][NStep]->GetEntries();
			double QCDPt20to30MuS0 = histo_QCDPt20to30Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt300to470MuS1 = histo_QCDPt300to470Mu[NJ][NStep]->GetEntries();
			double QCDPt300to470MuS0 = histo_QCDPt300to470Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt300toInfEMS1 = histo_QCDPt300toInfEM[NJ][NStep]->GetEntries();
			double QCDPt300toInfEMS0 = histo_QCDPt300toInfEM_gen[NJ][NStep]->GetEntries();

			double QCDPt30to50EMS1 = histo_QCDPt30to50EM[NJ][NStep]->GetEntries();
			double QCDPt30to50MuS1 = histo_QCDPt30to50Mu[NJ][NStep]->GetEntries();
			double QCDPt30to50EMS0 = histo_QCDPt30to50EM_gen[NJ][NStep]->GetEntries();
			double QCDPt30to50MuS0 = histo_QCDPt30to50Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt470to600MuS1 = histo_QCDPt470to600Mu[NJ][NStep]->GetEntries();
			double QCDPt470to600MuS0 = histo_QCDPt470to600Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt50to80EMS1 = histo_QCDPt50to80EM[NJ][NStep]->GetEntries();
			double QCDPt50to80MuS1 = histo_QCDPt50to80Mu[NJ][NStep]->GetEntries();
			double QCDPt50to80EMS0 = histo_QCDPt50to80EM_gen[NJ][NStep]->GetEntries();
			double QCDPt50to80MuS0 = histo_QCDPt50to80Mu_gen[NJ][NStep]->GetEntries();

			double QCDPt600to800MuS1 = histo_QCDPt600to800Mu[NJ][NStep]->GetEntries();
                        double QCDPt800to1000MuS1 = histo_QCDPt800to1000Mu[NJ][NStep]->GetEntries();
                        double QCDPt600to800MuS0 = histo_QCDPt600to800Mu_gen[NJ][NStep]->GetEntries();
                        double QCDPt800to1000MuS0 = histo_QCDPt800to1000Mu_gen[NJ][NStep]->GetEntries();

			//-------------------------------------------------------------------

			double QCDS1 = QCDPt80to120EMS1+QCDPt80to120MuS1+QCDPt1000toInfMuS1+QCDPt120to170EMS1+QCDPt120to170MuS1+QCDPt15to20MuS1+QCDPt170to300EMS1+QCDPt170to300MuS1+QCDPt20to30EMS1+QCDPt20to30MuS1+QCDPt300to470MuS1+QCDPt300toInfEMS1+QCDPt30to50EMS1+QCDPt30to50MuS1+QCDPt470to600MuS1+QCDPt50to80EMS1+QCDPt50to80MuS1+QCDPt600to800MuS1+QCDPt800to1000MuS1;
			double QCDS0 = QCDPt80to120EMS0+QCDPt80to120MuS0+QCDPt1000toInfMuS0+QCDPt120to170EMS0+QCDPt120to170MuS0+QCDPt15to20MuS0+QCDPt170to300EMS0+QCDPt170to300MuS0+QCDPt20to30EMS0+QCDPt20to30MuS0+QCDPt300to470MuS0+QCDPt300toInfEMS0+QCDPt30to50EMS0+QCDPt30to50MuS0+QCDPt470to600MuS0+QCDPt50to80EMS0+QCDPt50to80MuS0+QCDPt600to800MuS0+QCDPt800to1000MuS0;

			double BR = 0.6741;//theoritical value W->Hadron
			double lumi = 36*1000;//pb-1
			//4top->all hadrons = BR^4.
			//ttbar->all hadrons = BR^2.

			cout<<""<<endl;
			cout<<"---------------------------------------"<<Step_txt[NStep]<<"-------------------------------------"<<endl;
			cout<<"lumi : "<<lumi<<" pb-1"<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<< (TTTTS1/TTTTS0)*100<<"%"<<" , "<<ttttHad_Ch<<", 4 top " <<endl;
			cout<<""<<endl;
			cout<< (ttbarS1/ttbarS0)*100<<"%"<<", "<<ttbarHad_Ch <<", ttbar " <<endl;
			cout<<""<<endl;
			cout<< (DYJetsS1/DYJetsS0)*100<<"%"<<", "<<", DYJets " <<endl;
			cout<<""<<endl;
			cout<< (WJetsS1/WJetsS0)*100<<"%"<<", "<<", WJets " <<endl;
			cout<<""<<endl;
			cout<< (QCDS1/QCDS0)*100<<"%"<<", "<<", QCD " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			double tttt_ev = 0.009103*lumi*BR*BR*BR*BR*(TTTTS1/TTTTS0);
			double ttbar_ev = 832.76*lumi*BR*BR*(ttbarS1/ttbarS0);
			double DYJets_ev = 6025.2*lumi*(DYJetsS1/DYJetsS0);
			double WJets_ev = 61526.7*lumi*(WJetsS1/WJetsS0);

			//-----------------------------QCD-----------------------------
			double QCDPt80to120EM_ev = 350000*lumi*(QCDPt80to120EMS1/QCDPt80to120EMS0);
			double QCDPt80to120Mu_ev = 106033.6648*lumi*(QCDPt80to120MuS1/QCDPt80to120MuS0);
			double QCDPt1000toInfMu_ev = 1.62131692*lumi*(QCDPt1000toInfMuS1/QCDPt1000toInfMuS0);
			double QCDPt120to170EM_ev = 62964*lumi*(QCDPt120to170EMS1/QCDPt120to170EMS0);
			double QCDPt120to170Mu_ev = 25190.51514*lumi*(QCDPt120to170MuS1/QCDPt120to170MuS0);
			double QCDPt15to20Mu_ev = 3819570*lumi*(QCDPt15to20MuS1/QCDPt15to20MuS0);
			double QCDPt170to300EM_ev = 18810*lumi*(QCDPt170to300EMS1/QCDPt170to300EMS0);
			double QCDPt170to300Mu_ev = 8654.49315*lumi*(QCDPt170to300MuS1/QCDPt170to300MuS0);
			double QCDPt20to30EM_ev = 5352960.0*lumi*(QCDPt20to30EMS1/QCDPt20to30EMS0);
			double QCDPt20to30Mu_ev = 2960198.4*lumi*(QCDPt20to30MuS1/QCDPt20to30MuS0);
			double QCDPt300to470Mu_ev = 797.35269*lumi*(QCDPt300to470MuS1/QCDPt300to470MuS0);
			double QCDPt300toInfEM_ev = 1350*lumi*(QCDPt300toInfEMS1/QCDPt300toInfEMS0);
			double QCDPt30to50EM_ev = 9928000.0*lumi*(QCDPt30to50EMS1/QCDPt30to50EMS0);
			double QCDPt30to50Mu_ev = 1652471.46*lumi*(QCDPt30to50MuS1/QCDPt30to50MuS0);
			double QCDPt470to600Mu_ev = 79.02553776*lumi*(QCDPt470to600MuS1/QCDPt470to600MuS0);
			double QCDPt50to80EM_ev = 2890800.0*lumi*(QCDPt50to80EMS1/QCDPt50to80EMS0);
			double QCDPt50to80Mu_ev = 437504.1*lumi*(QCDPt50to80MuS1/QCDPt50to80MuS0);
			double QCDPt600to800Mu_ev = 25.09505908*lumi*(QCDPt600to800MuS1/QCDPt600to800MuS0);
			double QCDPt800to1000Mu_ev = 4.707368272*lumi*(QCDPt800to1000MuS1/QCDPt800to1000MuS0);
			//-------------------------------------------------------------
			double QCD_ev = QCDPt80to120EM_ev+QCDPt80to120Mu_ev+QCDPt1000toInfMu_ev+QCDPt120to170EM_ev+QCDPt120to170Mu_ev+QCDPt15to20Mu_ev+QCDPt170to300EM_ev+QCDPt170to300Mu_ev+QCDPt20to30EM_ev+QCDPt20to30Mu_ev+QCDPt300to470Mu_ev+QCDPt300toInfEM_ev+QCDPt30to50EM_ev+QCDPt30to50Mu_ev+QCDPt470to600Mu_ev+QCDPt50to80EM_ev+QCDPt50to80Mu_ev+QCDPt600to800Mu_ev+QCDPt800to1000Mu_ev;

			cout<<"number of 4top expected events: "<< tttt_ev<<endl;
			cout<<""<<endl;
			cout<<"number of ttbar expected events: "<< ttbar_ev<<endl;
			cout<<""<<endl;
			cout<<"number of DYJets expected events: "<< DYJets_ev<<endl;
			cout<<""<<endl;
			cout<<"number of WJets expected events: "<< WJets_ev<<endl;
			cout<<""<<endl;
			cout<<"number of QCD expected events: "<< QCD_ev<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			//------------------------------QCD------------------------------
			cout<<"number of QCDPt80to120EM expected events: "<< QCDPt80to120EM_ev<<endl;
			cout<<"number of QCDPt80to120Mu expected events: "<< QCDPt80to120Mu_ev<<endl;
			cout<<"number of QCDPt1000toInfMu expected events: "<< QCDPt1000toInfMu_ev<<endl;
			cout<<"number of QCDPt120to170EM expected events: "<< QCDPt120to170EM_ev<<endl;
			cout<<"number of QCDPt120to170Mu expected events: "<< QCDPt120to170Mu_ev<<endl;
			cout<<"number of QCDPt15to20Mu expected events: "<< QCDPt15to20Mu_ev<<endl;
			cout<<"number of QCDPt170to300EM expected events: "<< QCDPt170to300EM_ev<<endl;
			cout<<"number of QCDPt170to300Mu expected events: "<< QCDPt170to300Mu_ev<<endl;
			cout<<"number of QCDPt20to30EM expected events: "<< QCDPt20to30EM_ev<<endl;
			cout<<"number of QCDPt20to30Mu expected events: "<< QCDPt20to30Mu_ev<<endl;
			cout<<"number of QCDPt300to470Mu expected events: "<< QCDPt300to470Mu_ev<<endl;
			cout<<"number of QCDPt300toInfEM expected events: "<< QCDPt300toInfEM_ev<<endl;
			cout<<"number of QCDPt30to50EM expected events: "<< QCDPt30to50EM_ev<<endl;
			cout<<"number of QCDPt30to50Mu expected events: "<< QCDPt30to50Mu_ev<<endl;
			cout<<"number of QCDPt470to600Mu expected events: "<< QCDPt470to600Mu_ev<<endl;
			cout<<"number of QCDPt50to80EM expected events: "<< QCDPt50to80EM_ev<<endl;
			cout<<"number of QCDPt50to80Mu expected events: "<< QCDPt50to80Mu_ev<<endl;
			cout<<"number of QCDPt600to800Mu expected events: "<< QCDPt600to800Mu_ev<<endl;
			cout<<"number of QCDPt800to1000Mu expected events: "<< QCDPt800to1000Mu_ev<<endl;

			//---------------------------------------------------------------
			cout<<""<<endl;
			cout<<"------------------------------------------------"<<endl;

			histo_TTTT[NJ][NStep]->Scale(0.009103*lumi*BR*BR*BR*BR/TTTTS0);
			histo_ttbar[NJ][NStep]->Scale(832.76*lumi*BR*BR/ttbarS0);
			histo_DYJets[NJ][NStep]->Scale(6025.2*lumi/DYJetsS0);
			histo_WJets[NJ][NStep]->Scale(61526.7*lumi/WJetsS0);

			//-----------------------------------QCD-----------------------------------
			histo_QCDPt80to120EM[NJ][NStep]->Scale(350000*lumi/QCDPt80to120EMS0);
			histo_QCDPt80to120Mu[NJ][NStep]->Scale(106033.6648*lumi/QCDPt80to120MuS0);
			histo_QCDPt1000toInfMu[NJ][NStep]->Scale(1.62131692*lumi/QCDPt1000toInfMuS0);
			histo_QCDPt120to170EM[NJ][NStep]->Scale(62964*lumi/QCDPt120to170EMS0);
			histo_QCDPt120to170Mu[NJ][NStep]->Scale(25190.51514*lumi/QCDPt120to170MuS0);
			histo_QCDPt15to20Mu[NJ][NStep]->Scale(3819570*lumi/QCDPt15to20MuS0);
			histo_QCDPt170to300EM[NJ][NStep]->Scale(18810*lumi/QCDPt170to300EMS0);
			histo_QCDPt170to300Mu[NJ][NStep]->Scale(8654.49315*lumi/QCDPt170to300MuS0);
			histo_QCDPt20to30EM[NJ][NStep]->Scale(5352960.0*lumi/QCDPt20to30EMS0);
			histo_QCDPt20to30Mu[NJ][NStep]->Scale(2960198.4*lumi/QCDPt20to30MuS0);
			histo_QCDPt300to470Mu[NJ][NStep]->Scale(797.35269*lumi/QCDPt300to470MuS0);
			histo_QCDPt300toInfEM[NJ][NStep]->Scale(1350*lumi/QCDPt300toInfEMS0);
			histo_QCDPt30to50EM[NJ][NStep]->Scale(9928000.0*lumi/QCDPt30to50EMS0);
			histo_QCDPt30to50Mu[NJ][NStep]->Scale(1652471.46*lumi/QCDPt30to50MuS0);
			histo_QCDPt470to600Mu[NJ][NStep]->Scale(79.02553776*lumi/QCDPt470to600MuS0);
			histo_QCDPt50to80EM[NJ][NStep]->Scale(2890800.0*lumi/QCDPt50to80EMS0);
			histo_QCDPt50to80Mu[NJ][NStep]->Scale(437504.1*lumi/QCDPt50to80MuS0);
			histo_QCDPt600to800Mu[NJ][NStep]->Scale(25.09505908*lumi/QCDPt600to800MuS0);
			histo_QCDPt800to1000Mu[NJ][NStep]->Scale(4.707368272*lumi/QCDPt800to1000MuS0);
			//--------------------------------------------------------------------
			cout<<""<<endl;
			cout<<"4top yield Integral(1,nbin+1): "<<histo_TTTT[NJ][NStep]->Integral(1,nbin+1)<<endl;
			//cout<<"4top yield Integral: "<<histo_TTTT[NJ][NStep]->Integral()<<endl;
			//cout<<"4top yield GetSum: "<<histo_TTTT[NJ][NStep]->GetSum()<<endl;
			cout<<""<<endl;
			cout<<"ttbar yield Integral(1,nbin+1): "<<histo_ttbar[NJ][NStep]->Integral(1,nbin+1)<<endl;
			//cout<<"ttbar yield Integral: "<<histo_ttbar[NJ][NStep]->Integral()<<endl;
			//cout<<"ttbar yield GetSum: "<<histo_ttbar[NJ][NStep]->GetSum()<<endl;
			cout<<""<<endl;
			cout<<"DYJets yield Integral(1,nbin+1): "<<histo_DYJets[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<""<<endl;
			cout<<"WJets yield Integral(1,nbin+1): "<<histo_WJets[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<""<<endl;

			//--------------------------------------QCD---------------------------------
			double QCD80to120EM = histo_QCDPt80to120EM[NJ][NStep]->Integral(1,nbin+1);
			double QCD80to120Mu = histo_QCDPt80to120Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD1000toInfMu = histo_QCDPt1000toInfMu[NJ][NStep]->Integral(1,nbin+1);
			double QCD120to170EM = histo_QCDPt120to170EM[NJ][NStep]->Integral(1,nbin+1);
			double QCD120to170Mu = histo_QCDPt120to170Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD15to20Mu = histo_QCDPt15to20Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD170to300EM = histo_QCDPt170to300EM[NJ][NStep]->Integral(1,nbin+1);
			double QCD170to300Mu = histo_QCDPt170to300Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD20to30EM = histo_QCDPt20to30EM[NJ][NStep]->Integral(1,nbin+1);
			double QCD20to30Mu = histo_QCDPt20to30Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD300to470Mu = histo_QCDPt300to470Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD300toInfEM = histo_QCDPt300toInfEM[NJ][NStep]->Integral(1,nbin+1);
			double QCD30to50EM = histo_QCDPt30to50EM[NJ][NStep]->Integral(1,nbin+1);
			double QCD30to50Mu = histo_QCDPt30to50Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD470to600Mu = histo_QCDPt470to600Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD50to80EM = histo_QCDPt50to80EM[NJ][NStep]->Integral(1,nbin+1);
			double QCD50to80Mu = histo_QCDPt50to80Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD600to800Mu = histo_QCDPt600to800Mu[NJ][NStep]->Integral(1,nbin+1);
			double QCD800to1000Mu = histo_QCDPt800to1000Mu[NJ][NStep]->Integral(1,nbin+1);
			//------------------------------------------------------------------

			double QCD_Int = QCD80to120EM+QCD80to120Mu+QCD1000toInfMu+QCD120to170EM+QCD120to170Mu+QCD15to20Mu+QCD170to300EM+QCD170to300Mu+QCD20to30EM+QCD20to30Mu+QCD300to470Mu+QCD300toInfEM+QCD30to50EM+QCD30to50Mu+QCD470to600Mu+QCD50to80EM+QCD50to80Mu+QCD600to800Mu+QCD800to1000Mu;

			cout<<"QCD yield Integral(1,nbin+1): "<<QCD_Int<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			//-----------------------------------QCD-------------------------------------------
			cout<<"QCDPt80to120EM yield Integral(1,nbin+1): "<<histo_QCDPt80to120EM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt80to120Mu yield Integral(1,nbin+1): "<<histo_QCDPt80to120Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt1000toInfMu yield Integral(1,nbin+1): "<<histo_QCDPt1000toInfMu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt120to170EM yield Integral(1,nbin+1): "<<histo_QCDPt120to170EM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt120to170Mu yield Integral(1,nbin+1): "<<histo_QCDPt120to170Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt15to20Mu yield Integral(1,nbin+1): "<<histo_QCDPt15to20Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt170to300EM yield Integral(1,nbin+1): "<<histo_QCDPt170to300EM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt170to300Mu yield Integral(1,nbin+1): "<<histo_QCDPt170to300Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt20to30EM yield Integral(1,nbin+1): "<<histo_QCDPt20to30EM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt20to30Mu yield Integral(1,nbin+1): "<<histo_QCDPt20to30Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt300to470Mu yield Integral(1,nbin+1): "<<histo_QCDPt300to470Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt300toInfEM yield Integral(1,nbin+1): "<<histo_QCDPt300toInfEM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt30to50EM yield Integral(1,nbin+1): "<<histo_QCDPt30to50EM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt30to50Mu yield Integral(1,nbin+1): "<<histo_QCDPt30to50Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt470to600Mu yield Integral(1,nbin+1): "<<histo_QCDPt470to600Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt50to80EM yield Integral(1,nbin+1): "<<histo_QCDPt50to80EM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt50to80Mu yield Integral(1,nbin+1): "<<histo_QCDPt50to80Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt600to800Mu yield Integral(1,nbin+1): "<<histo_QCDPt600to800Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<"QCDPt800to1000Mu yield Integral(1,nbin+1): "<<histo_QCDPt800to1000Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			//------------------------------------------------------------------------------

			cout<<""<<endl;

			histo_QCD[NJ][NStep] = new TH1F(Form("histo_QCD_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			histo_QCD[NJ][NStep]->SetLineColor(qcd_c);
			histo_QCD[NJ][NStep]->SetLineWidth(2);
			histo_QCD[NJ][NStep]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NJ][NStep]->GetXaxis()->SetTitle("Jet_HT");
			l_[NJ][NStep]->AddEntry(histo_QCD[NJ][NStep],"QCD ", "lp");

			histo_QCD[NJ][NStep]->Add(histo_QCDPt80to120Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt80to120EM[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt1000toInfMu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt120to170Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt120to170EM[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt15to20Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt170to300Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt170to300EM[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt20to30Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt20to30EM[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt300to470Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt300toInfEM[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt30to50EM[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt30to50Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt470to600Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt50to80EM[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt50to80Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt600to800Mu[NJ][NStep]);
			histo_QCD[NJ][NStep]->Add(histo_QCDPt800to1000Mu[NJ][NStep]);

			double ymax = 0;
			ymax = histo_QCD[NJ][NStep]->GetMaximum();
			//double ymin = 0;
			//ymin = histo_TTTT[NJ][NStep]->GetMinimum();

			histo_QCD[NJ][NStep]->SetMaximum(ymax*100);
			histo_QCD[NJ][NStep]->SetMinimum(0.01);
			histo_QCD[NJ][NStep]->Draw();
			histo_DYJets[NJ][NStep]->Draw("same");
			histo_WJets[NJ][NStep]->Draw("same");
			histo_ttbar[NJ][NStep]->Draw("same");
			histo_TTTT[NJ][NStep]->Draw("same");

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text+Step_txt[NStep]);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NJ][NStep]->Draw();
			//canvIso_[NJ][NStep]->Print(Step_txt[NStep]+".png");
			canvIso_[NJ][NStep]->SaveAs(Save_dir+Step_txt[NStep]+".png");
			//canvIso_[NJ][NStep]->SaveAs(Save_dir+Step_txt[NStep]+".pdf");
		}
	}
	cout<<"13TeV"<<endl;
}
