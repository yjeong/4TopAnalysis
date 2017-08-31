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
	const int nSample = 4;//=======================check
	const int nQCD = 19;

	TH1F *histo_Sample[TreeVar][CutVar][nSample];
	TH1F *histo_Sample_gen[TreeVar][CutVar][nSample];

	TH1F *histo_nQCD[TreeVar][CutVar][nQCD];
	TH1F *histo_nQCD_gen[TreeVar][CutVar][nQCD];

	TH1F *histo_QCD[TreeVar][CutVar];

	/*TH1F *histo_BR_4Top;
	  TH1F *histo_BR_ttbar;
	  TH1F *histo_BR_4Top_total;
	  TH1F *histo_BR_ttbar_total;*/

	TCanvas *canv_[TreeVar][CutVar];
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
	TString Cut_base[] = {"IsHadronTrig==1"};
	ttttHad_Ch = "nl==0 && nq==8";
	ttbarHad_Ch = "nl==0 && nq==4";
	nlep_Ch = "nl==0";

	Cut_base_text = "Hadronic";

	////////////////////////////////Get Samples/////////////////////////////////
	const int Sample_Num = 23;//========================check
	TString Sample_name[Sample_Num] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu","vallot","TT_powheg","DYJets","WJets"};//=====================check

	TString Legend_Name[] = {"TTTT","ttbar","DYJets","WJets"};//========================check

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
	tree[19]->Project(Form("hNJet"),"NJet");
	cout<<"NJet events number"<<endl;

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
			float xmin = 0;//
			float xmax[] = {18,8,6,6};//
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;

			canv_[NT][NC] = new TCanvas();
			//canv_[NT][NC]->SetLogy();
			canv_[NT][NC]->SetFillColor(0);
			canv_[NT][NC]->SetBorderMode(2);
			canv_[NT][NC]->SetFrameFillStyle(3);
			canv_[NT][NC]->SetFrameBorderMode(0);
			canv_[NT][NC]->SetTickx(1);
			canv_[NT][NC]->SetTicky(1);
			canv_[NT][NC]->Update();
			canv_[NT][NC]->RedrawAxis();
			canv_[NT][NC]->GetFrame()->Draw();

			l_[NT][NC] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NT][NC]->SetFillColor(0);
			l_[NT][NC]->SetLineColor(0);
			l_[NT][NC]->SetLineStyle(kSolid);
			l_[NT][NC]->SetLineWidth(1);
			l_[NT][NC]->SetFillStyle(1);
			l_[NT][NC]->SetTextFont(2);
			l_[NT][NC]->SetTextSize(0.035);

			for(int nSam = 0; nSam < nSample; nSam++){//=============================check
				histo_Sample[NT][NC][nSam] = new TH1F(Form("histo_Sample_%d_%d_%d",NT,NC,nSam),Form(""),nbin[NT],xmin,xmax[NT]);
				tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NT,NC,nSam),Variable[NT],Cut_base[NC]);
				histo_Sample[NT][NC][nSam]->SetLineWidth(2);
				if(nSam == 0){
					histo_Sample[NT][NC][nSam]->SetLineColor(TTTT_c);
					histo_Sample[NT][NC][nSam]->SetMarkerColor(TTTT_c);
				}
				if(nSam == 1){
					histo_Sample[NT][NC][nSam]->SetLineColor(ttbar_c);
					histo_Sample[NT][NC][nSam]->SetMarkerColor(ttbar_c);
				}
				if(nSam == 2){
					histo_Sample[NT][NC][nSam]->SetLineColor(dyjets_c);
					histo_Sample[NT][NC][nSam]->SetMarkerColor(dyjets_c);
				}
				if(nSam == 3){
					histo_Sample[NT][NC][nSam]->SetLineColor(wjets_c);
					histo_Sample[NT][NC][nSam]->SetMarkerColor(wjets_c);
				}
				histo_Sample[NT][NC][nSam]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
				histo_Sample[NT][NC][nSam]->GetXaxis()->SetTitle(Variable[NT]);
				l_[NT][NC]->AddEntry(histo_Sample[NT][NC][nSam],Legend_Name[nSam], "lp");
			}

			//----------------------------------------------------------------

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[NT][NC][NQ] = new TH1F(Form("histo_nQCD_%d_%d_%d",NT,NC,NQ),Form(""),nbin[NT],xmin,xmax[NT]);
				tree[NQ]->Project(Form("histo_nQCD_%d_%d_%d",NT,NC,NQ),Variable[NT],Cut_base[NC]);
			}

			//---------------------------------------------------------------------

			histo_QCD[NT][NC] = new TH1F(Form("histo_QCD_%d_%d",NT,NC),Form(""),nbin[NT],xmin,xmax[NT]);
			histo_QCD[NT][NC]->SetLineColor(qcd_c);
			histo_QCD[NT][NC]->SetLineWidth(2);
			histo_QCD[NT][NC]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NT][NC]->GetXaxis()->SetTitle(Variable[NT]);
			l_[NT][NC]->AddEntry(histo_QCD[NT][NC],"QCD ", "lp");

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_QCD[NT][NC]->Add(histo_nQCD[NT][NC][NQ]);
			}

			TString Sample_Name[] = {"TTTT","ttbar","DYJets","WJets"};
			for(int nSam = 0; nSam < nSample; nSam++){
				cout<<"original "<<Sample_Name[nSam] <<" Entries: "<< histo_Sample[NT][NC][nSam]->GetEntries()<<endl;
			}

			cout<<"original QCD Entries: "<<histo_QCD[NT][NC]->GetEntries()<<endl;

			double nev_[nSample];
			for(int nSam = 0; nSam < nSample; nSam++){
				nev_[nSam] = histo_Sample[NT][NC][nSam]->GetEntries();
				histo_Sample[NT][NC][nSam]->Scale(1/nev_[nSam]);
			}

			double nev_qcd = histo_QCD[NT][NC]->GetEntries();
			histo_QCD[NT][NC]->Scale(1/nev_qcd);

			double ymax[] = {0.7,0.5,0.8,1.1};
			//double ymax = 0;
			//ymax = histo_QCD[NT][NC]->GetMaximum();
			//histo_QCD[NT][NC]->SetMaximum(ymax*1.3);
			histo_QCD[NT][NC]->SetMaximum(ymax[NT]);
			histo_QCD[NT][NC]->Draw();
			for(int nSam = 0; nSam < nSample; nSam++){
				histo_Sample[NT][NC][nSam]->Draw("same");
			}

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NT][NC]->Draw();
			canv_[NT][NC]->SaveAs(Save_dir+Variable[NT]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
