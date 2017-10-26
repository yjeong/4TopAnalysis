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
	//--------------------------------------Set Maximum histo_TTTT[nCh][NVar]---------------------------------
	//float ymin_1 = 0;
	//-----------------------------------------ExtraText---------------------------------------
	float tx = 0.9;
	float ty = 0.94;
	//-------------------------Legend coordinate--------------------
	float lx1 = 0.62;
	float ly1 = 0.61;
	float lx2 = 0.94;
	float ly2 = 0.78;

	const int NVariable = 6;//Pt Cut number
	const int NChannel = 2;
	const int nSample = 4;//==============================check
	const int nQCD = 19;

	TH1F *histo_Sample[NVariable][NChannel][nSample];
	TH1F *histo_Sample_gen[NVariable][NChannel][nSample];

	TH1F *histo_nQCD[NVariable][NChannel][nQCD];
	TH1F *histo_nQCD_gen[NVariable][NChannel][nQCD];

	TH1F *histo_QCD[NVariable][NChannel];

	TCanvas *canv_[NVariable][NChannel];
	TLegend *l_[NVariable][NChannel];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI
	TString Save_dir;
	Save_dir = "/cms/scratch/yjeong/catMacro/plots/";

	TString Variable[NVariable] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]"};

	TString Triger[NChannel] = {"IsHadronTrig == 1","IsMuonTrig == 1 && IsElectronTrig == 1"};

	TString ttttHad_Ch[NChannel] = {"nq==8 && nl==0 &&","nq == 8 && nl == 1 &&"};
	TString ttbarHad_Ch[NChannel] = {"nq==4 && nl==0 && ","nq == 4 && nl == 1 &&"};
	TString nRecolep[NChannel] = {"&& (NLooseMuon+NLooseElectron)==0", "&& (NLooseMuon+NLooseElectron)==1"};

	TString Cut_base_text[NChannel] = {"Hadronic","Leptonic"};

	////////////////////////////////Get Samples/////////////////////////////////
	const int Sample_Num = 23;//================================check
	TString Sample_name[Sample_Num] = {"QCDPt80to120EM","QCDPt80to120Mu","QCDPt1000toInfMu","QCDPt120to170EM","QCDPt120to170Mu","QCDPt15to20Mu","QCDPt170to300EM","QCDPt170to300Mu","QCDPt20to30EM","QCDPt20to30Mu","QCDPt300to470Mu","QCDPt300toInfEM","QCDPt30to50EM","QCDPt30to50Mu","QCDPt470to600Mu","QCDPt50to80EM","QCDPt50to80Mu","QCDPt600to800Mu","QCDPt800to1000Mu","vallot","TT_powheg","DYJets","WJets"};//========================check

	TString Legend_Name[] = {"TTTT","ttbar","DYJets","WJets"};//=================================check

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

	for(int i = 1; i < 17; i++){
		cout<< hNJet->GetBinContent(i) << endl;
	}

	for(int nCh = 0; nCh < NChannel; nCh++){
		for(int NVar = 0; NVar < NVariable; NVar++){
			float nbin[] = {35,35,35,35,35,35,35};
			float xmin = 0;
			//float xmax = 350;
			float xmax = 500-(500-250)/10*NVar;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 3;
			int wjets_c = 6;
			int qcd_c = 1;

			canv_[nCh][NVar] = new TCanvas();
			//canv_[nCh][NVar]->SetLogy();
			canv_[nCh][NVar]->SetFillColor(0);
			canv_[nCh][NVar]->SetBorderMode(2);
			canv_[nCh][NVar]->SetFrameFillStyle(3);
			canv_[nCh][NVar]->SetFrameBorderMode(0);
			canv_[nCh][NVar]->SetTickx(1);
			canv_[nCh][NVar]->SetTicky(1);
			canv_[nCh][NVar]->Update();
			canv_[nCh][NVar]->RedrawAxis();
			canv_[nCh][NVar]->GetFrame()->Draw();

			l_[nCh][NVar] = new TLegend(lx1,ly1,lx2,ly2);
			l_[nCh][NVar]->SetFillColor(0);
			l_[nCh][NVar]->SetLineColor(0);
			l_[nCh][NVar]->SetLineStyle(kSolid);
			l_[nCh][NVar]->SetLineWidth(1);
			l_[nCh][NVar]->SetFillStyle(1);
			l_[nCh][NVar]->SetTextFont(2);
			l_[nCh][NVar]->SetTextSize(0.035);

			for(int nSam = 0; nSam < nSample; nSam++){//=============================check
				histo_Sample[nCh][NVar][nSam] = new TH1F(Form("histo_Sample_%d_%d_%d",nCh,NVar,nSam),Form(""),nbin[NVar],xmin,xmax);
				if(nSam==0)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",nCh,NVar,nSam),Variable[NVar],ttttHad_Ch[nCh]+Triger[nCh]+nRecolep[nCh]);
				if(nSam==1)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",nCh,NVar,nSam),Variable[NVar],ttbarHad_Ch[nCh]+Triger[nCh]+nRecolep[nCh]);
				if(nSam > 1)tree[nSam+19]->Project(Form("histo_Sample_%d_%d_%d",nCh,NVar,nSam),Variable[NVar],Triger[nCh]+nRecolep[nCh]);
				histo_Sample[nCh][NVar][nSam]->SetLineWidth(2);
				if(nSam == 0){
					histo_Sample[nCh][NVar][nSam]->SetLineColor(TTTT_c);
					histo_Sample[nCh][NVar][nSam]->SetMarkerColor(TTTT_c);
				}
				if(nSam == 1){
					histo_Sample[nCh][NVar][nSam]->SetLineColor(ttbar_c);
					histo_Sample[nCh][NVar][nSam]->SetMarkerColor(ttbar_c);
				}
				if(nSam == 2){
					histo_Sample[nCh][NVar][nSam]->SetLineColor(dyjets_c);
					histo_Sample[nCh][NVar][nSam]->SetMarkerColor(dyjets_c);
				}
				if(nSam == 3){
					histo_Sample[nCh][NVar][nSam]->SetLineColor(wjets_c);
					histo_Sample[nCh][NVar][nSam]->SetMarkerColor(wjets_c);
				}
				histo_Sample[nCh][NVar][nSam]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
				histo_Sample[nCh][NVar][nSam]->GetXaxis()->SetTitle(Variable[NVar]);
				l_[nCh][NVar]->AddEntry(histo_Sample[nCh][NVar][nSam],Legend_Name[nSam], "lp");
			}

			//----------------------------------------------------------------

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_nQCD[nCh][NVar][NQ] = new TH1F(Form("histo_nQCD_%d_%d_%d",nCh,NVar,NQ),Form(""),nbin[NVar],xmin,xmax);
				tree[NQ]->Project(Form("histo_nQCD_%d_%d_%d",nCh,NVar,NQ),Variable[NVar],Triger[nCh]+nRecolep[nCh]);
			}

			//-----------------------------------------------------------------

			histo_QCD[nCh][NVar] = new TH1F(Form("histo_QCD_%d_%d",nCh,NVar),Form(""),nbin[NVar],xmin,xmax);
			histo_QCD[nCh][NVar]->SetLineColor(qcd_c);
			histo_QCD[nCh][NVar]->SetLineWidth(2);
			histo_QCD[nCh][NVar]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_QCD[nCh][NVar]->GetXaxis()->SetTitle(Variable[NVar]);
			l_[nCh][NVar]->AddEntry(histo_QCD[nCh][NVar],"QCD ", "lp");

			for(int NQ = 0; NQ < nQCD; NQ++){
				histo_QCD[nCh][NVar]->Add(histo_nQCD[nCh][NVar][NQ]);
			}

			double nev_[nSample];
			for(int nSam = 0; nSam < nSample; nSam++){
				nev_[nSam] = histo_Sample[nCh][NVar][nSam]->GetEntries();
				histo_Sample[nCh][NVar][nSam]->Scale(1/nev_[nSam]);
			}

			double nev_qcd = histo_QCD[nCh][NVar]->GetEntries();
			histo_QCD[nCh][NVar]->Scale(1/nev_qcd);

			double ymax = 0;
			ymax = histo_Sample[nCh][NVar][1]->GetMaximum();

			histo_Sample[nCh][NVar][1]->SetMaximum(ymax*1.3);
			histo_Sample[nCh][NVar][1]->Draw();
			histo_QCD[nCh][NVar]->Draw("same");
			for(int nSam = 0; nSam < nSample; nSam++){
				if(nSam!=1)histo_Sample[nCh][NVar][nSam]->Draw("same");
			}

			lt1.DrawLatex(xx_1,yy_1,Cut_base_text[nCh]);
			lt2.DrawLatex(x_1,y_1,"CMS");
			lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV, 36 fb^{-1}");
			l_[nCh][NVar]->Draw();
			canv_[nCh][NVar]->SaveAs(Save_dir+Cut_base_text[nCh]+"_"+Variable[NVar]+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
