/**************************************************
 * Systematics - Exercise 4                       *
 * Plot the systematic uncertainties calculated   *
 * in exercise 2                                  *
 **************************************************/

#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "PlotUtils/MnvPlotter.h"
#include "PlotUtils/MnvH1D.h"
#include "TROOT.h"
#include "PlotUtils/MnvApplication.h"
#include "TH1.h"

using namespace std;
using namespace PlotUtils;

void Systematics_Solution4(string filename="mySystematics.root", double data_pot=1.85814, double mc_pot=5.747);
void SetupStyles(PlotUtils::MnvPlotter *plotter);

int main(int argc, char *argv[])
{
  PlotUtils::Initialize();
  Systematics_Solution4();
}

void Systematics_Solution4(string filename, double data_pot, double mc_pot)
{
  // Read the ROOT file containing your histograms
  TFile *f = new TFile( filename.c_str(), "READ" );
  
  // Set up a plotter object, using the PlotUtils functionality
  MnvPlotter *plotter = new MnvPlotter( ); 
  SetupStyles(plotter);

  // Get the histograms from your ROOT file and convert them to MnvH1D.
  // The MnvH1D structure holds the central value TH1D histogram
  // as well as histograms for all the systematics universes
  MnvH1D *h_Muon_Energy_mc = (MnvH1D*)f->Get("h_Muon_Energy_mc");
  MnvH1D *h_Muon_Energy_data = (MnvH1D*)f->Get("h_Muon_Energy_data");

  // Scale the Monte Carlo to the data POT
  if (h_Muon_Energy_mc->GetSumw2N() == 0 )   h_Muon_Energy_mc ->Sumw2();
  h_Muon_Energy_mc->Scale(data_pot/mc_pot);

  TCanvas *c;

  // Set up a canvas, and use the DrawDataMCWithErrorBand feature of MnvPlotter
  // to plot the data and Monte Carlo including systematic uncertainties
  // Save the plot as myMuonEnergyplot.png and other formats
  c = new TCanvas("cEnergy","Emu");
  plotter->DrawDataMCWithErrorBand( h_Muon_Energy_data, h_Muon_Energy_mc, 1, "TL", true, NULL, NULL, false);
  plotter->MultiPrint( c, "myMuonEnergyplot"); 

  // Set up a canvas, and use the DrawDataMCErrorSummary feature of MnvPlotter
  // to draw the fractional uncertainties.
  // Save the plot as mySysplot.png and other formats
  c = new TCanvas("cEmySysS","Emu");
  plotter->DrawDataMCErrorSummary( h_Muon_Energy_mc,h_Muon_Energy_data, "TL", true, true, 0.0, false  ); 
//  plotter->DrawDataMCErrorSummary( h_Muon_Energy_data,h_Muon_Energy_mc, "TL", true, true, 0.0, false  ); 
  plotter->MultiPrint( c, "mySysplot"); 

}
void SetupStyles(PlotUtils::MnvPlotter *plotter)
{
  //-- legend
  plotter->height_nspaces_per_hist = 1.2;
  plotter->width_xspace_per_letter = .4;
  plotter->legend_text_size        = .03;
  plotter->legend_n_columns        = 1;

  plotter->axis_title_size_y = 0.05;
  plotter->axis_title_size_x = 0.05;
  plotter->axis_title_offset_y = 1.15;
  plotter->extra_left_margin   = 0.1;
  plotter->title_size = 0.07;
}
