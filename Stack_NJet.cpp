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
	//--------------------------------------Set Maximum histo_TTTT1[NPt]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.62;
	float ly1 = 0.44;
	float lx2 = 0.94;
	float ly2 = 0.78;

	const int JetPtCut = 10;//Pt Cut number
	//const int NJetNum = 5;//Variable
	//int NJet[] = {4,5,6,7,8};

	TH1F *histo_TTTT1[JetPtCut];
	TH1F *histo_ttbar1[JetPtCut];

	TH1F *histo_TTTT2[JetPtCut];
	TH1F *histo_ttbar2[JetPtCut];
	TH1F *histo_TTTT3[JetPtCut];
	TH1F *histo_ttbar3[JetPtCut];
	TH1F *histo_TTTT4[JetPtCut];
	TH1F *histo_ttbar4[JetPtCut];
	TH1F *histo_TTTT5[JetPtCut];
	TH1F *histo_ttbar5[JetPtCut];

	TCanvas *canvIso_[JetPtCut];
	TLegend *l_[JetPtCut];

	TString PATH_samples;
	PATH_samples = "/cms/scratch/yjeong/CMSSW_8_0_26_patch1/src/CATTools/CatAnalyzer/prod/";//KISTI
	//PATH_samples = "/d3/scratch/$USER/CMSSW_8_0_26_patch1/src/CATTools/CatAnalyzer/prod/";//KNU

	//TString Cut_base;
	TString Cut_base_text;
	TString tttt_Ch_Cut;
	TString ttbar_Ch_Cut;

	TString NJ4;
	TString NJ5;
	TString NJ6;
	TString NJ7;
	TString NJ8;

	NJ4 = "NJet>=4";
	NJ5 = "NJet>=5";
	NJ6 = "NJet>=6";
	NJ7 = "NJet>=7";
	NJ8 = "NJet>=8";

	TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]"};

	//Cut_base = "fabs(Muon_Pt) > 30 && fabs(Muon_Eta) < 2.4 && ";
	tttt_Ch_Cut = "nq==8 && nl==0 && ";
	ttbar_Ch_Cut = "nq==4 && nl==0 && ";

	Cut_base_text = "Hadronic Ch, ";

	TFile h1(PATH_samples+"vallot.root");
	TFile h2(PATH_samples+"TT_powheg.root");

	TTree *FourTop = (TTree*)h1.Get("TopTree/events");
	TTree *TTbar = (TTree*)h2.Get("TopTree/events");

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

	for(int NPt = 0; NPt < JetPtCut; NPt++){
		float nbin = 20;
		float xmin = 0;
		float xmax = 350-(350-100)/10*NPt;
		//float xmax = 350;
		float size = 0.8;
		int TTTT_c = 4;
		int kRed = 2;
		double nev_1, nev_2, nev_3, nev_4, nev_5;
		double nev_6, nev_7, nev_8, nev_9, nev_10;

		canvIso_[NPt] = new TCanvas();
		//canvIso_[NPt]->SetLogy();
		canvIso_[NPt]->SetFillColor(0);
		canvIso_[NPt]->SetBorderMode(2);
		canvIso_[NPt]->SetFrameFillStyle(3);
		canvIso_[NPt]->SetFrameBorderMode(0);
		canvIso_[NPt]->SetTickx(1);
		canvIso_[NPt]->SetTicky(1);
		canvIso_[NPt]->Update();
		canvIso_[NPt]->RedrawAxis();
		canvIso_[NPt]->GetFrame()->Draw();

		l_[NPt] = new TLegend(lx1,ly1,lx2,ly2);
		l_[NPt]->SetFillColor(0);
		l_[NPt]->SetLineColor(0);
		l_[NPt]->SetLineStyle(kSolid);
		l_[NPt]->SetLineWidth(1);
		l_[NPt]->SetFillStyle(1);
		l_[NPt]->SetTextFont(2);
		l_[NPt]->SetTextSize(0.035);

		histo_TTTT1[NPt] = new TH1F(Form("histo_TTTT1_%d",NPt),Form(""),nbin,xmin,xmax);
		FourTop->Project(Form("histo_TTTT1_%d",NPt),Variable[NPt],tttt_Ch_Cut+NJ4);
		histo_TTTT1[NPt]->SetLineWidth(2);
		l_[NPt]->AddEntry(histo_TTTT1[NPt],"TTTT "+NJ4, "lp");

		histo_TTTT1[NPt]->SetLineColor(12);
		histo_TTTT1[NPt]->SetMarkerColor(12);
		//-
                histo_TTTT2[NPt] = new TH1F(Form("histo_TTTT2_%d",NPt),Form(""),nbin,xmin,xmax);
                FourTop->Project(Form("histo_TTTT2_%d",NPt),Variable[NPt],tttt_Ch_Cut+NJ5);
                histo_TTTT2[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_TTTT2[NPt],"TTTT "+NJ5, "lp");

                histo_TTTT2[NPt]->SetLineColor(13);
                histo_TTTT2[NPt]->SetMarkerColor(13);
		//-
		histo_TTTT3[NPt] = new TH1F(Form("histo_TTTT3_%d",NPt),Form(""),nbin,xmin,xmax);
                FourTop->Project(Form("histo_TTTT3_%d",NPt),Variable[NPt],tttt_Ch_Cut+NJ6);
                histo_TTTT3[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_TTTT3[NPt],"TTTT "+NJ6, "lp");

                histo_TTTT3[NPt]->SetLineColor(14);
                histo_TTTT3[NPt]->SetMarkerColor(14);
		//
		histo_TTTT4[NPt] = new TH1F(Form("histo_TTTT4_%d",NPt),Form(""),nbin,xmin,xmax);
                FourTop->Project(Form("histo_TTTT4_%d",NPt),Variable[NPt],tttt_Ch_Cut+NJ7);
                histo_TTTT4[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_TTTT4[NPt],"TTTT "+NJ7, "lp");

                histo_TTTT4[NPt]->SetLineColor(15);
                histo_TTTT4[NPt]->SetMarkerColor(15);
		//
		histo_TTTT5[NPt] = new TH1F(Form("histo_TTTT5_%d",NPt),Form(""),nbin,xmin,xmax);
                FourTop->Project(Form("histo_TTTT5_%d",NPt),Variable[NPt],tttt_Ch_Cut+NJ8);
                histo_TTTT5[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_TTTT5[NPt],"TTTT "+NJ8, "lp");

                histo_TTTT5[NPt]->SetLineColor(16);
                histo_TTTT5[NPt]->SetMarkerColor(16);
		//-----------------------------------


		histo_ttbar1[NPt] = new TH1F(Form("histo_ttbar1_%d",NPt),Form(""),nbin,xmin,xmax);
		TTbar->Project(Form("histo_ttbar1_%d",NPt),Variable[NPt],ttbar_Ch_Cut+NJ4);
		histo_ttbar1[NPt]->SetLineWidth(2);
		l_[NPt]->AddEntry(histo_ttbar1[NPt],"ttbar "+NJ4, "lp");

		histo_ttbar1[NPt]->SetLineColor(42);
		histo_ttbar1[NPt]->SetMarkerColor(42);

		histo_ttbar1[NPt]->GetYaxis()->SetTitle("Events");
		histo_ttbar1[NPt]->GetXaxis()->SetTitle(Variable[NPt]);
		//-
		histo_ttbar2[NPt] = new TH1F(Form("histo_ttbar2_%d",NPt),Form(""),nbin,xmin,xmax);
                TTbar->Project(Form("histo_ttbar2_%d",NPt),Variable[NPt],ttbar_Ch_Cut+NJ5);
                histo_ttbar2[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_ttbar2[NPt],"ttbar "+NJ5, "lp");

                histo_ttbar2[NPt]->SetLineColor(43);
                histo_ttbar2[NPt]->SetMarkerColor(43);
		//-
		histo_ttbar3[NPt] = new TH1F(Form("histo_ttbar3_%d",NPt),Form(""),nbin,xmin,xmax);
                TTbar->Project(Form("histo_ttbar3_%d",NPt),Variable[NPt],ttbar_Ch_Cut+NJ6);
                histo_ttbar3[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_ttbar3[NPt],"ttbar "+NJ6, "lp");

                histo_ttbar3[NPt]->SetLineColor(44);
                histo_ttbar3[NPt]->SetMarkerColor(44);
		//-
		histo_ttbar4[NPt] = new TH1F(Form("histo_ttbar4_%d",NPt),Form(""),nbin,xmin,xmax);
                TTbar->Project(Form("histo_ttbar4_%d",NPt),Variable[NPt],ttbar_Ch_Cut+NJ7);
                histo_ttbar4[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_ttbar4[NPt],"ttbar "+NJ7, "lp");

                histo_ttbar4[NPt]->SetLineColor(45);
                histo_ttbar4[NPt]->SetMarkerColor(45);
		//-
		histo_ttbar5[NPt] = new TH1F(Form("histo_ttbar5_%d",NPt),Form(""),nbin,xmin,xmax);
                TTbar->Project(Form("histo_ttbar5_%d",NPt),Variable[NPt],ttbar_Ch_Cut+NJ8);
                histo_ttbar5[NPt]->SetLineWidth(2);
                l_[NPt]->AddEntry(histo_ttbar5[NPt],"ttbar "+NJ8, "lp");

                histo_ttbar5[NPt]->SetLineColor(46);
                histo_ttbar5[NPt]->SetMarkerColor(46);

		nev_1 = histo_TTTT1[NPt]->GetEntries();
		histo_TTTT1[NPt]->Scale(1/nev_1);
		nev_2 = histo_TTTT2[NPt]->GetEntries();
		histo_TTTT2[NPt]->Scale(1/nev_2);
		nev_3 = histo_TTTT3[NPt]->GetEntries();
		histo_TTTT3[NPt]->Scale(1/nev_3);
		nev_4 = histo_TTTT4[NPt]->GetEntries();
		histo_TTTT4[NPt]->Scale(1/nev_4);
		nev_5 = histo_TTTT5[NPt]->GetEntries();
		histo_TTTT5[NPt]->Scale(1/nev_5);
		//-----
		nev_6 = histo_ttbar1[NPt]->GetEntries();
		histo_ttbar1[NPt]->Scale(1/nev_6);
		nev_7 = histo_ttbar2[NPt]->GetEntries();
		histo_ttbar2[NPt]->Scale(1/nev_7);
		nev_8 = histo_ttbar3[NPt]->GetEntries();
		histo_ttbar3[NPt]->Scale(1/nev_8);
		nev_9 = histo_ttbar4[NPt]->GetEntries();
		histo_ttbar4[NPt]->Scale(1/nev_9);
		nev_10 = histo_ttbar5[NPt]->GetEntries();
		histo_ttbar5[NPt]->Scale(1/nev_10);

		double ymax = 0;
		ymax = histo_ttbar1[NPt]->GetMaximum();
		histo_ttbar1[NPt]->SetMaximum(ymax*1.1);
		//-----
		histo_ttbar1[NPt]->Draw();
		histo_ttbar2[NPt]->Draw("same");
		histo_ttbar3[NPt]->Draw("same");
		histo_ttbar4[NPt]->Draw("same");
		histo_ttbar5[NPt]->Draw("same");

		histo_TTTT1[NPt]->Draw("same");
		histo_TTTT2[NPt]->Draw("same");
		histo_TTTT3[NPt]->Draw("same");
		histo_TTTT4[NPt]->Draw("same");
		histo_TTTT5[NPt]->Draw("same");

		lt1.DrawLatex(xx_1,yy_1,Form("TTTT & Ttbar, ")+Variable[NPt]);
		//lt1.DrawLatex(xx_1,yy_1,Form("TTTT, ")+Cut_base_text+Variable[NPt]);
		lt2.DrawLatex(x_1,y_1,"CMS");
		lt3.DrawLatex(x_2,y_2,"Preliminary");
		lt4.DrawLatex(tx,ty,"13 TeV");
		l_[NPt]->Draw();
		canvIso_[NPt]->Print(Variable[NPt]+".png");
	}
	cout<<"13TeV"<<endl;
}
