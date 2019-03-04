/* 
   Nuruzzaman 04/05/2018
   A quick script to trim trees.

   To run the script, please provide the input file 
   with path and output file with path.
   e.g;
   root -l 'trimRootfile.C("/minerva/data/users/nur/NuE/NuE_mc_minervame1B_SignalOnly_v21r1p1.root","/minerva/data/users/nur/NuE/NuE_mc_me1B_SignalOnly_v21r1p1.root")'
*/
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"

void trimRootfile(char *input_file, char *output_file) {

  /* Array of analysis variables */
  const unsigned int AnaVar = 65;
  Char_t *AnaTreeArray[AnaVar] = {
    "nullReco","truth_is_plausible","chi2PerDoF","e_is_plausible","fiducial_evt",
    "trackerVisE","ecalVisE","sideEcalVisEX","sideEcalVisEU","sideEcalVisEV",
    "hcalVisE","tdead","bendingAngle","E","dEdx_4planes","theta","theta_bc",
    "Eth2","Q2_ccqe","angle_x_bc","angle_y_bc","shower_TPosResidual_x",
    "shower_TPosResidual_u","shower_TPosResidual_v","peaksInEcal",
    "recoE_x","recoE_u","recoE_v","shower_end_mod2","shower_meanR_trk_1stOneThird",
    "vtxToShowerMaxSlope","trk_end_x","trk_end_u","trk_end_v","vtx_x","vtx_y","vtx_z",
    "vtx_mod","upstreamE","upstreamE_n_overlaps","neighborhoodEnergy",
    "nTrackableClustersInTracker","nClustersInTracker","mc_run","mc_subrun",
    "mc_intType","mc_current","mc_incoming","wgt","seedingMethod","nx","ny","nz",
    "dE1","dE2","dE3","dE4","dE5","dE6","ev_run","ev_subrun","ev_gate",
    "numi_pot","batch_structure","reco_vertex_batch"
  };

  /* Array of meta variables */
  const unsigned int MetaVar = 8;
  Char_t *MetaTreeArray[MetaVar] = {
    "POT_Used","POT_Total","POT_Used_batch1","POT_Used_batch2","POT_Used_batch3",
    "POT_Used_batch4","POT_Used_batch5","POT_Used_batch6"
  };

  TFile *oldfile;
  TString dir = Form("%s",input_file);
  gSystem->ExpandPathName(dir);
  if (!gSystem->AccessPathName(dir))
    {oldfile = new TFile(Form("%s",input_file));}
  else {oldfile = new TFile(Form("%s",input_file));}

  /* Turn off all the branches from the slected EMShower tree */
  TTree *oldtree = (TTree*)oldfile->Get("EMShower");
  oldtree->SetBranchStatus("*",0);

  /* Turn off all the branches from the slected Meta tree */
  TTree *oldtreeM = (TTree*)oldfile->Get("Meta");
  oldtreeM->SetBranchStatus("*",0);

  /* Turn on the branches you need from the EMShower tree*/
  for( int i = 0; i < AnaVar; i++ ) {
    cout << "AnaTreeArray: " << i+1 <<" "<< AnaTreeArray[i]  << endl;
    oldtree->SetBranchStatus(AnaTreeArray[i],1);
  }

  /* Turn on the branches you need from the Meta tree*/
  for( int i = 0; i < MetaVar; i++ ) {
    cout << "MetaTreeArray: " << i+1 <<" "<< MetaTreeArray[i]  << endl;
    oldtreeM->SetBranchStatus(MetaTreeArray[i],1);
  }

  /* Create a clone of old tree to a new file */
  TFile *newfile = new TFile(Form("%s",output_file),"recreate");
  TTree *newtree = oldtree->CloneTree();
  TTree *newtree = oldtreeM->CloneTree();
  newtree->Print();
  newfile->Write();
  delete oldfile;
  delete newfile;


}

