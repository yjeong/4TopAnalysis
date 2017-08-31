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
	//--------------------------------------Set Maximum histo_TTTT[NJ][NPt]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.62;
	float ly1 = 0.61;
	float lx2 = 0.94;
	float ly2 = 0.78;

	const int JetPtCut = 4;//Pt Cut number
	const int NJetNum = 1;//Variable
	//int NJet[] = {4,5,6,7,8,9,10};
	const int nSample = 4;//===========================check
	const int nQCD = 19;

	TH1F *histo_Sample[JetPtCut][NJetNum][nSample];
	TH1F *histo_Sample_gen[JetPtCut][NJetNum][nSample];

	TH1F *histo_nQCD[JetPtCut][NJetNum][nQCD];
	TH1F *histo_nQCD_gen[JetPtCut][NJetNum][nQCD];

	TH1F *histo_QCD[JetPtCut][NJetNum];

	TCanvas *canv_[JetPtCut][NJetNum];
	TLegend *l_[JetPtCut][NJetNum];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";

	TString Cut_base_text;
	TString ttttHad_Ch;
	TString ttbarHad_Ch;
	TString dyHad_Ch;
	TString HadronTrig;
	TString Jet_HT_Cut;
	TString nlep_Cut;
	TString NBJet;

	//TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]"};
	TString Variable;
	Variable = "Jet_HT";

	TString Pt_0;
	Pt_0 = "Jet_Pt[0] > 90 &&";
	TString Pt_1;
	Pt_1 = "Jet_Pt[1] > 70 &&";
	TString Pt_2;
	Pt_2 = "Jet_Pt[2] > 60 &&";
	TString Pt_3;
	Pt_3 = "Jet_Pt[3] > 50 &&";

	TString Pt_Cut[] = {Pt_0, Pt_0+Pt_1, Pt_0+Pt_1+Pt_2, Pt_0+Pt_1+Pt_2+Pt_3};

	//Cut_base = "fabs(Muon_Pt) > 30 && fabs(Muon_Eta) < 2.4 &&";
	ttttHad_Ch = "nq==8 && nl==0 &&";
	ttbarHad_Ch = "nq==4 && nl==0 &&";
	nRecolep = "(NLooseMuon+NLooseElectron)==0 &&";
	NBJet = "NBJet>=2 && NJet >= 6";

	HadronTrig = "IsHadronTrig==1 &&";

	Cut_base_text = "Hadronic ";

	//////////////////////////////////////Get Samples///////////////////////////////////
	const int Sample_Num = 23;//=========================check
	TString Sample_name[Sample_Num] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu","vallot","TT_powheg","DYJets","WJets"};//===================check

	TString Legend_Name[] = {"TTTT","ttbar","DYJets","WJets"};//========================check

	TFile *tfile[Sample_Num];

	for(int i = 0; i < Sample_Num; i++){
		tfile[i] = new TFile(PATH_samples+Sample_name[i]+".root");
	}

	TTree *tree[Sample_Num];
	for(int i = 0; i < Sample_Num; i++){
		tree[i] = (TTree*)tfile[i]->Get("TopTree/events");
	}
	//////////////////////////////////////////////////////////////////////////////////////
	TH1F *hNJet;
	hNJet = new TH1F(Form("hNJet"),Form(""),16,0,16);
	tree[19]->Project(Form("hNJet"),"NJet");

	for(int NJ = 0; NJ < NJetNum; NJ++){
		for(int NPt = 0; NPt < JetPtCut; NPt++){
			float nbin = 60;
			float xmin = 0;
			float xmax = 2800;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;

			canv_[NJ][NPt] = new TCanvas();
			//canv_[NJ][NPt]->SetLogy();
			canv_[NJ][NPt]->SetFillColor(0);
			canv_[NJ][NPt]->SetBorderMode(2);
			canv_[NJ][NPt]->SetFrameFillStyle(3);
			canv_[NJ][NPt]->SetFrameBorderMode(0);
			canv_[NJ][NPt]->SetTickx(1);
			canv_[NJ][NPt]->SetTicky(1);
			canv_[NJ][NPt]->Update();
			canv_[NJ][NPt]->RedrawAxis();
			canv_[NJ][NPt]->GetFrame()->Draw();

			l_[NJ][NPt] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NJ][NPt]->SetFillColor(0);
			l_[NJ][NPt]->SetLineColor(0);
			l_[NJ][NPt]->SetLineStyle(kSolid);
			l_[NJ][NPt]->SetLineWidth(1);
			l_[NJ][NPt]->SetFillStyle(1);
			l_[NJ][NPt]->SetTextFont(2);
			l_[NJ][NPt]->SetTextSize(0.035);

			for(int nSam = 0; nSam < nSample; nSam++){//===========================check
				histo_Sample[NJ][NPt][nSam] = new TH1F(Form("histo_Sample_%d_%d_%d",NJ,NPt,nSam),Form(""),nbin,xmin,xmax);
				if(nSam==0)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NJ,NPt,nSam),Variable,nRecolep+ttttHad_Ch+Pt_Cut[NPt]+HadronTrig+NBJet);
				if(nSam==1)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NJ,NPt,nSam),Variable,nRecolep+ttbarHad_Ch+Pt_Cut[NPt]+HadronTrig+NBJet);
				if(nSam > 1)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NJ,NPt,nSam),Variable,nRecolep+Pt_Cut[NPt]+HadronTrig+NBJet);
				histo_Sample[NJ][NPt][nSam]->SetLineWidth(2);
				if(nSam == 0){
					histo_Sample[NJ][NPt][nSam]->SetLineColor(TTTT_c);
					histo_Sample[NJ][NPt][nSam]->SetMarkerColor(TTTT_c);
				}
				if(nSam == 1){
					histo_Sample[NJ][NPt][nSam]->SetLineColor(ttbar_c);
					histo_Sample[NJ][NPt][nSam]->SetMarkerColor(ttbar_c);
				}
				if(nSam == 2){
					histo_Sample[NJ][NPt][nSam]->SetLineColor(dyjets_c);
					histo_Sample[NJ][NPt][nSam]->SetMarkerColor(dyjets_c);
				}
				if(nSam == 3){
					histo_Sample[NJ][NPt][nSam]->SetLineColor(wjets_c);
					histo_Sample[NJ][NPt][nSam]->SetMarkerColor(wjets_c);
				}
				histo_Sample[NJ][NPt][nSam]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
				histo_Sample[NJ][NPt][nSam]->GetXaxis()->SetTitle(Variable);
				l_[NJ][NPt]->AddEntry(histo_Sample[NJ][NPt][nSam],Legend_Name[nSam], "lp");
			}

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[NJ][NPt][NQ] = new TH1F(Form("histo_nQCD_%d_%d_%d",NJ,NPt,NQ),Form(""),nbin,xmin,xmax);
				tree[NQ]->Project(Form("histo_nQCD_%d_%d_%d",NJ,NPt,NQ),Variable,nRecolep+Pt_Cut[NPt]+HadronTrig+NBJet);
			}

			histo_QCD[NJ][NPt] = new TH1F(Form("histo_QCD_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			histo_QCD[NJ][NPt]->SetLineColor(qcd_c);
			histo_QCD[NJ][NPt]->SetLineWidth(2);
			histo_QCD[NJ][NPt]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NJ][NPt]->GetXaxis()->SetTitle(Variable);
			l_[NJ][NPt]->AddEntry(histo_QCD[NJ][NPt],"QCD ", "lp");

			for(int NQ = 0; NQ < nQCD; NQ++){
                                histo_QCD[NJ][NPt]->Add(histo_nQCD[NJ][NPt][NQ]);
                        }

			double nev_[nSample];
                        for(int nSam = 0; nSam < nSample; nSam++){
                                nev_[nSam] = histo_Sample[NJ][NPt][nSam]->GetEntries();
                                histo_Sample[NJ][NPt][nSam]->Scale(1/nev_[nSam]);
                        }

			double nev_qcd = histo_QCD[NJ][NPt]->GetEntries();
			histo_QCD[NJ][NPt]->Scale(1/nev_qcd);

			double ymax = 0;
                        ymax = histo_Sample[NJ][NPt][1]->GetMaximum();

                        histo_Sample[NJ][NPt][1]->SetMaximum(ymax*1.3);
                        histo_Sample[NJ][NPt][1]->Draw();
                        histo_QCD[NJ][NPt]->Draw("same");
                        for(int nSam = 0; nSam < nSample; nSam++){
                                if(nSam!=1)histo_Sample[NJ][NPt][nSam]->Draw("same");
                        }

			lt1.DrawLatex(xx_1,yy_1,HadronTrig);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NJ][NPt]->Draw();
			canv_[NJ][NPt]->SaveAs(Save_dir+Variable+Pt_Cut[NPt]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
