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

	const int JetPtCut = 35;//Pt Cut number
	const int NJetNum = 1;//Variable
	//int NJet[] = {4,5,6,7,8,9,10};
	int NJet[] = {6};

	double cut_pt = 0;
	double S[JetPtCut][NJetNum]={0,};
	double B[JetPtCut][NJetNum]={0,};
	double S_[JetPtCut][NJetNum]={0,};
	double B_[JetPtCut][NJetNum]={0,};
	double S_ex[JetPtCut][NJetNum]={0,};
	double B_ex[JetPtCut][NJetNum]={0,};

	double Significance[JetPtCut][NJetNum]={0,};
	double Significance_[JetPtCut][NJetNum]={0,};
	double Significance_ex[JetPtCut][NJetNum]={0,};

	TH1F *histo_TTTT[JetPtCut][NJetNum];
	TH1F *histo_ttbar[JetPtCut][NJetNum];
	TH1F *histo_TTTT_tot[JetPtCut][NJetNum];
	TH1F *histo_ttbar_tot[JetPtCut][NJetNum];
	TH1F *histo_TTTT_gen[JetPtCut][NJetNum];
	TH1F *histo_ttbar_gen[JetPtCut][NJetNum];

	TCanvas *canvIso_[JetPtCut][NJetNum];
	TLegend *l_[JetPtCut][NJetNum];

	TString PATH_samples;
	PATH_samples = "/cms/scratch/yjeong/CMSSW_8_0_26_patch1/src/CATTools/CatAnalyzer/prod/";//KISTI

	TString Cut_base_text;
	TString ttttHad_Ch;
	TString ttbarHad_Ch;

	//TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]"};
	TString Variable;
	Variable = "Jet_HT";

	//TString Pt_Cut[] = {"Jet_Pt[0] > 100 &&","Jet_Pt[0] > 100 && Jet_Pt[1] > 80 &&","Jet_Pt[0] > 100 && Jet_Pt[1] > 80 && Jet_Pt[2] > 70 &&","Jet_Pt[0] > 100 && Jet_Pt[1] > 80 && Jet_Pt[2] > 70 && Jet_Pt[3] > 60 &&",""};

	//Cut_base = "fabs(Muon_Pt) > 30 && fabs(Muon_Eta) < 2.4 &&";
	ttttHad_Ch = "nq==8 && nl==0 ";
	ttbarHad_Ch = "nq==4 && nl==0 ";

	TString HadronTrig;
	HadronTrig = "&& IsHadronTrig==1 ";

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

	for(int NJ = 0; NJ < NJetNum; NJ++){
		for(int NPt = 0; NPt < JetPtCut; NPt++){
			float nbin = 20;
			float xmin = 0;
			float xmax = 2800;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			static int count;
			static int count_;

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

			histo_TTTT[NJ][NPt] = new TH1F(Form("histo_TTTT_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			FourTop->Project(Form("histo_TTTT_%d_%d",NJ,NPt),Variable,ttttHad_Ch+Form("&& Jet_Pt[2]>%f",cut_pt)+HadronTrig+Form("&& NJet>=%d",NJet[NJ]));
			histo_TTTT[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_TTTT[NJ][NPt],"TTTT "+Variable, "lp");
			histo_TTTT[NJ][NPt]->SetLineColor(TTTT_c);
			histo_TTTT[NJ][NPt]->SetMarkerColor(TTTT_c);

			histo_TTTT_tot[NJ][NPt] = new TH1F(Form("histo_TTTT_tot_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			FourTop->Project(Form("histo_TTTT_tot_%d_%d",NJ,NPt),Variable,ttttHad_Ch+HadronTrig+Form("&& NJet>=%d",NJet[NJ]));
			histo_TTTT_gen[NJ][NPt] = new TH1F(Form("histo_TTTT_gen_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			FourTop->Project(Form("histo_TTTT_gen_%d_%d",NJ,NPt),Variable,ttttHad_Ch);

			//-----------------------------------
			histo_ttbar[NJ][NPt] = new TH1F(Form("histo_ttbar_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			TTbar->Project(Form("histo_ttbar_%d_%d",NJ,NPt),Variable,ttbarHad_Ch+Form("&& Jet_Pt[2]>%f",cut_pt)+HadronTrig+Form("&& NJet>=%d",NJet[NJ]));
			histo_ttbar[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_ttbar[NJ][NPt],"ttbar "+Variable, "lp");
			/*histo_ttbar[NJ][NPt]->SetLineColor(ttbar_c);
			  histo_ttbar[NJ][NPt]->SetMarkerColor(ttbar_c);
			  histo_ttbar[NJ][NPt]->GetYaxis()->SetTitle(Variable+Form(" Events"));
			  histo_ttbar[NJ][NPt]->GetXaxis()->SetTitle(Pt_Cut[NPt]);*/

			histo_ttbar_tot[NJ][NPt] = new TH1F(Form("histo_ttbar_tot_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			TTbar->Project(Form("histo_ttbar_tot_%d_%d",NJ,NPt),Variable,ttbarHad_Ch+HadronTrig+Form("&& NJet>=%d",NJet[NJ]));
			histo_ttbar_gen[NJ][NPt] = new TH1F(Form("histo_ttbar_gen_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			TTbar->Project(Form("histo_ttbar_gen_%d_%d",NJ,NPt),Variable,ttbarHad_Ch);

			double BR = 0.6741;

			double nev_1 = histo_TTTT[NJ][NPt]->GetEntries();
			histo_TTTT[NJ][NPt]->Scale(1/nev_1);
			double nev_2 = histo_ttbar[NJ][NPt]->GetEntries();
			histo_ttbar[NJ][NPt]->Scale(1/nev_2);

			S[NJ][NPt] = (double)histo_TTTT[NJ][NPt]->GetEntries();
			B[NJ][NPt] = (double)histo_ttbar[NJ][NPt]->GetEntries();
			S_[NJ][NPt] = (double)S[NJ][NPt]/histo_TTTT_tot[NJ][NPt]->GetEntries();
			B_[NJ][NPt] = (double)B[NJ][NPt]/histo_ttbar_tot[NJ][NPt]->GetEntries();
			S_ex[NJ][NPt] = (double)9*10*BR*BR*BR*BR*(S[NJ][NPt]/histo_TTTT_gen[NJ][NPt]->GetEntries());
			B_ex[NJ][NPt] = (double)832000*10*BR*BR*(B[NJ][NPt]/histo_ttbar_gen[NJ][NPt]->GetEntries());

			//if((S[NJ][NPt]+B[NJ][NPt])>0) Significance[NJ][NPt] = S[NJ][NPt]/sqrt(S[NJ][NPt]+B[NJ][NPt]);
			if((S_[NJ][NPt]+B_[NJ][NPt])>0) Significance_[NJ][NPt] = S_[NJ][NPt]/sqrt(S_[NJ][NPt]+B_[NJ][NPt]);
			if((S_ex[NJ][NPt]+B_ex[NJ][NPt])>0) Significance_ex[NJ][NPt] = S_ex[NJ][NPt]/sqrt(S_ex[NJ][NPt]+B_ex[NJ][NPt]);

			cut_pt+=10;

			cout<<"Significance of Pt(Norm_1, )"<<++count<<" : "<<Significance_[NJ][NPt]<<endl;
			cout<<"Significance of Pt(Expected ev, )"<<++count_<<" : "<<Significance_ex[NJ][NPt]<<endl;

			/*
			   double ymax = 0;
			   ymax = histo_ttbar[NJ][NPt]->GetMaximum();

			   histo_ttbar[NJ][NPt]->SetMaximum(ymax*1.1);
			   histo_ttbar[NJ][NPt]->Draw();
			   histo_TTTT[NJ][NPt]->Draw("same");

			   lt1.DrawLatex(xx_1,yy_1,Cut_base_text+HadronTrig+Form("NJet>=%d",NJet[NJ]));
			   lt2.DrawLatex(x_1,y_1,"CMS");
			   lt3.DrawLatex(x_2,y_2,"Preliminary");
			   lt4.DrawLatex(tx,ty,"13 TeV");
			   l_[NJ][NPt]->Draw();
			   canvIso_[NJ][NPt]->Print("Pt"+Pt_Cut[NPt]+HadronTrig+Form("NJet>=%d",NJet[NJ])+".png");*/
		}
	}
	cout<<"13TeV"<<endl;
}
