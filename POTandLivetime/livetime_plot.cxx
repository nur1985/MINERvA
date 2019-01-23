/*
################################################################
# A script to plot the live time for MINERvA, and MINOS 
# Nuruzzaman <nur@fnal.gov>, Date Created: 02/17/2017
# 
# Run the script without any input options by doing 
# -> root -l livetime_plot.C
# this will produce a plot "live_time.png" in plots/ area. 
# With options you can run 
# -> root -l 'livetime_plot.C(90,102.5,0.1,0.1,1)'
# Here are the options: 
# 90 - Y low scale
# 102.5 - Y hi scale  
# 0.1 and 0.1 - set the label co-ordinates
# 1 - copy the plot to shift website and o will not copy the plot.
# The plot can be accessed at
# http://minerva-exp.fnal.gov/shift/live.html
#################################################################
*/

#include <ctype.h>
#include <string.h>
#include <map>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;
int livetime_plot(double y_min = 0, double y_max=101.5,double xlab_start=0.10,double ylab_start=0.10,int copy_fun=0)  
{
  double eff_low_cut=0.01;
   std::string month_label[13]
    = {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  ifstream in_data;
  int numData=0;
  int month, day, year;
  char*current_year="2017";
  double pot_recorded, pot_delivered, total_daq_livetime,minos_pot,minos_efficiency;
  double live_time, minos_live, minerva_daq_livetime;
  double pot_recorded_tot, pot_delivered_tot, pot_recorded_minos, pot_delivered_minos, avg_daq_livetime=0;
  char dat[20], blank[20], char_day[2], char_year[10];
// Parameters
  double x_err=0.0001, y_err=0.0001;

  int minerva_eff_marker=kFullStar, minos_eff_marker=kFullCircle, minerva_livetime_marker=kFullSquare;
  int minerva_eff_color=kBlue, minos_eff_color=kGreen+2, minerva_livetime_color=kRed;
  double minerva_eff_size=2.5, minos_eff_size=1.8, minerva_livetime_size=1.7;
  int text_color=51, label_color=kBlack;
  double x_size_label=0.070, y_size_label=0.050, y_text_label_size=0.050, y_title_offset=1.05;
  float txtsize=0.050;

  int color_label=1;
  int y_color_axis=1;
  double symSize=2.50;
  char* y_axis_label="Live time [%]";
  TText *titl = new TText();
  titl->SetTextSize(y_text_label_size);
  titl->SetTextColor(label_color);
  int fillcolor=38;
//end parameters
  in_data.open("lt.txt");
  while( in_data>>year>>month>>day>>pot_recorded>>minos_pot>>pot_delivered>>live_time>>minos_efficiency>>minerva_daq_livetime)
  { 
    in_data.ignore(100,'\n');
    total_daq_livetime=total_daq_livetime+minerva_daq_livetime; 
    numData++;
  }
  avg_daq_livetime=total_daq_livetime/numData;
  cout<<avg_daq_livetime<<'\n';
  in_data.close();

//  Margin( 0.10, 0.04, 0.13, 0.12);
  TCanvas *c2 = new TCanvas("c2","",1200,700);
  gPad->SetGrid();
  gPad->SetTopMargin(0.10);
  gPad->SetBottomMargin(0.12);
  gPad->SetLeftMargin(0.12);
  gPad->SetRightMargin(0.05);
  c2->Range(0,0,20,20);
  c2->SetFillColor(0);
// minerva efficiency
  TH1F *mnv_eff = new TH1F("mnv_eff","MINERvA Efficiency",numData,0,numData);
  mnv_eff->SetTitle("");
  mnv_eff->SetStats(0);
  mnv_eff->SetFillColor(0);
  mnv_eff->SetBit(TH1::kCanRebin);
  mnv_eff->GetYaxis()->SetTitle(y_axis_label);
  mnv_eff->GetXaxis()->SetLabelSize(x_size_label);
  mnv_eff->GetYaxis()->SetLabelSize(y_size_label); //new
  mnv_eff->GetXaxis()->SetLabelColor(label_color);
  mnv_eff->GetYaxis()->SetLabelColor(label_color);
  mnv_eff->SetMinimum(y_min);
  mnv_eff->SetMaximum(y_max);
  mnv_eff->GetYaxis()->SetTitleColor(label_color);
  mnv_eff->GetYaxis()->SetTitleSize(y_text_label_size);
  mnv_eff->GetYaxis()->SetTitleOffset(y_title_offset);

// minerva DAQ clock livetime
  TH1F *mnv_daq_eff = new TH1F("mnv_daq_eff","MINERvA DAQ Efficiency",numData,0,numData);
  mnv_daq_eff->SetTitle("");
  mnv_daq_eff->SetStats(0);
  mnv_daq_eff->SetFillColor(kRed-7);
  mnv_daq_eff->SetFillStyle(3001);
  mnv_daq_eff->SetBarWidth(0.3);
  mnv_daq_eff->SetBarOffset(0.3);
  mnv_daq_eff->SetBit(TH1::kCanRebin);
  mnv_daq_eff->GetYaxis()->SetTitle(y_axis_label);
  mnv_daq_eff->GetXaxis()->SetLabelSize(x_size_label);
  mnv_daq_eff->GetYaxis()->SetLabelSize(y_size_label); //new
  mnv_daq_eff->GetXaxis()->SetLabelColor(color_label);
  mnv_daq_eff->GetYaxis()->SetLabelColor(color_label);
  mnv_daq_eff->SetMinimum(y_min);
  mnv_daq_eff->SetMaximum(y_max);
  mnv_daq_eff->GetYaxis()->SetTitleColor(y_color_axis);
  mnv_daq_eff->GetYaxis()->SetTitleSize(y_text_label_size);
  mnv_daq_eff->GetYaxis()->SetTitleOffset(y_title_offset);

// minerva efficiency
  TH1F *minos_eff = new TH1F("minos_eff","MINOS Efficiency",numData,0,numData);
  minos_eff->SetTitle("");
  minos_eff->SetStats(0);
  minos_eff->SetFillColor(0);
  minos_eff->SetBit(TH1::kCanRebin);
  minos_eff->GetYaxis()->SetTitle(y_axis_label);
  minos_eff->GetXaxis()->SetLabelSize(x_size_label);
  minos_eff->GetYaxis()->SetLabelSize(y_size_label); //new
  minos_eff->GetXaxis()->SetLabelColor(color_label);
  minos_eff->GetYaxis()->SetLabelColor(color_label);
  minos_eff->SetMinimum(y_min);
  minos_eff->SetMaximum(y_max);
  minos_eff->GetYaxis()->SetTitleColor(y_color_axis);
  minos_eff->GetYaxis()->SetTitleSize(y_text_label_size);
  minos_eff->GetYaxis()->SetTitleOffset(y_title_offset);
  numData=0;
  ifstream in_dat;
  in_dat.open("lt.txt");
  while( in_dat>>year>>month>>day>>pot_recorded>>minos_pot>>pot_delivered>>live_time>>minos_efficiency>>minerva_daq_livetime)
  { 
//    cout<<"numData = "<<numData<<" day="<<day<<" live_time = "<<live_time<<minos_live<<endl;
    in_dat.ignore(100,'\n');
    pot_recorded_tot+=pot_recorded;
    pot_delivered_tot+=pot_delivered;
    minos_live=100*(minos_efficiency/live_time);
    cout<<"minos_live "<<minos_live<<endl;

    if(minos_live>eff_low_cut)
    {
      pot_recorded_minos+=pot_recorded*minos_live*0.01;
      pot_delivered_minos+=pot_delivered;
    } 
    sprintf(dat,"%d/%d",month,day);
    if(numData==0)
    {
      sprintf(char_day,"%d",day);
      std::string dat_begin = month_label[month] + " " + char_day;
    }
    sprintf(blank,"%d/%d",month,day);
    double xday=day;
    int half_day=day/2;
    double day_dif=xday/2.0-half_day;
//    cout<<" day_dif="<<day_dif<<endl;
    if(day_dif<0.1)
    {
//      cout<<" dat="<< dat<<" live_time="<<live_time<<endl;
      mnv_eff->Fill(dat,live_time);
      mnv_daq_eff->Fill(dat,minerva_daq_livetime);
      minos_eff->Fill(dat,live_time*minos_live*0.01);
    }
    else
    {
//      cout<<" blank="<< blank<<" live_time="<<live_time<<endl;
      mnv_eff->Fill(blank,live_time);
      mnv_daq_eff->Fill(blank,minerva_daq_livetime);
      minos_eff->Fill(blank,live_time*minos_live*0.01);
    }
    numData++;
  }
  sprintf(char_day,"%d",day);
  std::string dat_end = month_label[month] + " " + char_day;
  sprintf(char_year,"%d",year);

// minerva daq clock livetime
  mnv_daq_eff->LabelsOption("v");
  mnv_daq_eff->LabelsDeflate();
  mnv_daq_eff->SetMarkerSize(minerva_livetime_size);
  mnv_daq_eff->SetMarkerStyle(minerva_livetime_marker);
  mnv_daq_eff->SetMarkerColor(minerva_livetime_color);
  mnv_daq_eff->DrawCopy("P");
//  mnv_eff->DrawCopy("smaeP");

// minerva livetime
  mnv_eff->LabelsOption("v");
  mnv_eff->LabelsDeflate();
  int marker=29;
  int iColor=4;
  mnv_eff->SetMarkerSize(minerva_eff_size);
  mnv_eff->SetMarkerStyle(minerva_eff_marker);
  mnv_eff->SetMarkerColor(minerva_eff_color);
  mnv_eff->DrawCopy("sameP");


// Put in labels
  double xstep = 0.305;
  double ystep = 0.08;
  double xposit=xlab_start;
  double yposit=ylab_start;
  double xlim[2];
  double ylim[2];
  xlim[0]=0.0;
  xlim[1]=numData;
  ylim[0]=y_min;
  ylim[1]=y_max;
  TLatex *label1 = new TLatex();
  label1->SetTextSize(txtsize);
  label1->SetTextColor(minerva_eff_color);
//  label1->SetFillColor(0);
  double xtxt=start_text(xlim,xposit);
  double ytxt=start_text(ylim,yposit);
  char char_mnv_eff[6];
  sprintf(char_mnv_eff,"%2.1f%%",pot_recorded_tot/pot_delivered_tot*100);
  cout<<char_mnv_eff<<endl;
  std::string txt1 = "MINERvA Live Time = ";
//  std::string txt1 = "MINERvA Live Time  = ";
  txt1 += char_mnv_eff;
  label1->DrawLatex(xtxt,ytxt,txt1.c_str());
  double xsym=start_text(xlim,xposit-0.03);
  double ysym=start_text(ylim,yposit+0.01);
  TMarker *symb = new TMarker(xsym,ysym,marker);
  FormatMarker(symb,minerva_eff_color,minerva_eff_marker,minerva_eff_size);
  symb->Draw();
// end putting in labels
  c2->Update();

//MINOS live time
  minos_eff->LabelsOption("v");
  minos_eff->LabelsDeflate();
  double symSizeDiff=-1.0;
  minos_eff->SetMarkerSize(minos_eff_size);
  minos_eff->SetMarkerStyle(minos_eff_marker);
  minos_eff->SetMarkerColor(minos_eff_color);
  minos_eff->DrawCopy("sameP");
// MINOS Labels
  TLatex *label1 = new TLatex();
  label1->SetTextSize(txtsize);
  label1->SetTextColor(minos_eff_color);
  double ytxt=move_text(ylim,ytxt,ystep);
  char char_minos_eff[5];
  sprintf(char_minos_eff,"%2.1f%%",pot_recorded_minos/pot_delivered_minos*100);
  std::string txt1 = "MINERvA#timesMINOS Live Time = ";
  txt1 += char_minos_eff;
  label1->DrawLatex(xtxt,ytxt,txt1.c_str());
  double ysym=move_text(ylim,ysym,ystep);
  TMarker *symb = new TMarker(xsym,ysym,marker);
  FormatMarker(symb,minos_eff_color,minos_eff_marker,minos_eff_size);
  symb->Draw();

// MINERvA DAQ Livetime Labels
  TLatex *label1 = new TLatex();
  label1->SetTextSize(txtsize);
  label1->SetTextColor(minerva_livetime_color);
  double ytxt=move_text(ylim,ytxt,-2*ystep);
  char char_minerva_daq_eff[5];
  sprintf(char_minerva_daq_eff,"%2.1f%%",avg_daq_livetime);
  std::string txt1 = "MINERvA DAQ Clock Live Time = ";
  txt1 += char_minerva_daq_eff;
  label1->DrawLatex(xtxt,ytxt,txt1.c_str());
  double ysym=move_text(ylim,ysym,-2*ystep);
  TMarker *symb = new TMarker(xsym,ysym,marker);
  FormatMarker(symb,minerva_livetime_color,minerva_livetime_marker,minerva_livetime_size);
  symb->Draw();


  TLegend * leg = new TLegend(0.10,0.12,0.70,0.32);
  leg->AddEntry(mnv_daq_eff,(Form("MINERvA DAQ Clock Live Time = %2.1f%%",avg_daq_livetime)),"f");
  leg->AddEntry(mnv_eff,(Form("MINERvA Live Time = %2.1f%%",pot_recorded_tot/pot_delivered_tot*100)),"P");
  leg->AddEntry(minos_eff,(Form("MINERvA#timesMINOS Live Time = %2.1f%%",pot_recorded_minos/pot_delivered_minos*100)),"P");
//  leg->SetLegendBorderSize(1);
//  leg->SetLegendFillColor(0);
//  leg->SetLegendFont(42);
//  leg->SetLegendTextSize(0.2);
//  leg->Draw();


// Put on Title
  TLatex *label1 = new TLatex();
  label1->SetTextSize(txtsize);
  label1->SetTextColor(text_color);
  double xposit=0.0;;
  double yposit=1.02;
  double xtxt=start_text(xlim,xposit);
  double ytxt=start_text(ylim,yposit);
  char char_pot[5];
  sprintf(char_pot,"%2.2f",pot_delivered_tot/1E+019);
  std::string txt1 = dat_begin + " - " + dat_end + ", "+ char_year + ": POT Delivered = " + char_pot;
  txt1 +="#times10^{19}";
  cout<< txt1<<endl;
  label1->DrawLatex(xtxt,ytxt,txt1.c_str());
//

  cout<<"Start: "<<dat_begin<< ", End:"<<dat_end<<endl;

  c2->Print("plots/live_time.png");
  cout<<" pot ="<<pot_recorded_tot;
  cout<<" pot_delivered ="<<pot_delivered_tot;
  cout<<" live_mnv ="<<pot_recorded_tot/pot_delivered_tot;
  cout<<" live_minos ="<<pot_recorded_minos/pot_delivered_tot<<endl;

  if (copy_fun==1){
     std::system("scp plots/live_time.png mnvonline@minervagpvm02.fnal.gov:/web/sites/minerva.fnal.gov/htdocs/shift/images");
     cout <<"Copied plot"<<endl;
  }
  else
  {
     cout <<"Didn't copy plot"<<endl;
  }

}
double start_text(double* axisLimit,double position)
{
  return axisLimit[0]*(1.0-position)+axisLimit[1]*position;
}
double move_text(double* axisLimit,double start_txt, double step)
{
  return start_txt-(axisLimit[1]-axisLimit[0])*step;
}
void FormatMarker(TMarker* pnt, int icolor,int marker,float symSize)
{
  pnt->SetMarkerSize(symSize);
  pnt->SetMarkerStyle(marker);
  pnt->SetMarkerColor(icolor);
}


