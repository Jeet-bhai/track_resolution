
//Barak, Jeet
//------------------

#include "PadMxN.h"

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

//------------------
//N.B. dupl_cut_qop is given in percent; dupl_cut_angle is given in mRad
void track_resolutions_rs(float dupl_cut_qop = 5, float dupl_cut_angle = 2, int use_bg = 0){

  //Define Style
  gStyle->SetOptStat(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameLineWidth(2);
  gStyle->SetLabelSize(0.035,"X");
  gStyle->SetLabelSize(0.035,"Y");
  //gStyle->SetLabelOffset(0.01,"X");
  //gStyle->SetLabelOffset(0.01,"Y");
  gStyle->SetTitleXSize(0.04);
  gStyle->SetTitleXOffset(0.9);
  gStyle->SetTitleYSize(0.04);
  gStyle->SetTitleYOffset(0.9);

  //Define histograms
  TH1 *p_res_seed[5];
  TH1 *p_res_trk[5];
  TH1 *p_res_true[5];
  TH1 *p_seed[5];
  TH1 *p_trk[5];
  TH1 *p_true[5];
  TH1 *p_mc[5];
  TH2 *pz_ratio_seed[5];
  TH2 *pz_ratio_track[5];
  TH2 *pz_ratio_true[5];
  TH2 *pt_ratio_seed[5];
  TH2 *pt_ratio_track[5];
  TH2 *pt_ratio_true[5];
  TH1 *theta_res_seed[5];
  TH1 *theta_res_trk[5];
  TH1 *theta_res_true[5];
  TH1 *theta_seed[5];
  TH1 *theta_trk[5];
  TH1 *theta_true[5];
  TH1 *theta_mc[5];
  TH1 *phi_res_seed[5];
  TH1 *phi_res_trk[5];
  TH1 *phi_res_true[5];
  TH1 *phi_seed[5];
  TH1 *phi_trk[5];
  TH1 *phi_true[5];
  TH1 *phi_mc[5];
  TH1 *r_seed[5];
  TH1 *r_trk[5];
  TH1 *r_true[5];
  TH1 *z_seed[5];
  TH1 *z_trk[5];
  TH1 *z_true[5];
  TH1 *charge_seed[5];
  TH1 *charge_trk[5];
  TH1 *charge_true[5];
  TH1 *num_track[5];
  TH2 *num_trk_vs_particle_eta[5];
  TH2 *unique_trk_vs_particle_eta[5];
  TH1 *efficiency_vs_eta_track[5];
  TH1 *efficiency_vs_eta_track2[5];
  TH1 *efficiency_vs_eta_real_Seed[5];
  TH1 *efficiency_vs_eta_real_Seed2[5];
  TH1 *efficiency_vs_eta_truth_Seed[5];
  TH1 *efficiency_vs_eta_truth_Seed2[5];
  TH1 *efficiency_vs_phi_track[5];
  TH1 *efficiency_vs_phi_track2[5];
  TH1 *efficiency_vs_phi_real_Seed[5];
  TH1 *efficiency_vs_phi_real_Seed2[5];
  TH1 *efficiency_vs_phi_truth_Seed[5];
  TH1 *efficiency_vs_phi_truth_Seed2[5];
  TH1 *efficiency_vs_eta_gentrack[5];
  TH1 *efficiency_vs_eta_gentrack2[5];
  TH1 *efficiency_vs_eta_real_genSeed[5];
  TH1 *efficiency_vs_eta_real_genSeed2[5];
  TH1 *efficiency_vs_eta_truth_genSeed[5];
  TH1 *efficiency_vs_eta_truth_genSeed2[5];
  TH1 *efficiency_vs_phi_gentrack[5];
  TH1 *efficiency_vs_phi_gentrack2[5];
  TH1 *efficiency_vs_phi_real_genSeed[5];
  TH1 *efficiency_vs_phi_real_genSeed2[5];
  TH1 *efficiency_vs_phi_truth_genSeed[5];
  TH1 *efficiency_vs_phi_truth_genSeed2[5];
  TH1 *eta_efficiency_gentrack[5]; //Ratio histogram
  TH1 *eta_efficiency_real_genseed[5]; //Ratio histogram
  TH1 *eta_efficiency_truth_genseed[5]; //Ratio histogram
  TH1 *phi_efficiency_gentrack[5]; //Ratio histogram
  TH1 *phi_efficiency_real_genseed[5]; //Ratio histogram
  TH1 *phi_efficiency_truth_genseed[5]; //Ratio histogram
  TH1 *eta_efficiency_track[5]; //Ratio histogram
  TH1 *eta_efficiency_real_seed[5]; //Ratio histogram
  TH1 *eta_efficiency_truth_seed[5]; //Ratio histogram
  TH1 *phi_efficiency_track[5]; //Ratio histogram
  TH1 *phi_efficiency_real_seed[5]; //Ratio histogram
  TH1 *phi_efficiency_truth_seed[5]; //Ratio histogram
  TH2 *h_r_z_seed[5];
  TH2 *h_r_z_true[5];
  TH2 *h_r_z_track[5];
  TH2 *h_rec_over_gen_seed[5];
  TH2 *h_rec_over_gen_trk[5];
  TH2 *h_rec_over_gen_true[5];
  TH2 *theta_vs_phi_real[5];
  TH2 *theta_vs_p_real[5];
  TH2 *phi_vs_p_real[5];
  TH2 *pt_vs_phi_seed[5];
  TH2 *pt_vs_phi_for_wrong_charge_seed[5];
  TH2 *pt_vs_eta_seed[5];
  TH2 *pt_vs_eta_ckf[5];
  TH2 *pt_vs_eta_for_wrong_charge_seed[5];
  TH1 *nmeasurement[5];
    TH1 *noutlier[5];
    TH1 *nhole[5];
    TH1 *chi[5];
    TH2 *nmeasurement_vs_noutlier[5];
    TH1 *q_over_p_before[5];
    TH1 *q_over_p_after[5];
    TH1 *q_over_p_truth[5];
    TH1 *p_for_outlier0[5];
    TH1 *p_for_outlier1[5];
    TH1 *p_for_outlier2[5];
    TH1 *p_for_outlier3[5];
    TH1 *p_for_outlier4[5];
    TH1 *p_for_outlier5[5];
    TH1 *p_for_outlier6[5];
    TH1 *eta_for_outlier0[5];
    TH1 *eta_for_outlier1[5];
    TH1 *eta_for_outlier2[5];
    TH1 *eta_for_outlier3[5];
    TH1 *eta_for_outlier4[5];
    TH1 *eta_for_outlier5[5];
    TH1 *eta_for_outlier6[5];
    TH1 *phi_for_outlier0[5];
    TH1 *phi_for_outlier1[5];
    TH1 *phi_for_outlier2[5];
    TH1 *phi_for_outlier3[5];
    TH1 *phi_for_outlier4[5];
    TH1 *phi_for_outlier5[5];
    TH1 *phi_for_outlier6[5];
    TH1 *chi_for_outlier0[5];
    TH1 *chi_for_outlier1[5];
    TH1 *chi_for_outlier2[5];
    TH1 *chi_for_outlier3[5];
    TH1 *chi_for_outlier4[5];
    TH1 *chi_for_outlier5[5];
    TH1 *chi_for_outlier6[5];
    //     for(int i=0; i<40; i++)
    TH1 *p_res_eta[16][20][5];

     
  for(int i=0; i<5; i++){

    for(int j=0; j<16; j++){
      for (int k=0; k<20; k++)
        {
	  p_res_eta[j][k][i] = new TH1F(Form("p_res_eta_[%d]_[%d]_[%d]",j,k,i), Form("P resolution for eta [%0.1f] to [%0.1f], p [%0.1d] to [%0.1d]",-4+0.5*j,-4+0.5*(j+1),0+k,0+(k+1)), 100, -50,50);
        }}

    
    nmeasurement[i] = new TH1D(Form("nmeasurement[%d]",i), "number of measurements", 10,0,10);
        noutlier[i] = new TH1D(Form("noutler[%d]",i), "number of outliers", 5,1,5);
        nhole[i] = new TH1D(Form("nhole[%d]",i), "number of holes", 5,1,5);
        chi[i] = new TH1D(Form("nchi[%d]",i), "chi2", 100, 0, 5);
        nmeasurement_vs_noutlier[i] = new TH2D(Form("nmeasurement_vs_noutlier[%d]",i),"nmeasurement vs noutlier", 100,0,12, 100,0,5);
        nmeasurement_vs_noutlier[i]->GetXaxis()->SetTitle("nmeasurement");nmeasurement_vs_noutlier[i]->GetXaxis()->CenterTitle();
        nmeasurement_vs_noutlier[i]->GetYaxis()->SetTitle("noutllier");nmeasurement_vs_noutlier[i]->GetYaxis()->CenterTitle();

	q_over_p_before[i] = new TH1D(Form("q_over_p1[%d]",i), "q over p res", 100, -0.4, 0.4);
	q_over_p_before[i]->SetLineColor(kBlue);q_over_p_before[i]->SetLineWidth(2);

	q_over_p_after[i] = new TH1D(Form("q_over_p2[%d]",i), "q over p res", 100, -0.4, 0.4);
	q_over_p_after[i]->SetLineColor(kGreen);q_over_p_after[i]->SetLineWidth(2);

	q_over_p_truth[i] = new TH1D(Form("q_over_p3[%d]",i), "q over p  res", 100, -0.4, 0.4);
	q_over_p_truth[i]->SetLineColor(kRed);q_over_p_truth[i]->SetLineWidth(2);

	p_for_outlier0[i] = new TH1D(Form("p__for_outlier0[%d]",i), "p for outlier", 100, 0, 25);
	p_for_outlier0[i]->SetLineColor(kBlue);p_for_outlier0[i] ->GetXaxis()->SetTitle("p for outlier"); p_for_outlier0[i] ->GetXaxis()->CenterTitle();

	p_for_outlier1[i] = new TH1D(Form("p__for_outlier1[%d]",i), "p for outlier", 100, 0, 25);
	p_for_outlier1[i]->SetLineColor(kRed);  p_for_outlier1[i] ->GetXaxis()->SetTitle("p for outlier"); p_for_outlier1[i] ->GetXaxis()->CenterTitle();


	  p_for_outlier2[i] = new TH1D(Form("p__for_outlier2[%d]",i), "p for outlier", 100, 0, 25);
	  p_for_outlier2[i]->SetLineColor(kGreen);p_for_outlier2[i] ->GetXaxis()->SetTitle("p for outlier"); p_for_outlier2[i] ->GetXaxis()->CenterTitle();

	  p_for_outlier3[i] = new TH1D(Form("p__for_outlier3[%d]",i), "p for outlier", 100, 0, 25);
	  p_for_outlier3[i]->SetLineColor(kBlack);p_for_outlier3[i] ->GetXaxis()->SetTitle("p for outlier"); p_for_outlier3[i] ->GetXaxis()->CenterTitle();

	  p_for_outlier4[i] = new TH1D(Form("p__for_outlier4[%d]",i), "p for outlier", 100, 0, 25);
	  p_for_outlier4[i]->SetLineColor(kViolet);p_for_outlier4[i] ->GetXaxis()->SetTitle("p for outlier"); p_for_outlier4[i] ->GetXaxis()->CenterTitle();

	  p_for_outlier5[i] = new TH1D(Form("p__for_outlier5[%d]",i), "p for outlier", 100, 0, 25);
	  p_for_outlier5[i]->SetLineColor(kOrange);p_for_outlier5[i] ->GetXaxis()->SetTitle("p for outlier"); p_for_outlier5[i] ->GetXaxis()->CenterTitle();

	  p_for_outlier6[i] = new TH1D(Form("p__for_outlier6[%d]",i), "p for outlier", 100, 0, 25);
	  p_for_outlier6[i]->SetLineColor(kPink);p_for_outlier6[i] ->GetXaxis()->SetTitle("p for outlier"); p_for_outlier6[i] ->GetXaxis()->CenterTitle();



	  eta_for_outlier0[i] = new TH1D(Form("eta__for_outlier0[%d]",i), " eta for outlier", 100, -4, 4);
	  eta_for_outlier0[i]->SetLineColor(kBlue);eta_for_outlier0[i] ->GetXaxis()->SetTitle("eta for outlier"); eta_for_outlier0[i] ->GetXaxis()->CenterTitle();

	  eta_for_outlier1[i] =	new TH1D(Form("eta__for_outlier1[%d]",i), " eta for outlier", 100, -4, 4);
          eta_for_outlier1[i]->SetLineColor(kRed);eta_for_outlier1[i] ->GetXaxis()->SetTitle("eta for outlier"); eta_for_outlier1[i] ->GetXaxis()->CenterTitle();

	  eta_for_outlier2[i] =	new TH1D(Form("eta__for_outlier2[%d]",i), " eta for outlier", 100, -4, 4);
          eta_for_outlier2[i]->SetLineColor(kGreen);eta_for_outlier2[i] ->GetXaxis()->SetTitle("eta for outlier"); eta_for_outlier2[i] ->GetXaxis()->CenterTitle();

	  eta_for_outlier3[i] =	new TH1D(Form("eta__for_outlier3[%d]",i), " eta for outlier", 100, -4, 4);
          eta_for_outlier3[i]->SetLineColor(kBlack);eta_for_outlier3[i] ->GetXaxis()->SetTitle("eta for outlier"); eta_for_outlier3[i] ->GetXaxis()->CenterTitle();

	  eta_for_outlier4[i] =	new TH1D(Form("eta__for_outlier4[%d]",i), " eta for outlier", 100, -4, 4);
          eta_for_outlier4[i]->SetLineColor(kViolet);eta_for_outlier4[i] ->GetXaxis()->SetTitle("eta for outlier"); eta_for_outlier4[i] ->GetXaxis()->CenterTitle();
	  
	  eta_for_outlier5[i] =	new TH1D(Form("eta__for_outlier5[%d]",i), " eta for outlier", 100, -4, 4);
          eta_for_outlier5[i]->SetLineColor(kOrange);eta_for_outlier5[i] ->GetXaxis()->SetTitle("eta for outlier"); eta_for_outlier5[i] ->GetXaxis()->CenterTitle();

	  eta_for_outlier6[i] =	new TH1D(Form("eta__for_outlier6[%d]",i), " eta for outlier", 100, -4, 4);
          eta_for_outlier6[i]->SetLineColor(kPink);eta_for_outlier6[i] ->GetXaxis()->SetTitle("eta for outlier"); eta_for_outlier6[i] ->GetXaxis()->CenterTitle();


	  phi_for_outlier0[i] = new TH1D(Form("phi__for_outlier0[%d]",i), " phi for outlier", 100, -4, 4);
	  phi_for_outlier0[i]->SetLineColor(kBlue);phi_for_outlier0[i] ->GetXaxis()->SetTitle("phi for outlier"); phi_for_outlier0[i] ->GetXaxis()->CenterTitle();

	   phi_for_outlier1[i] = new TH1D(Form("phi__for_outlier1[%d]",i), " phi for outlier", 100, -4, 4);
          phi_for_outlier1[i]->SetLineColor(kRed);phi_for_outlier1[i] ->GetXaxis()->SetTitle("phi for outlier"); phi_for_outlier1[i] ->GetXaxis()->CenterTitle();

	   phi_for_outlier2[i] = new TH1D(Form("phi__for_outlier2[%d]",i), " phi for outlier", 100, -4, 4);
          phi_for_outlier2[i]->SetLineColor(kGreen);phi_for_outlier2[i] ->GetXaxis()->SetTitle("phi for outlier"); phi_for_outlier2[i] ->GetXaxis()->CenterTitle();

	   phi_for_outlier3[i] = new TH1D(Form("phi__for_outlier3[%d]",i), " phi for outlier", 100, -4, 4);
          phi_for_outlier3[i]->SetLineColor(kBlack);phi_for_outlier3[i] ->GetXaxis()->SetTitle("phi for outlier"); phi_for_outlier3[i] ->GetXaxis()->CenterTitle();

	   phi_for_outlier4[i] = new TH1D(Form("phi__for_outlier4[%d]",i), " phi for outlier", 100, -4, 4);
          phi_for_outlier4[i]->SetLineColor(kViolet);phi_for_outlier4[i] ->GetXaxis()->SetTitle("phi for outlier"); phi_for_outlier4[i] ->GetXaxis()->CenterTitle();

	   phi_for_outlier5[i] = new TH1D(Form("phi__for_outlier5[%d]",i), " phi for outlier", 100, -4, 4);
          phi_for_outlier5[i]->SetLineColor(kOrange);phi_for_outlier5[i] ->GetXaxis()->SetTitle("phi for outlier"); phi_for_outlier5[i] ->GetXaxis()->CenterTitle();

	   phi_for_outlier6[i] = new TH1D(Form("phi__for_outlier6[%d]",i), " phi for outlier", 100, -4, 4);
          phi_for_outlier6[i]->SetLineColor(kPink);phi_for_outlier6[i] ->GetXaxis()->SetTitle("phi for outlier"); phi_for_outlier6[i] ->GetXaxis()->CenterTitle();

	  
	   chi_for_outlier0[i] = new TH1D(Form("chi__for_outlier0[%d]",i), " chi for outlier", 100, 0, 5);
          chi_for_outlier0[i]->SetLineColor(kBlue);chi_for_outlier0[i] ->GetXaxis()->SetTitle("chi for outlier"); chi_for_outlier0[i] ->GetXaxis()->CenterTitle();

           chi_for_outlier1[i] = new TH1D(Form("chi__for_outlier1[%d]",i), " chi for outlier", 100, 0, 5);
          chi_for_outlier1[i]->SetLineColor(kRed);chi_for_outlier1[i] ->GetXaxis()->SetTitle("chi for outlier"); chi_for_outlier1[i] ->GetXaxis()->CenterTitle();

           chi_for_outlier2[i] = new TH1D(Form("chi__for_outlier2[%d]",i), " chi for outlier", 100, 0, 5);
          chi_for_outlier2[i]->SetLineColor(kGreen);chi_for_outlier2[i] ->GetXaxis()->SetTitle("chi for outlier"); chi_for_outlier2[i] ->GetXaxis()->CenterTitle();

           chi_for_outlier3[i] = new TH1D(Form("chi__for_outlier3[%d]",i), " chi for outlier", 100, 0, 5);
          chi_for_outlier3[i]->SetLineColor(kBlack);chi_for_outlier3[i] ->GetXaxis()->SetTitle("chi for outlier"); chi_for_outlier3[i] ->GetXaxis()->CenterTitle();

           chi_for_outlier4[i] = new TH1D(Form("chi__for_outlier4[%d]",i), " chi for outlier", 100, 0, 5);
          chi_for_outlier4[i]->SetLineColor(kViolet);chi_for_outlier4[i] ->GetXaxis()->SetTitle("chi for outlier"); chi_for_outlier4[i] ->GetXaxis()->CenterTitle();

           chi_for_outlier5[i] = new TH1D(Form("chi__for_outlier5[%d]",i), " chi for outlier", 100, 0, 5);
          chi_for_outlier5[i]->SetLineColor(kOrange);chi_for_outlier5[i] ->GetXaxis()->SetTitle("chi for outlier"); chi_for_outlier5[i] ->GetXaxis()->CenterTitle();

	  chi_for_outlier6[i] = new TH1D(Form("chi__for_outlier6[%d]",i), " chi for outlier", 100, 0, 5);
          chi_for_outlier6[i]->SetLineColor(kPink);chi_for_outlier6[i] ->GetXaxis()->SetTitle("chi for outlier"); chi_for_outlier6[i] ->GetXaxis()->CenterTitle();


	  
	  p_res_seed[i] = new TH1D(Form("p_res_seed[%d]",i),"Momentum Resolution: (rec. - mc)/mc",100,-30,30);
    p_res_seed[i]->GetXaxis()->SetTitle("Resolution [%]");p_res_seed[i]->GetXaxis()->CenterTitle();
    p_res_seed[i]->SetLineColor(kBlue);p_res_seed[i]->SetLineWidth(2);
        
    p_res_trk[i] = new TH1D(Form("p_res_trk[%d]",i),"Momentum Resolution: (rec. - mc)/mc",100,-30,30);
    p_res_trk[i]->GetXaxis()->SetTitle("Resolution [%]");p_res_trk[i]->GetXaxis()->CenterTitle();
    p_res_trk[i]->SetLineColor(kGreen);p_res_trk[i]->SetLineWidth(2);

        
    p_res_true[i] = new TH1D(Form("p_res_true[%d]",i),"Momentum Resolution: (rec. - mc)/mc",100,-30,30);
    p_res_true[i]->GetXaxis()->SetTitle("Resolution [%]");p_res_true[i]->GetXaxis()->CenterTitle();
    p_res_true[i]->SetLineColor(kRed);p_res_true[i]->SetLineWidth(2);
        
    p_seed[i] = new TH1D(Form("p_seed[%d]",i),"Momentum distribution",1000,0,1);
    p_seed[i]->GetXaxis()->SetTitle("momentum");p_seed[i]->GetXaxis()->CenterTitle();
    p_seed[i]->SetLineColor(kBlue);p_seed[i]->SetLineWidth(2);
        
    p_trk[i] = new TH1D(Form("p_trk[%d]",i),"Momentum distribution",1000,0,1);
    p_trk[i]->GetXaxis()->SetTitle("momentum");p_trk[i]->GetXaxis()->CenterTitle();
    p_trk[i]->SetLineColor(kGreen);p_trk[i]->SetLineWidth(2);
        
    p_true[i] = new TH1D(Form("p_true[%d]",i),"Momentum distribution",1000,0,1);
    p_true[i]->GetXaxis()->SetTitle("Resolution [%]");p_true[i]->GetXaxis()->CenterTitle();
    p_true[i]->SetLineColor(kRed);p_true[i]->SetLineWidth(2);
        
    p_mc[i] = new TH1D(Form("p_mc[%d]",i),"Momentum distribution",1000,0,1);
    p_mc[i]->GetXaxis()->SetTitle("momentum");p_mc[i]->GetXaxis()->CenterTitle();
    p_mc[i]->SetLineColor(1);p_mc[i]->SetLineWidth(2);
        
    pz_ratio_seed[i] = new TH2D(Form("pz_ratio_seed[%d] ",i), "reco/gen pz vs gen_pz real seed", 100, -23,23,100,-.5,5);
    pz_ratio_seed[i] ->GetXaxis()->SetTitle("gen_pz"); pz_ratio_seed[i] ->GetXaxis()->CenterTitle();
    pz_ratio_seed[i] ->GetYaxis()->SetTitle("Reco/gen pz"); pz_ratio_seed[i] ->GetYaxis()->CenterTitle();
    pz_ratio_seed[i]  -> SetMarkerColor(kBlue);
        
    pz_ratio_track[i] = new TH2D(Form("pz_ratio_trk[%d] ",i), "reco/gen pz vs gen_pz track", 100, -23,23,100,-.5,5);
    pz_ratio_track[i] ->GetXaxis()->SetTitle("gen_pz"); pz_ratio_track[i] ->GetXaxis()->CenterTitle();
    pz_ratio_track[i] ->GetYaxis()->SetTitle("Reco/gen pz"); pz_ratio_track[i] ->GetYaxis()->CenterTitle();
    pz_ratio_track[i]  -> SetMarkerColor(kGreen);
        
    pz_ratio_true[i] = new TH2D(Form("pz_ratio_true[%d] ",i), "reco/gen pz vs gen_pz true seed", 100, -23,23,100,-.5,5);
    pz_ratio_true[i] ->GetXaxis()->SetTitle("gen_pz");  pz_ratio_true[i] ->GetXaxis()->CenterTitle();
    pz_ratio_true[i] ->GetYaxis()->SetTitle("Reco/gen pz"); pz_ratio_true[i] ->GetYaxis()->CenterTitle();
    pz_ratio_true[i]  -> SetMarkerColor(kRed);
        
    pt_ratio_seed[i] = new TH2D(Form("pt_ratio_seed[%d]",i), "reco/gen pt vs gen_pt real seed", 100, -3,23,100,-.5,5);
    pt_ratio_seed[i] ->GetXaxis()->SetTitle("gen_pt"); pz_ratio_seed[i] ->GetXaxis()->CenterTitle();
    pt_ratio_seed[i] ->GetYaxis()->SetTitle("Reco/gen pt"); pz_ratio_seed[i] ->GetYaxis()->CenterTitle();
    pt_ratio_seed[i]  -> SetMarkerColor(kBlue);
        
    pt_ratio_track[i] = new TH2D(Form("pt_ratio_trk[%d]",i), "reco/gen pt vs gen_pt track", 100, -3,23,100,-.5,5);
    pt_ratio_track[i] ->GetXaxis()->SetTitle("gen_pt"); pt_ratio_track[i] ->GetXaxis()->CenterTitle();
    pt_ratio_track[i] ->GetYaxis()->SetTitle("Reco/gen pt"); pt_ratio_track[i] ->GetYaxis()->CenterTitle();
    pt_ratio_track[i]  -> SetMarkerColor(kGreen);
        
    pt_ratio_true[i] = new TH2D(Form("pt_ratio_true[%d]",i), "reco/gen pt vs gen_pt true seed", 100, -3,23,100,-.5,5);
    pt_ratio_true[i] ->GetXaxis()->SetTitle("gen_pt");  pt_ratio_true[i] ->GetXaxis()->CenterTitle();
    pt_ratio_true[i] ->GetYaxis()->SetTitle("Reco/gen pt"); pt_ratio_true[i] ->GetYaxis()->CenterTitle();
    pt_ratio_true[i]  -> SetMarkerColor(kRed);
        
        
    theta_seed[i] = new TH1D(Form("theta_seed[%d)",i),"Theta",100,-1,5);
    theta_seed[i]->GetXaxis()->SetTitle("theta");theta_seed[i]->GetXaxis()->CenterTitle();
    theta_seed[i]->SetLineColor(kBlue);theta_seed[i]->SetLineWidth(2);
        
    theta_trk[i] = new TH1D(Form("theta_trk[%d]",i),"Theta",100,-1,5);
    theta_trk[i]->GetXaxis()->SetTitle("theta");theta_trk[i]->GetXaxis()->CenterTitle();
    theta_trk[i]->SetLineColor(kGreen);theta_trk[i]->SetLineWidth(2);
        
    theta_true[i] = new TH1D(Form("theta_true[%d]",i),"Theta",100,-1,5);
    theta_true[i]->GetXaxis()->SetTitle("theta");theta_true[i]->GetXaxis()->CenterTitle();
    theta_true[i]->SetLineColor(kRed);theta_true[i]->SetLineWidth(2);
        
    theta_mc[i] = new TH1D(Form("theta_mc[%d]",i),"Theta",100,-1,5);
    theta_mc[i]->GetXaxis()->SetTitle("theta");theta_mc[i]->GetXaxis()->CenterTitle();
    theta_mc[i]->SetLineColor(1);theta_mc[i]->SetLineWidth(2);
        
    theta_res_seed[i] = new TH1D(Form("theta_res_seed[%d]",i),"Theta Resolution: (rec. - mc)",100,-2,2);
    theta_res_seed[i]->GetXaxis()->SetTitle("Resolution [mRad]");theta_res_seed[i]->GetXaxis()->CenterTitle();
    theta_res_seed[i]->SetLineColor(kBlue);theta_res_seed[i]->SetLineWidth(2);
        
    theta_res_trk[i] = new TH1D(Form("theta_res_trk[%d]",i),"Theta Resolution: (rec. - mc)",100,-2,2);
    theta_res_trk[i]->GetXaxis()->SetTitle("Resolution [mRad]");theta_res_trk[i]->GetXaxis()->CenterTitle();
    theta_res_trk[i]->SetLineColor(kGreen);theta_res_trk[i]->SetLineWidth(2);
        
    theta_res_true[i] = new TH1D(Form("theta_res_true[%d]",i),"Theta Resolution: (rec. - mc)",100,-2,2);
    theta_res_true[i]->GetXaxis()->SetTitle("Resolution [mRad]");theta_res_true[i]->GetXaxis()->CenterTitle();
    theta_res_true[i]->SetLineColor(kRed);theta_res_true[i]->SetLineWidth(2);
        
    phi_res_seed[i] = new TH1D(Form("phi_res_seed[%d]",i),"Phi Resolution: (rec. - mc)",100,-50,15);
    phi_res_seed[i]->GetXaxis()->SetTitle("Resolution [mRad]");phi_res_seed[i]->GetXaxis()->CenterTitle();
    phi_res_seed[i]->SetLineColor(kBlue);phi_res_seed[i]->SetLineWidth(2);
        
    phi_res_trk[i] = new TH1D(Form("phi_res_trk[%d]",i),"Phi Resolution: (rec. - mc)",100,-50,15);
    phi_res_trk[i]->GetXaxis()->SetTitle("Resolution [mRad]");phi_res_trk[i]->GetXaxis()->CenterTitle();
    phi_res_trk[i]->SetLineColor(kGreen);phi_res_trk[i]->SetLineWidth(2);
        
    phi_res_true[i] = new TH1D(Form("phi_res_true[%d]",i),"Phi Resolution: (rec. - mc)",100,-50,15);
    phi_res_true[i]->GetXaxis()->SetTitle("Resolution [mRad]");phi_res_true[i]->GetXaxis()->CenterTitle();
    phi_res_true[i]->SetLineColor(kRed);phi_res_true[i]->SetLineWidth(2);
        
    phi_seed[i] = new TH1D(Form("phi_seed[%d]",i),"Phi",100,-5,5);
    phi_seed[i]->GetXaxis()->SetTitle("phi");phi_seed[i]->GetXaxis()->CenterTitle();
    phi_seed[i]->SetLineColor(kBlue);phi_seed[i]->SetLineWidth(2);
        
    phi_trk[i] = new TH1D(Form("phi_trk[%d]",i),"Phi",100,-5,5);
    phi_trk[i]->GetXaxis()->SetTitle("phi");phi_trk[i]->GetXaxis()->CenterTitle();
    phi_trk[i]->SetLineColor(kGreen);phi_trk[i]->SetLineWidth(2);
        
    phi_true[i] = new TH1D(Form("phi_true[%d]",i),"Phi",100,-5,5);
    phi_true[i]->GetXaxis()->SetTitle("phi");phi_true[i]->GetXaxis()->CenterTitle();
    phi_true[i]->SetLineColor(kRed);phi_true[i]->SetLineWidth(2);
        
    phi_mc[i] = new TH1D(Form("phi_mc[%d]",i),"Phi",100,-5,5);
    phi_mc[i]->GetXaxis()->SetTitle("phi");phi_mc[i]->GetXaxis()->CenterTitle();
    phi_mc[i]->SetLineColor(1);phi_mc[i]->SetLineWidth(2);
        
    r_seed[i] = new TH1D(Form("r_seed[%d]",i),"ACTS loc-a r",100,-20,20);
    r_seed[i]->GetXaxis()->SetTitle("[mm]");r_seed[i]->GetXaxis()->CenterTitle();
    r_seed[i]->SetLineColor(kBlue);r_seed[i]->SetLineWidth(2);
        
    r_trk[i] = new TH1D(Form("r_trk[%d]",i),"ACTS loc-a r",100,-20,20);
    r_trk[i]->GetXaxis()->SetTitle("[mm]");r_trk[i]->GetXaxis()->CenterTitle();
    r_trk[i]->SetLineColor(kGreen);r_trk[i]->SetLineWidth(2);
        
    r_true[i] = new TH1D(Form("r_true[%d]",i),"ACTS loc-a r",100,-20,20);
    r_true[i]->GetXaxis()->SetTitle("[mm]");r_true[i]->GetXaxis()->CenterTitle();
    r_true[i]->SetLineColor(kRed);r_true[i]->SetLineWidth(2);
        
    z_seed[i] = new TH1D(Form("z_seed[%d]",i),"ACTS loc-b z",1000,-100,100);
    z_seed[i]->GetXaxis()->SetTitle("[mm]");z_seed[i]->GetXaxis()->CenterTitle();
    z_seed[i]->SetLineColor(kBlue);z_seed[i]->SetLineWidth(2);
        
    z_trk[i] = new TH1D(Form("z_trk[%d]",i),"ACTS loc-b z",1000,-100,100);
    z_trk[i]->GetXaxis()->SetTitle("[mm]");z_trk[i]->GetXaxis()->CenterTitle();
        z_trk[i]->SetLineColor(kGreen);z_trk[i]->SetLineWidth(2);
        
	z_true[i] = new TH1D(Form("h5_true[%d]",i),"ACTS loc-b z",1000,-100,100);
       z_true[i]->GetXaxis()->SetTitle("[mm]");z_true[i]->GetXaxis()->CenterTitle();
       z_true[i]->SetLineColor(kRed);z_true[i]->SetLineWidth(2);
        
       charge_seed[i] = new TH1D(Form("charge_seed[%d]",i),"Charge",100,-1.5,1.5);
        charge_seed[i]->GetXaxis()->SetTitle("Charge [e]");charge_seed[i]->GetXaxis()->CenterTitle();
        charge_seed[i]->SetLineColor(kBlue);charge_seed[i]->SetLineWidth(2);
        
        charge_trk[i] = new TH1D(Form("charge_trk[%d]",i),"Charge",100,-1.5,1.5);
        charge_trk[i]->GetXaxis()->SetTitle("Charge [e]");charge_trk[i]->GetXaxis()->CenterTitle();
        charge_trk[i]->SetLineColor(kGreen);charge_trk[i]->SetLineWidth(2);
        
        charge_true[i] = new TH1D(Form("charge_true[%d]",i),"Charge",100,-1.5,1.5);
        charge_true[i]->GetXaxis()->SetTitle("Charge [e]");charge_true[i]->GetXaxis()->CenterTitle();
        charge_true[i]->SetLineColor(kRed);charge_true[i]->SetLineWidth(2);
        
        pt_vs_phi_seed[i] = new TH2D(Form("pt_vs_phi_seed[%d]",i), "pt_vs_phi_seed", 100, -4,4,100,-3.5,3.5);
        pt_vs_phi_seed[i] ->GetXaxis()->SetTitle("phi "); pt_vs_phi_seed[i] ->GetXaxis()->CenterTitle();
        pt_vs_phi_seed[i] ->GetYaxis()->SetTitle("pt"); pt_vs_phi_seed[i] ->GetYaxis()->CenterTitle();
        pt_vs_phi_seed[i]  -> SetMarkerColor(kBlue);
        
        pt_vs_phi_for_wrong_charge_seed[i] = new TH2D(Form("pt_vs_phi_for_wrong_charge_seed[%d]",i), "pt_vs_phi_for_wrong_charge_seed", 100, -4,4,100,-3.5,25);
        pt_vs_phi_for_wrong_charge_seed[i] ->GetXaxis()->SetTitle("phi "); pt_vs_phi_for_wrong_charge_seed[i] ->GetXaxis()->CenterTitle();
        pt_vs_phi_for_wrong_charge_seed[i] ->GetYaxis()->SetTitle("pt"); pt_vs_phi_for_wrong_charge_seed[i] ->GetYaxis()->CenterTitle();
        pt_vs_phi_for_wrong_charge_seed[i]  -> SetMarkerColor(kBlue);
        
        pt_vs_eta_seed[i] = new TH2D(Form("pt_vs_eta_seed[%d]",i), "p_vs_eta_seed", 100, 85,125,100,-3.5,3.5);
        pt_vs_eta_seed[i] ->GetXaxis()->SetTitle("eta "); pt_vs_eta_seed[i] ->GetXaxis()->CenterTitle();
        pt_vs_eta_seed[i] ->GetYaxis()->SetTitle("pt"); pt_vs_eta_seed[i] ->GetYaxis()->CenterTitle();
        pt_vs_eta_seed[i]  -> SetMarkerColor(kBlue);

	pt_vs_eta_ckf[i] = new TH2D(Form("pt_vs_eta_ckf[%d]",i), "p_vs_eta_ckf", 100, -4.5,4.5,100,-3.5,35);
        pt_vs_eta_ckf[i] ->GetXaxis()->SetTitle("eta "); pt_vs_eta_ckf[i] ->GetXaxis()->CenterTitle();
        pt_vs_eta_ckf[i] ->GetYaxis()->SetTitle("pt"); pt_vs_eta_ckf[i] ->GetYaxis()->CenterTitle();
        pt_vs_eta_ckf[i]  -> SetMarkerColor(kBlue);
	
        pt_vs_eta_for_wrong_charge_seed[i] = new TH2D(Form("pt_vs_eta_for_wrong_charge_seed[%d]",i), "pt_vs_eta_for_wrong_charge_seed", 100, -4.5,4.5,100,-3.5,25);
        pt_vs_eta_for_wrong_charge_seed[i] ->GetXaxis()->SetTitle("eta "); pt_vs_eta_for_wrong_charge_seed[i] ->GetXaxis()->CenterTitle();
        pt_vs_eta_for_wrong_charge_seed[i] ->GetYaxis()->SetTitle("pt"); pt_vs_eta_for_wrong_charge_seed[i] ->GetYaxis()->CenterTitle();
        pt_vs_eta_for_wrong_charge_seed[i]  -> SetMarkerColor(kBlue);
        
        
	num_track[i] = new TH1D(Form("num_track[%d]",i),"Number of tracks",10,0,10);
       num_track[i]->GetXaxis()->SetTitle("Number of tracks");num_track[i]->GetXaxis()->CenterTitle();
       num_track[i]->GetYaxis()->SetTitle("Fraction of events");num_track[i]->GetYaxis()->CenterTitle();
       num_track[i]->SetLineColor(kBlue);num_track[i]->SetLineWidth(2);
       num_track[i]->GetXaxis()->CenterLabels();
        
       num_trk_vs_particle_eta[i] = new TH2D(Form("num_trk_vs_particle_eta[%d]",i),"Number of tracks vs. generated particle #eta",100,-4,4,5,0,5);
        num_trk_vs_particle_eta[i]->GetXaxis()->SetTitle("#eta");num_trk_vs_particle_eta[i]->GetXaxis()->CenterTitle();
        num_trk_vs_particle_eta[i]->GetYaxis()->SetTitle("Number of tracks");num_trk_vs_particle_eta[i]->GetYaxis()->CenterTitle();
        num_trk_vs_particle_eta[i]->GetYaxis()->SetNdivisions(405);num_trk_vs_particle_eta[i]->GetYaxis()->CenterLabels();
        
        unique_trk_vs_particle_eta[i] = new TH2D(Form("unique_trk_vs_particle_eta[%d]",i),"Number of unique tracks vs. generated particle #eta",100,-4,4,5,0,5);
        unique_trk_vs_particle_eta[i]->GetXaxis()->SetTitle("#eta");unique_trk_vs_particle_eta[i]->GetXaxis()->CenterTitle();
        unique_trk_vs_particle_eta[i]->GetYaxis()->SetTitle("Number of unique tracks");unique_trk_vs_particle_eta[i]->GetYaxis()->CenterTitle();
        unique_trk_vs_particle_eta[i]->GetYaxis()->SetNdivisions(405);unique_trk_vs_particle_eta[i]->GetYaxis()->CenterLabels();
        
        //Tracker Efficiency for seed
        //----
        //Generated particle counts
        efficiency_vs_eta_gentrack[i] = new TH1D(Form("efficiency_vs_eta_gentrack[%d]",i),"Tracker Efficiency vs. generated particle #eta",100,-4,4);
        efficiency_vs_eta_gentrack[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_gentrack[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_gentrack[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_gentrack[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_gentrack[i]->SetLineColor(kGreen);efficiency_vs_eta_gentrack[i]->SetLineWidth(4);
        
        //Generated particle counts when at least one track found
        efficiency_vs_eta_gentrack2[i] = new TH1D(Form("efficiency_vs_eta_gentrack2[%d]",i),"Tracker Efficiency vs. generated particle #eta",100,-4,4);
        efficiency_vs_eta_gentrack2[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_gentrack2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_gentrack2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_gentrack2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_gentrack2[i]->SetLineColor(kGreen);efficiency_vs_eta_gentrack2[i]->SetLineWidth(4);
        
        
        //Tracker Efficiency for real seed
        //----
        //Generated particle counts
        efficiency_vs_eta_real_genSeed[i] = new TH1D(Form("efficiency_vs_eta_real_genSeed[%d]",i),"Tracker Efficiency vs. generated particle #eta",100,-4,4);
        efficiency_vs_eta_real_genSeed[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_real_genSeed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_real_genSeed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_real_genSeed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_real_genSeed[i]->SetLineColor(kBlue);efficiency_vs_eta_real_genSeed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_eta_real_genSeed2[i] = new TH1D(Form("efficiency_vs_eta_real_genSeed2[%d]",i),"Tracker Efficiency vs. generated particle #eta",100,-4,4);
        efficiency_vs_eta_real_genSeed2[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_real_genSeed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_real_genSeed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_real_genSeed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_real_genSeed2[i]->SetLineColor(kBlue);efficiency_vs_eta_real_genSeed2[i]->SetLineWidth(2);
        
        
        //Tracker Efficiency for truth seed
        //----
        //Generated particle counts
        efficiency_vs_eta_truth_genSeed[i] = new TH1D(Form("efficiency_vs_eta_truth_genSeed[%d]",i),"Tracker Efficiency vs. generated particle #eta",100,-4,4);
        efficiency_vs_eta_truth_genSeed[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_truth_genSeed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_truth_genSeed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_truth_genSeed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_truth_genSeed[i]->SetLineColor(kRed);efficiency_vs_eta_truth_genSeed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_eta_truth_genSeed2[i] = new TH1D(Form("efficiency_vs_eta_truth_genSeed2[%d]",i),"Tracker Efficiency vs. generated particle #eta",100,-4,4);
        efficiency_vs_eta_truth_genSeed2[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_truth_genSeed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_truth_genSeed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_truth_genSeed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_truth_genSeed2[i]->SetLineColor(kRed);efficiency_vs_eta_truth_genSeed2[i]->SetLineWidth(2);
        
        
        efficiency_vs_phi_gentrack[i] = new TH1D(Form("efficiency_vs_phi_gentrack[%d]",i),"Tracker Efficiency vs. generated particle #phi",100,-4,4);
        efficiency_vs_phi_gentrack[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_gentrack[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_gentrack[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_gentrack[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_gentrack[i]->SetLineColor(kGreen);efficiency_vs_phi_gentrack[i]->SetLineWidth(4);
        
        //Generated particle counts when at least one track found
        efficiency_vs_phi_gentrack2[i] = new TH1D(Form("efficiency_vs_phi_gentrack2[%d]",i),"Tracker Efficiency vs. generated particle #phi",100,-4,4);
        efficiency_vs_phi_gentrack2[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_gentrack2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_gentrack2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_gentrack2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_gentrack2[i]->SetLineColor(kGreen);efficiency_vs_phi_gentrack2[i]->SetLineWidth(4);
        
        
        //Tracker Efficiency for real seed
        //----
        //Generated particle counts
        efficiency_vs_phi_real_genSeed[i] = new TH1D(Form("efficiency_vs_phi_real_genSeed[%d]",i),"Tracker Efficiency vs. generated particle #phi",100,-4,4);
        efficiency_vs_phi_real_genSeed[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_real_genSeed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_real_genSeed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_real_genSeed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_real_genSeed[i]->SetLineColor(kBlue);efficiency_vs_phi_real_genSeed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_phi_real_genSeed2[i] = new TH1D(Form("efficiency_vs_phi_real_genSeed2[%d]",i),"Tracker Efficiency vs. generated particle #phi",100,-4,4);
        efficiency_vs_phi_real_genSeed2[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_real_genSeed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_real_genSeed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_real_genSeed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_real_genSeed2[i]->SetLineColor(kBlue);efficiency_vs_eta_real_genSeed2[i]->SetLineWidth(2);
        
        
        //Tracker Efficiency for truth seed
        //----
        //Generated particle counts
        efficiency_vs_phi_truth_genSeed[i] = new TH1D(Form("efficiency_vs_phi_truth_genSeed[%d]",i),"Tracker Efficiency vs. generated particle #phi",100,-4,4);
        efficiency_vs_phi_truth_genSeed[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_truth_genSeed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_truth_genSeed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_truth_genSeed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_truth_genSeed[i]->SetLineColor(kRed);efficiency_vs_phi_truth_genSeed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_phi_truth_genSeed2[i] = new TH1D(Form("efficiency_vs_phi_truth_genSeed2[%d]",i),"Tracker Efficiency vs. generated particle #phi",100,-4,4);
        efficiency_vs_phi_truth_genSeed2[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_truth_genSeed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_truth_genSeed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_truth_genSeed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_truth_genSeed2[i]->SetLineColor(kRed);efficiency_vs_phi_truth_genSeed2[i]->SetLineWidth(2);

        efficiency_vs_eta_track[i] = new TH1D(Form("efficiency_vs_eta_track[%d]",i),"Tracker Efficiency vs. reconstructed particle #eta",100,-4,4);
        efficiency_vs_eta_track[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_track[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_track[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_track[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_track[i]->SetLineColor(kGreen);efficiency_vs_eta_track[i]->SetLineWidth(4);
        
        //Generated particle counts when at least one track found
        efficiency_vs_eta_track2[i] = new TH1D(Form("efficiency_vs_eta_track2[%d]",i),"Tracker Efficiency vs. reconstructed particle #eta",100,-4,4);
        efficiency_vs_eta_track2[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_track2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_track2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_track2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_track2[i]->SetLineColor(kGreen);efficiency_vs_eta_track2[i]->SetLineWidth(4);
        
        
        //Tracker Efficiency for real seed
        //----
        //Generated particle counts
        efficiency_vs_eta_real_Seed[i] = new TH1D(Form("efficiency_vs_eta_real_Seed[%d]",i),"Tracker Efficiency vs. reconstructed particle #eta",100,-4,4);
        efficiency_vs_eta_real_Seed[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_real_Seed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_real_Seed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_real_Seed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_real_Seed[i]->SetLineColor(kBlue);efficiency_vs_eta_real_Seed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_eta_real_Seed2[i] = new TH1D(Form("efficiency_vs_eta_real_Seed2[%d]",i),"Tracker Efficiency vs. reconstructed particle #eta",100,-4,4);
        efficiency_vs_eta_real_Seed2[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_real_Seed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_real_Seed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_real_Seed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_real_Seed2[i]->SetLineColor(kBlue);efficiency_vs_eta_real_Seed2[i]->SetLineWidth(2);
        
        
        //Tracker Efficiency for truth seed
        //----
        //Generated particle counts
        efficiency_vs_eta_truth_Seed[i] = new TH1D(Form("efficiency_vs_eta_truth_Seed[%d]",i),"Tracker Efficiency vs. reconstructed particle #eta",100,-4,4);
        efficiency_vs_eta_truth_Seed[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_truth_Seed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_truth_Seed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_truth_Seed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_truth_Seed[i]->SetLineColor(kRed);efficiency_vs_eta_truth_Seed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_eta_truth_Seed2[i] = new TH1D(Form("efficiency_vs_eta_truth_Seed2[%d]",i),"Tracker Efficiency vs. reconstructed particle #eta",100,-4,4);
        efficiency_vs_eta_truth_Seed2[i]->GetXaxis()->SetTitle("#eta");efficiency_vs_eta_truth_Seed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_eta_truth_Seed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_eta_truth_Seed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_eta_truth_Seed2[i]->SetLineColor(kRed);efficiency_vs_eta_truth_Seed2[i]->SetLineWidth(2);
        
        
        efficiency_vs_phi_track[i] = new TH1D(Form("efficiency_vs_phi_track[%d]",i),"Tracker Efficiency vs. reconstructed particle #phi",100,-4,4);
        efficiency_vs_phi_track[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_track[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_track[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_track[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_track[i]->SetLineColor(kGreen);efficiency_vs_phi_track[i]->SetLineWidth(4);
        
        //Generated particle counts when at least one track found
        efficiency_vs_phi_track2[i] = new TH1D(Form("efficiency_vs_phi_track2[%d]",i),"Tracker Efficiency vs. reconstructed particle #phi",100,-4,4);
        efficiency_vs_phi_track2[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_track2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_track2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_track2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_track2[i]->SetLineColor(kGreen);efficiency_vs_phi_track2[i]->SetLineWidth(4);
        
        
        //Tracker Efficiency for real seed
        //----
        //Generated particle counts
        efficiency_vs_phi_real_Seed[i] = new TH1D(Form("efficiency_vs_phi_real_Seed[%d]",i),"Tracker Efficiency vs. reconstructed particle #phi",100,-4,4);
        efficiency_vs_phi_real_Seed[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_real_Seed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_real_Seed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_real_Seed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_real_Seed[i]->SetLineColor(kBlue);efficiency_vs_phi_real_Seed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_phi_real_Seed2[i] = new TH1D(Form("efficiency_vs_phi_real_Seed2[%d]",i),"Tracker Efficiency vs. reconstructed particle #phi",100,-4,4);
        efficiency_vs_phi_real_Seed2[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_real_Seed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_real_Seed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_real_Seed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_real_Seed2[i]->SetLineColor(kBlue);efficiency_vs_eta_real_Seed2[i]->SetLineWidth(2);
        
        
        //Tracker Efficiency for truth seed
        //----
        //Generated particle counts
        efficiency_vs_phi_truth_Seed[i] = new TH1D(Form("efficiency_vs_phi_truth_Seed[%d]",i),"Tracker Efficiency vs. reconstructed particle #phi",100,-4,4);
        efficiency_vs_phi_truth_Seed[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_truth_Seed[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_truth_Seed[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_truth_Seed[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_truth_Seed[i]->SetLineColor(kRed);efficiency_vs_phi_truth_Seed[i]->SetLineWidth(2);
        
        //Generated particle counts when at least one track found
        efficiency_vs_phi_truth_Seed2[i] = new TH1D(Form("efficiency_vs_phi_truth_Seed2[%d]",i),"Tracker Efficiency vs. reconstructed particle #phi",100,-4,4);
        efficiency_vs_phi_truth_Seed2[i]->GetXaxis()->SetTitle("#phi");efficiency_vs_phi_truth_Seed2[i]->GetXaxis()->CenterTitle();
        efficiency_vs_phi_truth_Seed2[i]->GetYaxis()->SetTitle("Efficiency");efficiency_vs_phi_truth_Seed2[i]->GetYaxis()->CenterTitle();
        efficiency_vs_phi_truth_Seed2[i]->SetLineColor(kRed);efficiency_vs_phi_truth_Seed2[i]->SetLineWidth(2);
        
        h_r_z_seed[i] = new TH2D(Form("h_r_z_seed[%d]",i), "radius vs z real seeded", 100, -25,25,100,-10,20);
        h_r_z_seed[i]->GetXaxis()->SetTitle("Reconstructed z [mm]"); h_r_z_seed[i]->GetXaxis()->CenterTitle();
        h_r_z_seed[i]->GetYaxis()->SetTitle("Reconstructed transverse DCA [mm]"); h_r_z_seed[i]->GetYaxis()->CenterTitle();
        h_r_z_seed[i] -> SetMarkerColor(kBlue);
        
        h_r_z_true[i] = new TH2D(Form("h_r_z_true[%d]",i), "radius vs z true seeded", 100,-25,25,100,-10,20);
        h_r_z_true[i]->GetXaxis()->SetTitle("Reconstructed z [mm]"); h_r_z_true[i]->GetXaxis()->CenterTitle();
        h_r_z_true[i]->GetYaxis()->SetTitle("Reconstructed transverse DCA [mm]"); h_r_z_true[i]->GetYaxis()->CenterTitle();
        h_r_z_true[i] -> SetMarkerColor(kRed);
        
        h_r_z_track[i] = new TH2D(Form("h_r_z_track[%d]",i), "radius vs z CKF with real seed", 100,-25,25,100,-10,20);
        h_r_z_track[i]->GetXaxis()->SetTitle("Reconstructed z [mm]"); h_r_z_track[i]->GetXaxis()->CenterTitle();
        h_r_z_track[i]->GetYaxis()->SetTitle("Reconstructed transverse DCA [mm]"); h_r_z_track[i]->GetYaxis()->CenterTitle();
        h_r_z_track[i] -> SetMarkerColor(kGreen);
        
        h_rec_over_gen_seed[i] = new TH2D(Form("h_rec_over_gen_seed[%d]",i), "reco/gen p vs gen_p real seed", 100, -3,23,100,-.5,5);
        h_rec_over_gen_seed[i] ->GetXaxis()->SetTitle("gen_p"); h_rec_over_gen_seed[i] ->GetXaxis()->CenterTitle();
        h_rec_over_gen_seed[i] ->GetYaxis()->SetTitle("Reco/gen p"); h_rec_over_gen_seed[i] ->GetYaxis()->CenterTitle();
        h_rec_over_gen_seed[i]  -> SetMarkerColor(kBlue);
        
        h_rec_over_gen_trk[i] = new TH2D(Form("h_rec_over_gen_trk[%d]",i), "reco/gen p vs gen_p track", 100, -3,23,100,-.5,5);
        h_rec_over_gen_trk[i] ->GetXaxis()->SetTitle("gen_p"); h_rec_over_gen_trk[i] ->GetXaxis()->CenterTitle();
        h_rec_over_gen_trk[i] ->GetYaxis()->SetTitle("Reco/gen p"); h_rec_over_gen_trk[i] ->GetYaxis()->CenterTitle();
        h_rec_over_gen_trk[i]  -> SetMarkerColor(kGreen);
        
        h_rec_over_gen_true[i] = new TH2D(Form("h_rec_over_gen_true[%d]",i), "reco/gen p vs gen_p true seed", 100, -3,23,100,-.5,5);
        h_rec_over_gen_true[i] ->GetXaxis()->SetTitle("gen_p"); h_rec_over_gen_true[i] ->GetXaxis()->CenterTitle();
        h_rec_over_gen_true[i] ->GetYaxis()->SetTitle("Reco/gen p"); h_rec_over_gen_true[i] ->GetYaxis()->CenterTitle();
        h_rec_over_gen_true[i]  -> SetMarkerColor(kRed);
        
        theta_vs_phi_real[i] = new TH2D(Form("theta_vs_phi_real [%d]",i),"theta_vs_phi_real",100,-0.5,4,100,-4,4);
        theta_vs_p_real[i] = new TH2D(Form("theta_vs_p_real [%d]",i),"theta_vs_p_real",100,-0.5,4,100,0,50);
        phi_vs_p_real[i] = new TH2D(Form("phi_vs_p_real [%d]",i),"phi_vs_p_real",100,-4,4,100,0,50);
  }
    
  //Open File

  for(int ifile=0;ifile<5;ifile++){
    TFile *f;
    if(ifile==0) f = new TFile("eicrecon_z0_200_300MeV.root");
    else if(ifile==1) f = new TFile("eicrecon_z0_300_400MeV.root");
    else if(ifile==2) f = new TFile("eicrecon_z0_400_500MeV.root");
    else if(ifile==3) f = new TFile("eicrecon_z0_500_600MeV.root");
    else if(ifile==4) f = new TFile("eicrecon_z0_600_700MeV.root");

    
        
        
    TTree *tree = (TTree*) f->Get("events");
        
    //Create Array Reader
    TTreeReader tr(tree);
        
    TTreeReaderArray<int>   gen_status(tr, "MCParticles.generatorStatus");
    TTreeReaderArray<int>   gen_pid(tr, "MCParticles.PDG");
    TTreeReaderArray<float> gen_px(tr, "MCParticles.momentum.x");
    TTreeReaderArray<float> gen_py(tr, "MCParticles.momentum.y");
    TTreeReaderArray<float> gen_pz(tr, "MCParticles.momentum.z");
    TTreeReaderArray<double> gen_mass(tr, "MCParticles.mass"); //Not important here
    TTreeReaderArray<float> gen_charge(tr, "MCParticles.charge");
    TTreeReaderArray<double> gen_vx(tr, "MCParticles.vertex.x");
    TTreeReaderArray<double> gen_vy(tr, "MCParticles.vertex.y");
    TTreeReaderArray<double> gen_vz(tr, "MCParticles.vertex.z");
        
    // real seed before ckf
    TTreeReaderArray<float> seed_qoverp(tr, "CentralTrackSeedingResults.qOverP");
    TTreeReaderArray<float> seed_theta(tr, "CentralTrackSeedingResults.theta");
    TTreeReaderArray<float> seed_phi(tr, "CentralTrackSeedingResults.phi");
    TTreeReaderArray<float> seed_loca(tr, "CentralTrackSeedingResults.loc.a"); //Local ACTS coordinates
    TTreeReaderArray<float> seed_locb(tr, "CentralTrackSeedingResults.loc.b"); //''
    //    TTreeReaderArray<float> seed_charge(tr, "CentralTrackSeedingResults.charge");
        
    // real seed after ckf
    TTreeReaderArray<float> track_qoverp(tr, "CentralCKFTrackParameters.qOverP");
    TTreeReaderArray<float> track_theta(tr, "CentralCKFTrackParameters.theta");
    TTreeReaderArray<float> track_phi(tr, "CentralCKFTrackParameters.phi");
    TTreeReaderArray<float> track_loca(tr, "CentralCKFTrackParameters.loc.a"); //Local ACTS coordinates
    TTreeReaderArray<float> track_locb(tr, "CentralCKFTrackParameters.loc.b"); //''
    // TTreeReaderArray<float> track_charge(tr, "CentralCKFSeededTrackParameters.charge");
        
    // true seed
    TTreeReaderArray<float> track_ts_qoverp(tr, "CentralCKFTruthSeededTrackParameters.qOverP");
        TTreeReaderArray<float> track_ts_theta(tr, "CentralCKFTruthSeededTrackParameters.theta");
        TTreeReaderArray<float> track_ts_phi(tr, "CentralCKFTruthSeededTrackParameters.phi");
        TTreeReaderArray<float> track_ts_loca(tr, "CentralCKFTruthSeededTrackParameters.loc.a"); //Local ACTS coordinates
        TTreeReaderArray<float> track_ts_locb(tr, "CentralCKFTruthSeededTrackParameters.loc.b"); //''
	//  TTreeReaderArray<float> track_ts_charge(tr, "CentralCKFTrackParameters.charge");


 TTreeReaderArray<unsigned int> measurement(tr, "CentralCKFTrajectories.nMeasurements");
        TTreeReaderArray<unsigned int> outlier(tr,"CentralCKFTrajectories.nOutliers");
        TTreeReaderArray<unsigned int> hole(tr, "CentralCKFTrajectories.nHoles");
              TTreeReaderArray<float> chi2(tr, "CentralCKFTruthSeededTracks.chi2");
	        TTreeReaderArray<unsigned int> ndf(tr, "CentralCKFTruthSeededTracks.ndf");

	      TTreeReaderArray<unsigned int> true_outlier(tr, "CentralCKFTruthSeededTrajectories.nOutliers");
	
        //Other variables
        TLorentzVector gen_vec;
        TVector3 gen_vertex;
        float charge;
        bool found_primary(false);
        int counter(0);
        
        int track_tot(0); //Total tracks found in all events
        int track_tot_gen(0); //Total tracks in all events associated with generated particle
        int seed_wrong(0); //number of wrong charge for real seeding before ckf
        int after_ckf_seed_wrong(0); //number of wrong charge after ckf
        int truth_seed_wrong(0);
        
        int tot_real_seed_before_ckf(0);
        int unique_real_seed_before_ckf(0);
        int tot_real_seed_after_ckf(0);
        int unique_real_seed_after_ckf(0);

	int event_with_no_seed_after_ckf(0);
	int event_with_one_seed_after_ckf(0);
	int event_with_two_seed_after_ckf(0);
	int event_with_three_seed_after_ckf(0);
	int event_with_four_seed_after_ckf(0);
	int event_with_five_seed_after_ckf(0);

	int event_with_one_unique_seed_after_ckf(0);
	int event_with_two_unique_seed_after_ckf(0);
	int event_with_three_unique_seed_after_ckf(0);
	int event_with_four_unique_seed_after_ckf(0);
	int event_with_five_unique_seed_after_ckf(0);
	
	int number_of_measurement(0);
	int number_of_outlier(0);
	int number_of_hole(0);

	int one_measurement(0);
	int two_measurement(0);
	 int three_measurement(0);
 int four_measurement(0);
 int five_measurement(0);
 int six_measurement(0);
 int seven_measurement(0);
 int eight_measurement(0);
 int nine_measurement(0);

 int zero_outlier(0);
 int one_outlier(0);
 int two_outlier(0);
 int three_outlier(0);
 int four_outlier(0);
 int five_outlier(0);
 int six_outlier(0);
 
 int one_hole(0);
int two_hole(0);
 int three_hole(0);
 int four_hole(0);
 int five_hole(0); 
	
        //Loop over events
        while (tr.Next()) {

            if(counter%100==0) cout<<"Analyzing event "<<counter<<endl;
	    //	     cout << counter << endl;
            counter++;
            
            //Reset variables
            found_primary = false;
            
            //Loop over generated particles, select primary particle (assuming single particle)
            for(int igen=0;igen<gen_status.GetSize();igen++){
                //PID requirement so that background particles are not used, but may not be needed because of 'break'
                if(gen_status[igen]==1 && gen_pid[igen]==13){
                    gen_vec.SetXYZM(gen_px[igen],gen_py[igen],gen_pz[igen],gen_mass[igen]);
                    gen_vertex.SetXYZ(gen_vx[igen],gen_vy[igen],gen_vz[igen]);
                    charge = gen_charge[igen];
                    found_primary = true;
                    break;
                }
            }
            
          
            theta_mc[ifile]->Fill(gen_vec.Theta());
           
            
            //cout << "file = " << ifile << ", charge = " << charge << endl;
            //Require primary particle for seed results
            if(found_primary)  {
                p_mc[ifile]->Fill(gen_vec.P());
                
               // cout << gen_vec.P()<< endl;
                
                int seed_mult = seed_qoverp.GetSize();
                
                if (seed_mult ==0) {cout << "event = " << counter-1 <<  " p = " << gen_vec.P() << endl;}
                
                tot_real_seed_before_ckf += seed_mult;
                
                //    cout << "seed_mult " << seed_mult << endl;
                
                efficiency_vs_eta_real_genSeed[ifile]->Fill(gen_vec.Eta());
                if(seed_mult>0) efficiency_vs_eta_real_genSeed2[ifile]->Fill(gen_vec.Eta());
                
                efficiency_vs_phi_real_genSeed[ifile]->Fill(gen_vec.Phi());
                if(seed_mult>0) efficiency_vs_phi_real_genSeed2[ifile]->Fill(gen_vec.Phi());
                
                int num_ureal(0); //Number of unique seeds
                float ureal_qop[100],ureal_theta[100],ureal_phi[100];
                
                
                //Loop over seeds.
                for(int iseed=0;iseed<seed_mult;iseed++){
		  //   cout << "irealseed = " << iseed << ", real seed mult = " << seed_mult << ", real seed_q0verp= " << seed_qoverp[iseed] << endl;
		  //check for duplicate seeds based on theta and phi
		  //Look for unique tracks


		 

		  bool found_unique = false;
                    
		  //Handle first track
		  if(num_ureal==0){
		    found_unique = true;
		    ureal_qop[num_ureal] = seed_qoverp[iseed];
		    ureal_theta[num_ureal] = seed_theta[iseed];
		    ureal_phi[num_ureal] = seed_phi[iseed];
		    // cout << "file = " << ifile << ", irealseed = " << iseed << ", seed mult = " << seed_mult << ", unique real seed_q0verp= " <<  ureal_qop[num_ureal] << endl;
		  }
                    
		  //When num_utracks>0
	//	  for(int ureal=0;ureal<num_ureal;ureal++){
		    //If current track is a duplicate, break out of loop
//		    if( //fabs( (seed_qoverp[iseed] - ureal_qop[ureal])/ureal_qop[ureal]) < dupl_cut_qop/100. &&
//		       fabs( (seed_theta[iseed] - ureal_theta[ureal]) ) < dupl_cut_angle/1000. &&
//		       fabs( (seed_phi[iseed] - ureal_phi[ureal]) ) < dupl_cut_angle/1000. ){
//		      break;
//		    }
//		    else if( ureal == (num_ureal-1) ){ //If on last unique track and have not found a dupicate
//		      found_unique = true;
                            
//		      ureal_qop[num_ureal] = seed_qoverp[iseed];
	//	      ureal_theta[num_ureal] = seed_theta[iseed];
//		      ureal_phi[num_ureal] = seed_phi[iseed];
//		    }
		    //   cout << "file = " << ifile << ", irealseed = " << iseed << ", real seed mult = " << seed_mult << ", unique real seed_q0verp= " <<  ureal_qop[num_ureal] << endl;
//		  }
//		  if(found_unique)
                    {
		      num_ureal++;


		      q_over_p_before[ifile]->Fill((seed_qoverp[iseed])-(charge/gen_vec.P()));
		      phi_mc[ifile]->Fill(gen_vec.Phi());
		      //Fill histograms using all found seeds
                        
		      //Momentum Resolution in percent
		      auto seed_p = fabs(charge/seed_qoverp[iseed]); //I use gen charge, but just checking momentum magnitude here
                      //  cout << "file = " << ifile << ", irealseed = " << iseed << ", real seed mult = " << seed_mult << ", real p= " <<  seed_p << endl;
              

		      auto p_res =  100. * (seed_p - gen_vec.P()) / gen_vec.P() ;
		      p_res_seed[ifile]->Fill(p_res);
		      p_seed[ifile]->Fill(seed_p);
		      //cout << "file = " << ifile << ", seed = " << iseed << ", p = " << gen_vec.P() << endl;
                        
		      auto p_ratio = seed_p / gen_vec.P();
		      h_rec_over_gen_seed[ifile]->Fill(gen_vec.P(),p_ratio);
		      // h_rec_over_gen_seed[ifile]->FitSlicesY();
                        
		      // cout << "file = " << ifile << ", seed = " << iseed << ", mc pz = " << gen_vec.P()*sin(gen_vec.Theta()) << ", real seed pz = " << seed_p * sin(seed_theta[iseed]) << endl;
                        
		      //Theta Resolution in radians
		      auto theta_res = 1000. * (seed_theta[iseed] - gen_vec.Theta());
		      theta_res_seed[ifile]->Fill(theta_res);
		      //		      theta_seed[ifile]->Fill(seed_theta[iseed]);
                        theta_seed[ifile]->Fill(0);      
		      double eta = -TMath::Log(TMath::Tan(seed_theta[iseed]/2));
                                                
		      auto gen_pz = gen_vec.P()*cos(gen_vec.Theta());
		      auto seed_pz = seed_p * cos(seed_theta[iseed]);
		      pz_ratio_seed[ifile]->Fill(gen_pz, (seed_pz/gen_pz));
		      //  pz_ratio_seed[ifile]-> FitSlicesY();
                        
                        
		      // cout << "file = " << ifile << ", seed = " << iseed << ", pz seed raito = " << seed_pz/gen_pz << endl;
                        
		      auto gen_pt = gen_vec.P()*sin(gen_vec.Theta());
		      auto seed_pt = seed_p * sin(seed_theta[iseed]);
		      pt_ratio_seed[ifile]->Fill(gen_pt, seed_pt/gen_pt);
		      //   pt_ratio_seed[ifile]->FitSlicesY();
                        
		      //Phi Resolution in radians
		      auto phi_res = 1000. * ((seed_phi[iseed]) - (gen_vec.Phi()));
		      phi_res_seed[ifile]->Fill(phi_res);
		      phi_seed[ifile]->Fill(seed_phi[iseed]);
                        
		      //		      cout << "file = " << ifile << ", event = " << counter <<", iseed = " << iseed << ", seed mult = " << seed_mult << " seed phi = " <<  seed_phi[iseed] << " mc phi = " << gen_vec.Phi() << endl;
                        
		      theta_vs_phi_real[ifile]->Fill(seed_theta[iseed],seed_phi[iseed]);
		      theta_vs_p_real[ifile]->Fill(seed_theta[iseed],seed_p);
		      phi_vs_p_real[ifile]->Fill(seed_phi[iseed],seed_p);
                        
		      //Loca resolution in mm.
		      //I think this corresponds to r for the defined perigee surface.
		      auto gen_radius = sqrt( gen_vertex.X()*gen_vertex.X() + gen_vertex.Y()*gen_vertex.Y() );
		      //   cout << "file = " << ifile << ", gen_radius = " << gen_radius << ", gen_z = " << gen_vertex.Z() << endl;
		      //cout << ifile << " " << seed_loca[iseed] << endl;
		      auto loca_res = seed_loca[iseed] - gen_radius;
		      r_seed[ifile]->Fill(seed_loca[iseed]);
                        
		      //Locb resolution in mm.
		      //I think this corresponds to z for the defined perigee surface.
		      auto locb_res = seed_locb[iseed] - gen_vertex.Z();
		      z_seed[ifile]->Fill(seed_locb[iseed]);
                        
		      //Seed charge
		      charge_seed[ifile]->Fill(seed_qoverp[iseed]/fabs(seed_qoverp[iseed]));
		      //  cout << "file = " << ifile << "charge_seed = " << seed_charge[iseed] << endl;
                        
		      if (seed_qoverp[iseed] > 0){
			//			cout << "file = " << ifile << ", event = " << counter <<", iseed = " << iseed << ", seed mult = " << seed_mult << ", mc charge = " << charge << " , seed charge = " << seed_charge[iseed] << " iseed p = " << seed_p << " seed theta = " << seed_theta[iseed] << " seed phi = " << seed_phi[iseed] << " mc phi = " << gen_vec.Phi() << endl;
			seed_wrong++;
			pt_vs_phi_for_wrong_charge_seed[ifile]->Fill(seed_phi[iseed],seed_pt);
			pt_vs_eta_for_wrong_charge_seed[ifile]->Fill(eta,seed_pt);
                           
		      }
		      //		      pt_vs_phi_seed[ifile]->Fill(seed_phi[iseed],seed_pt);

		      pt_vs_phi_seed[ifile]->Fill(seed_theta[iseed],seed_phi[iseed]);
		      //	pt_vs_eta_seed[ifile]->Fill(eta,seed_pt);
		      pt_vs_eta_seed[ifile]->Fill(seed_locb[iseed],seed_loca[iseed]);
		     		      h_r_z_seed[ifile]->Fill(seed_locb[iseed],seed_loca[iseed]);
                        
                    }
                } //End loop over seeds
                
                unique_real_seed_before_ckf += num_ureal;
                
                
                int track_ts_mult = track_ts_qoverp.GetSize();
                
                efficiency_vs_eta_truth_genSeed[ifile]->Fill(gen_vec.Eta());
                if(track_ts_mult>0) efficiency_vs_eta_truth_genSeed2[ifile]->Fill(gen_vec.Eta());
                
                efficiency_vs_phi_truth_genSeed[ifile]->Fill(gen_vec.Phi());
                if(track_ts_mult>0) efficiency_vs_phi_truth_genSeed2[ifile]->Fill(gen_vec.Phi());
                
                int num_utrue(0); //Number of unique seeds
                float utrue_qop[100],utrue_theta[100],utrue_phi[100];
                
                for(int itrue=0;itrue<track_ts_mult;itrue++){
                    
                    //  cout << "itrue = " << itrue << ", true mult = " << track_ts_mult << ", true_q0verp= " << track_ts_qoverp[itrue] << endl;
                    //Look for unique tracks
                    bool found_unique = false;
                    
                    //Handle first track
                    if(num_utrue==0){
                        found_unique = true;
                        utrue_qop[num_utrue] = track_ts_qoverp[itrue];
                        utrue_theta[num_utrue] = track_ts_theta[itrue];
                        utrue_phi[num_utrue] = track_ts_phi[itrue];
                        //   cout << "file = " << ifile << ", event = " << counter << ", itrue = " << itrue << ", true mult = " << track_ts_mult << ", unique true_q0verp= " <<  utrue_qop[num_utrue] << " , unique true theta = " << utrue_theta[num_utrue] << " , unique true phi = " << utrue_phi[num_utrue] << ", mc charge = " << gen_charge[ifile] << " , true charge = " << track_charge[itrack] << endl;
                    }
                    
                    //When num_utracks>0
        //         for(int utrue=0;utrue<num_utrue;utrue++){
                        //If current track is a duplicate, break out of loop
             //           if(//fabs( (track_ts_qoverp[itrue] - utrue_qop[utrue])/utrue_qop[utrue] ) < dupl_cut_qop/100. &&
             //              fabs( (track_ts_theta[itrue] - utrue_theta[utrue]) ) < dupl_cut_angle/1000. &&
              //             fabs( (track_ts_phi[itrue] - utrue_phi[utrue]) ) < dupl_cut_angle/1000. ){
             //                  break;
            //               }
            //            else if( utrue == (num_utrue-1) ){ //If on last unique track and have not found a dupicate
            //                found_unique = true;
                            
              //              utrue_qop[num_utrue] = track_ts_qoverp[itrue];
             //               utrue_theta[num_utrue] = track_ts_theta[itrue];
             //               utrue_phi[num_utrue] = track_ts_phi[itrue];
             //           }
                        //   cout << "file = " << ifile << ", event = " << counter << ", itrue = " << itrue << ", true mult = " << track_ts_mult << ", unique true_q0verp= " <<  utrue_qop[num_utrue] << " , unique true theta = " << utrue_theta[num_utrue] << " , unique true phi = " << utrue_phi[num_utrue] << endl;
              //      }
                    
		//  if(found_unique)
                    {
		      num_utrue++;
                        
		      q_over_p_truth[ifile]->Fill((track_ts_qoverp[itrue])-(charge/gen_vec.P()));
		      auto true_p = fabs(charge/track_ts_qoverp[itrue]);
		      //   cout << "file = " << ifile << ", event = " << counter <<", itrue = " << itrue << ", true mult = " << track_ts_mult  << ", mc charge = " << charge << " , true charge = " << track_ts_charge[itrue]  << endl;

		      //		     		        if (true_outlier[itrue] == 0) {p_for_outlier0[ifile]->Fill(true_p);eta_for_outlier0[ifile]->Fill(gen_vec.Eta()); phi_for_outlier0[ifile]->Fill(track_ts_phi[itrue]);}
		      //
		      //		else if (true_outlier[itrue] == 1) {p_for_outlier1[ifile]->Fill(true_p);eta_for_outlier1[ifile]->Fill(gen_vec.Eta()); phi_for_outlier1[ifile]->Fill(track_ts_phi[itrue]);}
		      //else if (true_outlier[itrue] == 2) {p_for_outlier2[ifile]->Fill(true_p);eta_for_outlier2[ifile]->Fill(gen_vec.Eta());phi_for_outlier2[ifile]->Fill(track_ts_phi[itrue]);}
		      //    else if (true_outlier[itrue] == 3) {p_for_outlier3[ifile]->Fill(true_p);eta_for_outlier3[ifile]->Fill(gen_vec.Eta()); phi_for_outlier3[ifile]->Fill(track_ts_phi[itrue]);}
		      //      else if (true_outlier[itrue] == 4) {p_for_outlier4[ifile]->Fill(true_p);eta_for_outlier4[ifile]->Fill(gen_vec.Eta()); phi_for_outlier4[ifile]->Fill(track_ts_phi[itrue]);}
		      //        else if (true_outlier[itrue] == 5) {p_for_outlier5[ifile]->Fill(true_p);eta_for_outlier5[ifile]->Fill(gen_vec.Eta());phi_for_outlier5[ifile]->Fill(track_ts_phi[itrue]);}
		      //          else if (true_outlier[itrue] == 6) {p_for_outlier6[ifile]->Fill(true_p);eta_for_outlier6[ifile]->Fill(gen_vec.Eta());phi_for_outlier6[ifile]->Fill(track_ts_phi[itrue]);}



		      
		      auto p_res = 100. * (true_p - gen_vec.P()) / gen_vec.P() ;
		      p_res_true[ifile]->Fill(p_res);
		      p_true[ifile]->Fill(true_p);

		      
		      auto p_ratio = true_p / gen_vec.P();
		      h_rec_over_gen_true[ifile]->Fill(gen_vec.P(),p_ratio);
		      //    h_rec_over_gen_true[ifile]-> FitSlicesY();
                        
               
		      //		      if (track_ts_theta[itrue]>0.6 && track_ts_theta[itrue] < 1) {cout << " events truth seed = " << counter-1 << " true theta = " << track_ts_theta[itrue] << endl;
		      //			  cout << "p = " << true_p << endl;}
		       
		      //Theta Resolution in radians
		      auto theta_res = 1000. * (track_ts_theta[itrue] - gen_vec.Theta());
		      theta_res_true[ifile]->Fill(theta_res);
		      theta_true[ifile]->Fill(track_ts_theta[itrue]);
                        
		      auto gen_pz = gen_vec.P()*cos(gen_vec.Theta());
		      auto true_pz = true_p * cos(track_ts_theta[itrue]);
		      pz_ratio_true[ifile]->Fill(gen_pz, true_pz/gen_pz);
		      //  pz_ratio_true[ifile]-> FitSlicesY();
                        
		      auto gen_pt = gen_vec.P()*sin(gen_vec.Theta());
		      auto true_pt = true_p * sin(track_ts_theta[itrue]);
		      pt_ratio_true[ifile]->Fill(gen_pt, (true_pt/gen_pt));
		      //    pt_ratio_true[ifile]->FitSlicesY();
                        
		      //Phi Resolution in radians
		      auto phi_res = 1000. * ((track_ts_phi[itrue]) - (gen_vec.Phi()));
		      phi_res_true[ifile]->Fill(phi_res);
		      phi_true[ifile]->Fill(track_ts_phi[itrue]);
                        
		      //Loca resolution in mm.
		      //I think this corresponds to r for the defined perigee surface.
		      auto gen_radius = sqrt( gen_vertex.X()*gen_vertex.X() + gen_vertex.Y()*gen_vertex.Y() );
		      // cout << ifile << " " << track_ts_loca[itrue] << endl;
		      auto loca_res = track_ts_loca[itrue] - gen_radius;
		      r_true[ifile]->Fill(track_ts_loca[itrue]);
                        
		      auto locb_res = track_ts_locb[itrue] - gen_vertex.Z();
		      z_true[ifile]->Fill(track_ts_locb[itrue]);
                        
		      h_r_z_true[ifile]->Fill(track_ts_locb[itrue], track_ts_loca[itrue]);
                        
		       charge_true[ifile]->Fill(track_ts_qoverp[itrue]/fabs(track_ts_qoverp[itrue]));
                        
		      if (track_ts_qoverp[itrue] > 0) {
			//			cout << "file = " << ifile << ", event = " << counter <<", itrue = " << itrue << ", true mult = " << track_ts_mult << ", mc charge = " << charge << " , true charge = " << track_ts_charge[itrue] << " true p = " << true_p << " theta true = " << track_ts_theta[itrue] << " phi true = " << track_ts_phi[itrue] << endl;
                            truth_seed_wrong++;

                           
                        }
                        
                        // cout << "file = " << ifile << "charge_true = " << track_ts_charge[itrue] << endl;
                    }
                }
                
                
                
                //Loop over tracks.
                int track_mult = track_qoverp.GetSize();

		if (track_mult == 0) event_with_no_seed_after_ckf++;
		else if (track_mult == 1) event_with_one_seed_after_ckf++;
		else if	(track_mult == 2) event_with_two_seed_after_ckf++;
		else if	(track_mult == 3) event_with_three_seed_after_ckf++;
		else if	(track_mult == 4) event_with_four_seed_after_ckf++;
		else if	(track_mult == 5) event_with_five_seed_after_ckf++;



		//   cout << "track_mult= " << track_mult << endl;
                tot_real_seed_after_ckf += track_mult;
                
                num_trk_vs_particle_eta[ifile]->Fill(gen_vec.Eta(),track_mult);
                
                efficiency_vs_eta_gentrack[ifile]->Fill(gen_vec.Eta());
                if(track_mult>0) efficiency_vs_eta_gentrack2[ifile]->Fill(gen_vec.Eta());
                
                efficiency_vs_phi_gentrack[ifile]->Fill(gen_vec.Phi());
                if(track_mult>0) efficiency_vs_phi_gentrack2[ifile]->Fill(gen_vec.Phi());
                
               num_track[ifile]->Fill(track_mult);
                
                int num_utracks(0); //Number of unique seeds
                float utrack_qop[100],utrack_theta[100],utrack_phi[100];
                
                for(int itrack=0;itrack<track_mult;itrack++){
                    
                 //   cout << "file = " << ifile << ", event = " << counter << ", itrack = " << itrack << ", track mult = " << track_mult  << ", gen p = " << gen_vec.P() << ", track p = " << fabs(charge/track_qoverp[itrack]) << ", track theta = " << track_theta[itrack] << ", track phi = " << track_phi[itrack] << " , mc phi = " << gen_vec.Phi() << endl;
                    
                    //Look for unique tracks
                    bool found_unique = false;

		        double eta_ckf = -TMath::Log(TMath::Tan(track_theta[itrack]/2));

			
			// pt_vs_eta_ckf[ifile]->Fill(eta_ckf,fabs(charge/track_qoverp[itrack])*sin(track_theta[itrack]));   
		    
                    //Handle first track
                    if(num_utracks==0){
                        found_unique = true;
                        utrack_qop[num_utracks] = track_qoverp[itrack];
                        utrack_theta[num_utracks] = track_theta[itrack];
                        utrack_phi[num_utracks] = track_phi[itrack];
                 //       cout << "file = " << ifile << ", event = " << counter << ", itrack = " << itrack << ", track mult = " << track_mult << ", unique track_q0verp= " <<  utrack_qop[num_utracks] << ", unique track theta = " << utrack_theta[num_utracks] << ", unique track phi = " << utrack_phi[num_utracks] << endl;;
                    }
                   
                   
                    //When num_utracks>0
     //               for(int utrack=0;utrack<num_utracks;utrack++){
                        //If current track is a duplicate, break out of loop
//		      if(//fabs( (track_qoverp[itrack] - utrack_qop[utrack])/utrack_qop[utrack]) < dupl_cut_qop/100. &&
//			 fabs( (track_theta[itrack] - utrack_theta[utrack]) ) < dupl_cut_angle/1000. &&
//			 fabs( (track_phi[itrack] - utrack_phi[utrack]) ) < dupl_cut_angle/1000. ){
//			break;
//		      }
	//	      else if( utrack == (num_utracks-1) ){ //If on last unique track and have not found a dupicate
	//		found_unique = true;
                            
	//		utrack_qop[num_utracks] = track_qoverp[itrack];
//			utrack_theta[num_utracks] = track_theta[itrack];
//			utrack_phi[num_utracks] = track_phi[itrack];
//		      }
		      //    cout << "file = " << ifile << ", event = " << counter << ", itrack = " << itrack << ", track mult = " << track_mult << ", unique track_q0verp= " <<  utrack_qop[num_utracks] << ", unique track theta = " << utrack_theta[num_utracks] << ", unique track phi = " << utrack_phi[num_utracks] << endl;
  //                  }
    //                if(found_unique )
		      {
                        num_utracks++;

			//			q_over_p_after[ifile]->Fill((track_qoverp[itrack])-(charge/gen_vec.P()));
			 chi[ifile]->Fill(chi2[itrack]/ndf[itrack]);  
		    
			//		nmeasurement[ifile]->Fill(measurement[itrack]);
			//			number_of_measurement += measurement[itrack];
              
                        
                        //Fill histograms using all found tracks
                        
                        //Momentum Resolution in percent
                        auto track_p = fabs(charge/track_qoverp[itrack]); //I use gen charge, but just checking momentum magnitude here
			//   cout << "file = " << ifile << ", event = " << counter << ", itrack = " << itrack << ", ckf mult = " << track_mult <<  ", mc charge = " << charge << " , ckf charge = " << track_charge[itrack] << endl;
                        
                        auto p_res = 100. * (track_p - gen_vec.P()) / gen_vec.P() ;
                        p_res_trk[ifile]->Fill(p_res);
                        p_trk[ifile]->Fill(track_p);

		       	if (outlier[itrack] == 0) {p_for_outlier0[ifile]->Fill(track_p);eta_for_outlier0[ifile]->Fill(gen_vec.Eta()); phi_for_outlier0[ifile]->Fill(track_phi[itrack]); chi_for_outlier0[ifile]->Fill(chi2[itrack]/ndf[itrack]);}
			else if (outlier[itrack] == 1) {p_for_outlier1[ifile]->Fill(track_p);eta_for_outlier1[ifile]->Fill(gen_vec.Eta()); phi_for_outlier1[ifile]->Fill(track_phi[itrack]); chi_for_outlier1[ifile]->Fill(chi2[itrack]/ndf[itrack]);}
			else if (outlier[itrack] == 2) {p_for_outlier2[ifile]->Fill(track_p);eta_for_outlier2[ifile]->Fill(gen_vec.Eta());phi_for_outlier2[ifile]->Fill(track_phi[itrack]);chi_for_outlier2[ifile]->Fill(chi2[itrack]/ndf[itrack]);}
			    else if (outlier[itrack] == 3) {p_for_outlier3[ifile]->Fill(track_p);eta_for_outlier3[ifile]->Fill(gen_vec.Eta()); phi_for_outlier3[ifile]->Fill(track_phi[itrack]);chi_for_outlier3[ifile]->Fill(chi2[itrack]/ndf[itrack]);}
			      else if (outlier[itrack] == 4) {p_for_outlier4[ifile]->Fill(track_p);eta_for_outlier4[ifile]->Fill(gen_vec.Eta()); phi_for_outlier4[ifile]->Fill(track_phi[itrack]); chi_for_outlier4[ifile]->Fill(chi2[itrack]/ndf[itrack]);}
				else if (outlier[itrack] == 5) {p_for_outlier5[ifile]->Fill(track_p);eta_for_outlier5[ifile]->Fill(gen_vec.Eta());phi_for_outlier5[ifile]->Fill(track_phi[itrack]); chi_for_outlier5[ifile]->Fill(chi2[itrack]/ndf[itrack]);}
				else if (outlier[itrack] == 6) {p_for_outlier6[ifile]->Fill(track_p);eta_for_outlier6[ifile]->Fill(gen_vec.Eta());phi_for_outlier6[ifile]->Fill(track_phi[itrack]); chi_for_outlier6[ifile]->Fill(chi2[itrack]/ndf[itrack]);}

			 for (int i=0; i<16; i++)
                        {
			  for(int k=0; k<20; k++){
                            if (gen_vec.Eta() > (-4 + 0.5*i) && gen_vec.Eta() < (-4 + 0.5 * (i+1)) && gen_vec.P() > (0+k) && gen_vec.P() < ((k+1)))
                                p_res_eta[i][k][ifile]->Fill(p_res);
			  }}
                        
                        auto p_ratio = track_p / gen_vec.P();
                        h_rec_over_gen_trk[ifile]->Fill(gen_vec.P(),p_ratio);
                        //    h_rec_over_gen_trk[ifile]->FitSlicesY();
                        
                        //Theta Resolution in milli-radians
                        auto theta_res = 1000. * (track_theta[itrack] - gen_vec.Theta());
                        theta_res_trk[ifile]->Fill(theta_res);
			// theta_trk[ifile]->Fill(track_theta[itrack]);
                        theta_trk[ifile]->Fill(0);   
                        auto gen_pz = gen_vec.P()*cos(gen_vec.Theta());
                        auto trk_pz = track_p * cos(track_theta[itrack]);
                        pz_ratio_track[ifile]->Fill(gen_pz, trk_pz/gen_pz);
                        //      pz_ratio_track[ifile]->FitSlicesY();
                        
                        auto gen_pt = gen_vec.P()*sin(gen_vec.Theta());
                        auto trk_pt = track_p * sin(track_theta[itrack]);
                        pt_ratio_track[ifile]->Fill(gen_pt, (trk_pt/gen_pt));
                        //    pt_ratio_track[ifile]->FitSlicesY();


			//			 double eta_ckf = -TMath::Log(TMath::Tan(track_theta[itrack]/2));

			
                        //Phi Resolution in milli-radians
                        auto phi_res = 1000. * ((track_phi[itrack]) - (gen_vec.Phi()));
                        //   cout << "track_phi" << itrack << " = " << track_phi[itrack] << endl;
                        phi_res_trk[ifile]->Fill(phi_res);
                        phi_trk[ifile]->Fill(track_phi[itrack]);
                        
                        //Loca resolution in mm.
                        //I think this corresponds to r for the defined perigee surface.
                        auto gen_radius = sqrt( gen_vertex.X()*gen_vertex.X() + gen_vertex.Y()*gen_vertex.Y() );
                        auto loca_res = track_loca[itrack] - gen_radius;
                        r_trk[ifile]->Fill(track_loca[itrack]);
                        
                        //Locb resolution in mm.
                        //I think this corresponds to z for the defined perigee surface.
                        auto locb_res = track_locb[itrack] - gen_vertex.Z();
                        z_trk[ifile]->Fill(track_locb[itrack]);
                        
                        //track charge
			 charge_trk[ifile]->Fill(track_qoverp[itrack]/fabs(track_qoverp[itrack]));
                        
			   if (track_qoverp[itrack] > 0){
			     //  cout << "file = " << ifile << ", event = " << counter <<", ickf = " << itrack << ", ckf mult = " << track_mult << ", mc charge = " << charge << " , after ckf charge = " << track_charge[itrack] << " ckf p = " << track_p << " ckf theta = " << track_theta[itrack] << " ckf phi " << track_phi[itrack] << endl;
			  after_ckf_seed_wrong++;

                           
                        }
                        
                        
                        h_r_z_track[ifile]->Fill(track_locb[itrack],track_loca[itrack]);
                        
                        //Total number of tracks
                        //require 10% for momentum and 10 mRad for angles for association
                        track_tot++;
                        if( fabs(p_res)<10 && fabs(theta_res)<10 && fabs(phi_res)<10) track_tot_gen++;


				pt_vs_eta_ckf[ifile]->Fill(eta_ckf,track_p);

			
		      }

		     q_over_p_after[ifile]->Fill((track_qoverp[itrack])-(charge/gen_vec.P()));

                        nmeasurement[ifile]->Fill(measurement[itrack]);
                        number_of_measurement += measurement[itrack];

                         if (measurement[itrack] == 1) one_measurement++;
                    else if (measurement[itrack] == 2) two_measurement++;
                     else if (measurement[itrack] == 3) three_measurement++;
                     else if (measurement[itrack] == 4) four_measurement++;
                     else if (measurement[itrack] == 5) five_measurement++;
                     else if (measurement[itrack] == 6) six_measurement++;
                     else if (measurement[itrack] == 7) seven_measurement++;
                     else if (measurement[itrack] == 8) eight_measurement++;
                     else if (measurement[itrack] == 9) nine_measurement++;

			 if (outlier[itrack] == 0) zero_outlier++;
                         else if (outlier[itrack] == 1) one_outlier++;
                          else if (outlier[itrack] == 2) two_outlier++;
                          else if (outlier[itrack] == 3) three_outlier++;
                          else if (outlier[itrack] == 4) four_outlier++;
                          else if (outlier[itrack] == 5) five_outlier++;
			  else if (outlier[itrack] == 6) six_outlier++;

                          if (hole[itrack]==1) one_hole++;
                          else if (hole[itrack]==2) two_hole++;
                           else if (hole[itrack]==3) three_hole++;
                           else if (hole[itrack]==4) four_hole++;
			   else if (hole[itrack]==5) five_hole++;

                          noutlier[ifile]->Fill(outlier[itrack]);
                        number_of_outlier += outlier[itrack];

                        nhole[ifile]->Fill(hole[itrack]);
                        number_of_hole += hole[itrack];
			//                                   chi[ifile]->Fill(chi2[itrack]);                                                                                                                                                                                                                                                                                               
                          nmeasurement_vs_noutlier[ifile]->Fill(measurement[itrack],outlier[itrack]);


		    
		} //End loop over tracks
                unique_trk_vs_particle_eta[ifile]->Fill(gen_vec.Eta(),num_utracks);
                unique_real_seed_after_ckf += num_utracks;

		//		int tot_measurement = measurement.GetSize();

		//    for (int i=0; i<tot_measurement;i++)
		  //     {
		  //       nmeasurement[ifile]->Fill(measurement[i]);
		    //      noutlier[ifile]->Fill(outlier[i]);
		    //     nhole[ifile]->Fill(hole[i]);
		    //    chi[ifile]->Fill(chi2[i]);
		    //        nmeasurement_vs_noutlier[ifile]->Fill(measurement[i],outlier[i]);
		    //                }

		if (num_utracks == 1) event_with_one_unique_seed_after_ckf++;
		else if (num_utracks == 2) event_with_two_unique_seed_after_ckf++;
		else if (num_utracks == 3) event_with_three_unique_seed_after_ckf++;
		else if (num_utracks == 4) event_with_four_unique_seed_after_ckf++;
		else if (num_utracks == 5) event_with_five_unique_seed_after_ckf++;


		
            } //End if found primary
        } //End loop over events
        
        cout << "wrong charge before ckf = " << seed_wrong << endl;
        cout << "wrong charge after ckf = " << after_ckf_seed_wrong << endl;
        cout << "wrong charge truth seed = " << truth_seed_wrong << endl;
        
        
        cout<<endl;
        cout<<"---------------"<<endl;
        cout<<"Total number of found tracks = "<<track_tot<<"!"<<endl;
        cout<<"Total number of found tracks associated with generated particle = "<<track_tot_gen<<"!"<<endl;
        cout<<"---------------"<<endl;
        cout<<endl;
        
        cout<<"Total real seed before ckf = "<<tot_real_seed_before_ckf<<"!"<<endl;
        cout<<"unique real seed before ckf = "<<unique_real_seed_before_ckf<<"!"<<endl;
        
        cout<<"Total real seed after ckf = "<<tot_real_seed_after_ckf<<"!"<<endl;
        cout<<"unique real seed after ckf = "<<unique_real_seed_after_ckf<<"!"<<endl;
        cout<<endl;

	cout << "event with 0 seed after ckf = " << event_with_no_seed_after_ckf << endl;
	cout <<	"event with 1 seed after ckf = " << event_with_one_seed_after_ckf << endl;
	cout << "event with 1 unique seed after ckf = " << event_with_one_unique_seed_after_ckf << endl;

	cout <<	"event with 2 seed after ckf = " << event_with_two_seed_after_ckf << endl;
	cout << "event with 2 unique seed after ckf = " << event_with_two_unique_seed_after_ckf << endl;

	cout <<	"event with 3 seed after ckf = " << event_with_three_seed_after_ckf << endl;
	cout << "event with 3 unique seed after ckf = " << event_with_three_unique_seed_after_ckf << endl;

	cout <<	"event with 4 seed after ckf = " << event_with_four_seed_after_ckf << endl;
	cout << "event with 4 unique seed after ckf = " << event_with_four_unique_seed_after_ckf << endl;

	cout <<	"event with 5 seed after ckf = " << event_with_five_seed_after_ckf << endl;
	cout << "event with 5 unique seed after ckf = " << event_with_five_unique_seed_after_ckf << endl;

        //Scale and divide histograms
        eta_efficiency_gentrack[ifile] = (TH1*) efficiency_vs_eta_gentrack2[ifile]->Clone("eta_efficiency_gentrack");
        eta_efficiency_gentrack[ifile]->Divide(efficiency_vs_eta_gentrack[ifile]);
        
        eta_efficiency_real_genseed[ifile] = (TH1*) efficiency_vs_eta_real_genSeed2[ifile]->Clone("eta_efficiency_real_genseed");
        eta_efficiency_real_genseed[ifile]->Divide(efficiency_vs_eta_real_genSeed[ifile]);
        
        eta_efficiency_truth_genseed[ifile] = (TH1*) efficiency_vs_eta_truth_genSeed2[ifile]->Clone("eta_efficiency_real_genseed");
        eta_efficiency_truth_genseed[ifile]->Divide(efficiency_vs_eta_truth_genSeed[ifile]);

        
        phi_efficiency_gentrack[ifile] = (TH1*) efficiency_vs_phi_gentrack2[ifile]->Clone("phi_efficiency_gentrack");
        phi_efficiency_gentrack[ifile]->Divide(efficiency_vs_phi_gentrack[ifile]);
        
        phi_efficiency_real_genseed[ifile] = (TH1*) efficiency_vs_phi_real_genSeed2[ifile]->Clone("phi_efficiency_real_genseed");
        phi_efficiency_real_genseed[ifile]->Divide(efficiency_vs_phi_real_genSeed[ifile]);
        
        phi_efficiency_truth_genseed[ifile] = (TH1*) efficiency_vs_phi_truth_genSeed2[ifile]->Clone("phi_efficiency_real_genseed");
        phi_efficiency_truth_genseed[ifile]->Divide(efficiency_vs_phi_truth_genSeed[ifile]);
       
        num_track[ifile]->Scale(1./counter);
        
        //h_rec_over_gen_trk->FitSlicesX();
        //h_rec_over_gen_seed->FitSlicesX();
        // h_rec_over_gen_true->FitSlicesX();
        





		cout << "mean q/p res before ckf = " << q_over_p_before[ifile]->GetMean() << ", mean error  = " << q_over_p_before[ifile]->GetMeanError() << endl;
		cout << "mean q/p res after ckf = " << q_over_p_after[ifile]->GetMean() << ", mean error = " << q_over_p_after[ifile]->GetMeanError() << endl;
	 cout << "mean q/p res truth = " << q_over_p_truth[ifile]->GetMean() << ", mean error = " << q_over_p_truth[ifile]->GetMeanError() << endl;

	 cout << "mean loc a res after ckf = " << r_trk[ifile]->GetMean() << ", mean error = " << r_trk[ifile]->GetMeanError() << endl;
	 cout << "mean loc b res after ckf = " << z_trk[ifile]->GetMean() << ", mean error = "	<< z_trk[ifile]->GetMeanError() << endl;

	 cout << "mean theta res after ckf = " << theta_res_trk[ifile]->GetMean() << ", mean error = " << theta_res_trk[ifile]->GetMeanError() << endl;
	 cout << "mean phi res after ckf = " << phi_res_trk[ifile]->GetMean() << ", mean error = " << phi_res_trk[ifile]->GetMeanError() << endl;
	 
	 cout << "number of measurement = " << number_of_measurement << endl;
	 cout << "number of outlier = " << number_of_outlier <<	endl;
	 cout << "number of hole = " << number_of_hole  << endl;

	 cout << "one measurement = " << one_measurement << endl;
	 cout << "two measurement = " << two_measurement << endl;
	 cout << "three measurement = " << three_measurement << endl;
	 cout << "four measurement = " << four_measurement << endl;
	   cout << "five measurement = " << five_measurement << endl;
	 cout << "six measurement = " << six_measurement << endl;
	 cout << "seven measurement = " << seven_measurement << endl;
	 cout << "eight measurement = " << eight_measurement << endl;
	 cout << "nine measurement = " << nine_measurement << endl;

	   cout << "zero outlier = " << zero_outlier << endl;
	 cout << "one outlier = " << one_outlier << endl;
	 cout << "two outlier = " << two_outlier << endl;
	 cout << "three outlier = " << three_outlier << endl;
	 cout << "four outlier = " << four_outlier << endl;
	 cout << "five outlier = " << five_outlier << endl;
	 cout << "six outlier = " << six_outlier << endl;
	   
	 cout <<"one hole = " << one_hole << endl;
	 cout <<"two hole = " << two_hole << endl;
	 cout <<"three hole = " << three_hole << endl;
	 cout <<"four hole = " << four_hole << endl;
	  cout <<"five hole = " << five_hole << endl;

  }// end loop over files
    
   // h_rec_over_gen_trk[0]->FitSlicesY();
    
    
    
  //Make plots



	//TCanvas *p_res_eta_80_c = new TCanvas("p_res_eta_80_c");
	//  p_res_eta_80_c->Divide(4,4);
	//   for (int j=0; j<16; j++)
	// {
	//  p_res_eta_80_c->cd(j); p_res_eta_[j+62][0]->Draw("same");
	//  }
  
  TCanvas *nmeasurements = new TCanvas("nmeasurements");
    nmeasurements->Divide(2,3);
    nmeasurements->cd(1);nmeasurement[0]->Draw();
    nmeasurements->cd(2);nmeasurement[1]->Draw();
    nmeasurements->cd(3);nmeasurement[2]->Draw();
    nmeasurements->cd(4);nmeasurement[3]->Draw();
    nmeasurements->cd(5);nmeasurement[4]->Draw();
    
    TCanvas *noutliers = new TCanvas("noutliers");
    noutliers->Divide(2,3);
    noutliers->cd(1);noutlier[0]->Draw();
    noutliers->cd(2);noutlier[1]->Draw();
    noutliers->cd(3);noutlier[2]->Draw();
    noutliers->cd(4);noutlier[3]->Draw();
    noutliers->cd(5);noutlier[4]->Draw();
    
    TCanvas *nholes = new TCanvas("nholes");
    nholes->Divide(2,3);
    nholes->cd(1);nhole[0]->Draw();
    nholes->cd(2);nhole[1]->Draw();
    nholes->cd(3);nhole[2]->Draw();
    nholes->cd(4);nhole[3]->Draw();
    nholes->cd(5);nhole[4]->Draw();
    
    
    TCanvas *nchi= new TCanvas("nchi");
    nchi->Divide(2,3);
    nchi->cd(1);chi[0]->Draw();
    nchi->cd(2);chi[1]->Draw();
    nchi->cd(3);chi[2]->Draw();
    nchi->cd(4);chi[3]->Draw();
    nchi->cd(5);chi[4]->Draw();
    
    TCanvas *nmeasurement_vs_noutliers= new TCanvas("nmeasurement_vs_noutliers");
    nmeasurement_vs_noutliers->Divide(2,3);
    nmeasurement_vs_noutliers->cd(1);nmeasurement_vs_noutlier[0]->Draw("colz");
    nmeasurement_vs_noutliers->cd(2);nmeasurement_vs_noutlier[1]->Draw("colz");
    nmeasurement_vs_noutliers->cd(3);nmeasurement_vs_noutlier[2]->Draw("colz");
    nmeasurement_vs_noutliers->cd(4);nmeasurement_vs_noutlier[3]->Draw("colz");
    nmeasurement_vs_noutliers->cd(5);nmeasurement_vs_noutlier[4]->Draw("colz");


    TCanvas *q_over_p_c = new TCanvas("q_over_p_c");
    q_over_p_c->Divide(2,3);
    q_over_p_c->cd(1);q_over_p_before[0]->Draw();q_over_p_after[0]->Draw("same");q_over_p_truth[0]->Draw("same");
    q_over_p_c->cd(2);q_over_p_before[1]->Draw();q_over_p_after[1]->Draw("same");q_over_p_truth[1]->Draw("same");
    q_over_p_c->cd(3);q_over_p_before[2]->Draw();q_over_p_after[2]->Draw("same");q_over_p_truth[2]->Draw("same");
    q_over_p_c->cd(4);q_over_p_before[3]->Draw();q_over_p_after[3]->Draw("same");q_over_p_truth[3]->Draw("same");
    q_over_p_c->cd(5);q_over_p_before[4]->Draw();q_over_p_after[4]->Draw("same");q_over_p_truth[4]->Draw("same");

    TCanvas *p_for_outlier_c = new TCanvas("p_for_outlier_c");
    p_for_outlier_c->Divide(2,3);
    p_for_outlier_c->cd(1);p_for_outlier0[0]->Draw();p_for_outlier1[0]->Draw("same");p_for_outlier2[0]->Draw("same");
p_for_outlier3[0]->Draw("same");p_for_outlier4[0]->Draw("same");p_for_outlier5[0]->Draw("same");p_for_outlier6[0]->Draw("same");
 p_for_outlier_c->cd(2);p_for_outlier0[1]->Draw();p_for_outlier1[1]->Draw("same");p_for_outlier2[1]->Draw("same");
p_for_outlier3[1]->Draw("same");p_for_outlier4[1]->Draw("same");p_for_outlier5[1]->Draw("same");p_for_outlier6[1]->Draw("same");
 p_for_outlier_c->cd(3);p_for_outlier0[2]->Draw();p_for_outlier1[2]->Draw("same");p_for_outlier2[2]->Draw("same");
p_for_outlier3[2]->Draw("same");p_for_outlier4[2]->Draw("same");p_for_outlier5[2]->Draw("same");p_for_outlier6[2]->Draw("same");
 p_for_outlier_c->cd(4);p_for_outlier0[3]->Draw();p_for_outlier1[3]->Draw("same");p_for_outlier2[3]->Draw("same");
p_for_outlier3[3]->Draw("same");p_for_outlier4[3]->Draw("same");p_for_outlier5[3]->Draw("same");p_for_outlier6[3]->Draw("same");
 p_for_outlier_c->cd(5);p_for_outlier0[4]->Draw();p_for_outlier1[4]->Draw("same");p_for_outlier2[4]->Draw("same");
p_for_outlier3[4]->Draw("same");p_for_outlier4[4]->Draw("same");p_for_outlier5[4]->Draw("same");p_for_outlier6[4]->Draw("same");
 

 TCanvas *eta_for_outlier_c = new TCanvas("eta_for_outlier_c");
    eta_for_outlier_c->Divide(2,3);
    eta_for_outlier_c->cd(1);eta_for_outlier0[0]->Draw();eta_for_outlier1[0]->Draw("same");eta_for_outlier2[0]->Draw("same");
eta_for_outlier3[0]->Draw("same");eta_for_outlier4[0]->Draw("same");eta_for_outlier5[0]->Draw("same");eta_for_outlier6[0]->Draw("same");
 eta_for_outlier_c->cd(2);eta_for_outlier0[1]->Draw();eta_for_outlier1[1]->Draw("same");eta_for_outlier2[1]->Draw("same");
eta_for_outlier3[1]->Draw("same");eta_for_outlier4[1]->Draw("same");eta_for_outlier5[1]->Draw("same");eta_for_outlier6[1]->Draw("same");
 eta_for_outlier_c->cd(3);eta_for_outlier0[2]->Draw();eta_for_outlier1[2]->Draw("same");eta_for_outlier2[2]->Draw("same");
eta_for_outlier3[2]->Draw("same");eta_for_outlier4[2]->Draw("same");eta_for_outlier5[2]->Draw("same");eta_for_outlier6[2]->Draw("same");
 eta_for_outlier_c->cd(4);eta_for_outlier0[3]->Draw();eta_for_outlier1[3]->Draw("same");eta_for_outlier2[3]->Draw("same");
eta_for_outlier3[3]->Draw("same");eta_for_outlier4[3]->Draw("same");eta_for_outlier5[3]->Draw("same");eta_for_outlier6[3]->Draw("same");
 eta_for_outlier_c->cd(5);eta_for_outlier0[4]->Draw();eta_for_outlier1[4]->Draw("same");eta_for_outlier2[4]->Draw("same");
eta_for_outlier3[4]->Draw("same");eta_for_outlier4[4]->Draw("same");eta_for_outlier5[4]->Draw("same");eta_for_outlier6[4]->Draw("same");


  TCanvas *phi_for_outlier_c = new TCanvas("phi_for_outlier_c");
    phi_for_outlier_c->Divide(2,3);
    phi_for_outlier_c->cd(1);phi_for_outlier0[0]->Draw();phi_for_outlier1[0]->Draw("same");phi_for_outlier2[0]->Draw("same");
phi_for_outlier3[0]->Draw("same");phi_for_outlier4[0]->Draw("same");phi_for_outlier5[0]->Draw("same");phi_for_outlier6[0]->Draw("same");
 phi_for_outlier_c->cd(2);phi_for_outlier0[1]->Draw();phi_for_outlier1[1]->Draw("same");phi_for_outlier2[1]->Draw("same");
phi_for_outlier3[1]->Draw("same");phi_for_outlier4[1]->Draw("same");phi_for_outlier5[1]->Draw("same");phi_for_outlier6[1]->Draw("same");
 phi_for_outlier_c->cd(3);phi_for_outlier0[2]->Draw();phi_for_outlier1[2]->Draw("same");phi_for_outlier2[2]->Draw("same");
phi_for_outlier3[2]->Draw("same");phi_for_outlier4[2]->Draw("same");phi_for_outlier5[2]->Draw("same");phi_for_outlier6[2]->Draw("same");
 phi_for_outlier_c->cd(4);phi_for_outlier0[3]->Draw();phi_for_outlier1[3]->Draw("same");phi_for_outlier2[3]->Draw("same");
phi_for_outlier3[3]->Draw("same");phi_for_outlier4[3]->Draw("same");phi_for_outlier5[3]->Draw("same");phi_for_outlier6[3]->Draw("same");
 phi_for_outlier_c->cd(5);phi_for_outlier0[4]->Draw();phi_for_outlier1[4]->Draw("same");phi_for_outlier2[4]->Draw("same");
phi_for_outlier3[4]->Draw("same");phi_for_outlier4[4]->Draw("same");phi_for_outlier5[4]->Draw("same");phi_for_outlier6[4]->Draw("same");


 TCanvas *chi_for_outlier_c = new TCanvas("chi_for_outlier_c");
    chi_for_outlier_c->Divide(2,3);
    chi_for_outlier_c->cd(1);chi_for_outlier0[0]->Draw();chi_for_outlier1[0]->Draw("same");chi_for_outlier2[0]->Draw("same");
chi_for_outlier3[0]->Draw("same");chi_for_outlier4[0]->Draw("same");chi_for_outlier5[0]->Draw("same");chi_for_outlier6[0]->Draw("same");
 chi_for_outlier_c->cd(2);chi_for_outlier0[1]->Draw();chi_for_outlier1[1]->Draw("same");chi_for_outlier2[1]->Draw("same");
chi_for_outlier3[1]->Draw("same");chi_for_outlier4[1]->Draw("same");chi_for_outlier5[1]->Draw("same");chi_for_outlier6[1]->Draw("same");
 chi_for_outlier_c->cd(3);chi_for_outlier0[2]->Draw();chi_for_outlier1[2]->Draw("same");chi_for_outlier2[2]->Draw("same");
chi_for_outlier3[2]->Draw("same");chi_for_outlier4[2]->Draw("same");chi_for_outlier5[2]->Draw("same");chi_for_outlier6[2]->Draw("same");
 chi_for_outlier_c->cd(4);chi_for_outlier0[3]->Draw();chi_for_outlier1[3]->Draw("same");chi_for_outlier2[3]->Draw("same");
chi_for_outlier3[3]->Draw("same");chi_for_outlier4[3]->Draw("same");chi_for_outlier5[3]->Draw("same");chi_for_outlier6[3]->Draw("same");
 chi_for_outlier_c->cd(5);chi_for_outlier0[4]->Draw();chi_for_outlier1[4]->Draw("same");chi_for_outlier2[4]->Draw("same");
chi_for_outlier3[4]->Draw("same");chi_for_outlier4[4]->Draw("same");chi_for_outlier5[4]->Draw("same");chi_for_outlier6[4]->Draw("same");

 TCanvas *p_res_c = new TCanvas("p_res_c");
  p_res_c->Divide(2,3);
  p_res_c->cd(1);
  p_res_trk[0]->Draw();p_res_seed[0]->Draw("same");  p_res_true[0]->Draw("same");
  TLegend *legend0 = new TLegend(0.67,0.7,0.89,0.88);
  legend0->AddEntry(p_res_trk[0],"real seeding after CKF","l");
  legend0->AddEntry(p_res_seed[0],"real seeding before CKF","l");
  legend0->AddEntry(p_res_true[0],"truth seeded tracking","l");
  legend0->Draw();
    
  p_res_c->cd(2);
  p_res_trk[1]->Draw();p_res_seed[1]->Draw("same");  p_res_true[1]->Draw("same");
  TLegend *legend1 = new TLegend(0.67,0.7,0.89,0.88);
  legend1->AddEntry(p_res_trk[1],"real seeding after CKF","l");
  legend1->AddEntry(p_res_seed[1],"real seeding before CKF","l");
  legend1->AddEntry(p_res_true[1],"truth seeded tracking","l");
  legend1->Draw();
    
  p_res_c->cd(3);
  p_res_trk[2]->Draw();p_res_seed[2]->Draw("same");  p_res_true[2]->Draw("same");
    TLegend *legend2 = new TLegend(0.67,0.7,0.89,0.88);
     legend2->AddEntry(p_res_trk[2],"real seeding after CKF","l");
     legend2->AddEntry(p_res_seed[2],"real seeding before CKF","l");
    legend2->AddEntry(p_res_true[2],"truth seeded tracking","l");
     legend2->Draw();
    
    p_res_c->cd(4);
    p_res_trk[3]->Draw();p_res_seed[3]->Draw("same");  p_res_true[3]->Draw("same");
    TLegend *legend3 = new TLegend(0.67,0.7,0.89,0.88);
     legend3->AddEntry(p_res_trk[3],"real seeding after CKF","l");
     legend3->AddEntry(p_res_seed[3],"real seeding before CKF","l");
    legend3->AddEntry(p_res_true[3],"truth seeded tracking","l");
     legend3->Draw();
    
    p_res_c->cd(5);
    p_res_trk[4]->Draw();p_res_seed[4]->Draw("same");  p_res_true[4]->Draw("same");
    TLegend *legend4 = new TLegend(0.67,0.7,0.89,0.88);
     legend4->AddEntry(p_res_trk[4],"real seeding after CKF","l");
     legend4->AddEntry(p_res_seed[4],"real seeding before CKF","l");
    legend4->AddEntry(p_res_true[4],"truth seeded tracking","l");
     legend4->Draw();
    
    p_res_c->cd(6);
    TPaveText* tex_gen = new TPaveText(0.075,0.1,0.9,0.85,"NDCNB");
    tex_gen->AddText("Single #mu^{-} generated:");
    tex_gen->AddText("0.5 GeV/c < P < 20 GeV/c");
    tex_gen->AddText("-4 < #eta < 4");
    tex_gen->AddText("Generated vertex: ... mm");
    tex_gen->AddText("1) (0,0,0)");
    tex_gen->AddText("2) (0,0,10)");
    tex_gen->AddText("3) (0,0,-10)");
    tex_gen->AddText("4) (1,0,0)");
    tex_gen->AddText("5) (10,0,0)");
    tex_gen->SetFillStyle(400);tex_gen->SetTextFont(3);tex_gen->SetTextSize(10);
    tex_gen->Draw();
    
    TCanvas *p_c = new TCanvas("p_c");
    p_c->Divide(2,3);
    p_c->cd(1);
    p_trk[0]->Draw(); p_true[0]->Draw("same"); p_mc[0]->Draw("same"); p_seed[0]->Draw("same");
    TLegend *legend5 = new TLegend(0.67,0.7,0.89,0.88);
     legend5->AddEntry(p_trk[0],"real seeding after CKF","l");
     legend5->AddEntry(p_seed[0],"real seeding before CKF","l");
    legend5->AddEntry(p_true[0],"truth seeded tracking","l");
    legend5->AddEntry(p_mc[0],"generated particle","l");
     legend5->Draw();
    p_c->cd(2);
    p_trk[1]->Draw();  p_true[1]->Draw("same"); p_mc[0]->Draw("same"); p_seed[1]->Draw("same");
    TLegend *legend6 = new TLegend(0.67,0.7,0.89,0.88);
     legend6->AddEntry(p_trk[0],"real seeding after CKF","l");
     legend6->AddEntry(p_seed[0],"real seeding before CKF","l");
    legend6->AddEntry(p_true[0],"truth seeded tracking","l");
    legend6->AddEntry(p_mc[0],"generated particle","l");
     legend6->Draw();
    p_c->cd(3);
    p_trk[2]->Draw();p_seed[2]->Draw("same");  p_true[2]->Draw("same"); p_mc[0]->Draw("same");
    TLegend *legend7 = new TLegend(0.67,0.7,0.89,0.88);
     legend7->AddEntry(p_trk[0],"real seeding after CKF","l");
     legend7->AddEntry(p_seed[0],"real seeding before CKF","l");
    legend7->AddEntry(p_true[0],"truth seeded tracking","l");
    legend7->AddEntry(p_mc[0],"generated particle","l");
     legend7->Draw();
    p_c->cd(4);
    p_trk[3]->Draw();p_seed[3]->Draw("same");  p_true[3]->Draw("same"); p_mc[0]->Draw("same");
    TLegend *legend8 = new TLegend(0.67,0.7,0.89,0.88);
     legend8->AddEntry(p_trk[0],"real seeding after CKF","l");
     legend8->AddEntry(p_seed[0],"real seeding before CKF","l");
    legend8->AddEntry(p_true[0],"truth seeded tracking","l");
    legend8->AddEntry(p_mc[0],"generated particle","l");
     legend8->Draw();
    p_c->cd(5);
    p_trk[4]->Draw();p_seed[4]->Draw("same");  p_true[4]->Draw("same"); p_mc[0]->Draw("same");
    TLegend *legend9 = new TLegend(0.67,0.7,0.89,0.88);
     legend9->AddEntry(p_trk[0],"real seeding after CKF","l");
     legend9->AddEntry(p_seed[0],"real seeding before CKF","l");
    legend9->AddEntry(p_true[0],"truth seeded tracking","l");
    legend9->AddEntry(p_mc[0],"generated particle","l");
     legend9->Draw();
    p_c->cd(6);
    TPaveText* tex_gen1 = new TPaveText(0.075,0.1,0.9,0.85,"NDCNB");
    tex_gen1->AddText("Single #mu^{-} generated:");
    tex_gen1->AddText("0.5 GeV/c < P < 20 GeV/c");
    tex_gen1->AddText("-4 < #eta < 4");
    tex_gen1->AddText("Generated vertex: ... mm");
    tex_gen1->AddText("1) (0,0,0)");
    tex_gen1->AddText("2) (0,0,10)");
    tex_gen1->AddText("3) (0,0,-10)");
    tex_gen1->AddText("4) (1,0,0)");
    tex_gen1->AddText("5) (10,0,0)");
    tex_gen1->SetFillStyle(400);tex_gen1->SetTextFont(3);tex_gen1->SetTextSize(10);
    tex_gen1->Draw();
    
    TCanvas *pz_true_c = new TCanvas("pz_true_c");
    pz_true_c->Divide(2,3);
    pz_true_c->cd(1); pz_ratio_true[0]->Draw();
    pz_true_c->cd(2); pz_ratio_true[1]->Draw();
    pz_true_c->cd(3); pz_ratio_true[2]->Draw();
    pz_true_c->cd(4); pz_ratio_true[3]->Draw();
    pz_true_c->cd(5); pz_ratio_true[4]->Draw();
    pz_true_c->cd(6);
    TPaveText* tex_gen14a = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen14a->AddText("1) (0,0,0)");
    tex_gen14a->AddText("2) (0,0,10)");
    tex_gen14a->AddText("3) (0,0,-10)");
    tex_gen14a->AddText("4) (1,0,0)");
    tex_gen14a->AddText("5) (10,0,0)");
    tex_gen14a->SetFillStyle(400);tex_gen14a->SetTextFont(3);tex_gen14a->SetTextSize(10);
    tex_gen14a->Draw();
    
    TCanvas *pz_seed_c = new TCanvas("pz_seed_c");
    pz_seed_c->Divide(2,3);
    pz_seed_c->cd(1); pz_ratio_seed[0]->Draw();
    pz_seed_c->cd(2); pz_ratio_seed[1]->Draw();
    pz_seed_c->cd(3); pz_ratio_seed[2]->Draw();
    pz_seed_c->cd(4); pz_ratio_seed[3]->Draw();
    pz_seed_c->cd(5); pz_ratio_seed[4]->Draw();
    pz_seed_c->cd(6);
    TPaveText* tex_gen14b = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen14b->AddText("1) (0,0,0)");
    tex_gen14b->AddText("2) (0,0,10)");
    tex_gen14b->AddText("3) (0,0,-10)");
    tex_gen14b->AddText("4) (1,0,0)");
    tex_gen14b->AddText("5) (10,0,0)");
    tex_gen14b->SetFillStyle(400);tex_gen14b->SetTextFont(3);tex_gen14b->SetTextSize(10);
    tex_gen14b->Draw();
    
    TCanvas *pz_track_c = new TCanvas("pz_track_c");
    pz_track_c->Divide(2,3);
    pz_track_c->cd(1); pz_ratio_track[0]->Draw();
    pz_track_c->cd(2); pz_ratio_track[1]->Draw();
    pz_track_c->cd(3); pz_ratio_track[2]->Draw();
    pz_track_c->cd(4); pz_ratio_track[3]->Draw();
    pz_track_c->cd(5); pz_ratio_track[4]->Draw();
    pz_track_c->cd(6);
    TPaveText* tex_gen14c = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen14c->AddText("1) (0,0,0)");
    tex_gen14c->AddText("2) (0,0,10)");
    tex_gen14c->AddText("3) (0,0,-10)");
    tex_gen14c->AddText("4) (1,0,0)");
    tex_gen14c->AddText("5) (10,0,0)");
    tex_gen14c->SetFillStyle(400);tex_gen14c->SetTextFont(3);tex_gen14c->SetTextSize(10);
    tex_gen14c->Draw();
    
    TCanvas *pt_true_c = new TCanvas("pt_true_c");
    pt_true_c->Divide(2,3);
    pt_true_c->cd(1); pt_ratio_true[0]->Draw();
    pt_true_c->cd(2); pt_ratio_true[1]->Draw();
    pt_true_c->cd(3); pt_ratio_true[2]->Draw();
    pt_true_c->cd(4); pt_ratio_true[3]->Draw();
    pt_true_c->cd(5); pt_ratio_true[4]->Draw();
    pt_true_c->cd(6);
    TPaveText* tex_gen14ab = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen14ab->AddText("1) (0,0,0)");
    tex_gen14ab->AddText("2) (0,0,10)");
    tex_gen14ab->AddText("3) (0,0,-10)");
    tex_gen14ab->AddText("4) (1,0,0)");
    tex_gen14ab->AddText("5) (10,0,0)");
    tex_gen14ab->SetFillStyle(400);tex_gen14ab->SetTextFont(3);tex_gen14ab->SetTextSize(10);
    tex_gen14ab->Draw();
    
    TCanvas *pt_seed_c = new TCanvas("pt_seed_c");
    pt_seed_c->Divide(2,3);
    pt_seed_c->cd(1); pt_ratio_seed[0]->Draw();
    pt_seed_c->cd(2); pt_ratio_seed[1]->Draw();
    pt_seed_c->cd(3); pt_ratio_seed[2]->Draw();
    pt_seed_c->cd(4); pt_ratio_seed[3]->Draw();
    pt_seed_c->cd(5); pt_ratio_seed[4]->Draw();
    pt_seed_c->cd(6);
    TPaveText* tex_gen14bb = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen14bb->AddText("1) (0,0,0)");
    tex_gen14bb->AddText("2) (0,0,10)");
    tex_gen14bb->AddText("3) (0,0,-10)");
    tex_gen14bb->AddText("4) (1,0,0)");
    tex_gen14bb->AddText("5) (10,0,0)");
    tex_gen14bb->SetFillStyle(400);tex_gen14bb->SetTextFont(3);tex_gen14bb->SetTextSize(10);
    tex_gen14bb->Draw();
    
    TCanvas *pt_track_c = new TCanvas("pt_track_c");
    pt_track_c->Divide(2,3);
    pt_track_c->cd(1); pt_ratio_track[0]->Draw();
    pt_track_c->cd(2); pt_ratio_track[1]->Draw();
    pt_track_c->cd(3); pt_ratio_track[2]->Draw();
    pt_track_c->cd(4); pt_ratio_track[3]->Draw();
    pt_track_c->cd(5); pt_ratio_track[4]->Draw();
    pt_track_c->cd(6);
    TPaveText* tex_gen14cb = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen14cb->AddText("1) (0,0,0)");
    tex_gen14cb->AddText("2) (0,0,10)");
    tex_gen14cb->AddText("3) (0,0,-10)");
    tex_gen14cb->AddText("4) (1,0,0)");
    tex_gen14cb->AddText("5) (10,0,0)");
    tex_gen14cb->SetFillStyle(400);tex_gen14cb->SetTextFont(3);tex_gen14cb->SetTextSize(10);
    tex_gen14cb->Draw();
    
    

    TCanvas *theta_res_c = new TCanvas("theta_res_c");
    theta_res_c->Divide(2,3);
    theta_res_c->cd(1);
    theta_res_trk[0]->Draw();theta_res_seed[0]->Draw("same"); theta_res_true[0]->Draw("same");
    TLegend *legend15 = new TLegend(0.67,0.7,0.89,0.88);
    legend15->AddEntry(theta_res_trk[0],"real seeding after CKF","l");
    legend15->AddEntry(theta_res_seed[0],"real seeding before CKF","l");
    legend15->AddEntry(theta_res_true[0],"truth seeded tracking","l");
    legend15->Draw();
    theta_res_c->cd(2);
    theta_res_trk[1]->Draw();theta_res_seed[1]->Draw("same"); theta_res_true[1]->Draw("same");
    TLegend *legend16 = new TLegend(0.67,0.7,0.89,0.88);
    legend16->AddEntry(theta_res_trk[0],"real seeding after CKF","l");
    legend16->AddEntry(theta_res_seed[0],"real seeding before CKF","l");
    legend16->AddEntry(theta_res_true[0],"truth seeded tracking","l");
    legend16->Draw();
    theta_res_c->cd(3);
    theta_res_trk[2]->Draw();theta_res_seed[2]->Draw("same"); theta_res_true[2]->Draw("same");
    TLegend *legend17 = new TLegend(0.67,0.7,0.89,0.88);
    legend17->AddEntry(theta_res_trk[0],"real seeding after CKF","l");
    legend17->AddEntry(theta_res_seed[0],"real seeding before CKF","l");
    legend17->AddEntry(theta_res_true[0],"truth seeded tracking","l");
    legend17->Draw();
    theta_res_c->cd(4);
    theta_res_trk[3]->Draw();theta_res_seed[3]->Draw("same"); theta_res_true[3]->Draw("same");
    TLegend *legend18 = new TLegend(0.67,0.7,0.89,0.88);
    legend18->AddEntry(theta_res_trk[0],"real seeding after CKF","l");
    legend18->AddEntry(theta_res_seed[0],"real seeding before CKF","l");
    legend18->AddEntry(theta_res_true[0],"truth seeded tracking","l");
    legend18->Draw();
    theta_res_c->cd(5);
    theta_res_trk[4]->Draw();theta_res_seed[4]->Draw("same"); theta_res_true[4]->Draw("same");
    TLegend *legend19 = new TLegend(0.67,0.7,0.89,0.88);
    legend19->AddEntry(theta_res_trk[0],"real seeding after CKF","l");
    legend19->AddEntry(theta_res_seed[0],"real seeding before CKF","l");
    legend19->AddEntry(theta_res_true[0],"truth seeded tracking","l");
    legend19->Draw();
    theta_res_c->cd(6);
    TPaveText* tex_gen2 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen2->AddText("1) (0,0,0)");
    tex_gen2->AddText("2) (0,0,10)");
    tex_gen2->AddText("3) (0,0,-10)");
    tex_gen2->AddText("4) (1,0,0)");
    tex_gen2->AddText("5) (10,0,0)");
    tex_gen2->SetFillStyle(400);tex_gen2->SetTextFont(3);tex_gen2->SetTextSize(10);
    tex_gen2->Draw();

    TCanvas *theta_c = new TCanvas("theta_c");
    theta_c->Divide(2,3);
    theta_c->cd(1);
    theta_trk[0]->Draw();theta_seed[0]->Draw("same");  theta_true[0]->Draw("same"); theta_mc[0]->Draw("same");
    TLegend *legend20 = new TLegend(0.67,0.7,0.89,0.88);
    legend20->AddEntry(theta_trk[0],"real seeding after CKF","l");
    legend20->AddEntry(theta_seed[0],"real seeding before CKF","l");
    legend20->AddEntry(theta_true[0],"truth seeded tracking","l");
    legend20->AddEntry(theta_mc[0],"generated particle","l");
    legend20->Draw();
    theta_c->cd(2);
    theta_trk[1]->Draw();theta_seed[1]->Draw("same");  theta_true[1]->Draw("same"); theta_mc[0]->Draw("same");
    TLegend *legend21 = new TLegend(0.67,0.7,0.89,0.88);
    legend21->AddEntry(theta_trk[0],"real seeding after CKF","l");
    legend21->AddEntry(theta_seed[0],"real seeding before CKF","l");
    legend21->AddEntry(theta_true[0],"truth seeded tracking","l");
    legend21->AddEntry(theta_mc[0],"generated particle","l");
    legend21->Draw();
    theta_c->cd(3);
    theta_trk[2]->Draw();theta_seed[2]->Draw("same");  theta_true[2]->Draw("same"); theta_mc[0]->Draw("same");
    TLegend *legend22 = new TLegend(0.67,0.7,0.89,0.88);
    legend22->AddEntry(theta_trk[0],"real seeding after CKF","l");
    legend22->AddEntry(theta_seed[0],"real seeding before CKF","l");
    legend22->AddEntry(theta_true[0],"truth seeded tracking","l");
    legend22->AddEntry(theta_mc[0],"generated particle","l");
    legend22->Draw();
    theta_c->cd(4);
    theta_trk[3]->Draw();theta_seed[3]->Draw("same");  theta_true[3]->Draw("same"); theta_mc[0]->Draw("same");
    TLegend *legend23 = new TLegend(0.67,0.7,0.89,0.88);
    legend23->AddEntry(theta_trk[0],"real seeding after CKF","l");
    legend23->AddEntry(theta_seed[0],"real seeding before CKF","l");
    legend23->AddEntry(theta_true[0],"truth seeded tracking","l");
    legend23->AddEntry(theta_mc[0],"generated particle","l");
    legend23->Draw();
    theta_c->cd(5);
    theta_trk[4]->Draw();theta_seed[4]->Draw("same");  theta_true[4]->Draw("same"); theta_mc[0]->Draw("same");
    TLegend *legend24 = new TLegend(0.67,0.7,0.89,0.88);
    legend24->AddEntry(theta_trk[0],"real seeding after CKF","l");
    legend24->AddEntry(theta_seed[0],"real seeding before CKF","l");
    legend24->AddEntry(theta_true[0],"truth seeded tracking","l");
    legend24->AddEntry(theta_mc[0],"generated particle","l");
    legend24->Draw();
    theta_c->cd(6);
    TPaveText* tex_gen2a = new TPaveText(0.075,0.1,0.9,0.85,"NDCNB");
    tex_gen2a->AddText("Single #mu^{-} generated:");
    tex_gen2a->AddText("0.5 GeV/c < P < 20 GeV/c");
    tex_gen2a->AddText("-4 < #eta < 4");
    tex_gen2a->AddText("Generated vertex: ... mm");
    tex_gen2a->AddText("1) (0,0,0)");
    tex_gen2a->AddText("2) (0,0,10)");
    tex_gen2a->AddText("3) (0,0,-10)");
    tex_gen2a->AddText("4) (1,0,0)");
    tex_gen2a->AddText("5) (10,0,0)");
    tex_gen2a->SetFillStyle(400);tex_gen2a->SetTextFont(3);tex_gen2a->SetTextSize(10);
    tex_gen2a->Draw();
    
    TCanvas *phi_res_c = new TCanvas("phi_res_c");
    phi_res_c->Divide(2,3);
    phi_res_c->cd(1);
    phi_res_trk[0]->Draw();phi_res_seed[0]->Draw("same"); phi_res_true[0]->Draw("same");
    TLegend *legend25 = new TLegend(0.67,0.7,0.89,0.88);
    legend25->AddEntry(phi_res_trk[0],"real seeding after CKF","l");
    legend25->AddEntry(phi_res_seed[0],"real seeding before CKF","l");
    legend25->AddEntry(phi_res_true[0],"truth seeded tracking","l");
    legend25->Draw();
    phi_res_c->cd(2);
    phi_res_trk[1]->Draw();phi_res_seed[1]->Draw("same"); phi_res_true[1]->Draw("same");
    TLegend *legend26 = new TLegend(0.67,0.7,0.89,0.88);
    legend26->AddEntry(phi_res_trk[0],"real seeding after CKF","l");
    legend26->AddEntry(phi_res_seed[0],"real seeding before CKF","l");
    legend26->AddEntry(phi_res_true[0],"truth seeded tracking","l");
    legend26->Draw();
    phi_res_c->cd(3);
    phi_res_trk[2]->Draw();phi_res_seed[2]->Draw("same"); phi_res_true[2]->Draw("same");
    TLegend *legend27 = new TLegend(0.67,0.7,0.89,0.88);
    legend27->AddEntry(phi_res_trk[0],"real seeding after CKF","l");
    legend27->AddEntry(phi_res_seed[0],"real seeding before CKF","l");
    legend27->AddEntry(phi_res_true[0],"truth seeded tracking","l");
    legend27->Draw();
    phi_res_c->cd(4);
    phi_res_trk[3]->Draw();phi_res_seed[3]->Draw("same"); phi_res_true[3]->Draw("same");
    TLegend *legend28 = new TLegend(0.67,0.7,0.89,0.88);
    legend28->AddEntry(phi_res_trk[0],"real seeding after CKF","l");
    legend28->AddEntry(phi_res_seed[0],"real seeding before CKF","l");
    legend28->AddEntry(phi_res_true[0],"truth seeded tracking","l");
    legend28->Draw();
    phi_res_c->cd(5);
    phi_res_trk[4]->Draw();phi_res_seed[4]->Draw("same"); phi_res_true[4]->Draw("same");
    TLegend *legend29 = new TLegend(0.67,0.7,0.89,0.88);
    legend29->AddEntry(phi_res_trk[0],"real seeding after CKF","l");
    legend29->AddEntry(phi_res_seed[0],"real seeding before CKF","l");
    legend29->AddEntry(phi_res_true[0],"truth seeded tracking","l");
    legend29->Draw();
    phi_res_c->cd(6);
    TPaveText* tex_gen3 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen3->AddText("1) (0,0,0)");
    tex_gen3->AddText("2) (0,0,10)");
    tex_gen3->AddText("3) (0,0,-10)");
    tex_gen3->AddText("4) (1,0,0)");
    tex_gen3->AddText("5) (10,0,0)");
    tex_gen3->SetFillStyle(400);tex_gen3->SetTextFont(3);tex_gen3->SetTextSize(10);
    tex_gen3->Draw();
    
    TCanvas *phi_c = new TCanvas("phi_c");
    phi_c->Divide(2,3);
    phi_c->cd(1);
    phi_trk[0]->Draw();phi_seed[0]->Draw("same");  phi_true[0]->Draw("same"); phi_mc[0]->Draw("same");
    TLegend *legend30 = new TLegend(0.67,0.7,0.89,0.88);
    legend30->AddEntry(phi_trk[0],"real seeding after CKF","l");
    legend30->AddEntry(phi_seed[0],"real seeding before CKF","l");
    legend30->AddEntry(phi_true[0],"truth seeded tracking","l");
    legend30->AddEntry(phi_mc[0],"generated particle","l");
    legend30->Draw();
    phi_c->cd(2);
    phi_trk[1]->Draw();phi_seed[1]->Draw("same");  phi_true[1]->Draw("same"); phi_mc[0]->Draw("same");
    TLegend *legend31 = new TLegend(0.67,0.7,0.89,0.88);
    legend31->AddEntry(phi_trk[0],"real seeding after CKF","l");
    legend31->AddEntry(phi_seed[0],"real seeding before CKF","l");
    legend31->AddEntry(phi_true[0],"truth seeded tracking","l");
    legend31->AddEntry(phi_mc[0],"generated particle","l");
    legend31->Draw();
    phi_c->cd(3);
    phi_trk[2]->Draw();phi_seed[2]->Draw("same");  phi_true[2]->Draw("same"); phi_mc[0]->Draw("same");
    TLegend *legend32 = new TLegend(0.67,0.7,0.89,0.88);
    legend32->AddEntry(phi_trk[0],"real seeding after CKF","l");
    legend32->AddEntry(phi_seed[0],"real seeding before CKF","l");
    legend32->AddEntry(phi_true[0],"truth seeded tracking","l");
    legend32->AddEntry(phi_mc[0],"generated particle","l");
    legend32->Draw();
    phi_c->cd(4);
    phi_trk[3]->Draw();phi_seed[3]->Draw("same");  phi_true[3]->Draw("same"); phi_mc[0]->Draw("same");
    TLegend *legend33 = new TLegend(0.67,0.7,0.89,0.88);
    legend33->AddEntry(phi_trk[0],"real seeding after CKF","l");
    legend33->AddEntry(phi_seed[0],"real seeding before CKF","l");
    legend33->AddEntry(phi_true[0],"truth seeded tracking","l");
    legend33->AddEntry(phi_mc[0],"generated particle","l");
    legend33->Draw();
    phi_c->cd(5);
    phi_trk[4]->Draw();phi_seed[4]->Draw("same");  phi_true[4]->Draw("same"); phi_mc[0]->Draw("same");
    TLegend *legend34 = new TLegend(0.67,0.7,0.89,0.88);
    legend34->AddEntry(phi_trk[0],"real seeding after CKF","l");
    legend34->AddEntry(phi_seed[0],"real seeding before CKF","l");
    legend34->AddEntry(phi_true[0],"truth seeded tracking","l");
    legend34->AddEntry(phi_mc[0],"generated particle","l");
    legend34->Draw();
    phi_c->cd(6);
    TPaveText* tex_gen3a = new TPaveText(0.075,0.1,0.9,0.85,"NDCNB");
    tex_gen3a->AddText("Single #mu^{-} generated:");
    tex_gen3a->AddText("0.5 GeV/c < P < 20 GeV/c");
    tex_gen3a->AddText("-4 < #eta < 4");
    tex_gen3a->AddText("Generated vertex: ... mm");
    tex_gen3a->AddText("1) (0,0,0)");
    tex_gen3a->AddText("2) (0,0,10)");
    tex_gen3a->AddText("3) (0,0,-10)");
    tex_gen3a->AddText("4) (1,0,0)");
    tex_gen3a->AddText("5) (10,0,0)");
    tex_gen3a->SetFillStyle(400);tex_gen3a->SetTextFont(3);tex_gen3a->SetTextSize(10);
    tex_gen3a->Draw();


    TCanvas *r_res_c = new TCanvas("r_res_c");
    r_res_c->Divide(2,3);
    r_res_c->cd(1);
    r_trk[0]->Draw(); r_seed[0]->Draw("same"); r_true[0]->Draw("same");
    TLegend *legend35 = new TLegend(0.67,0.7,0.89,0.88);
    legend35->AddEntry(r_trk[0],"real seeding after CKF","l");
    legend35->AddEntry(r_seed[0],"real seeding before CKF","l");
    legend35->AddEntry(r_true[0],"truth seeded tracking","l");
    legend35->Draw();
    r_res_c->cd(2);
    r_trk[1]->Draw(); r_seed[1]->Draw("same"); r_true[1]->Draw("same");
    TLegend *legend36 = new TLegend(0.67,0.7,0.89,0.88);
    legend36->AddEntry(r_trk[0],"real seeding after CKF","l");
    legend36->AddEntry(r_seed[0],"real seeding before CKF","l");
    legend36->AddEntry(r_true[0],"truth seeded tracking","l");
    legend36->Draw();
    r_res_c->cd(3);
    r_trk[2]->Draw(); r_seed[2]->Draw("same"); r_true[2]->Draw("same");
    TLegend *legend37 = new TLegend(0.67,0.7,0.89,0.88);
    legend37->AddEntry(r_trk[0],"real seeding after CKF","l");
    legend37->AddEntry(r_seed[0],"real seeding before CKF","l");
    legend37->AddEntry(r_true[0],"truth seeded tracking","l");
    legend37->Draw();
    r_res_c->cd(4);
    r_trk[3]->Draw(); r_seed[3]->Draw("same"); r_true[3]->Draw("same");
    TLegend *legend38 = new TLegend(0.67,0.7,0.89,0.88);
    legend38->AddEntry(r_trk[0],"real seeding after CKF","l");
    legend38->AddEntry(r_seed[0],"real seeding before CKF","l");
    legend38->AddEntry(r_true[0],"truth seeded tracking","l");
    legend38->Draw();
    r_res_c->cd(5);
    r_trk[4]->Draw(); r_seed[4]->Draw("same"); r_true[4]->Draw("same");
    TLegend *legend39 = new TLegend(0.67,0.7,0.89,0.88);
    legend39->AddEntry(r_trk[0],"real seeding after CKF","l");
    legend39->AddEntry(r_seed[0],"real seeding before CKF","l");
    legend39->AddEntry(r_true[0],"truth seeded tracking","l");
    legend39->Draw();
    r_res_c->cd(6);
    TPaveText* tex_gen4 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen4->AddText("1) (0,0,0)");
    tex_gen4->AddText("2) (0,0,10)");
    tex_gen4->AddText("3) (0,0,-10)");
    tex_gen4->AddText("4) (1,0,0)");
    tex_gen4->AddText("5) (10,0,0)");
    tex_gen4->SetFillStyle(400);tex_gen4->SetTextFont(3);tex_gen4->SetTextSize(10);
    tex_gen4->Draw();

    TCanvas *z_res_c = new TCanvas("z_res_c");
    z_res_c->Divide(2,3);
    z_res_c->cd(1);
    z_trk[0]->Draw(); z_seed[0]->Draw("same");z_true[0]->Draw("same");
    TLegend *legend40 = new TLegend(0.67,0.7,0.89,0.88);
    legend40->AddEntry(z_trk[0],"real seeding after CKF","l");
    legend40->AddEntry(z_seed[0],"real seeding before CKF","l");
    legend40->AddEntry(z_true[0],"truth seeded tracking","l");
    legend40->Draw();
    z_res_c->cd(2);
    z_trk[1]->Draw(); z_seed[1]->Draw("same");z_true[1]->Draw("same");
    TLegend *legend41 = new TLegend(0.67,0.7,0.89,0.88);
    legend41->AddEntry(z_trk[0],"real seeding after CKF","l");
    legend41->AddEntry(z_seed[0],"real seeding before CKF","l");
    legend41->AddEntry(z_true[0],"truth seeded tracking","l");
    legend41->Draw();
    z_res_c->cd(3);
    z_trk[2]->Draw(); z_seed[2]->Draw("same");z_true[2]->Draw("same");
    TLegend *legend42 = new TLegend(0.67,0.7,0.89,0.88);
    legend42->AddEntry(z_trk[0],"real seeding after CKF","l");
    legend42->AddEntry(z_seed[0],"real seeding before CKF","l");
    legend42->AddEntry(z_true[0],"truth seeded tracking","l");
    legend42->Draw();
    z_res_c->cd(4);
    z_trk[3]->Draw(); z_seed[3]->Draw("same");z_true[3]->Draw("same");
    TLegend *legend43 = new TLegend(0.67,0.7,0.89,0.88);
    legend43->AddEntry(z_trk[0],"real seeding after CKF","l");
    legend43->AddEntry(z_seed[0],"real seeding before CKF","l");
    legend43->AddEntry(z_true[0],"truth seeded tracking","l");
    legend43->Draw();
    z_res_c->cd(5);
    z_trk[4]->Draw(); z_seed[4]->Draw("same");z_true[4]->Draw("same");
    TLegend *legend44 = new TLegend(0.67,0.7,0.89,0.88);
    legend44->AddEntry(z_trk[0],"real seeding after CKF","l");
    legend44->AddEntry(z_seed[0],"real seeding before CKF","l");
    legend44->AddEntry(z_true[0],"truth seeded tracking","l");
    legend44->Draw();
    z_res_c->cd(6);
    TPaveText* tex_gen5 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen5->AddText("1) (0,0,0)");
    tex_gen5->AddText("2) (0,0,10)");
    tex_gen5->AddText("3) (0,0,-10)");
    tex_gen5->AddText("4) (1,0,0)");
    tex_gen5->AddText("5) (10,0,0)");
    tex_gen5->SetFillStyle(400);tex_gen5->SetTextFont(3);tex_gen5->SetTextSize(10);
    tex_gen5->Draw();
    
 

    TCanvas *charge_c = new TCanvas("charge_c");
    charge_c->Divide(2,3);
    charge_c->cd(1);
    charge_trk[0]->Draw(); charge_seed[0]->Draw("same"); charge_true[0]->Draw("same");
    TLegend *legend45 = new TLegend(0.67,0.7,0.89,0.88);
    legend45->AddEntry(charge_trk[0],"real seeding after CKF","l");
    legend45->AddEntry(charge_seed[0],"real seeding before CKF","l");
    legend45->AddEntry(charge_true[0],"truth seeded tracking","l");
    legend45->Draw();
    charge_c->cd(2);
    charge_trk[1]->Draw(); charge_seed[1]->Draw("same"); charge_true[1]->Draw("same");
    TLegend *legend46 = new TLegend(0.67,0.7,0.89,0.88);
    legend46->AddEntry(charge_trk[0],"real seeding after CKF","l");
    legend46->AddEntry(charge_seed[0],"real seeding before CKF","l");
    legend46->AddEntry(charge_true[0],"truth seeded tracking","l");
    legend46->Draw();
    charge_c->cd(3);
    charge_trk[2]->Draw(); charge_seed[2]->Draw("same"); charge_true[2]->Draw("same");
    TLegend *legend47 = new TLegend(0.67,0.7,0.89,0.88);
    legend47->AddEntry(charge_trk[0],"real seeding after CKF","l");
    legend47->AddEntry(charge_seed[0],"real seeding before CKF","l");
    legend47->AddEntry(charge_true[0],"truth seeded tracking","l");
    legend47->Draw();
    charge_c->cd(4);
    charge_trk[3]->Draw(); charge_seed[3]->Draw("same"); charge_true[3]->Draw("same");
    TLegend *legend48 = new TLegend(0.67,0.7,0.89,0.88);
    legend48->AddEntry(charge_trk[0],"real seeding after CKF","l");
    legend48->AddEntry(charge_seed[0],"real seeding before CKF","l");
    legend48->AddEntry(charge_true[0],"truth seeded tracking","l");
    legend48->Draw();
    charge_c->cd(5);
    charge_trk[4]->Draw(); charge_seed[4]->Draw("same"); charge_true[4]->Draw("same");
    TLegend *legend49 = new TLegend(0.67,0.7,0.89,0.88);
    legend49->AddEntry(charge_trk[0],"real seeding after CKF","l");
    legend49->AddEntry(charge_seed[0],"real seeding before CKF","l");
    legend49->AddEntry(charge_true[0],"truth seeded tracking","l");
    legend49->Draw();
    charge_c->cd(6);
    TPaveText* tex_gen6 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen6->AddText("1) (0,0,0)");
    tex_gen6->AddText("2) (0,0,10)");
    tex_gen6->AddText("3) (0,0,-10)");
    tex_gen6->AddText("4) (1,0,0)");
    tex_gen6->AddText("5) (10,0,0)");
    tex_gen6->SetFillStyle(400);tex_gen6->SetTextFont(3);tex_gen6->SetTextSize(10);
    tex_gen6->Draw();
    
    TCanvas *pt_vs_phi_seed_c = new TCanvas("pt_vs_phi_seed_c");
    pt_vs_phi_seed_c->Divide(2,3);
    pt_vs_phi_seed_c->cd(1); pt_vs_phi_seed[0]->Draw("COLZ");
    pt_vs_phi_seed_c->cd(2); pt_vs_phi_seed[1]->Draw("COLZ");
    pt_vs_phi_seed_c->cd(3); pt_vs_phi_seed[2]->Draw("COLZ");
    pt_vs_phi_seed_c->cd(4); pt_vs_phi_seed[3]->Draw("COLZ");
    pt_vs_phi_seed_c->cd(5); pt_vs_phi_seed[4]->Draw("COLZ");
    pt_vs_phi_seed_c->cd(6);
    TPaveText* tex_gen60 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen60->AddText("1) (0,0,0)");
    tex_gen60->AddText("2) (0,0,10)");
    tex_gen60->AddText("3) (0,0,-10)");
    tex_gen60->AddText("4) (1,0,0)");
    tex_gen60->AddText("5) (10,0,0)");
    tex_gen60->SetFillStyle(400);tex_gen60->SetTextFont(3);tex_gen60->SetTextSize(10);
    tex_gen60->Draw();
    
    TCanvas *pt_vs_phi_for_wrong_charge_seed_c = new TCanvas("pt_vs_phi_for_wrong_charge_seed_c");
    pt_vs_phi_for_wrong_charge_seed_c->Divide(2,3);
    pt_vs_phi_for_wrong_charge_seed_c->cd(1); pt_vs_phi_for_wrong_charge_seed[0]->Draw("COLZ");
    pt_vs_phi_for_wrong_charge_seed_c->cd(2); pt_vs_phi_for_wrong_charge_seed[1]->Draw("COLZ");
    pt_vs_phi_for_wrong_charge_seed_c->cd(3); pt_vs_phi_for_wrong_charge_seed[2]->Draw("COLZ");
    pt_vs_phi_for_wrong_charge_seed_c->cd(4); pt_vs_phi_for_wrong_charge_seed[3]->Draw("COLZ");
    pt_vs_phi_for_wrong_charge_seed_c->cd(5); pt_vs_phi_for_wrong_charge_seed[4]->Draw("COLZ");
    pt_vs_phi_for_wrong_charge_seed_c->cd(6);
    TPaveText* tex_gen61 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen61->AddText("1) (0,0,0)");
    tex_gen61->AddText("2) (0,0,10)");
    tex_gen61->AddText("3) (0,0,-10)");
    tex_gen61->AddText("4) (1,0,0)");
    tex_gen61->AddText("5) (10,0,0)");
    tex_gen61->SetFillStyle(400);tex_gen61->SetTextFont(3);tex_gen61->SetTextSize(10);
    tex_gen61->Draw();
    
    TCanvas *pt_vs_eta_seed_c = new TCanvas("pt_vs_eta_seed_c");
    pt_vs_eta_seed_c->Divide(2,3);
    pt_vs_eta_seed_c->cd(1); pt_vs_eta_seed[0]->Draw("COLZ");
    pt_vs_eta_seed_c->cd(2); pt_vs_eta_seed[1]->Draw("COLZ");
    pt_vs_eta_seed_c->cd(3); pt_vs_eta_seed[2]->Draw("COLZ");
    pt_vs_eta_seed_c->cd(4); pt_vs_eta_seed[3]->Draw("COLZ");
    pt_vs_eta_seed_c->cd(5); pt_vs_eta_seed[4]->Draw("COLZ");
    pt_vs_eta_seed_c->cd(6);
    TPaveText* tex_gen600 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen600->AddText("1) (0,0,0)");
    tex_gen600->AddText("2) (0,0,10)");
    tex_gen600->AddText("3) (0,0,-10)");
    tex_gen600->AddText("4) (1,0,0)");
    tex_gen600->AddText("5) (10,0,0)");
    tex_gen600->SetFillStyle(400);tex_gen600->SetTextFont(3);tex_gen600->SetTextSize(10);
    tex_gen600->Draw();


 TCanvas *pt_vs_eta_ckf_c = new TCanvas("pt_vs_eta_ckf_c");
    pt_vs_eta_ckf_c->Divide(2,3);
    pt_vs_eta_ckf_c->cd(1); pt_vs_eta_ckf[0]->Draw("COLZ");
    pt_vs_eta_ckf_c->cd(2); pt_vs_eta_ckf[1]->Draw("COLZ");
    pt_vs_eta_ckf_c->cd(3); pt_vs_eta_ckf[2]->Draw("COLZ");
    pt_vs_eta_ckf_c->cd(4); pt_vs_eta_ckf[3]->Draw("COLZ");
    pt_vs_eta_ckf_c->cd(5); pt_vs_eta_ckf[4]->Draw("COLZ");
    pt_vs_eta_ckf_c->cd(6);

    
    TCanvas *pt_vs_eta_for_wrong_charge_seed_c = new TCanvas("pt_vs_eta_for_wrong_charge_seed_c");
    pt_vs_eta_for_wrong_charge_seed_c->Divide(2,3);
    pt_vs_eta_for_wrong_charge_seed_c->cd(1); pt_vs_eta_for_wrong_charge_seed[0]->Draw("COLZ");
    pt_vs_eta_for_wrong_charge_seed_c->cd(2); pt_vs_eta_for_wrong_charge_seed[1]->Draw("COLZ");
    pt_vs_eta_for_wrong_charge_seed_c->cd(3); pt_vs_eta_for_wrong_charge_seed[2]->Draw("COLZ");
    pt_vs_eta_for_wrong_charge_seed_c->cd(4); pt_vs_eta_for_wrong_charge_seed[3]->Draw("COLZ");
    pt_vs_eta_for_wrong_charge_seed_c->cd(5); pt_vs_eta_for_wrong_charge_seed[4]->Draw("COLZ");
    pt_vs_eta_for_wrong_charge_seed_c->cd(6);
    TPaveText* tex_gen611 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen611->AddText("1) (0,0,0)");
    tex_gen611->AddText("2) (0,0,10)");
    tex_gen611->AddText("3) (0,0,-10)");
    tex_gen611->AddText("4) (1,0,0)");
    tex_gen611->AddText("5) (10,0,0)");
    tex_gen611->SetFillStyle(400);tex_gen611->SetTextFont(3);tex_gen611->SetTextSize(10);
    tex_gen611->Draw();
    
    
    TCanvas *num_trk_c = new TCanvas("num_trk_c");
    num_trk_c->Divide(2,3);
    num_trk_c->cd(1);num_track[0]->Draw("hist");
    num_trk_c->cd(2);num_track[1]->Draw("hist");
    num_trk_c->cd(3);num_track[2]->Draw("hist");
    num_trk_c->cd(4);num_track[3]->Draw("hist");
    num_trk_c->cd(5);num_track[4]->Draw("hist");
    num_trk_c->cd(6);
    TPaveText* tex_gen7 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen7->AddText("1) (0,0,0)");
    tex_gen7->AddText("2) (0,0,10)");
    tex_gen7->AddText("3) (0,0,-10)");
    tex_gen7->AddText("4) (1,0,0)");
    tex_gen7->AddText("5) (10,0,0)");
    tex_gen7->SetFillStyle(400);tex_gen7->SetTextFont(3);tex_gen7->SetTextSize(10);
    tex_gen7->Draw();
    
    TCanvas *num_trk_eta_c = new TCanvas("num_trk_eta_c");
    num_trk_eta_c->Divide(2,3);
    num_trk_eta_c->cd(1); num_trk_vs_particle_eta[0]->Draw("colz");
    num_trk_eta_c->cd(2); num_trk_vs_particle_eta[1]->Draw("colz");
    num_trk_eta_c->cd(3); num_trk_vs_particle_eta[2]->Draw("colz");
    num_trk_eta_c->cd(4); num_trk_vs_particle_eta[3]->Draw("colz");
    num_trk_eta_c->cd(5); num_trk_vs_particle_eta[4]->Draw("colz");
    num_trk_eta_c->cd(6);
    TPaveText* tex_gen8 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen8->AddText("1) (0,0,0)");
    tex_gen8->AddText("2) (0,0,10)");
    tex_gen8->AddText("3) (0,0,-10)");
    tex_gen8->AddText("4) (1,0,0)");
    tex_gen8->AddText("5) (10,0,0)");
    tex_gen8->SetFillStyle(400);tex_gen8->SetTextFont(3);tex_gen8->SetTextSize(10);
    tex_gen8->Draw();

    TCanvas *c8 = new TCanvas("c8");
    c8->Divide(2,3);
    c8->cd(1); eta_efficiency_gentrack[0]->Draw(); eta_efficiency_real_genseed[0]->Draw("same"); eta_efficiency_truth_genseed[0]->Draw("same");
    c8->cd(2); eta_efficiency_gentrack[1]->Draw(); eta_efficiency_real_genseed[1]->Draw("same"); eta_efficiency_truth_genseed[1]->Draw("same");
    c8->cd(3); eta_efficiency_gentrack[2]->Draw(); eta_efficiency_real_genseed[2]->Draw("same"); eta_efficiency_truth_genseed[2]->Draw("same");
    c8->cd(4); eta_efficiency_gentrack[3]->Draw(); eta_efficiency_real_genseed[3]->Draw("same"); eta_efficiency_truth_genseed[3]->Draw("same");
    c8->cd(5); eta_efficiency_gentrack[4]->Draw(); eta_efficiency_real_genseed[4]->Draw("same"); eta_efficiency_truth_genseed[4]->Draw("same");
    c8->cd(6);
    TPaveText* tex_gen9 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen9->AddText("1) (0,0,0)");
    tex_gen9->AddText("2) (0,0,10)");
    tex_gen9->AddText("3) (0,0,-10)");
    tex_gen9->AddText("4) (1,0,0)");
    tex_gen9->AddText("5) (10,0,0)");
    tex_gen9->SetFillStyle(400);tex_gen9->SetTextFont(3);tex_gen9->SetTextSize(10);
    tex_gen9->Draw();
 
    TCanvas *c8b = new TCanvas("c8b");
    c8b->Divide(2,3);
    c8b->cd(1); phi_efficiency_gentrack[0]->Draw(); phi_efficiency_real_genseed[0]->Draw("same"); phi_efficiency_truth_genseed[0]->Draw("same");
    c8b->cd(2); phi_efficiency_gentrack[1]->Draw(); phi_efficiency_real_genseed[1]->Draw("same"); phi_efficiency_truth_genseed[1]->Draw("same");
    c8b->cd(3); phi_efficiency_gentrack[2]->Draw(); phi_efficiency_real_genseed[2]->Draw("same"); phi_efficiency_truth_genseed[2]->Draw("same");
    c8b->cd(4); phi_efficiency_gentrack[3]->Draw(); phi_efficiency_real_genseed[3]->Draw("same"); phi_efficiency_truth_genseed[3]->Draw("same");
    c8b->cd(5); phi_efficiency_gentrack[4]->Draw(); phi_efficiency_real_genseed[4]->Draw("same"); phi_efficiency_truth_genseed[4]->Draw("same");
    c8b->cd(6);
    TPaveText* tex_gen9b = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen9b->AddText("1) (0,0,0)");
    tex_gen9b->AddText("2) (0,0,10)");
    tex_gen9b->AddText("3) (0,0,-10)");
    tex_gen9b->AddText("4) (1,0,0)");
    tex_gen9b->AddText("5) (10,0,0)");
    tex_gen9b->SetFillStyle(400);tex_gen9b->SetTextFont(3);tex_gen9b->SetTextSize(10);
    tex_gen9b->Draw();
    
    
    TCanvas *unique_trk_vs_eta_c = new TCanvas("unique_trk_vs_eta_c");
    unique_trk_vs_eta_c->Divide(2,3);
    unique_trk_vs_eta_c->cd(1); unique_trk_vs_particle_eta[0]->Draw("colz");
    unique_trk_vs_eta_c->cd(2); unique_trk_vs_particle_eta[1]->Draw("colz");
    unique_trk_vs_eta_c->cd(3); unique_trk_vs_particle_eta[2]->Draw("colz");
    unique_trk_vs_eta_c->cd(4); unique_trk_vs_particle_eta[3]->Draw("colz");
    unique_trk_vs_eta_c->cd(5); unique_trk_vs_particle_eta[4]->Draw("colz");
    unique_trk_vs_eta_c->cd(6);
    TPaveText* tex_gen10 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen10->AddText("1) (0,0,0)");
    tex_gen10->AddText("2) (0,0,10)");
    tex_gen10->AddText("3) (0,0,-10)");
    tex_gen10->AddText("4) (1,0,0)");
    tex_gen10->AddText("5) (10,0,0)");
    tex_gen10->SetFillStyle(400);tex_gen7->SetTextFont(3);tex_gen7->SetTextSize(10);
    tex_gen10->Draw();
    
    
    TCanvas *r_z_true_c = new TCanvas("r_z_true_c");
    r_z_true_c->Divide(2,3);
    r_z_true_c->cd(1); h_r_z_true[0]->Draw("colz");
    r_z_true_c->cd(2); h_r_z_true[1]->Draw("colz");
    r_z_true_c->cd(3); h_r_z_true[2]->Draw("colz");
    r_z_true_c->cd(4); h_r_z_true[3]->Draw("colz");
    r_z_true_c->cd(5); h_r_z_true[4]->Draw("colz");
    r_z_true_c->cd(6);
    TPaveText* tex_gen19 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen19->AddText("1) (0,0,0)");
    tex_gen19->AddText("2) (0,0,10)");
    tex_gen19->AddText("3) (0,0,-10)");
    tex_gen19->AddText("4) (1,0,0)");
    tex_gen19->AddText("5) (10,0,0)");
    tex_gen19->SetFillStyle(400);tex_gen19->SetTextFont(3);tex_gen19->SetTextSize(10);
    tex_gen19->Draw();
    
    
    TCanvas *r_z_trk_c = new TCanvas("r_z_trk_c");
    r_z_trk_c->Divide(2,3);
    r_z_trk_c->cd(1); h_r_z_track[0]->Draw("colz");
    r_z_trk_c->cd(2); h_r_z_track[1]->Draw("colz");
    r_z_trk_c->cd(3); h_r_z_track[2]->Draw("colz");
    r_z_trk_c->cd(4); h_r_z_track[3]->Draw("colz");
    r_z_trk_c->cd(5); h_r_z_track[4]->Draw("colz");
    r_z_trk_c->cd(6);
    TPaveText* tex_gen18 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen18->AddText("1) (0,0,0)");
    tex_gen18->AddText("2) (0,0,10)");
    tex_gen18->AddText("3) (0,0,-10)");
    tex_gen18->AddText("4) (1,0,0)");
    tex_gen18->AddText("5) (10,0,0)");
    tex_gen18->SetFillStyle(400);tex_gen18->SetTextFont(3);tex_gen18->SetTextSize(10);
    tex_gen18->Draw();
    
    TCanvas *r_z_seed_c = new TCanvas("r_z_seed_c");
    r_z_seed_c->Divide(2,3);
    r_z_seed_c->cd(1); h_r_z_seed[0]->Draw("colz");
    r_z_seed_c->cd(2); h_r_z_seed[1]->Draw("colz");
    r_z_seed_c->cd(3); h_r_z_seed[2]->Draw("colz");
    r_z_seed_c->cd(4); h_r_z_seed[3]->Draw("colz");
    r_z_seed_c->cd(5); h_r_z_seed[4]->Draw("colz");
    r_z_seed_c->cd(6);
    TPaveText* tex_gen17 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen17->AddText("1) (0,0,0)");
    tex_gen17->AddText("2) (0,0,10)");
    tex_gen17->AddText("3) (0,0,-10)");
    tex_gen17->AddText("4) (1,0,0)");
    tex_gen17->AddText("5) (10,0,0)");
    tex_gen17->SetFillStyle(400);tex_gen17->SetTextFont(3);tex_gen17->SetTextSize(10);
    tex_gen17->Draw();
    
    TCanvas *rec_over_gen_trk_c = new TCanvas("rec_over_gen_trk_c");
    rec_over_gen_trk_c->Divide(2,3);
    rec_over_gen_trk_c->cd(1); h_rec_over_gen_trk[0]->Draw();
    rec_over_gen_trk_c->cd(2); h_rec_over_gen_trk[1]->Draw();
    rec_over_gen_trk_c->cd(3); h_rec_over_gen_trk[2]->Draw();
    rec_over_gen_trk_c->cd(4); h_rec_over_gen_trk[3]->Draw();
    rec_over_gen_trk_c->cd(5); h_rec_over_gen_trk[4]->Draw();
    rec_over_gen_trk_c->cd(6);
    TPaveText* tex_gen14 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen14->AddText("1) (0,0,0)");
    tex_gen14->AddText("2) (0,0,10)");
    tex_gen14->AddText("3) (0,0,-10)");
    tex_gen14->AddText("4) (1,0,0)");
    tex_gen14->AddText("5) (10,0,0)");
    tex_gen14->SetFillStyle(400);tex_gen14->SetTextFont(3);tex_gen14->SetTextSize(10);
    tex_gen14->Draw();
    
   
    TCanvas *rec_over_gen_seed_c = new TCanvas("rec_over_gen_seed_c");
    rec_over_gen_seed_c->Divide(2,3);
    rec_over_gen_seed_c->cd(1); h_rec_over_gen_seed[0]->Draw();
    rec_over_gen_seed_c->cd(2); h_rec_over_gen_seed[1]->Draw();
    rec_over_gen_seed_c->cd(3); h_rec_over_gen_seed[2]->Draw();
    rec_over_gen_seed_c->cd(4); h_rec_over_gen_seed[3]->Draw();
    rec_over_gen_seed_c->cd(5); h_rec_over_gen_seed[4]->Draw();
    rec_over_gen_seed_c->cd(6);
    TPaveText* tex_gen15 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen15->AddText("1) (0,0,0)");
    tex_gen15->AddText("2) (0,0,10)");
    tex_gen15->AddText("3) (0,0,-10)");
    tex_gen15->AddText("4) (1,0,0)");
    tex_gen15->AddText("5) (10,0,0)");
    tex_gen15->SetFillStyle(400);tex_gen15->SetTextFont(3);tex_gen15->SetTextSize(10);
    tex_gen15->Draw();
    
    TCanvas *rec_over_gen_true_c = new TCanvas("rec_over_gen_true_c");
    rec_over_gen_true_c->Divide(2,3);
    rec_over_gen_true_c->cd(1); h_rec_over_gen_true[0]->Draw();
    rec_over_gen_true_c->cd(2); h_rec_over_gen_true[1]->Draw();
    rec_over_gen_true_c->cd(3); h_rec_over_gen_true[2]->Draw();
    rec_over_gen_true_c->cd(4); h_rec_over_gen_true[3]->Draw();
    rec_over_gen_true_c->cd(5); h_rec_over_gen_true[4]->Draw();
    rec_over_gen_true_c->cd(6);
    TPaveText* tex_gen16 = new TPaveText(0.475,0.1,0.9,0.85,"NDCNB");
    tex_gen16->AddText("1) (0,0,0)");
    tex_gen16->AddText("2) (0,0,10)");
    tex_gen16->AddText("3) (0,0,-10)");
    tex_gen16->AddText("4) (1,0,0)");
    tex_gen16->AddText("5) (10,0,0)");
    tex_gen16->SetFillStyle(400);tex_gen16->SetTextFont(3);tex_gen16->SetTextSize(10);
    tex_gen16->Draw();
    
    TCanvas *theta_vs_phi_real_c = new TCanvas("theta_vs_phi_real_c");
    theta_vs_phi_real_c->Divide(2,3);
    theta_vs_phi_real_c->cd(1); theta_vs_phi_real[0]->Draw();
    theta_vs_phi_real_c->cd(2); theta_vs_phi_real[1]->Draw();
    theta_vs_phi_real_c->cd(3); theta_vs_phi_real[2]->Draw();
    theta_vs_phi_real_c->cd(4); theta_vs_phi_real[3]->Draw();
    theta_vs_phi_real_c->cd(5); theta_vs_phi_real[4]->Draw();
    
    TCanvas *theta_vs_p_real_c = new TCanvas("theta_vs_p_real_c");
    theta_vs_p_real_c->Divide(2,3);
    theta_vs_p_real_c->cd(1); theta_vs_p_real[0]->Draw();
    theta_vs_p_real_c->cd(2); theta_vs_p_real[1]->Draw();
    theta_vs_p_real_c->cd(3); theta_vs_p_real[2]->Draw();
    theta_vs_p_real_c->cd(4); theta_vs_p_real[3]->Draw();
    theta_vs_p_real_c->cd(5); theta_vs_p_real[4]->Draw();
    
    TCanvas *phi_vs_p_real_c = new TCanvas("phi_vs_p_real_c");
    phi_vs_p_real_c->Divide(2,3);
    phi_vs_p_real_c->cd(1); phi_vs_p_real[0]->Draw();
    phi_vs_p_real_c->cd(2);phi_vs_p_real[1]->Draw();
    phi_vs_p_real_c->cd(3); phi_vs_p_real[2]->Draw();
    phi_vs_p_real_c->cd(4); phi_vs_p_real[3]->Draw();
    phi_vs_p_real_c->cd(5); phi_vs_p_real[4]->Draw();
    
    // TCanvas *r_z_true_c = new TCanvas("r_z_true_c");
    //  h_m->Draw();
    //Print plots to file
       p_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf[",dupl_cut_qop));
       p_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
       p_res_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      theta_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      theta_res_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      phi_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      phi_res_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      c8->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      c8b->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
       r_res_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      z_res_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
       charge_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      pt_vs_phi_seed_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      pt_vs_phi_for_wrong_charge_seed_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      pt_vs_eta_seed_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      pt_vs_eta_ckf_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      pt_vs_eta_for_wrong_charge_seed_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
       num_trk_eta_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
  // -- pz_true_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
 //   pt_true_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
 //   rec_over_gen_true_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
// pz_seed_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
//    pt_seed_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
 //  rec_over_gen_seed_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
//    pz_track_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
//  pt_track_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
//          rec_over_gen_trk_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
//    r_z_true_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
//    r_z_seed_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
// --   r_z_trk_c->Print(Form("track_resolutions_rs_%.0ftest.pdf",dupl_cut_qop));
        num_trk_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	//p_res_eta_16_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	//  p_res_eta_32_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	//  p_res_eta_48_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	//p_res_eta_64_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	//p_res_eta_80_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	nmeasurements->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
    noutliers->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
    nholes->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
    nchi->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
    nmeasurement_vs_noutliers->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
    q_over_p_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));

      int neta = 16;
  TGraphErrors *gr[neta];

        for(int ieta=0;ieta<neta;ieta++){
                gr[ieta] = new TGraphErrors();
                gr[ieta]->SetMarkerColor(kBlue);gr[ieta]->SetLineColor(kBlue);
                gr[ieta]->SetMarkerStyle(20);gr[ieta]->SetMarkerSize(2);
                gr[ieta]->SetLineWidth(1);
        }

        PadMxN *pad4x4;
        PadMxN *pad4x2;
        TPad *mypad = {0};
        int counter = 0;

        for(int ieta=0;ieta<neta;ieta++){

                //Draw momentum from 0-8 GeV/c                                                                                                                                                                                                                                                                                                                                                                                                                                              
                pad4x4 = new PadMxN(Form("c7a_%d",ieta),500,500,150,100,100,150,4,4);
        pad4x4->Draw();
                mypad = {0};
                counter = 0;

                for(int i=0;i<16;i++){
                        mypad = pad4x4->GetPad(i+1);
                        p_res_eta[ieta][counter][0]->Draw();

                        if(p_res_eta[ieta][counter][0]->GetEntries() > 10){
                                p_res_eta[ieta][counter][0]->Fit("gaus");

                                gr[ieta]->SetPoint(counter , 0.5 + counter , p_res_eta[ieta][counter][0]->GetFunction("gaus")->GetParameter(2) );
                                gr[ieta]->SetPointError(counter, 0, p_res_eta[ieta][counter][0]->GetFunction("gaus")->GetParError(2) );
                        }
                        else{
                                gr[ieta]->SetPoint(counter ,0.5+counter, 0 );
                                gr[ieta]->SetPointError(counter, 0, 0 );
                        }

                        counter++;
                }

		//      gROOT->ProcessLine( Form("c7a_%d->Print(\"track_resolutions_rs_%.0f_cov_loc_3_3.pdf\");",ieta,dupl_cut_qop) );

               

pad4x2 = new PadMxN(Form("c7c_%d",ieta),500,500,150,100,100,150,4,2);
    	pad4x2->Draw();
	for(int imom=0;imom<4;imom++){
		mypad = pad4x2->GetPad(imom+1);
                        p_res_eta[ieta][counter][0]->Draw();

                        if(p_res_eta[ieta][counter][0]->GetEntries() > 10){
                               p_res_eta[ieta][counter][0]->Fit("gaus");

                                gr[ieta]->SetPoint(counter ,0.5+counter, p_res_eta[ieta][counter][0]->GetFunction("gaus")->GetParameter(2) );
                                gr[ieta]->SetPointError(counter, 0, p_res_eta[ieta][counter][0]->GetFunction("gaus")->GetParError(2) );
                        }
                        else{
                                gr[ieta]->SetPoint(counter ,0.5+counter, 0 );
                                gr[ieta]->SetPointError(counter, 0, 0 );
                        }

                        counter++;
                }

	//      gROOT->ProcessLine( Form("c7c_%d->Print(\"track_resolutions_rs_%.0f_cov_loc_3_3.pdf\");",ieta,dupl_cut_qop) );


        }





	PadMxN *pad4x4a = new PadMxN("ccc",500,500,150,100,100,150,4,4);
 pad4x4a->Draw();
	TH2 *htemp = new TH2F("htemp","",10,0,20,10,0,15);
        
	for(int ieta=0;ieta<neta;ieta++){
		mypad = pad4x4a->GetPad(ieta+1);

		htemp->Draw();
		htemp->GetXaxis()->SetTitle("Momentum [GeV/c]");htemp->GetYaxis()->SetTitle("100 x #sigma_{p}/p [%]");
		htemp->GetXaxis()->SetLabelFont(63);htemp->GetYaxis()->SetLabelFont(63);
      	htemp->GetXaxis()->SetLabelSize(25);htemp->GetYaxis()->SetLabelSize(25);
      	htemp->GetXaxis()->SetLabelOffset(0.01);htemp->GetYaxis()->SetLabelOffset(0.01);
      	htemp->GetXaxis()->CenterTitle(1);htemp->GetYaxis()->CenterTitle(1);
      	htemp->GetXaxis()->SetTitleSize(35);htemp->GetXaxis()->SetTitleOffset(2.5); 
      	htemp->GetYaxis()->SetTitleSize(35);htemp->GetYaxis()->SetTitleOffset(3.0);

		if(ieta<16){
		  gr[ieta]->Draw("P same");
		}}
	//gROOT->ProcessLine( Form("ccc->Print(\"track_resolutions_rs_%.0f_cov_loc_3_3.pdf\");",dupl_cut_qop) );
		  
	p_for_outlier_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	eta_for_outlier_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	phi_for_outlier_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	chi_for_outlier_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
	unique_trk_vs_eta_c->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf",dupl_cut_qop));
      unique_trk_vs_eta_c ->Print(Form("track_resolutions_rs_%.0f_cov_loc_3_3.pdf]",dupl_cut_qop));

}
