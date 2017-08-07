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
	//--------------------------------------Set Maximum histo_TTTT[NT]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.62;
	float ly1 = 0.61;
	float lx2 = 0.94;
	float ly2 = 0.78;

	const int TreeVar = 2;//Variable number

	TH1F *histo_TTTT[TreeVar];
	TH1F *histo_ttbar[TreeVar];
	TH1F *histo_DYJets[TreeVar];
	TH1F *histo_WJets[TreeVar];

	/*TH1F *histo_BR_4Top;
	  TH1F *histo_BR_ttbar;
	  TH1F *histo_BR_4Top_total;
	  TH1F *histo_BR_ttbar_total;*/

	TCanvas *canvIso_[TreeVar];
	TLegend *l_[TreeVar];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI

	TString Cut_base_text;
	TString Ch_Cut;
	TString nlep_Ch;

	//TString Variable[] = {"Muon_Pt","Electron_Pt","Jet_Pt","Muon_Eta","Electron_Eta","Jet_Eta"};
	//TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]","Jet_Pt[10]"};
	TString Variable[] = {"NJet","NBJet"};

	//Cut_base = "fabs(Muon_Pt) > 30 && fabs(Muon_Eta) < 2.4 ";
	ttttHad_Ch = "nl==0 && nq==8";
	ttbarHad_Ch = "nl==0 && nq==4";
	nlep_Ch = "nl==0";

	Cut_base_text = "Hadronic";

	TFile h1(PATH_samples+"vallot.root");
	TFile h2(PATH_samples+"TT_powheg.root");
	TFile h3(PATH_samples+"DYJets.root");
	TFile h4(PATH_samples+"WJets.root");

	TTree *FourTop = (TTree*)h1.Get("TopTree/events");
	TTree *TTbar = (TTree*)h2.Get("TopTree/events");
	TTree *DYJets = (TTree*)h3.Get("TopTree/events");
	TTree *WJets = (TTree*)h4.Get("TopTree/events");

	TH1F *hNJet;
	hNJet = new TH1F(Form("hNJet"),Form(""),16,1,16);
	FourTop->Project(Form("hNJet"),"nq");
	//TTbar->Project(Form("hNJet"),"nq");
	cout<< hNJet->GetBinContent(1) << endl;
	cout<< hNJet->GetBinContent(2) << endl;
	cout<< hNJet->GetBinContent(3) << endl;
	cout<< hNJet->GetBinContent(4) << endl;
	cout<< hNJet->GetBinContent(5) << endl;
	cout<< hNJet->GetBinContent(6) << endl;
	cout<< hNJet->GetBinContent(7) << endl;
	cout<< hNJet->GetBinContent(8) << endl;
	cout<< hNJet->GetBinContent(9) << endl;

	//--------------------------------Branching ratio---------------------------------
	/*histo_BR_4Top = new TH1F(Form("histo_BR_4top"),Form(""),20,0,270);
	  FourTop->Project(Form("histo_BR_4top"),"EVENT",Cut_base+" && nb==2&&nbbar==2&&nWp==2&&nWm==2&&nl==0&&nq==8");
	  histo_BR_4Top_total = new TH1F(Form("histo_BR_4Top_total"),Form(""),20,0,270);
	  FourTop->Project(Form("histo_BR_4Top_total"),"EVENT",Cut_base);

	  double nev_4T = histo_BR_4Top->GetEntries();
	  double nev_4T_tot = histo_BR_4Top_total->GetEntries();

	  histo_BR_ttbar = new TH1F(Form("histo_BR_ttbar"),Form(""),20,0,270);
	  TTbar->Project(Form("histo_BR_ttbar"),"EVENT",Cut_base+" && nb==1&&nbbar==1&&nWp==1&&nWm==1&&nl==0&&nq==8");
	  histo_BR_ttbar_total = new TH1F(Form("histo_BR_ttbar_total"),Form(""),20,0,270);
	  TTbar->Project(Form("histo_BR_ttbar_total"),"EVENT",Cut_base);

	  double nev_tt = histo_BR_ttbar->GetEntries();
	  double nev_tt_tot = histo_BR_ttbar_total->GetEntries();

	  double TTTT_had = 11454;
	  double TTTT_tot = 59020;
	  double tt_had = 43773;
	  double tt_tot = 96120;

	  cout << nev_4T << " , " << nev_tt << " , " << "channel cut" << endl;
	  cout << nev_4T_tot << " , " << nev_tt_tot << " , " << "total" << endl;
	  cout << "Branching Ratio : " << TTTT_had/TTTT_tot << " , " << tt_had/tt_tot << endl;
	  */
	for(int NT = 0; NT < TreeVar; NT++){
		float nbin[] = {18,8};
		//float xmin[] = {0,0,0,-3,-3,-3};//
		//float xmax[] = {350,350,350,3,3,3};//
		float xmin = 0;//
		float xmax[] = {18,8};//
		float size = 0.8;
		int TTTT_c = 4;
		int ttbar_c = 2;
		int dyjets_c = 1;
		int wjets_c = 6;
		//double ymax[] = {0.5,0.5,0.5,0.15,0.15,0.15};//

		canvIso_[NT] = new TCanvas();
		//canvIso_[NT]->SetLogy();
		canvIso_[NT]->SetFillColor(0);
		canvIso_[NT]->SetBorderMode(2);
		canvIso_[NT]->SetFrameFillStyle(3);
		canvIso_[NT]->SetFrameBorderMode(0);
		canvIso_[NT]->SetTickx(1);
		canvIso_[NT]->SetTicky(1);
		canvIso_[NT]->Update();
		canvIso_[NT]->RedrawAxis();
		canvIso_[NT]->GetFrame()->Draw();

		l_[NT] = new TLegend(lx1,ly1,lx2,ly2);
		l_[NT]->SetFillColor(0);
		l_[NT]->SetLineColor(0);
		l_[NT]->SetLineStyle(kSolid);
		l_[NT]->SetLineWidth(1);
		l_[NT]->SetFillStyle(1);
		l_[NT]->SetTextFont(2);
		l_[NT]->SetTextSize(0.035);

		//histo_TTTT[NT] = new TH1F(Form("histo_TTTT_%d",NT),Form(""),nbin,xmin[NT],xmax[NT]);
		histo_TTTT[NT] = new TH1F(Form("histo_TTTT_%d",NT),Form(""),nbin[NT],xmin,xmax[NT]);
		FourTop->Project(Form("histo_TTTT_%d",NT),Variable[NT]);
		histo_TTTT[NT]->SetLineWidth(2);
		l_[NT]->AddEntry(histo_TTTT[NT],"TTTT "+Cut_base_text, "lp");
		histo_TTTT[NT]->SetLineColor(TTTT_c);
		histo_TTTT[NT]->SetMarkerColor(TTTT_c);
		//histo_TTTT[NT]->GetYaxis()->SetTitle("Events");
		//histo_TTTT[NT]->GetXaxis()->SetTitle(Variable[NT]);
		//------------------------------------------------------------------

		histo_DYJets[NT] = new TH1F(Form("histo_DYJets_%d",NT),Form(""),nbin[NT],xmin,xmax[NT]);
		DYJets->Project(Form("histo_DYJets_%d",NT),Variable[NT]);
		histo_DYJets[NT]->SetLineWidth(2);
		l_[NT]->AddEntry(histo_DYJets[NT],"DYJets "+Cut_base_text, "lp");
		histo_DYJets[NT]->SetLineColor(dyjets_c);
		histo_DYJets[NT]->SetMarkerColor(dyjets_c);
		//---------------------------------------------------------------------

		histo_WJets[NT] = new TH1F(Form("histo_WJets_%d",NT),Form(""),nbin[NT],xmin,xmax[NT]);
		WJets->Project(Form("histo_WJets_%d",NT),Variable[NT]);
		histo_WJets[NT]->SetLineWidth(2);
		l_[NT]->AddEntry(histo_WJets[NT],"WJets "+Cut_base_text, "lp");
		histo_WJets[NT]->SetLineColor(wjets_c);
		histo_WJets[NT]->SetMarkerColor(wjets_c);
		histo_WJets[NT]->GetYaxis()->SetTitle("Events");
		histo_WJets[NT]->GetXaxis()->SetTitle(Variable[NT]);

		//---------------------------------------------------------------------
		//histo_ttbar[NT] = new TH1F(Form("histo_ttbar_%d",NT),Form(""),nbin,xmin[NT],xmax[NT]);
		histo_ttbar[NT] = new TH1F(Form("histo_ttbar_%d",NT),Form(""),nbin[NT],xmin,xmax[NT]);
		TTbar->Project(Form("histo_ttbar_%d",NT),Variable[NT]);
		histo_ttbar[NT]->SetLineWidth(2);
		l_[NT]->AddEntry(histo_ttbar[NT],"ttbar "+Cut_base_text, "lp");
		histo_ttbar[NT]->SetLineColor(ttbar_c);
		histo_ttbar[NT]->SetMarkerColor(ttbar_c);
		//histo_ttbar[NT]->GetYaxis()->SetTitle("Events");
		//histo_ttbar[NT]->GetXaxis()->SetTitle(Variable[NT]);

		double nev_1 = histo_TTTT[NT]->GetEntries();
		histo_TTTT[NT]->Scale(1/nev_1);
		double nev_2 = histo_ttbar[NT]->GetEntries();
		histo_ttbar[NT]->Scale(1/nev_2);
		double nev_3 = histo_DYJets[NT]->GetEntries();
		histo_DYJets[NT]->Scale(1/nev_3);
		double nev_4 = histo_WJets[NT]->GetEntries();
		histo_WJets[NT]->Scale(1/nev_4);

		double ymax = 0;
		ymax = histo_WJets[NT]->GetMaximum();

		histo_WJets[NT]->SetMaximum(ymax*1.2);
		histo_WJets[NT]->Draw();
		histo_TTTT[NT]->Draw("same");
		histo_DYJets[NT]->Draw("same");
		histo_ttbar[NT]->Draw("same");
		lt1.DrawLatex(xx_1,yy_1,Form("4top ")+Cut_base_text);
		lt2.DrawLatex(x_1,y_1,"CMS");
		lt3.DrawLatex(x_2,y_2,"Preliminary");
		lt4.DrawLatex(tx,ty,"13 TeV");
		l_[NT]->Draw();
		canvIso_[NT]->Print(Variable[NT]+".png");
	}
	cout<<"13TeV"<<endl;
}
