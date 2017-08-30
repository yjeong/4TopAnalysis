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

	const int JetPtCut = 6;//Pt Cut number
	const int NJetNum = 1;//Variable
	//int NJet[] = {6};

	TH1F *histo_TTTT[JetPtCut][NJetNum];
	TH1F *histo_ttbar[JetPtCut][NJetNum];
	TH1F *histo_DYJets[JetPtCut][NJetNum];
	TH1F *histo_WJets[JetPtCut][NJetNum];

	TH1F *histo_QCDPt80to120EM[JetPtCut][NJetNum];
	TH1F *histo_QCDPt80to120Mu[JetPtCut][NJetNum];

	TH1F *histo_QCD[JetPtCut][NJetNum];

	TCanvas *canvIso_[JetPtCut][NJetNum];
	TLegend *l_[JetPtCut][NJetNum];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";

	TString Cut_base_text;
	TString ttttHad_Ch;
	TString ttbarHad_Ch;
	TString dyHad_Ch;
	TString nRecolep;

	TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]"};

	TString Cut_base[] = {"NJet>=6","NJet>=6&&NBJet>=2"};

	TString Triger;
	Triger = "&& IsHadronTrig == 1";

	ttttHad_Ch = "nq==8 && nl==0 && ";
	ttbarHad_Ch = "nq==4 && nl==0 && ";
	nRecolep = "&& (NLooseMuon+NLooseElectron)==0";

	Cut_base_text = "Hadronic ";

	////////////////////////////////Get Samples/////////////////////////////////
	const int Sample_Num = 6;
	TString Sample_name[Sample_Num] = {"vallot","TT_powheg","DYJets","WJets","QCDPt80to120EM","QCDPt80to120Mu"};
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

	for(int i = 1; i < 17; i++){
		cout<< hNJet->GetBinContent(i) << endl;
	}

	for(int NJ = 0; NJ < NJetNum; NJ++){
		for(int NPt = 0; NPt < JetPtCut; NPt++){
			float nbin = 35;
			float xmin = 0;
			float xmax = 350;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;

			canvIso_[NJ][NPt] = new TCanvas();
			//canvIso_[NJ][NPt]->SetLogy();
			canvIso_[NJ][NPt]->SetFillColor(0);
			canvIso_[NJ][NPt]->SetBorderMode(2);
			canvIso_[NJ][NPt]->SetFrameFillStyle(3);
			canvIso_[NJ][NPt]->SetFrameBorderMode(0);
			canvIso_[NJ][NPt]->SetTickx(1);
			canvIso_[NJ][NPt]->SetTicky(1);
			canvIso_[NJ][NPt]->Update();
			canvIso_[NJ][NPt]->RedrawAxis();
			canvIso_[NJ][NPt]->GetFrame()->Draw();

			l_[NJ][NPt] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NJ][NPt]->SetFillColor(0);
			l_[NJ][NPt]->SetLineColor(0);
			l_[NJ][NPt]->SetLineStyle(kSolid);
			l_[NJ][NPt]->SetLineWidth(1);
			l_[NJ][NPt]->SetFillStyle(1);
			l_[NJ][NPt]->SetTextFont(2);
			l_[NJ][NPt]->SetTextSize(0.035);

			//---------------------------------------------------------

			histo_TTTT[NJ][NPt] = new TH1F(Form("histo_TTTT_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			tree[0]->Project(Form("histo_TTTT_%d_%d",NJ,NPt),Variable[NPt],ttttHad_Ch+Cut_base[NJ]+Triger+nRecolep);
			histo_TTTT[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_TTTT[NJ][NPt],"TTTT ", "lp");
			histo_TTTT[NJ][NPt]->SetLineColor(TTTT_c);
			histo_TTTT[NJ][NPt]->SetMarkerColor(TTTT_c);

			//----------------------------------------

			histo_ttbar[NJ][NPt] = new TH1F(Form("histo_ttbar_%d_%d",NJ,NPt),Form("Jet_Pt"),nbin,xmin,xmax);
			tree[1]->Project(Form("histo_ttbar_%d_%d",NJ,NPt),Variable[NPt],ttbarHad_Ch+Cut_base[NJ]+Triger+nRecolep);
			histo_ttbar[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_ttbar[NJ][NPt],"ttbar ", "lp");
			histo_ttbar[NJ][NPt]->SetLineColor(ttbar_c);
			histo_ttbar[NJ][NPt]->SetMarkerColor(ttbar_c);
			histo_ttbar[NJ][NPt]->GetYaxis()->SetTitle("# of Events");
			histo_ttbar[NJ][NPt]->GetXaxis()->SetTitle(Variable[NPt]);

			//-----------------------------------------------------------------

			histo_DYJets[NJ][NPt] = new TH1F(Form("histo_DYJets_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			tree[2]->Project(Form("histo_DYJets_%d_%d",NJ,NPt),Variable[NPt],Cut_base[NJ]+Triger+nRecolep);
			histo_DYJets[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_DYJets[NJ][NPt],"DYJets ", "lp");
			histo_DYJets[NJ][NPt]->SetLineColor(dyjets_c);
			histo_DYJets[NJ][NPt]->SetMarkerColor(dyjets_c);
			histo_DYJets[NJ][NPt]->GetYaxis()->SetTitle("# of Normalized Events");
			histo_DYJets[NJ][NPt]->GetXaxis()->SetTitle(Variable[NPt]);

			//---------------------------------------

			histo_WJets[NJ][NPt] = new TH1F(Form("histo_WJets_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			tree[3]->Project(Form("histo_WJets_%d_%d",NJ,NPt),Variable[NPt],Cut_base[NJ]+Triger+nRecolep);
			histo_WJets[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_WJets[NJ][NPt],"WJets ", "lp");
			histo_WJets[NJ][NPt]->SetLineColor(wjets_c);
			histo_WJets[NJ][NPt]->SetMarkerColor(wjets_c);

			//--------------------------------------------------------------

			histo_QCDPt80to120EM[NJ][NPt] = new TH1F(Form("histo_QCDPt80to120EM_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			tree[4]->Project(Form("histo_QCDPt80to120EM_%d_%d",NJ,NPt),Variable[NPt],Cut_base[NJ]+Triger+nRecolep);

			//------------------------------------------------------------------

			histo_QCDPt80to120Mu[NJ][NPt] = new TH1F(Form("histo_QCDPt80to120Mu_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			tree[5]->Project(Form("histo_QCDPt80to120Mu_%d_%d",NJ,NPt),Variable[NPt],Cut_base[NJ]+Triger+nRecolep);

			//-----------------------------------------------------------------

			histo_QCD[NJ][NPt] = new TH1F(Form("histo_QCD_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			histo_QCD[NJ][NPt]->SetLineColor(qcd_c);
			histo_QCD[NJ][NPt]->SetLineWidth(2);
			histo_QCD[NJ][NPt]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NJ][NPt]->GetXaxis()->SetTitle(Variable[NPt]);
			l_[NJ][NPt]->AddEntry(histo_QCD[NJ][NPt],"QCD ", "lp");

			histo_QCD[NJ][NPt]->Add(histo_QCDPt80to120Mu[NJ][NPt]);
			histo_QCD[NJ][NPt]->Add(histo_QCDPt80to120EM[NJ][NPt]);

			double nev_1 = histo_TTTT[NJ][NPt]->GetEntries();
			histo_TTTT[NJ][NPt]->Scale(1/nev_1);
			double nev_2 = histo_ttbar[NJ][NPt]->GetEntries();
			histo_ttbar[NJ][NPt]->Scale(1/nev_2);
			double nev_3 = histo_DYJets[NJ][NPt]->GetEntries();
			histo_DYJets[NJ][NPt]->Scale(1/nev_3);
			double nev_4 = histo_WJets[NJ][NPt]->GetEntries();
			histo_WJets[NJ][NPt]->Scale(1/nev_4);
			double nev_5 = histo_QCD[NJ][NPt]->GetEntries();
			histo_QCD[NJ][NPt]->Scale(1/nev_5);

			double ymax = 0;
			ymax = histo_QCD[NJ][NPt]->GetMaximum();

			histo_QCD[NJ][NPt]->SetMaximum(ymax*1.3);
			histo_QCD[NJ][NPt]->Draw();
			histo_DYJets[NJ][NPt]->Draw("same");
			histo_WJets[NJ][NPt]->Draw("same");
			histo_ttbar[NJ][NPt]->Draw("same");
			histo_TTTT[NJ][NPt]->Draw("same");

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text+Cut_base[NJ]);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NJ][NPt]->Draw();
			canvIso_[NJ][NPt]->SaveAs(Save_dir+Variable[NPt]+Cut_base[NJ]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
