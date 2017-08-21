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

	const int JetStepCut = 6;//Step Num
	const int NJetNum = 1;//Variable
	//int NJet[] = {4,5,6,7,8,9,10};
	int NJet[] = {6};

	TH1F *histo_TTTT[JetStepCut][NJetNum];
	TH1F *histo_TTTT_gen[JetStepCut][NJetNum];
	//TH1F *histo_TTTT_eff[JetStepCut][NJetNum];

	TH1F *histo_ttbar[JetStepCut][NJetNum];
	TH1F *histo_ttbar_gen[JetStepCut][NJetNum];
	//TH1F *histo_ttbar_eff[JetStepCut][NJetNum];

	TH1F *histo_DYJets[JetStepCut][NJetNum];
	TH1F *histo_DYJets_gen[JetStepCut][NJetNum];

	TH1F *histo_WJets[JetStepCut][NJetNum];
	TH1F *histo_WJets_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt80to120EM[JetStepCut][NJetNum];
	TH1F *histo_QCDPt80to120EM_gen[JetStepCut][NJetNum];

	TH1F *histo_QCDPt80to120Mu[JetStepCut][NJetNum];
	TH1F *histo_QCDPt80to120Mu_gen[JetStepCut][NJetNum];

	TCanvas *canvIso_[JetStepCut][NJetNum];
	TLegend *l_[JetStepCut][NJetNum];

	TString PATH_samples;
	//PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	PATH_samples = "/cms/scratch/yjeong/";//KISTI

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

	TString Step_Cut[] = {Step_1, Step_2+Step_1, Step_2+Step_3+Step_1, Step_2+Step_3+Step_4+Step_1, Step_2+Step_3+Step_4+Step_5+Step_1, Step_2+Step_3+Step_4+Step_5+Step_6+Step_1};

	TString Step_txt[] = {", step1, ",", step2, ",", step3, ",", step4, ",", step5, ",", step6, "};

	ttttHad_Ch = "nq==8 && nl==0 ";
	ttbarHad_Ch = "nq==4 && nl==0 ";

	NBJet = "&& NBJet &&";

	Cut_base_text = "Hadronic ";

	TFile h1(PATH_samples+"vallot.root");
	TFile h2(PATH_samples+"TT_powheg.root");
	TFile h3(PATH_samples+"DYJets.root");
	TFile h4(PATH_samples+"WJets.root");
	TFile h5(PATH_samples+"QCDPt80to120EM.root");
	TFile h6(PATH_samples+"QCDPt80to120Mu.root");

	TTree *FourTop = (TTree*)h1.Get("TopTree/events");
	TTree *TTbar = (TTree*)h2.Get("TopTree/events");
	TTree *DYJets = (TTree*)h3.Get("TopTree/events");
	TTree *WJets = (TTree*)h4.Get("TopTree/events");
	TTree *QCDPt80to120EM = (TTree*)h5.Get("TopTree/events");
	TTree *QCDPt80to120Mu = (TTree*)h6.Get("TopTree/events");

	TH1F *hNJet;
	hNJet = new TH1F(Form("hNJet"),Form(""),16,0,16);
	FourTop->Project(Form("hNJet"),"NJet");
	cout<<"NJet events number"<<endl;
	cout<< hNJet->GetBinContent(1) << endl;
	cout<< hNJet->GetBinContent(2) << endl;
	cout<< hNJet->GetBinContent(3) << endl;
	cout<< hNJet->GetBinContent(4) << endl;
	cout<< hNJet->GetBinContent(5) << endl;
	cout<< hNJet->GetBinContent(6) << endl;
	cout<< hNJet->GetBinContent(7) << endl;
	cout<< hNJet->GetBinContent(8) << endl;
	cout<< hNJet->GetBinContent(9) << endl;
	cout<< hNJet->GetBinContent(10) << endl;
	cout<< hNJet->GetBinContent(11) << endl;
	cout<< hNJet->GetBinContent(12) << endl;
	cout<< hNJet->GetBinContent(13) << endl;
	cout<< hNJet->GetBinContent(14) << endl;
	cout<< hNJet->GetBinContent(15) << endl;
	cout<< hNJet->GetBinContent(16) << endl;

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

	for(int NJ = 0; NJ < NJetNum; NJ++){
		for(int NStep = 0; NStep < JetStepCut; NStep++){
			float nbin = 60;
			float xmin = 0;
			float xmax = 2800;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 1;
			int wjets_c = 6;
			int qcdPt80to120EM_c = 3;
			int qcdPt80to120Mu_c = 7;

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
			//---------------------------------------

			histo_QCDPt80to120EM[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120EM_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120EM->Project(Form("histo_QCDPt80to120EM_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);
			histo_QCDPt80to120EM[NJ][NStep]->SetLineWidth(2);
			histo_QCDPt80to120EM[NJ][NStep]->SetLineColor(qcdPt80to120EM_c);
			//histo_QCDPt80to120EM[NJ][NStep]->SetFillColor(qcdPt80to120EM_c);
			histo_QCDPt80to120EM[NJ][NStep]->SetMarkerColor(qcdPt80to120EM_c);
			l_[NJ][NStep]->AddEntry(histo_QCDPt80to120EM[NJ][NStep],"QCDPt80to120EM ", "lp");

			histo_QCDPt80to120EM_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120EM_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120EM->Project(Form("histo_QCDPt80to120EM_gen_%d_%d",NJ,NStep),Variable);
			//---------------------------------------------
			histo_QCDPt80to120Mu[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120Mu_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120Mu->Project(Form("histo_QCDPt80to120Mu_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);
			histo_QCDPt80to120Mu[NJ][NStep]->SetLineWidth(2);
			histo_QCDPt80to120Mu[NJ][NStep]->SetLineColor(qcdPt80to120Mu_c);
			histo_QCDPt80to120Mu[NJ][NStep]->SetMarkerColor(qcdPt80to120Mu_c);
			l_[NJ][NStep]->AddEntry(histo_QCDPt80to120Mu[NJ][NStep],"QCDPt80to120Mu ", "lp");

			histo_QCDPt80to120Mu_gen[NJ][NStep] = new TH1F(Form("histo_QCDPt80to120Mu_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			QCDPt80to120Mu->Project(Form("histo_QCDPt80to120Mu_gen_%d_%d",NJ,NStep),Variable);

			//---------------------------------------------
			histo_WJets[NJ][NStep] = new TH1F(Form("histo_WJets_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			WJets->Project(Form("histo_WJets_%d_%d",NJ,NStep),Variable,Step_Cut[NStep]);
			histo_WJets[NJ][NStep]->SetLineWidth(2);
			histo_WJets[NJ][NStep]->SetLineColor(wjets_c);
			//histo_WJets[NJ][NStep]->SetFillColor(wjets_c);
			histo_WJets[NJ][NStep]->SetMarkerColor(wjets_c);
			l_[NJ][NStep]->AddEntry(histo_WJets[NJ][NStep],"WJets ", "lp");

			histo_WJets_gen[NJ][NStep] = new TH1F(Form("histo_WJets_gen_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			WJets->Project(Form("histo_WJets_gen_%d_%d",NJ,NStep),Variable);

			//-------------------------------------
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

			//-----------------------------------
			histo_ttbar[NJ][NStep] = new TH1F(Form("histo_ttbar_%d_%d",NJ,NStep),Form("Jet_HT"),nbin,xmin,xmax);
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
			//----------------------------------

			/*double nev_1 = histo_TTTT[NJ][NStep]->GetEntries();
			  histo_TTTT[NJ][NStep]->Scale(1/nev_1);
			  double nev_2 = histo_ttbar[NJ][NStep]->GetEntries();
			  histo_ttbar[NJ][NStep]->Scale(1/nev_2);
			  double nev_3 = histo_TTTT_gen[NJ][NStep]->GetEntries();
			  histo_TTTT_gen[NJ][NStep]->Scale(1/nev_3);
			  double nev_4 = histo_ttbar_gen[NJ][NStep]->GetEntries();
			  histo_ttbar_gen[NJ][NStep]->Scale(1/nev_4);*/
			/*
			   histo_TTTT_eff[NJ][NStep] = new TH1F(Form("histo_TTTT_eff_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			   histo_TTTT_eff[NJ][NStep]->GetYaxis()->SetTitle("Efficiency");
			   histo_TTTT_eff[NJ][NStep]->GetXaxis()->SetTitle(Variable);
			   histo_TTTT_eff[NJ][NStep]->SetLineWidth(2);

			   histo_ttbar_eff[NJ][NStep] = new TH1F(Form("histo_ttbar_eff_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			//l_[NJ][NStep]->AddEntry(histo_TTTT_eff[NJ][NStep],"TTTT "+Variable, "lp");
			//l_[NJ][NStep]->AddEntry(histo_ttbar_eff[NJ][NStep],"ttbar "+Variable, "lp");

			histo_ttbar_eff[NJ][NStep]->SetLineWidth(2);
			histo_ttbar_eff[NJ][NStep]->SetLineColor(ttbar_c);
			histo_ttbar_eff[NJ][NStep]->SetMarkerColor(ttbar_c);

			histo_TTTT_eff[NJ][NStep]->Divide(histo_TTTT[NJ][NStep],histo_TTTT_gen[NJ][NStep],1,1,"b");
			histo_ttbar_eff[NJ][NStep]->Divide(histo_ttbar[NJ][NStep],histo_ttbar_gen[NJ][NStep],1,1,"b");*/

			double TTTTS1 = histo_TTTT[NJ][NStep]->GetEntries();
			double TTTTS0 = histo_TTTT_gen[NJ][NStep]->GetEntries();
			double ttbarS1 = histo_ttbar[NJ][NStep]->GetEntries();
			double ttbarS0 = histo_ttbar_gen[NJ][NStep]->GetEntries();
			double DYJetsS1 = histo_DYJets[NJ][NStep]->GetEntries();
			double DYJetsS0 = histo_DYJets_gen[NJ][NStep]->GetEntries();
			double WJetsS1 = histo_WJets[NJ][NStep]->GetEntries();
			double WJetsS0 = histo_WJets_gen[NJ][NStep]->GetEntries();
			double QCDPt80to120EMS1 = histo_QCDPt80to120EM[NJ][NStep]->GetEntries();
			double QCDPt80to120EMS0 = histo_QCDPt80to120EM_gen[NJ][NStep]->GetEntries();
			double QCDPt80to120MuS1 = histo_QCDPt80to120Mu[NJ][NStep]->GetEntries();
			double QCDPt80to120MuS0 = histo_QCDPt80to120Mu_gen[NJ][NStep]->GetEntries();
			double BR = 0.6741;//theoritical value W->Hadron
			double lumi = 36000;//pb-1
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
			cout<< (QCDPt80to120EMS1/QCDPt80to120EMS0)*100<<"%"<<", "<<", QCDPt80to120EM " <<endl;
			cout<<""<<endl;
			cout<< (QCDPt80to120MuS1/QCDPt80to120MuS0)*100<<"%"<<", "<<", QCDPt80to120Mu " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			cout<<"number of 4top expected events: "<< 0.009103*lumi*BR*BR*BR*BR*(TTTTS1/TTTTS0)<<endl;
			cout<<""<<endl;
			cout<<"number of ttbar expected events: "<< 832.76*lumi*BR*BR*(ttbarS1/ttbarS0)<<endl;
			cout<<""<<endl;
			cout<<"number of DYJets expected events: "<< 6025.2*lumi*(DYJetsS1/DYJetsS0)<<endl;
			cout<<""<<endl;
			cout<<"number of WJets expected events: "<< 61526.7*lumi*(WJetsS1/WJetsS0)<<endl;
			cout<<""<<endl;
			cout<<"number of QCDPt80to120EM expected events: "<< 350000*lumi*(QCDPt80to120EMS1/QCDPt80to120EMS0)<<endl;
			cout<<""<<endl;
			cout<<"number of QCDPt80to120Mu expected events: "<< 106033.6648*lumi*(QCDPt80to120MuS1/QCDPt80to120MuS0)<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			histo_TTTT[NJ][NStep]->Scale(0.009103*lumi*BR*BR*BR*BR/TTTTS0);
			histo_ttbar[NJ][NStep]->Scale(832.76*lumi*BR*BR/ttbarS0);
			histo_DYJets[NJ][NStep]->Scale(6025.2*lumi/DYJetsS0);
			histo_WJets[NJ][NStep]->Scale(61526.7*lumi/WJetsS0);
			histo_QCDPt80to120EM[NJ][NStep]->Scale(350000*lumi/QCDPt80to120EMS0);
			histo_QCDPt80to120Mu[NJ][NStep]->Scale(106033.6648*lumi/QCDPt80to120MuS0);

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
			cout<<"QCDPt80to120EM yield Integral(1,nbin+1): "<<histo_QCDPt80to120EM[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<""<<endl;
			cout<<"QCDPt80to120Mu yield Integral(1,nbin+1): "<<histo_QCDPt80to120Mu[NJ][NStep]->Integral(1,nbin+1)<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			double ymax = 0;
			ymax = histo_ttbar[NJ][NStep]->GetMaximum();
			//double ymin = 0;
			//ymin = histo_TTTT[NJ][NStep]->GetMinimum();

			histo_ttbar[NJ][NStep]->SetMaximum(ymax*100);
			histo_ttbar[NJ][NStep]->SetMinimum(0.01);
			histo_ttbar[NJ][NStep]->Draw();
			histo_DYJets[NJ][NStep]->Draw("same");
			histo_WJets[NJ][NStep]->Draw("same");
			histo_QCDPt80to120EM[NJ][NStep]->Draw("same");
			histo_QCDPt80to120Mu[NJ][NStep]->Draw("same");
			histo_TTTT[NJ][NStep]->Draw("same");

			/*
			   double ymax = 0;
			   ymax = histo_TTTT[NJ][NStep]->GetMaximum();

			   histo_TTTT_eff[NJ][NStep]->SetMaximum(1.5);
			   histo_TTTT_eff[NJ][NStep]->Draw();
			   histo_ttbar_eff[NJ][NStep]->Draw("same");*/

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text+Step_txt[NStep]+Form("NJet>=%d",NJet[NJ]));
			//lt2.DrawLatex(x_1,y_1,"CMS");
			//lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV");
			l_[NJ][NStep]->Draw();
			canvIso_[NJ][NStep]->Print("Eff"+Step_txt[NStep]+"_"+Form("NJet>=%d",NJet[NJ])+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
