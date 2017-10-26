{
	gROOT->SetStyle("Plain");//"Pub","Plain"
	gStyle->SetOptStat(0);//To display the mean and RMS: SetOptStat("mr"), nemruoi, ;
	gStyle->SetOptDate(1);//display date position
	/*gStyle->SetCanvasDefH(600);//Height of canvas
	  gStyle->SetCanvasDefW(600);//Width of canvas
	  gStyle->SetCanvasDefX(0);//POsition on screen
	  gStyle->SetCanvasDefY(0);*/

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
	lt2.SetTextFont(61);
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
	//--------------------------------------Set Maximum histo_TTTT[NCh][NStep]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.62;
	float ly1 = 0.61;
	float lx2 = 0.94;
	float ly2 = 0.78;

	const int nStepCut = 5;//Step Num 5
	const int NChannel = 2;//number of Channel
	//int NJet[] = {4,5,6,7,8,9,10};
	//int NJet[] = {6};
	const int nSample = 4;//number of samples
	const int nQCD = 18;

	TH1F *histo_Sample[nStepCut][NChannel][nSample];
	TH1F *histo_Sample_gen[nStepCut][NChannel][nSample];

	TH1F *histo_nQCD[nStepCut][NChannel][nQCD];
	TH1F *histo_nQCD_gen[nStepCut][NChannel][nQCD];

	TH1F *histo_QCD[nStepCut][NChannel];

	//-----------------------------------------------------------

	TCanvas *canv_[nStepCut][NChannel];
	TLegend *l_[nStepCut][NChannel];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	//PATH_samples = "/cms/scratch/yjeong/";//KISTI
	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";

	TString NBJet;

	TString Variable;
	Variable = "Jet_HT";
	/*
	   TString Step_1;
	   Step_1 = "NJet >= 6 && NBJet >= 2";

	   TString Step_2;//fully hadronic
	   Step_2 = "IsHadronTrig == 1 &&";
	   */
	TString Step_1;
	//Step_1 = "Jet_Pt[0] > 90 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50";
	Step_1 = "Jet_Pt[0] > 90 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50 && Jet_Pt[0] < 700 && Jet_Pt[1] < 500 && Jet_Pt[2] < 300 && Jet_Pt[3] < 250";

	TString Step_2;
	Step_2 = "&& IsHadronTrig == 1 && Jet_HT > 500 && Jet_HT < 2500";

	TString Step_3;
	Step_3 = "&&(NLooseMuon+NLooseElectron)==0";

	TString Step_4;
	Step_4 = "&& NJet >= 10";

	TString Step_5;
	Step_5 = "&& NBJet >= 4 && Nt > 3";

	//TString Step_Cut[] = {Step_1, Step_2+Step_1, Step_2+Step_3+Step_1, Step_2+Step_3+Step_4+Step_1, Step_2+Step_3+Step_4+Step_5+Step_1, Step_2+Step_3+Step_4+Step_5+Step_6+Step_1, Step_2+Step_3+Step_4+Step_5+Step_6+Step_7+Step_1};//Hadronic Channel
	TString Step_Cut[nStepCut] = {Step_1, Step_1+Step_2, Step_1+Step_2+Step_3, Step_1+Step_2+Step_3+Step_4, Step_1+Step_2+Step_3+Step_4+Step_5};//Hadronic Channel


	//TString Step_txt[] = {"step1","step2","step3","step4","step5","step6","step7"};
	TString Step_txt[nStepCut] = {"step1","step2","step3","step4","step5"};

	TString tttt_Ch[NChannel] = {"nq==8 && nl==0 ","(nq==8 && nl==1) || nTau==1 || abs(dTau)==1"};
	TString ttbar_Ch[NChannel] = {"nq==4 && nl==0 ","(nq==4 && nl==1) || nTau==1 || abs(dTau)==1"};
	//TString tttt_Ch[NChannel] = {"(nq==8 && nl==0) || nTau==1 || abs(dTau)==0"};
	//TString ttbar_Ch[NChannel] = {"(nq==4 && nl==0) || nTau==1 || abs(dTau)==0"};

	NBJet = "&& NBJet &&";

	TString Cut_base_text[NChannel] = {"Hadronic ","Lepton "};
	//TString Cut_base_text[NChannel] = {"Lepton "};

	////////////////////////////////Get Samples/////////////////////////////////

	//const int Sample_Num = 23;//=======================================check
	const int Sample_Num = 22;//=======================================check
	//TString Sample_name[Sample_Num] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu","vallot","TT_powheg","DYJets","WJets"};//===============================check
	//TString Sample_name[Sample_Num] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu","vallot","TT_powheg","DYJets","WJets"};//===============================check
	TString Sample_name[Sample_Num] = {"vallot","TT_powheg","DYJets","WJets","QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu"};//===============================check

	TString Legend_Name[] = {"TTTT","ttbar","DYJets","WJets"};//===============================check

	TFile *tfile[Sample_Num];

	for(int i = 0; i < Sample_Num; i++){
		tfile[i] = new TFile(PATH_samples+Sample_name[i]+".root");
	}

	TTree *tree[Sample_Num];
	TH1D *hs0;
	TH1D *hs1;
	TH1D *ht0;
	TH1D *ht1;

	double skim_eff[Sample_Num][NChannel] = {0,};
	double trig_eff[Sample_Num][NChannel] = {0,};
	double s_eff = {0,};
	double t_eff = {0,};

	for(int i = 0; i < Sample_Num; i++){
		tree[i] = (TTree*)tfile[i]->Get("TopTree/events");

		hs0 = (TH1D*)tfile[i]->Get("TopTree/hskim0");
		hs1 = (TH1D*)tfile[i]->Get("TopTree/hskim1");
		ht0 = (TH1D*)tfile[i]->Get("TopTree/htrig0");
		ht1 = (TH1D*)tfile[i]->Get("TopTree/htrig1");
		hs1->Divide(hs1,hs0,1,1);
		ht1->Divide(ht1,ht0,1,1);

		for(int nch = 0; nch < NChannel; nch++){
			skim_eff[i][nch] = hs1->GetBinContent(nch+1+i*5);
			trig_eff[i][nch] = ht1->GetBinContent(nch+1+i*5);
		}
	}
	/////////////////////////////////////////////////////////////////////////////

	TH1F *hNJet;
	hNJet = new TH1F(Form("hNJet"),Form(""),16,0,16);
	tree[1]->Project(Form("hNJet"),"NJet");
	cout<<"NJet events number"<<endl;

	for(int i = 7; i < 17; i++){
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
	/*cout<<""<<endl;
	  cout<<"step6: "<<Step_6<<endl;
	  cout<<""<<endl;
	  cout<<"step7: "<<Step_7<<endl;*/

	for(int NCh = 0; NCh < NChannel; NCh++){
		for(int NStep = 0; NStep < nStepCut; NStep++){
			float nbin = 60;
			float xmin = 0;
			float xmax = 2500;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;

			canv_[NCh][NStep] = new TCanvas();
			canv_[NCh][NStep]->SetLogy();
			canv_[NCh][NStep]->SetFillColor(0);
			canv_[NCh][NStep]->SetBorderMode(2);
			canv_[NCh][NStep]->SetFrameFillStyle(3);
			canv_[NCh][NStep]->SetFrameBorderMode(0);
			canv_[NCh][NStep]->SetTickx(1);
			canv_[NCh][NStep]->SetTicky(1);
			canv_[NCh][NStep]->Update();
			canv_[NCh][NStep]->RedrawAxis();
			canv_[NCh][NStep]->GetFrame()->Draw();

			l_[NCh][NStep] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NCh][NStep]->SetFillColor(0);
			l_[NCh][NStep]->SetLineColor(0);
			l_[NCh][NStep]->SetLineStyle(kSolid);
			l_[NCh][NStep]->SetLineWidth(1);
			l_[NCh][NStep]->SetFillStyle(1);
			l_[NCh][NStep]->SetTextFont(2);
			l_[NCh][NStep]->SetTextSize(0.035);

			/////////////////////////////////////////////Samples////////////////////////////////////////////////////////

			for(int nSam = 0; nSam < nSample; nSam++){
				histo_Sample[NCh][NStep][nSam] = new TH1F(Form("histo_Sample_%d_%d_%d",NCh,NStep,nSam),Form(""),nbin,xmin,xmax);
				if(nSam == 0)tree[nSam]->Project(Form("histo_Sample_%d_%d_%d",NCh,NStep,nSam),Variable,tttt_Ch[NCh]+NBJet+Step_Cut[NStep]);
				if(nSam == 1)tree[nSam]->Project(Form("histo_Sample_%d_%d_%d",NCh,NStep,nSam),Variable,ttbar_Ch[NCh]+NBJet+Step_Cut[NStep]);
				if(nSam > 1)tree[nSam]->Project(Form("histo_Sample_%d_%d_%d",NCh,NStep,nSam),Variable,Step_Cut[NStep]);

				histo_Sample[NCh][NStep][nSam]->SetLineWidth(2);
				if(nSam == 0){//4Top
					histo_Sample[NCh][NStep][nSam]->SetLineColor(TTTT_c);
					histo_Sample[NCh][NStep][nSam]->SetMarkerColor(TTTT_c);
				}
				if(nSam == 1){//ttbar
					histo_Sample[NCh][NStep][nSam]->SetLineColor(ttbar_c);
					histo_Sample[NCh][NStep][nSam]->SetMarkerColor(ttbar_c);
				}
				if(nSam == 2){//WJets
					histo_Sample[NCh][NStep][nSam]->SetLineColor(dyjets_c);
					histo_Sample[NCh][NStep][nSam]->SetMarkerColor(dyjets_c);
				}
				if(nSam == 3){//DYJets
					histo_Sample[NCh][NStep][nSam]->SetLineColor(wjets_c);
					histo_Sample[NCh][NStep][nSam]->SetMarkerColor(wjets_c);
				}
				histo_Sample[NCh][NStep][nSam]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
				histo_Sample[NCh][NStep][nSam]->GetXaxis()->SetTitle(Variable);

				histo_Sample_gen[NCh][NStep][nSam] = new TH1F(Form("histo_Sample_gen_%d_%d_%d",NCh,NStep,nSam),Form(""),nbin,xmin,xmax);
				if(nSam == 0)tree[nSam]->Project(Form("histo_Sample_gen_%d_%d_%d",NCh,NStep,nSam),Variable,tttt_Ch[NCh]);
				if(nSam == 1)tree[nSam]->Project(Form("histo_Sample_gen_%d_%d_%d",NCh,NStep,nSam),Variable,ttbar_Ch[NCh]);
				if(nSam > 1)tree[nSam]->Project(Form("histo_Sample_gen_%d_%d_%d",NCh,NStep,nSam),Variable);

				l_[NCh][NStep]->AddEntry(histo_Sample[NCh][NStep][nSam],Legend_Name[nSam], "lp");
			}

			//////////////////////////////////////////////QCD/////////////////////////////////////////////////////

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[NCh][NStep][NQ] = new TH1F(Form("histo_nQCD_%d_%d_%d",NCh,NStep,NQ),Form(""),nbin,xmin,xmax);
				tree[NQ+4]->Project(Form("histo_nQCD_%d_%d_%d",NCh,NStep,NQ),Variable,Step_Cut[NStep]);

				histo_nQCD_gen[NCh][NStep][NQ] = new TH1F(Form("histo_nQCD_gen_%d_%d_%d",NCh,NStep,NQ),Form(""),nbin,xmin,xmax);
				tree[NQ+4]->Project(Form("histo_nQCD_gen_%d_%d_%d",NCh,NStep,NQ),Variable);
			}

			///////////////////////////////////////////// candidate ///////////////////////////////////////////

			double BR = 0.6741;//theoritical value W->Hadron
			//4top->all hadrons = BR^4.
			//ttbar->all hadrons = BR^2.
			double lumi = 36*1000;//pb-1
			cout<<""<<endl;
			cout<<"---------------------------------------"<<Step_txt[NStep]<<"-------------------------------------"<<endl;
			cout<<"lumi : "<<lumi<<" pb-1"<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			TString Sample_name[] = {"TTTT","TTbar","DYJets","WJets"};//======================================check
			double Sample_xsec[] = {0.009103,832.76,6025.2,61526.7};//======================================check

			/////////////////////////////////////////////// Samples ///////////////////////////////////////////////////

			double SampleS1[nSample];
			double SampleS0[nSample];
			double Sample_ev[nSample];
			//(double)Integral_TTTT = histo_Sample[NCh][NStep][nSam]->Scale(Sample_xsec[nSam]*skim_eff[nSam][nch]*trig_eff[nSam][nch]*lumi*BR*BR*BR*BR/SampleS0[nSam]);
			for(int nSam = 0; nSam < nSample; nSam++){
				SampleS1[nSam] = histo_Sample[NCh][NStep][nSam]->GetEntries();
				SampleS0[nSam] = histo_Sample_gen[NCh][NStep][nSam]->GetEntries();

				if(nSam==0){//TTTT change 0 -> 1 (different channel)
					histo_Sample[NCh][NStep][nSam]->Scale(Sample_xsec[nSam]*skim_eff[nSam][NCh]*trig_eff[nSam][NCh]*BR*BR*BR*BR*lumi/SampleS0[nSam]);
					Sample_ev[nSam] = Sample_xsec[nSam]*lumi*BR*BR*BR*BR*skim_eff[nSam][NCh]*trig_eff[nSam][NCh]*(SampleS1[nSam]/SampleS0[nSam]);
				}
				if(nSam==1){//ttbar change 0 -> 1 (different channel)
					cout<<"eff_skim: "<<skim_eff[nSam][NCh]<<endl;
					cout<<"eff_trig: "<<trig_eff[nSam][NCh]<<endl;
					histo_Sample[NCh][NStep][nSam]->Scale(Sample_xsec[nSam]*skim_eff[nSam][NCh]*trig_eff[nSam][NCh]*lumi*BR*BR/SampleS0[nSam]);
					Sample_ev[nSam] = Sample_xsec[nSam]*lumi*BR*BR*skim_eff[nSam][NCh]*trig_eff[nSam][NCh]*(SampleS1[nSam]/SampleS0[nSam]);
				}
				if(nSam>1){//bkg
					histo_Sample[NCh][NStep][nSam]->Scale(Sample_xsec[nSam]*skim_eff[nSam][NCh]*trig_eff[nSam][NCh]*lumi/SampleS0[nSam]);
					Sample_ev[nSam] = Sample_xsec[nSam]*lumi*skim_eff[nSam][NCh]*trig_eff[nSam][NCh]*(SampleS1[nSam]/SampleS0[nSam]);
				}
			}
			//--------------------------------------------Print-----------------------------------------------
			for(int nSam = 0; nSam < nSample; nSam++){
				cout<<(SampleS1[nSam]/SampleS0[nSam])*100<<"%"<<" , "<<Legend_Name[nSam]<<endl;
				cout<<""<<endl;
				cout<<"number of " <<Sample_name[nSam]<< " expected events " << Sample_ev[nSam] << endl;
				cout<<""<<endl;
				cout<<Legend_Name[nSam] <<" yield Integral(1,nbin+1): "<<histo_Sample[NCh][NStep][nSam]->Integral(1,nbin+1)<<endl;
				cout<<""<<endl;
				cout<<Legend_Name[nSam] <<" Sum: "<<histo_Sample[NCh][NStep][nSam]->GetSum()<<endl;
				cout<<""<<endl;
				cout<<""<<endl;
			}

			////////////////////////////////////////////////// QCD ///////////////////////////////////////////////////

			//TString QCD_name[] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu"};
			TString QCD_name[] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu"};
			double QCD_xsec[] = {350000, 106033.6648, 1.62131692, 62964, 25190.51514, 3819570, 18810, 8654.49315, 5352960.0, 2960198.4, 797.35269, 1350, 9928000.0, 1652471.46, 79.02553776, 2890800.0, 437504.1, 25.09505908, 4.707368272};

			double nQCDS1[nQCD];
			double nQCDS0[nQCD];
			double nQCD_ev[nQCD];
			double QCD_Int[nQCD];

			for(int NQ = 0; NQ < nQCD; NQ++){
				nQCDS1[NQ] = histo_nQCD[NCh][NStep][NQ]->GetEntries();
				nQCDS0[NQ] = histo_nQCD_gen[NCh][NStep][NQ]->GetEntries();
			}

			double QCD_S1 = 0, QCD_S0 = 0;//selected events, total events
			for(int NQ = 0; NQ < nQCD; NQ++){
				QCD_S1 += nQCDS1[NQ];
				QCD_S0 += nQCDS0[NQ];
			}
			//----------------------------------Cut Effciency----------------------------------

			cout<< (QCD_S1/QCD_S0)*100<<"%"<<", "<<", QCD " <<endl;
			cout<<""<<endl;
			//---------------------------------------------------------------------------------
			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[NCh][NStep][NQ]->Scale(QCD_xsec[NQ]*skim_eff[NQ][NCh]*trig_eff[NQ][NCh]*lumi/nQCDS0[NQ]);
				QCD_Int[NQ] = histo_nQCD[NCh][NStep][NQ]->Integral(1,nbin+1);
				nQCD_ev[NQ] = QCD_xsec[NQ]*lumi*(nQCDS1[NQ]*skim_eff[NQ][NCh]*trig_eff[NQ][NCh]/nQCDS0[NQ]);
			}

			double QCD_Integral = 0, QCD_ev = 0;//histo Integral, QCD total expected events
			for(int NQ = 0; NQ < nQCD; NQ++ ){
				QCD_Integral += QCD_Int[NQ];
				QCD_ev += nQCD_ev[NQ];
			}

			cout<<"QCD expected events: "<<QCD_ev <<endl;
			cout<<"QCD yield Integral(1,nbin+1): "<<QCD_Integral<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			//----------------------------------expected events, yield----------------------------
			for(int NQ = 0; NQ < nQCD; NQ++){
				cout <<"number of "<< QCD_name[NQ] << " expected events: " << nQCD_ev[NQ] << endl;
				cout << QCD_name[NQ] << " yield Integral(1,nbin+1): " << QCD_Int[NQ] <<endl;
				cout<<""<<endl;
			}
			//--------------------------------------------------------------------------------

			histo_QCD[NCh][NStep] = new TH1F(Form("histo_QCD_%d_%d",NCh,NStep),Form(""),nbin,xmin,xmax);
			histo_QCD[NCh][NStep]->SetLineColor(qcd_c);
			histo_QCD[NCh][NStep]->SetLineWidth(2);
			histo_QCD[NCh][NStep]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NCh][NStep]->GetXaxis()->SetTitle("Jet_HT");
			l_[NCh][NStep]->AddEntry(histo_QCD[NCh][NStep],"QCD ", "lp");

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_QCD[NCh][NStep]->Add(histo_nQCD[NCh][NStep][NQ]);
			}

			double ymax = 0;
			/*ymax = histo_QCD[NCh][NStep]->GetMaximum();
			  histo_QCD[NCh][NStep]->SetMaximum(ymax*1000);
			  histo_QCD[NCh][NStep]->SetMinimum(0.01);
			  histo_QCD[NCh][NStep]->Draw();*/
			for(int nSam = 0; nSam < nSample; nSam++){
				if(nSam==0){
					ymax = histo_Sample[NCh][NStep][nSam]->GetMaximum();
					histo_Sample[NCh][NStep][nSam]->SetMaximum(ymax*100000000000);
					histo_Sample[NCh][NStep][nSam]->SetMinimum(0.01);
					histo_Sample[NCh][NStep][nSam]->Draw();
				}
				if(nSam==1){
					histo_Sample[NCh][NStep][nSam]->Draw("same");
				}
				histo_Sample[NCh][NStep][nSam]->Draw("same");
			}
			histo_QCD[NCh][NStep]->Draw("same");

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text[NCh]+Step_txt[NStep]);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NCh][NStep]->Draw();
			canv_[NCh][NStep]->SaveAs(Save_dir+Cut_base_text[NCh]+Step_txt[NStep]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
