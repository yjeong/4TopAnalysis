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
	const int nSample = 4;
	const int nQCD = 19;

	TH1F *histo_Sample[JetStepCut][NJetNum][nSample];
	TH1F *histo_Sample_gen[JetStepCut][NJetNum][nSample];

	//----------------------------QCD samples----------------------------

	TH1F *histo_nQCD[JetStepCut][NJetNum][nQCD];
	TH1F *histo_nQCD_gen[JetStepCut][NJetNum][nQCD];

	//----------------------------------------------------------

	TH1F *histo_QCD[JetStepCut][NJetNum];

	//-----------------------------------------------------------

	TCanvas *canv_[JetStepCut][NJetNum];
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
	Step_3 = "Jet_Pt[0] > 90 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50 &&";
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

	////////////////////////////////Get Samples/////////////////////////////////

	const int Sample_Num = 23;//=======================================check
	TString Sample_name[Sample_Num] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu","vallot","TT_powheg","DYJets","WJets"};//===============================check

	TString Legend_Name[] = {"TTTT","ttbar","DYJets","WJets"};//===============================check

	TFile *tfile[Sample_Num];

	for(int i = 0; i < Sample_Num; i++){
		tfile[i] = new TFile(PATH_samples+Sample_name[i]+".root");
	}

	TTree *tree[Sample_Num];
	for(int i = 0; i < Sample_Num; i++){
		tree[i] = (TTree*)tfile[i]->Get("TopTree/events");
	}
	/////////////////////////////////////////////////////////////////////////////

	TH1F *hNJet;
	hNJet = new TH1F(Form("hNJet"),Form(""),16,0,16);
	tree[0]->Project(Form("hNJet"),"NJet");
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
			jets_c = 6;
			int qcd_c = 1;

			canv_[NJ][NStep] = new TCanvas();
			canv_[NJ][NStep]->SetLogy();
			canv_[NJ][NStep]->SetFillColor(0);
			canv_[NJ][NStep]->SetBorderMode(2);
			canv_[NJ][NStep]->SetFrameFillStyle(3);
			canv_[NJ][NStep]->SetFrameBorderMode(0);
			canv_[NJ][NStep]->SetTickx(1);
			canv_[NJ][NStep]->SetTicky(1);
			canv_[NJ][NStep]->Update();
			canv_[NJ][NStep]->RedrawAxis();
			canv_[NJ][NStep]->GetFrame()->Draw();

			l_[NJ][NStep] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NJ][NStep]->SetFillColor(0);
			l_[NJ][NStep]->SetLineColor(0);
			l_[NJ][NStep]->SetLineStyle(kSolid);
			l_[NJ][NStep]->SetLineWidth(1);
			l_[NJ][NStep]->SetFillStyle(1);
			l_[NJ][NStep]->SetTextFont(2);
			l_[NJ][NStep]->SetTextSize(0.035);

			/////////////////////////////////////////////Samples////////////////////////////////////////////////////////

			for(int nSam = 0; nSam < nSample; nSam++){
				histo_Sample[NJ][NStep][nSam] = new TH1F(Form("histo_Sample_%d_%d_%d",NJ,NStep,nSam),Form(""),nbin,xmin,xmax);
				if(nSam == 0)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NJ,NStep,nSam),Variable,ttttHad_Ch+NBJet+Step_Cut[NStep]);
				if(nSam == 1)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NJ,NStep,nSam),Variable,ttbarHad_Ch+NBJet+Step_Cut[NStep]);
				if(nSam > 1)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NJ,NStep,nSam),Variable,Step_Cut[NStep]);
				histo_Sample[NJ][NStep][nSam]->SetLineWidth(2);
				if(nSam == 0){
					histo_Sample[NJ][NStep][nSam]->SetLineColor(TTTT_c);
					histo_Sample[NJ][NStep][nSam]->SetMarkerColor(TTTT_c);
				}
				if(nSam == 1){
					histo_Sample[NJ][NStep][nSam]->SetLineColor(ttbar_c);
					histo_Sample[NJ][NStep][nSam]->SetMarkerColor(ttbar_c);
				}
				if(nSam == 2){
					histo_Sample[NJ][NStep][nSam]->SetLineColor(dyjets_c);
					histo_Sample[NJ][NStep][nSam]->SetMarkerColor(dyjets_c);
				}
				if(nSam == 3){
					histo_Sample[NJ][NStep][nSam]->SetLineColor(wjets_c);
					histo_Sample[NJ][NStep][nSam]->SetMarkerColor(wjets_c);
				}
				histo_Sample[NJ][NStep][nSam]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
				histo_Sample[NJ][NStep][nSam]->GetXaxis()->SetTitle(Variable);

				histo_Sample_gen[NJ][NStep][nSam] = new TH1F(Form("histo_Sample_gen_%d_%d_%d",NJ,NStep,nSam),Form(""),nbin,xmin,xmax);
				if(nSam == 0)tree[nSam+19]->Project(Form("histo_Sample_gen_%d_%d_%d",NJ,NStep,nSam),Variable,ttttHad_Ch);
				if(nSam == 1)tree[nSam+19]->Project(Form("histo_Sample_gen_%d_%d_%d",NJ,NStep,nSam),Variable,ttbarHad_Ch);
				if(nSam > 1)tree[nSam+19]->Project(Form("histo_Sample_gen_%d_%d_%d",NJ,NStep,nSam),Variable);

				l_[NJ][NStep]->AddEntry(histo_Sample[NJ][NStep][nSam],Legend_Name[nSam], "lp");
			}

			//////////////////////////////////////////////QCD/////////////////////////////////////////////////////

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[NJ][NStep][NQ] = new TH1F(Form("histo_nQCD_%d_%d_%d",NJ,NStep,NQ),Form(""),nbin,xmin,xmax);
				tree[NQ]->Project(Form("histo_nQCD_%d_%d_%d",NJ,NStep,NQ),Variable,Step_Cut[NStep]);

				histo_nQCD_gen[NJ][NStep][NQ] = new TH1F(Form("histo_nQCD_gen_%d_%d_%d",NJ,NStep,NQ),Form(""),nbin,xmin,xmax);
				tree[NQ]->Project(Form("histo_nQCD_gen_%d_%d_%d",NJ,NStep,NQ),Variable);
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
			for(int nSam = 0; nSam < nSample; nSam++){
				SampleS1[nSam] = histo_Sample[NJ][NStep][nSam]->GetEntries();
				SampleS0[nSam] = histo_Sample_gen[NJ][NStep][nSam]->GetEntries();
				Sample_ev[nSam] = Sample_xsec[nSam]*lumi*(SampleS1[nSam]/SampleS0[nSam]);
				if(nSam==0)histo_Sample[NJ][NStep][nSam]->Scale(Sample_xsec[nSam]*lumi*BR*BR*BR*BR/SampleS0[nSam]);
				if(nSam==1)histo_Sample[NJ][NStep][nSam]->Scale(Sample_xsec[nSam]*lumi*BR*BR/SampleS0[nSam]);
				if(nSam > 1)histo_Sample[NJ][NStep][nSam]->Scale(Sample_xsec[nSam]*lumi/SampleS0[nSam]);
			}
			//--------------------------------------------Print-----------------------------------------------
			for(int nSam = 0; nSam < nSample; nSam++){
				cout<<(SampleS1[nSam]/SampleS0[nSam])*100<<"%"<<" , "<<Legend_Name[nSam]<<endl;
				cout<<""<<endl;
				cout<<"number of " <<Sample_name[nSam]<< " expected events " << Sample_ev[nSam] << endl;
				cout<<""<<endl;
				cout<<Legend_Name[nSam] <<" yield Integral(1,nbin+1): "<<histo_Sample[NJ][NStep][nSam]->Integral(1,nbin+1)<<endl;
				cout<<""<<endl;
				cout<<""<<endl;
			}

			////////////////////////////////////////////////// QCD ///////////////////////////////////////////////////

			TString QCD_name[] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu"};
			double QCD_xsec[] = {350000, 106033.6648, 1.62131692, 62964, 25190.51514, 3819570, 18810, 8654.49315, 5352960.0, 2960198.4, 797.35269, 1350, 9928000.0, 1652471.46, 79.02553776, 2890800.0, 437504.1, 25.09505908, 4.707368272};

			double nQCDS1[nQCD];
			double nQCDS0[nQCD];
			double nQCD_ev[nQCD];
			double QCD_Int[nQCD];

			for(int NQ = 0; NQ < nQCD; NQ++){
				nQCDS1[NQ] = histo_nQCD[NJ][NStep][NQ]->GetEntries();
				nQCDS0[NQ] = histo_nQCD_gen[NJ][NStep][NQ]->GetEntries();
			}

			//-------------------------------Total, Cut event of QCD---------------------------------
			double QCD_S1 = 0, QCD_S0 = 0;
			for(int NQ = 0; NQ < nQCD; NQ++){
				QCD_S1 += nQCDS1[NQ];
				QCD_S0 += nQCDS0[NQ];
			}
			//------------------------------------------------------------------------------

			cout<< (QCD_S1/QCD_S0)*100<<"%"<<", "<<", QCD " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[NJ][NStep][NQ]->Scale(QCD_xsec[NQ]*lumi/nQCDS0[NQ]);
				QCD_Int[NQ] = histo_nQCD[NJ][NStep][NQ]->Integral(1,nbin+1);
				nQCD_ev[NQ] = QCD_xsec[NQ]*lumi*(nQCDS1[NQ]/nQCDS0[NQ]);
			}

			//--------------------------------------Integral, Expected ev of QCd------------------------------
			double QCD_Integral = 0, QCD_ev = 0;
			for(int NQ = 0; NQ < nQCD; NQ++ ){
				QCD_Integral += QCD_Int[NQ];
				QCD_ev += nQCD_ev[NQ];
			}
			//------------------------------------------------------------------------------------------

			cout<<"QCD expected events: "<<QCD_ev <<endl;
			cout<<"QCD yield Integral(1,nbin+1): "<<QCD_Integral<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			for(int NQ = 0; NQ < nQCD; NQ++){
				cout <<"number of "<< QCD_name[NQ] << " expected events: " << nQCD_ev[NQ] << endl;
				cout << QCD_name[NQ] << " yield Integral(1,nbin+1): " << QCD_Int[NQ] <<endl;
				cout<<""<<endl;
			}

			//////////////////////////////////////////// QCD histo //////////////////////////////////////////////
			histo_QCD[NJ][NStep] = new TH1F(Form("histo_QCD_%d_%d",NJ,NStep),Form(""),nbin,xmin,xmax);
			histo_QCD[NJ][NStep]->SetLineColor(qcd_c);
			histo_QCD[NJ][NStep]->SetLineWidth(2);
			histo_QCD[NJ][NStep]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NJ][NStep]->GetXaxis()->SetTitle("Jet_HT");
			l_[NJ][NStep]->AddEntry(histo_QCD[NJ][NStep],"QCD ", "lp");

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_QCD[NJ][NStep]->Add(histo_nQCD[NJ][NStep][NQ]);
			}

			double ymax = 0;
			ymax = histo_QCD[NJ][NStep]->GetMaximum();
			histo_QCD[NJ][NStep]->SetMaximum(ymax*100);
			histo_QCD[NJ][NStep]->SetMinimum(0.01);
			histo_QCD[NJ][NStep]->Draw();
			for(int nSam = 0; nSam < nSample; nSam++){
				histo_Sample[NJ][NStep][nSam]->Draw("same");
			}

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text+Step_txt[NStep]);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NJ][NStep]->Draw();
			canv_[NJ][NStep]->SaveAs(Save_dir+Step_txt[NStep]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
