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
	int NJet[] = {6};

	TH1F *histo_TTTT[JetPtCut][NJetNum];
	TH1F *histo_TTTT_gen[JetPtCut][NJetNum];
	//TH1F *histo_TTTT_eff[JetPtCut][NJetNum];

	TH1F *histo_ttbar[JetPtCut][NJetNum];
	TH1F *histo_ttbar_gen[JetPtCut][NJetNum];
	//TH1F *histo_ttbar_eff[JetPtCut][NJetNum];

	TH1F *histo_DYJets[JetPtCut][NJetNum];
	TH1F *histo_DYJets_gen[JetPtCut][NJetNum];

	TH1F *histo_WJets[JetPtCut][NJetNum];
	TH1F *histo_WJets_gen[JetPtCut][NJetNum];

	TH1F *histo_TTJets_aMC[JetPtCut][NJetNum];
	TH1F *histo_TTJets_aMC_gen[JetPtCut][NJetNum];

	TCanvas *canvIso_[JetPtCut][NJetNum];
	TLegend *l_[JetPtCut][NJetNum];

	TString PATH_samples;
	PATH_samples = "/xrootd/store/user/yjeong/4TopFullHadronic/";//KISTI

	TString Cut_base;
	TString Cut_base_text;
	TString tttt_Ch_Cut;
	TString ttbar_Ch_Cut;
	TString Jet_HT_Cut;
	TString HadronTrig;
	TString Jet_mass;
	TString NBJet;
	TString nRecolep;
	TString defualt;

	//TString Variable[] = {"Jet_Pt[0]","Jet_Pt[1]", "Jet_Pt[2]","Jet_Pt[3]","Jet_Pt[4]","Jet_Pt[5]","Jet_Pt[6]","Jet_Pt[7]","Jet_Pt[8]","Jet_Pt[9]"};
	TString Variable;
	Variable = "Jet_HT";

	TString Pt_Cut[] = {" Jet_Pt[0] > 80 &&"," Jet_Pt[0] > 80 && Jet_Pt[1] > 70 &&"," Jet_Pt[0] > 80 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 &&"," Jet_Pt[0] > 80 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50 &&"};
	//TString Pt_Cut[] = {"&& Jet_Pt[0] > 80 && Jet_Pt[1] > 70 && Jet_Pt[2] > 60 && Jet_Pt[3] > 50 &&"};

	//Cut_base = "fabs(Muon_Pt) > 30 && fabs(Muon_Eta) < 2.4 &&";
	ttttHad_Ch = "nq==8 && nl==0 &&";
	ttbarHad_Ch = "nq==4 && nl==0 &&";
	defualt = "NJet";
	nRecolep = "(NLooseMuon+NLooseElectron)==0 &&";

	Jet_HT_Cut = "Jet_HT > 500 &&";
	//Jet_mass = "Jet_mass_sum[5] > 400 && Jet_mass_sum[6] > 450 && Jet_mass_sum[7] > 500 && Jet_mass_sum[8] > 500 && Jet_mass_sum[9] > 500 && Jet_mass_sum[10] > 500 && Jet_mass_sum[11] > 500 &&";
	//Jet_mass = "Jet_mass_tot > 500 &&";
	NBJet = "NBJet>=2 &&";

	HadronTrig = "IsHadronTrig==1 &&";

	Cut_base_text = "Hadronic";

	TFile h1(PATH_samples+"vallot.root");
	TFile h2(PATH_samples+"TT_powheg.root");
	TFile h3(PATH_samples+"DYJets.root");
	TFile h4(PATH_samples+"WJets.root");
	TFile h5(PATH_samples+"TTJets_aMC.root");

	TTree *FourTop = (TTree*)h1.Get("TopTree/events");
	TTree *TTbar = (TTree*)h2.Get("TopTree/events");
	TTree *DYJets = (TTree*)h3.Get("TopTree/events");
	TTree *WJets = (TTree*)h4.Get("TopTree/events");
	TTree *TTJets_aMC = (TTree*)h5.Get("TopTree/events");

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
			float nbin = 60;
			float xmin = 0;
			float xmax = 2800;
			float size = 0.8;
			int TTTT_c = 4;
			int ttbar_c = 2;
			int dyjets_c = 1;
			int wjets_c = 6;
			int ttjets_c = 3;

			canvIso_[NJ][NPt] = new TCanvas();
			canvIso_[NJ][NPt]->SetLogy();
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

			histo_DYJets[NJ][NPt] = new TH1F(Form("histo_DYJets_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			DYJets->Project(Form("histo_DYJets_%d_%d",NJ,NPt),Variable,nRecolep+Pt_Cut[NPt]+HadronTrig+Jet_HT_Cut+NBJet+Form(" NJet>=%d",NJet[NJ]));
			histo_DYJets[NJ][NPt]->SetLineWidth(2);
			histo_DYJets[NJ][NPt]->SetLineColor(dyjets_c);
			//histo_DYJets[NJ][NPt]->SetFillColor(dyjets_c);
			histo_DYJets[NJ][NPt]->SetMarkerColor(dyjets_c);
			l_[NJ][NPt]->AddEntry(histo_DYJets[NJ][NPt],"DYJets "+Cut_base_text, "lp");

			histo_DYJets_gen[NJ][NPt] = new TH1F(Form("histo_DYJets_gen_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			DYJets->Project(Form("histo_DYJets_gen_%d_%d",NJ,NPt),Variable);
			//-----------------------------------------------

			histo_TTJets_aMC[NJ][NPt] = new TH1F(Form("histo_TTJets_aMC_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			TTJets_aMC->Project(Form("histo_TTJets_aMC_%d_%d",NJ,NPt),Variable,nRecolep+Pt_Cut[NPt]+HadronTrig+Jet_HT_Cut+NBJet+Form(" NJet>=%d",NJet[NJ]));
			histo_TTJets_aMC[NJ][NPt]->SetLineWidth(2);
			histo_TTJets_aMC[NJ][NPt]->SetLineColor(ttjets_c);
			//histo_TTJets_aMC[NJ][NPt]->SetFillColor(ttjets_c);
			histo_TTJets_aMC[NJ][NPt]->SetMarkerColor(ttjets_c);
			l_[NJ][NPt]->AddEntry(histo_TTJets_aMC[NJ][NPt],"TTJets_aMC "+Cut_base_text, "lp");

			histo_TTJets_aMC_gen[NJ][NPt] = new TH1F(Form("histo_TTJets_aMC_gen_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			TTJets_aMC->Project(Form("histo_TTJets_aMC_gen_%d_%d",NJ,NPt),Variable);


			//---------------------------------------

			histo_WJets[NJ][NPt] = new TH1F(Form("histo_WJets_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			WJets->Project(Form("histo_WJets_%d_%d",NJ,NPt),Variable,nRecolep+Pt_Cut[NPt]+HadronTrig+Jet_HT_Cut+NBJet+Form(" NJet>=%d",NJet[NJ]));
			histo_WJets[NJ][NPt]->SetLineWidth(2);
			histo_WJets[NJ][NPt]->SetLineColor(wjets_c);
			//histo_WJets[NJ][NPt]->SetFillColor(wjets_c);
			histo_WJets[NJ][NPt]->SetMarkerColor(wjets_c);
			l_[NJ][NPt]->AddEntry(histo_WJets[NJ][NPt],"WJets "+Cut_base_text, "lp");

			histo_WJets_gen[NJ][NPt] = new TH1F(Form("histo_WJets_gen_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			WJets->Project(Form("histo_WJets_gen_%d_%d",NJ,NPt),Variable);

			//-------------------------------------
			histo_TTTT[NJ][NPt] = new TH1F(Form("histo_TTTT_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			//histo_TTTT[NJ][NPt]->Sumw2();
			FourTop->Project(Form("histo_TTTT_%d_%d",NJ,NPt),Variable,nRecolep+ttttHad_Ch+Pt_Cut[NPt]+HadronTrig+Jet_HT_Cut+NBJet+Form(" NJet>=%d",NJet[NJ]));
			histo_TTTT[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_TTTT[NJ][NPt],"TTTT "+Cut_base_text, "lp");
			histo_TTTT[NJ][NPt]->SetLineColor(TTTT_c);
			//histo_TTTT[NJ][NPt]->SetFillColor(TTTT_c);
			histo_TTTT[NJ][NPt]->SetMarkerColor(TTTT_c);

			histo_TTTT_gen[NJ][NPt] = new TH1F(Form("histo_TTTT_gen_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			//histo_TTTT_gen[NJ][NPt]->Sumw2();
			FourTop->Project(Form("histo_TTTT_gen_%d_%d",NJ,NPt),Variable,ttttHad_Ch+defualt);

			//-----------------------------------
			histo_ttbar[NJ][NPt] = new TH1F(Form("histo_ttbar_%d_%d",NJ,NPt),Form("Jet_HT"),nbin,xmin,xmax);
			//histo_ttbar[NJ][NPt]->Sumw2();
			TTbar->Project(Form("histo_ttbar_%d_%d",NJ,NPt),Variable,nRecolep+ttbarHad_Ch+Pt_Cut[NPt]+HadronTrig+Jet_HT_Cut+NBJet+Form(" NJet>=%d",NJet[NJ]));
			histo_ttbar[NJ][NPt]->SetLineWidth(2);
			l_[NJ][NPt]->AddEntry(histo_ttbar[NJ][NPt],"ttbar "+Cut_base_text, "lp");
			histo_ttbar[NJ][NPt]->SetLineColor(ttbar_c);
			//histo_ttbar[NJ][NPt]->SetFillColor(ttbar_c);
			histo_ttbar[NJ][NPt]->SetMarkerColor(ttbar_c);
			histo_ttbar[NJ][NPt]->GetYaxis()->SetTitle(Form("# of Normalized Events"));
			histo_ttbar[NJ][NPt]->GetXaxis()->SetTitle(Pt_Cut[NPt]);

			histo_ttbar_gen[NJ][NPt] = new TH1F(Form("histo_ttbar_gen_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			//histo_ttbar_gen[NJ][NPt]->Sumw2();
			TTbar->Project(Form("histo_ttbar_gen_%d_%d",NJ,NPt),Variable,ttbarHad_Ch+defualt);
			//----------------------------------

			/*double nev_1 = histo_TTTT[NJ][NPt]->GetEntries();
			  histo_TTTT[NJ][NPt]->Scale(1/nev_1);
			  double nev_2 = histo_ttbar[NJ][NPt]->GetEntries();
			  histo_ttbar[NJ][NPt]->Scale(1/nev_2);
			  double nev_3 = histo_TTTT_gen[NJ][NPt]->GetEntries();
			  histo_TTTT_gen[NJ][NPt]->Scale(1/nev_3);
			  double nev_4 = histo_ttbar_gen[NJ][NPt]->GetEntries();
			  histo_ttbar_gen[NJ][NPt]->Scale(1/nev_4);*/
			/*
			   histo_TTTT_eff[NJ][NPt] = new TH1F(Form("histo_TTTT_eff_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			   histo_TTTT_eff[NJ][NPt]->GetYaxis()->SetTitle("Efficiency");
			   histo_TTTT_eff[NJ][NPt]->GetXaxis()->SetTitle(Variable);
			   histo_TTTT_eff[NJ][NPt]->SetLineWidth(2);

			   histo_ttbar_eff[NJ][NPt] = new TH1F(Form("histo_ttbar_eff_%d_%d",NJ,NPt),Form(""),nbin,xmin,xmax);
			//l_[NJ][NPt]->AddEntry(histo_TTTT_eff[NJ][NPt],"TTTT "+Variable, "lp");
			//l_[NJ][NPt]->AddEntry(histo_ttbar_eff[NJ][NPt],"ttbar "+Variable, "lp");

			histo_ttbar_eff[NJ][NPt]->SetLineWidth(2);
			histo_ttbar_eff[NJ][NPt]->SetLineColor(ttbar_c);
			histo_ttbar_eff[NJ][NPt]->SetMarkerColor(ttbar_c);

			histo_TTTT_eff[NJ][NPt]->Divide(histo_TTTT[NJ][NPt],histo_TTTT_gen[NJ][NPt],1,1,"b");
			histo_ttbar_eff[NJ][NPt]->Divide(histo_ttbar[NJ][NPt],histo_ttbar_gen[NJ][NPt],1,1,"b");*/

			double TTTTS1 = histo_TTTT[NJ][NPt]->GetEntries();
			double TTTTS0 = histo_TTTT_gen[NJ][NPt]->GetEntries();
			double ttbarS1 = histo_ttbar[NJ][NPt]->GetEntries();
			double ttbarS0 = histo_ttbar_gen[NJ][NPt]->GetEntries();
			double DYJetsS1 = histo_DYJets[NJ][NPt]->GetEntries();
			double DYJetsS0 = histo_DYJets_gen[NJ][NPt]->GetEntries();
			double WJetsS1 = histo_WJets[NJ][NPt]->GetEntries();
			double WJetsS0 = histo_WJets_gen[NJ][NPt]->GetEntries();
			double TTJets_aMCS1 = histo_TTJets_aMC[NJ][NPt]->GetEntries();
			double TTJets_aMCS0 = histo_TTJets_aMC_gen[NJ][NPt]->GetEntries();
			double BR = 0.6741;//theoritical value W->Hadron
			double lumi = 36000;//pb-1
			//4top->all hadrons = BR^4.
			//ttbar->all hadrons = BR^2.

			cout<<""<<endl;
			cout<< (TTTTS1/TTTTS0)*100<<"%"<<", "<<NBJet<<", "<<NBJet<<", "<<Pt_Cut[NPt]<<" , "<<Jet_HT_Cut<<", "<<HadronTrig<<" , "<<Form("NJet>=%d",NJet[NJ])<<" , "<<ttttHad_Ch<<", 4 top " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<< (ttbarS1/ttbarS0)*100<<"%"<<", "<<NBJet<<", "<<NBJet<<", "<<Pt_Cut[NPt]<<" , "<<Jet_HT_Cut <<", "<<HadronTrig<<" , "<<Form("NJet>=%d",NJet[NJ])<<" , "<<ttbarHad_Ch <<", ttbar " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			cout<< (DYJetsS1/DYJetsS0)*100<<"%"<<", "<<NBJet<<", "<<NBJet<<", "<<Pt_Cut[NPt]<<" , "<<Jet_HT_Cut <<", "<<HadronTrig<<" , "<<Form("NJet>=%d",NJet[NJ])<<", DYJets " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			cout<< (WJetsS1/WJetsS0)*100<<"%"<<", "<<NBJet<<", "<<NBJet<<", "<<Pt_Cut[NPt]<<" , "<<Jet_HT_Cut <<", "<<HadronTrig<<" , "<<Form("NJet>=%d",NJet[NJ])<<", WJets " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			cout<< (TTJets_aMCS1/TTJets_aMCS0)*100<<"%"<<", "<<NBJet<<", "<<NBJet<<", "<<Pt_Cut[NPt]<<" , "<<Jet_HT_Cut <<", "<<HadronTrig<<" , "<<Form("NJet>=%d",NJet[NJ])<<", WJets " <<endl;
			cout<<""<<endl;
			cout<<""<<endl;


			cout<<"number of 4top expected events: "<< 0.009103*lumi*BR*BR*BR*BR*(TTTTS1/TTTTS0) <<endl;
			cout<<""<<endl;
			cout<<"number of ttbar expected events: "<< 832.76*lumi*BR*BR*(ttbarS1/ttbarS0) <<endl;
			cout<<""<<endl;
			cout<<"number of DYJets expected events: "<< 6025.2*lumi*(DYJetsS1/DYJetsS0) <<endl;
			cout<<""<<endl;
			cout<<"number of WJets expected events: "<< 61526.7*lumi*(WJetsS1/WJetsS0) <<endl;
			cout<<""<<endl;
			cout<<"number of TTJets_aMC expected events: "<< 831.76*lumi*(TTJets_aMCS1/TTJets_aMCS0) <<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			histo_TTTT[NJ][NPt]->Scale(0.009103*lumi*BR*BR*BR*BR/TTTTS0);
			histo_ttbar[NJ][NPt]->Scale(832.76*lumi*BR*BR/ttbarS0);
			histo_DYJets[NJ][NPt]->Scale(6025.2*lumi/DYJetsS0);
			histo_WJets[NJ][NPt]->Scale(61526.7*lumi/WJetsS0);
			histo_TTJets_aMC[NJ][NPt]->Scale(831.76*lumi/WJetsS0);

			cout<<"4top yield Integral(1,nbin+1): "<<histo_TTTT[NJ][NPt]->Integral(1,nbin+1)<<endl;
			//cout<<"4top yield Integral: "<<histo_TTTT[NJ][NPt]->Integral()<<endl;
			//cout<<"4top yield GetSum: "<<histo_TTTT[NJ][NPt]->GetSum()<<endl;
			cout<<""<<endl;
			cout<<"ttbar yield Integral(1,nbin+1): "<<histo_ttbar[NJ][NPt]->Integral(1,nbin+1)<<endl;
			//cout<<"ttbar yield Integral: "<<histo_ttbar[NJ][NPt]->Integral()<<endl;
			//cout<<"ttbar yield GetSum: "<<histo_ttbar[NJ][NPt]->GetSum()<<endl;
			cout<<""<<endl;
			cout<<"DYJets yield Integral(1,nbin+1): "<<histo_DYJets[NJ][NPt]->Integral(1,nbin+1)<<endl;
			cout<<""<<endl;
			cout<<"WJets yield Integral(1,nbin+1): "<<histo_WJets[NJ][NPt]->Integral(1,nbin+1)<<endl;
			cout<<""<<endl;
			cout<<"TTJets_aMC yield Integral(1,nbin+1): "<<histo_TTJets_aMC[NJ][NPt]->Integral(1,nbin+1)<<endl;
			cout<<""<<endl;
			cout<<""<<endl;
			cout<<""<<endl;

			double ymax = 0;
			ymax = histo_ttbar[NJ][NPt]->GetMaximum();
			//double ymin = 0;
			//ymin = histo_TTTT[NJ][NPt]->GetMinimum();

			histo_ttbar[NJ][NPt]->SetMaximum(ymax*100);
			histo_ttbar[NJ][NPt]->SetMinimum(0.01);
			histo_ttbar[NJ][NPt]->Draw();
			histo_DYJets[NJ][NPt]->Draw("same");
			histo_WJets[NJ][NPt]->Draw("same");
			histo_TTJets_aMC[NJ][NPt]->Draw("same");
			histo_TTTT[NJ][NPt]->Draw("same");

			/*
			   double ymax = 0;
			   ymax = histo_TTTT[NJ][NPt]->GetMaximum();

			   histo_TTTT_eff[NJ][NPt]->SetMaximum(1.5);
			   histo_TTTT_eff[NJ][NPt]->Draw();
			   histo_ttbar_eff[NJ][NPt]->Draw("same");*/

			lt1.DrawLatex(xx_1,yy_1,HadronTrig+NBJet+Form("NJet>=%d",NJet[NJ]));
			//lt2.DrawLatex(x_1,y_1,"CMS");
			//lt3.DrawLatex(x_2,y_2,"Preliminary");
			lt4.DrawLatex(tx,ty,"13 TeV");
			l_[NJ][NPt]->Draw();
			canvIso_[NJ][NPt]->Print("Eff"+Pt_Cut[NPt]+"_"+Form("NJet>=%d",NJet[NJ])+".png");
		}
	}
	cout<<"13TeV"<<endl;
}
