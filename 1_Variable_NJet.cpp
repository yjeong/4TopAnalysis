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

	const int TreeVar = 4;//Variable number
	const int CutVar = 1;

	TH1F *histo_TTTT[TreeVar][CutVar];
	TH1F *histo_ttbar[TreeVar][CutVar];
	TH1F *histo_DYJets[TreeVar][CutVar];
	TH1F *histo_WJets[TreeVar][CutVar];

	TH1F *histo_QCDPt80to120EM[TreeVar][CutVar];
	TH1F *histo_QCDPt80to120Mu[TreeVar][CutVar];

	TH1F *histo_QCD[TreeVar][CutVar];

	/*TH1F *histo_BR_4Top;
	  TH1F *histo_BR_ttbar;
	  TH1F *histo_BR_4Top_total;
	  TH1F *histo_BR_ttbar_total;*/

	TCanvas *canvIso_[TreeVar][CutVar];
	TLegend *l_[TreeVar][CutVar];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	//PATH_samples = "/cms/scratch/yjeong/";//KISTI
	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";//KISTI

	TString Cut_base_text;
	TString Ch_Cut;
	TString nlep_Ch;

	//TString Variable[] = {"Muon_Pt","Electron_Pt","Jet_Pt","Muon_Eta","Electron_Eta","Jet_Eta"};
	//TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]","Jet_Pt[10]"};
	TString Variable[] = {"NJet","NBJet","NLooseMuon+NLooseElectron","NMuon+NElectron"};

	//TString Cut_base[] = {"IsHadronTrig==1",""," Jet_Pt[0] > 80 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50 "};
	TString Cut_base[] = {"IsHadronTrig==1","IsHadronTrig==1","IsHadronTrig==1","IsHadronTrig==1"};
	ttttHad_Ch = "nl==0 && nq==8";
	ttbarHad_Ch = "nl==0 && nq==4";
	nlep_Ch = "nl==0";

	Cut_base_text = "Hadronic";

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

	//--------------------------------Branching ratio---------------------------------
	/*histo_BR_4Top = new TH1F(Form("histo_BR_4top"),Form(""),20,0,270);
	  tree[0]->Project(Form("histo_BR_4top"),"EVENT",Cut_base+" && nb==2&&nbbar==2&&nWp==2&&nWm==2&&nl==0&&nq==8");
	  histo_BR_4Top_total = new TH1F(Form("histo_BR_4Top_total"),Form(""),20,0,270);
	  tree[0]->Project(Form("histo_BR_4Top_total"),"EVENT",Cut_base);

	  double nev_4T = histo_BR_4Top->GetEntries();
	  double nev_4T_tot = histo_BR_4Top_total->GetEntries();

	  histo_BR_ttbar = new TH1F(Form("histo_BR_ttbar"),Form(""),20,0,270);
	  tree[1]->Project(Form("histo_BR_ttbar"),"EVENT",Cut_base+" && nb==1&&nbbar==1&&nWp==1&&nWm==1&&nl==0&&nq==8");
	  histo_BR_ttbar_total = new TH1F(Form("histo_BR_ttbar_total"),Form(""),20,0,270);
	  tree[2]->Project(Form("histo_BR_ttbar_total"),"EVENT",Cut_base);

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
			float nbin[] = {18,8,6,6};
			//float xmin[] = {0,0,0,-3,-3,-3};//
			//float xmax[] = {350,350,350,3,3,3};//
			float xmin = 0;//
			float xmax[] = {18,8,6,6};//
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;
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
			tree[0]->Project(Form("histo_TTTT_%d_%d",NT,NC),Variable[NT],Cut_base[NT]);
			histo_TTTT[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_TTTT[NT][NC],"TTTT", "lp");
			histo_TTTT[NT][NC]->SetLineColor(TTTT_c);
			histo_TTTT[NT][NC]->SetMarkerColor(TTTT_c);
			histo_TTTT[NT][NC]->GetYaxis()->SetTitle("# of Normalized Events");
			histo_TTTT[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);

			//----------------------------------------------------------------

			histo_ttbar[NT][NC] = new TH1F(Form("histo_ttbar_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
                        tree[1]->Project(Form("histo_ttbar_%d_%d",NT,NC),Variable[NT],Cut_base[NC]);
                        histo_ttbar[NT][NC]->SetLineWidth(2);
                        l_[NT][NC]->AddEntry(histo_ttbar[NT][NC],"ttbar", "lp");
                        histo_ttbar[NT][NC]->SetLineColor(ttbar_c);
                        histo_ttbar[NT][NC]->SetMarkerColor(ttbar_c);
                        histo_ttbar[NT][NC]->GetYaxis()->SetTitle("# of Normalized Events");
                        histo_ttbar[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);

			//------------------------------------------------------------------

			histo_DYJets[NT][NC] = new TH1F(Form("histo_DYJets_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			tree[2]->Project(Form("histo_DYJets_%d_%d",NT,NC),Variable[NT],Cut_base[NT]);
			histo_DYJets[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_DYJets[NT][NC],"DYJets", "lp");
			histo_DYJets[NT][NC]->SetLineColor(dyjets_c);
			histo_DYJets[NT][NC]->SetMarkerColor(dyjets_c);
			histo_DYJets[NT][NC]->GetYaxis()->SetTitle("# of Normalized Events");
			histo_DYJets[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			//---------------------------------------------------------------------

			histo_WJets[NT][NC] = new TH1F(Form("histo_WJets_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			tree[3]->Project(Form("histo_WJets_%d_%d",NT,NC),Variable[NT],Cut_base[NT]);
			histo_WJets[NT][NC]->SetLineWidth(2);
			l_[NT][NC]->AddEntry(histo_WJets[NT][NC],"WJets", "lp");
			histo_WJets[NT][NC]->SetLineColor(wjets_c);
			histo_WJets[NT][NC]->SetMarkerColor(wjets_c);
			histo_WJets[NT][NC]->GetYaxis()->SetTitle("# of Normalized Events");
			histo_WJets[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			//---------------------------------------------------------------------

			histo_QCDPt80to120EM[NT][NC] = new TH1F(Form("histo_QCDPt80to120EM_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			tree[4]->Project(Form("histo_QCDPt80to120EM_%d_%d",NT,NC),Variable[NT],Cut_base[NT]);
			//------------------------------------------------------------------
			histo_QCDPt80to120Mu[NT][NC] = new TH1F(Form("histo_QCDPt80to120Mu_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			tree[5]->Project(Form("histo_QCDPt80to120Mu_%d_%d",NT,NC),Variable[NT],Cut_base[NT]);

			//---------------------------------------------------------------------

			/*cout<<""<<endl;
			  cout<<"origin-1st bin: "<<histo_DYJets[NT][NC]->GetBinContent(1)<<endl;
			  cout<<"origin-2nd bin: "<<histo_DYJets[NT][NC]->GetBinContent(2)<<endl;
			  cout<<""<<endl;
			  cout<<"DYJets yield Integral(1,nbin+1): "<<histo_DYJets[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"WJets yield Integral(1,nbin+1): "<<histo_WJets[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"ttbar yield Integral(1,nbin+1): "<<histo_ttbar[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;
			  cout<<"TTTT yield Integral(1,nbin+1): "<<histo_TTTT[NT][NC]->Integral(1,nbin[NT][NC]+1)<<endl;*/

			histo_QCD[NT][NC] = new TH1F(Form("histo_QCD_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			histo_QCD[NT][NC]->SetLineColor(qcd_c);
			histo_QCD[NT][NC]->SetLineWidth(2);
			histo_QCD[NT][NC]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			l_[NT][NC]->AddEntry(histo_QCD[NT][NC],"QCD ", "lp");

			histo_QCD[NT][NC]->Add(histo_QCDPt80to120Mu[NT][NC]);
			histo_QCD[NT][NC]->Add(histo_QCDPt80to120EM[NT][NC]);

			cout<<"original DYJets Entries: "<<histo_DYJets[NT][NC]->GetEntries()<<endl;
			cout<<"original WJets Entries: "<<histo_WJets[NT][NC]->GetEntries()<<endl;
			cout<<"original ttbar Entries: "<<histo_ttbar[NT][NC]->GetEntries()<<endl;
			cout<<"original TTTT Entries: "<<histo_TTTT[NT][NC]->GetEntries()<<endl;
			cout<<"original QCDM Entries: "<<histo_QCD[NT][NC]->GetEntries()<<endl;

			double nev_1 = histo_TTTT[NT][NC]->GetEntries();
			histo_TTTT[NT][NC]->Scale(1/nev_1);
			double nev_2 = histo_ttbar[NT][NC]->GetEntries();
			histo_ttbar[NT][NC]->Scale(1/nev_2);
			double nev_3 = histo_DYJets[NT][NC]->GetEntries();
			histo_DYJets[NT][NC]->Scale(1/nev_3);
			double nev_4 = histo_WJets[NT][NC]->GetEntries();
			histo_WJets[NT][NC]->Scale(1/nev_4);
			double nev_5 = histo_QCD[NT][NC]->GetEntries();
			histo_QCD[NT][NC]->Scale(1/nev_5);

			double ymax = 0;
			ymax = histo_QCD[NT][NC]->GetMaximum();

			histo_QCD[NT][NC]->SetMaximum(ymax*1.3);
			histo_QCD[NT][NC]->Draw();
			histo_DYJets[NT][NC]->Draw("same");
			histo_TTTT[NT][NC]->Draw("same");
			histo_WJets[NT][NC]->Draw("same");
			histo_ttbar[NT][NC]->Draw("same");

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NT][NC]->Draw();
			canvIso_[NT][NC]->SaveAs(Save_dir+Variable[NT]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
