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
	//--------------------------------------Set Maximum histo_TTTT[NV][nCh]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.62;
	float ly1 = 0.61;
	float lx2 = 0.94;
	float ly2 = 0.78;

	const int NVar = 7;//Variable number
	const int nChannel = 2;//Cut_base_Trig
	const int nSample = 4;//=======================check
	const int nQCD = 19;

	TH1F *histo_Sample[NVar][nChannel][nSample];
	TH1F *histo_Sample_gen[NVar][nChannel][nSample];

	TH1F *histo_nQCD[NVar][nChannel][nQCD];
	TH1F *histo_nQCD_gen[NVar][nChannel][nQCD];

	TH1F *histo_QCD[NVar][nChannel];

	/*TH1F *histo_BR_4Top;
	  TH1F *histo_BR_ttbar;
	  TH1F *histo_BR_4Top_total;
	  TH1F *histo_BR_ttbar_total;*/

	TCanvas *canv_[NVar][nChannel];
	TLegend *l_[NVar][nChannel];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	//PATH_samples = "/cms/scratch/yjeong/";//KISTI
	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";//KISTI

	TString Ch_Cut;
	TString nlep_Ch;

	//TString Variable[] = {"Muon_Pt","Electron_Pt","Jet_Pt","Muon_Eta","Electron_Eta","Jet_Eta"};
	//TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]","Jet_Pt[10]"};
	TString Variable[NVar] = {"NJet","NBJet","NLooseMuon+NLooseElectron","NMuon+NElectron","NVertex","NW","Nt"};

	TString Cut_base[nChannel] = {"IsHadronTrig == 1","IsMuonTrig == 1 && IsElectronTrig == 1"};

	TString Cut_base_text[nChannel] = {"Hadronic","Leptonic"};

	////////////////////////////////Get Samples/////////////////////////////////
	const int Sample_Num = 23;//========================check
	TString Sample_name[Sample_Num] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu","vallot","TT_powheg","DYJets","WJets"};//=====================check

	TString Legend_Name[nSample] = {"TTTT","ttbar","DYJets","WJets"};//========================check

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

	for(int i = 7; i < 17; i++){
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
	for(int nCh = 0; nCh < nChannel; nCh++){
		for(int NV = 0; NV < NVar; NV++){
			float nbin[] = {18,8,6,6,50,8,8};
			float xmin = 0;//
			float xmax[] = {18,8,6,6,50,8,8};//
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;

			canv_[NV][nCh] = new TCanvas();
			//canv_[NV][nCh]->SetLogy();
			canv_[NV][nCh]->SetFillColor(0);
			canv_[NV][nCh]->SetBorderMode(2);
			canv_[NV][nCh]->SetFrameFillStyle(3);
			canv_[NV][nCh]->SetFrameBorderMode(0);
			canv_[NV][nCh]->SetTickx(1);
			canv_[NV][nCh]->SetTicky(1);
			canv_[NV][nCh]->Update();
			canv_[NV][nCh]->RedrawAxis();
			canv_[NV][nCh]->GetFrame()->Draw();

			l_[NV][nCh] = new TLegend(lx1,ly1,lx2,ly2);
			l_[NV][nCh]->SetFillColor(0);
			l_[NV][nCh]->SetLineColor(0);
			l_[NV][nCh]->SetLineStyle(kSolid);
			l_[NV][nCh]->SetLineWidth(1);
			l_[NV][nCh]->SetFillStyle(1);
			l_[NV][nCh]->SetTextFont(2);
			l_[NV][nCh]->SetTextSize(0.035);

			for(int nSam = 0; nSam < nSample; nSam++){//=============================check
				histo_Sample[NV][nCh][nSam] = new TH1F(Form("histo_Sample_%d_%d_%d",NV,nCh,nSam),Form(""),nbin[NV],xmin,xmax[NV]);
				tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",NV,nCh,nSam),Variable[NV],Cut_base[nCh]);
				histo_Sample[NV][nCh][nSam]->SetLineWidth(2);
				if(nSam == 0){
					histo_Sample[NV][nCh][nSam]->SetLineColor(TTTT_c);
					histo_Sample[NV][nCh][nSam]->SetMarkerColor(TTTT_c);
				}
				if(nSam == 1){
					histo_Sample[NV][nCh][nSam]->SetLineColor(ttbar_c);
					histo_Sample[NV][nCh][nSam]->SetMarkerColor(ttbar_c);
				}
				if(nSam == 2){
					histo_Sample[NV][nCh][nSam]->SetLineColor(dyjets_c);
					histo_Sample[NV][nCh][nSam]->SetMarkerColor(dyjets_c);
				}
				if(nSam == 3){
					histo_Sample[NV][nCh][nSam]->SetLineColor(wjets_c);
					histo_Sample[NV][nCh][nSam]->SetMarkerColor(wjets_c);
				}
				histo_Sample[NV][nCh][nSam]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
				histo_Sample[NV][nCh][nSam]->GetXaxis()->SetTitle(Variable[NV]);
				l_[NV][nCh]->AddEntry(histo_Sample[NV][nCh][nSam],Legend_Name[nSam], "lp");
			}

			//----------------------------------------------------------------

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[NV][nCh][NQ] = new TH1F(Form("histo_nQCD_%d_%d_%d",NV,nCh,NQ),Form(""),nbin[NV],xmin,xmax[NV]);
				tree[NQ]->Project(Form("histo_nQCD_%d_%d_%d",NV,nCh,NQ),Variable[NV],Cut_base[nCh]);
			}

			//---------------------------------------------------------------------

			histo_QCD[NV][nCh] = new TH1F(Form("histo_QCD_%d_%d",NV,nCh),Form(""),nbin[NV],xmin,xmax[NV]);
			histo_QCD[NV][nCh]->SetLineColor(qcd_c);
			histo_QCD[NV][nCh]->SetLineWidth(2);
			histo_QCD[NV][nCh]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[NV][nCh]->GetXaxis()->SetTitle(Variable[NV]);
			l_[NV][nCh]->AddEntry(histo_QCD[NV][nCh],"QCD ", "lp");

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_QCD[NV][nCh]->Add(histo_nQCD[NV][nCh][NQ]);
			}

			TString Sample_Name[] = {"TTTT","ttbar","DYJets","WJets"};
			for(int nSam = 0; nSam < nSample; nSam++){
				cout<<"original "<<Sample_Name[nSam] <<" Entries: "<< histo_Sample[NV][nCh][nSam]->GetEntries()<<endl;
			}

			cout<<"original QCD Entries: "<<histo_QCD[NV][nCh]->GetEntries()<<endl;

			double nev_[nSample];
			for(int nSam = 0; nSam < nSample; nSam++){
				nev_[nSam] = histo_Sample[NV][nCh][nSam]->GetEntries();
				histo_Sample[NV][nCh][nSam]->Scale(1/nev_[nSam]);
			}

			double nev_qcd = histo_QCD[NV][nCh]->GetEntries();
			histo_QCD[NV][nCh]->Scale(1/nev_qcd);

			double ymax[] = {0.8,1.1,0.8,1.1,0.1,0.8,0.9};//NJet,NBJet,NLooseMuon+NLooseElectron,NMuon+NElectron,NVertex,NW,Nt
			//double ymax = 0;
			//ymax = histo_QCD[NV][nCh]->GetMaximum();
			//histo_QCD[NV][nCh]->SetMaximum(ymax*1.3);
			histo_QCD[NV][nCh]->SetMaximum(ymax[NV]);
			histo_QCD[NV][nCh]->Draw();
			for(int nSam = 0; nSam < nSample; nSam++){
				histo_Sample[NV][nCh][nSam]->Draw("same");
			}

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text[nCh]);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[NV][nCh]->Draw();
			canv_[NV][nCh]->SaveAs(Save_dir+Cut_base_text[nCh]+"_"+Variable[NV]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
