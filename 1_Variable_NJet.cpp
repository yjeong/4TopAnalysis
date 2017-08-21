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
	//--------------------------------------Set Maximum histo_TTTT[NT][NC]---------------------------------
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
	const int CutVar = 2;

	TH1F *histo_TTTT[TreeVar][CutVar];
	TH1F *histo_ttbar[TreeVar][CutVar];
	TH1F *histo_DYJets[TreeVar][CutVar];
	TH1F *histo_WJets[TreeVar][CutVar];
	TH1F *histo_QCDPt80to120EM[TreeVar][CutVar];
	TH1F *histo_QCDPt80to120Mu[TreeVar][CutVar];

	/*TH1F *histo_BR_4Top;
	  TH1F *histo_BR_ttbar;
	  TH1F *histo_BR_4Top_total;
	  TH1F *histo_BR_ttbar_total;*/

	TCanvas *canvIso_[TreeVar][CutVar];
	TLegend *l_[TreeVar][CutVar];

	TString PATH_samples;
	//PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	PATH_samples = "/cms/scratch/yjeong/";//KISTI

	TString Cut_base_text;
	TString Ch_Cut;
	TString nlep_Ch;

	//TString Variable[] = {"Muon_Pt","Electron_Pt","Jet_Pt","Muon_Eta","Electron_Eta","Jet_Eta"};
	//TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]","Jet_Pt[10]"};
	TString Variable[] = {"NJet","NBJet"};

	TString Cut_base[] = {" Jet_Pt[0] > 80 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50 ","IsHadronTrig==1"};
	ttttHad_Ch = "nl==0 && nq==8";
	ttbarHad_Ch = "nl==0 && nq==4";
	nlep_Ch = "nl==0";

	Cut_base_text = "Hadronic";

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
	for(int NC = 0; NC < CutVar; NC++){
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
			int qcdPt80to120EM_c = 3;
			int qcdPt80to120Mu_c = 7;
			//double ymax[] = {0.5,0.5,0.5,0.15,0.15,0.15};//

			canvIso_[NT][NC] = new TCanvas();
			//canvIso_[NT][NC]->SetLogy();
			canvIso_[NT][NC]->SetFillColor(0);
			canvIso_[NT][NC]->SetBorderMode(2);
			canvIso_[NT][NC]->SetFrameFillStyle(3);
			canvIso_[NT][NC]->SetFrameBorderMode(0);
			canvIso_[NT][NC]->SetTickx(1);
			canvIso_[NT][NC]->SetTicky(1);
			canvIso_[NT][NC]->Update();
			canvIso_[NT][NC]->RedrawAxis();
			canvIso_[NT][NC]->GetFrame()->Draw();

			l_[NT][NC] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NT][NC]->SetFillColor(0);
			l_[NT][NC]->SetLineColor(0);
			l_[NT][NC]->SetLineStyle(kSolid);
			l_[NT][NC]->SetLineWidth(1);
			l_[NT][NC]->SetFillStyle(1);
			l_[NT][NC]->SetTextFont(2);
			l_[NT][NC]->SetTextSize(0.035);

			//histo_TTTT[NT][NC] = new TH1F(Form("histo_TTTT_%d_%d",NT,NC),Form(""),nbin,xmin[NT][NC],xmax[NT][NC]);
			histo_TTTT[NT][NC] = new TH1F(Form("histo_TTTT_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			FourTop->Project(Form("histo_TTTT_%d_%d",NT,NC),Variable[NT],Cut_base[NC]);
			histo_TTTT[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_TTTT[NT][NC],"TTTT", "lp");
			histo_TTTT[NT][NC]->SetLineColor(TTTT_c);
			histo_TTTT[NT][NC]->SetMarkerColor(TTTT_c);
			//histo_TTTT[NT][NC]->GetYaxis()->SetTitle("Events");
			//histo_TTTT[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			//------------------------------------------------------------------

			histo_DYJets[NT][NC] = new TH1F(Form("histo_DYJets_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			DYJets->Project(Form("histo_DYJets_%d_%d",NT,NC),Variable[NT],Cut_base[NC]);
			histo_DYJets[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_DYJets[NT][NC],"DYJets", "lp");
			histo_DYJets[NT][NC]->SetLineColor(dyjets_c);
			histo_DYJets[NT][NC]->SetMarkerColor(dyjets_c);
			histo_DYJets[NT][NC]->GetYaxis()->SetTitle("Events");
			histo_DYJets[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			//---------------------------------------------------------------------

			histo_WJets[NT][NC] = new TH1F(Form("histo_WJets_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			WJets->Project(Form("histo_WJets_%d_%d",NT,NC),Variable[NT],Cut_base[NC]);
			histo_WJets[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_WJets[NT][NC],"WJets", "lp");
			histo_WJets[NT][NC]->SetLineColor(wjets_c);
			histo_WJets[NT][NC]->SetMarkerColor(wjets_c);
			histo_WJets[NT][NC]->GetYaxis()->SetTitle("Events");
			histo_WJets[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			//---------------------------------------------------------------------

			histo_QCDPt80to120EM[NT][NC] = new TH1F(Form("histo_QCDPt80to120EM_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			QCDPt80to120EM->Project(Form("histo_QCDPt80to120EM_%d_%d",NT,NC),Variable[NT],Cut_base[NC]);
			histo_QCDPt80to120EM[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_QCDPt80to120EM[NT][NC],"QCDPt80to120EM", "lp");
			histo_QCDPt80to120EM[NT][NC]->SetLineColor(qcdPt80to120EM_c);
			histo_QCDPt80to120EM[NT][NC]->SetMarkerColor(qcdPt80to120EM_c);
			histo_QCDPt80to120EM[NT][NC]->GetYaxis()->SetTitle("Events");
			histo_QCDPt80to120EM[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			//------------------------------------------------------------------
			histo_QCDPt80to120Mu[NT][NC] = new TH1F(Form("histo_QCDPt80to120Mu_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			QCDPt80to120Mu->Project(Form("histo_QCDPt80to120Mu_%d_%d",NT,NC),Variable[NT],Cut_base[NC]);
			histo_QCDPt80to120Mu[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_QCDPt80to120Mu[NT][NC],"QCDPt80to120Mu", "lp");
			histo_QCDPt80to120Mu[NT][NC]->SetLineColor(qcdPt80to120Mu_c);
			histo_QCDPt80to120Mu[NT][NC]->SetMarkerColor(qcdPt80to120Mu_c);
			histo_QCDPt80to120Mu[NT][NC]->GetYaxis()->SetTitle("Events");
			histo_QCDPt80to120Mu[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);


			//---------------------------------------------------------------------
			//histo_ttbar[NT][NC] = new TH1F(Form("histo_ttbar_%d_%d",NT,NC),Form(""),nbin,xmin[NT][NC],xmax[NT][NC]);
			histo_ttbar[NT][NC] = new TH1F(Form("histo_ttbar_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			TTbar->Project(Form("histo_ttbar_%d_%d",NT,NC),Variable[NT],Cut_base[NC]);
			histo_ttbar[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_ttbar[NT][NC],"ttbar", "lp");
			histo_ttbar[NT][NC]->SetLineColor(ttbar_c);
			histo_ttbar[NT][NC]->SetMarkerColor(ttbar_c);
			histo_ttbar[NT][NC]->GetYaxis()->SetTitle("Events");
			histo_ttbar[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);


			cout<<"original DYJets Entries: "<<histo_DYJets[NT][NC]->GetEntries()<<endl;
			cout<<"original WJets Entries: "<<histo_WJets[NT][NC]->GetEntries()<<endl;
			cout<<"original QCDPt80to120EM Entries: "<<histo_QCDPt80to120EM[NT][NC]->GetEntries()<<endl;
			cout<<"original QCDPt80to120Mu Entries: "<<histo_QCDPt80to120Mu[NT][NC]->GetEntries()<<endl;
			cout<<"original ttbar Entries: "<<histo_ttbar[NT][NC]->GetEntries()<<endl;
			cout<<"original TTTT Entries: "<<histo_TTTT[NT][NC]->GetEntries()<<endl;
			/*cout<<""<<endl;
			  cout<<"origin-1st bin: "<<histo_DYJets[NT][NC]->GetBinContent(1)<<endl;
			  cout<<"origin-2nd bin: "<<histo_DYJets[NT][NC]->GetBinContent(2)<<endl;
			  cout<<""<<endl;
			  cout<<"DYJets yield Integral(1,nbin+1): "<<histo_DYJets[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"WJets yield Integral(1,nbin+1): "<<histo_WJets[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"ttbar yield Integral(1,nbin+1): "<<histo_ttbar[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"TTTT yield Integral(1,nbin+1): "<<histo_TTTT[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;*/

			cout<<""<<endl;
			cout<<""<<endl;
			double nev_1 = histo_TTTT[NT][NC]->GetEntries();
			histo_TTTT[NT][NC]->Scale(1/nev_1);
			double nev_2 = histo_ttbar[NT][NC]->GetEntries();
			histo_ttbar[NT][NC]->Scale(1/nev_2);
			double nev_3 = histo_DYJets[NT][NC]->GetEntries();
			histo_DYJets[NT][NC]->Scale(1/nev_3);
			double nev_4 = histo_WJets[NT][NC]->GetEntries();
			histo_WJets[NT][NC]->Scale(1/nev_4);
			double nev_5 = histo_QCDPt80to120EM[NT][NC]->GetEntries();
			histo_QCDPt80to120EM[NT][NC]->Scale(1/nev_5);
			double nev_6 = histo_QCDPt80to120Mu[NT][NC]->GetEntries();
			histo_QCDPt80to120Mu[NT][NC]->Scale(1/nev_6);

			/*double scale_1 = 1/(histo_TTTT[NT][NC]->Integral(1,nbin[NT][NC]+1));
			  histo_TTTT[NT][NC]->Scale(scale_1);
			  double scale_2 = 1/(histo_ttbar[NT][NC]->Integral(1,nbin[NT][NC]+1));
			  histo_ttbar[NT][NC]->Scale(scale_2);
			  double scale_3 = 1/(histo_DYJets[NT][NC]->Integral(1,nbin[NT][NC]+1));
			  histo_DYJets[NT][NC]->Scale(scale_3);
			  double scale_4 = 1/(histo_WJets[NT][NC]->Integral(1,nbin[NT][NC]+1));
			  histo_WJets[NT][NC]->Scale(scale_4);*/


			/*cout<<"Norm-1st bin: "<<histo_DYJets[NT][NC]->GetBinContent(1)<<endl;
			  cout<<"Norm-2nd bin: "<<histo_DYJets[NT][NC]->GetBinContent(2)<<endl;
			  cout<<""<<endl;
			  cout<<"DYJets yield Integral(1,nbin+1): "<<histo_DYJets[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"WJets yield Integral(1,nbin+1): "<<histo_WJets[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"ttbar yield Integral(1,nbin+1): "<<histo_ttbar[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"TTTT yield Integral(1,nbin+1): "<<histo_TTTT[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<""<<endl;
			  cout<<"DYJets yield GetSum: "<<histo_DYJets[NT][NC]->GetSum()<<endl;
			  cout<<"WJets yield GetSum: "<<histo_WJets[NT][NC]->GetSum()<<endl;
			  cout<<"ttbar yield GetSum: "<<histo_ttbar[NT][NC]->GetSum()<<endl;
			  cout<<"TTTT yield GetSum: "<<histo_TTTT[NT][NC]->GetSum()<<endl;*/

			double ymax = 0;
			ymax = histo_WJets[NT][NC]->GetMaximum();

			histo_WJets[NT][NC]->SetMaximum(ymax*1.2);
			histo_WJets[NT][NC]->Draw();
			histo_TTTT[NT][NC]->Draw("same");
			histo_QCDPt80to120EM[NT][NC]->Draw("same");
			histo_QCDPt80to120Mu[NT][NC]->Draw("same");
			histo_ttbar[NT][NC]->Draw("same");
			histo_DYJets[NT][NC]->Draw("same");

			lt1.DrawLatex(xx_1,yy_1,Form("4top ")+Cut_base_text);
			//lt2.DrawLatex(x_1,y_1,"CMS");
			//lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV");
			l_[NT][NC]->Draw();
			canvIso_[NT][NC]->Print(Variable[NT]+Cut_base[NC]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
