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


void Systematics_Solution4(string filename="mySystematics.root", double data_pot=1.87572, double mc_pot=5.7295);
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
  // This will let you make formatted plots quickly and easily
  MnvPlotter *plotter = new MnvPlotter( ); 
  SetupStyles(plotter); // Edit this to change the look of your plots

  // Load the data and MC MnvH1D objects from your data file
  MnvH1D *h_Muon_Energy_mc = (MnvH1D*)f->Get("h_Muon_Energy_mc");
  MnvH1D *h_Muon_Energy_data = (MnvH1D*)f->Get("h_Muon_Energy_data");

  // ##### Scale the Monte Carlo to the data POT

  TCanvas *c;

  // ##### 
  //Set up a canvas, and use the DrawDataMCWithErrorBand feature of MnvPlotter
  // to plot the data and Monte Carlo including systematic uncertainties
  // Save the plot as myMuonEnergyplot.png and other formats

  // #####
  // Set up a canvas, and use the DrawDataMCErrorSummary feature of MnvPlotter
  // to draw the fractional uncertainties.
  // Save the plot as mySysplot.png and other formats using plotter->MultiPrint

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
