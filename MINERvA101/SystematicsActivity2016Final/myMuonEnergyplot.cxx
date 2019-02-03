{
//=========Macro generated from canvas: cEnergy/Emu
//=========  (Mon Jun 20 14:32:05 2016) by ROOT version5.34/05
   TCanvas *cEnergy = new TCanvas("cEnergy", "Emu",0,0,900,750);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cEnergy->SetHighLightColor(2);
   cEnergy->Range(-3214.286,-87.92764,18214.29,498.2566);
   cEnergy->SetFillColor(0);
   cEnergy->SetBorderMode(0);
   cEnergy->SetBorderSize(2);
   cEnergy->SetLeftMargin(0.15);
   cEnergy->SetRightMargin(0.15);
   cEnergy->SetBottomMargin(0.15);
   cEnergy->SetFrameLineWidth(2);
   cEnergy->SetFrameBorderMode(0);
   cEnergy->SetFrameLineWidth(2);
   cEnergy->SetFrameBorderMode(0);
   
   TH1D *tmpMC__1 = new TH1D("tmpMC__1","Muon Energy (MC) ",30,0,15000);
   tmpMC__1->SetBinContent(3,18.09518);
   tmpMC__1->SetBinContent(4,72.3713);
   tmpMC__1->SetBinContent(5,127.9094);
   tmpMC__1->SetBinContent(6,174.768);
   tmpMC__1->SetBinContent(7,218.6779);
   tmpMC__1->SetBinContent(8,235.5905);
   tmpMC__1->SetBinContent(9,257.4974);
   tmpMC__1->SetBinContent(10,242.5734);
   tmpMC__1->SetBinContent(11,230.1433);
   tmpMC__1->SetBinContent(12,208.3722);
   tmpMC__1->SetBinContent(13,166.7678);
   tmpMC__1->SetBinContent(14,124.6925);
   tmpMC__1->SetBinContent(15,92.58269);
   tmpMC__1->SetBinContent(16,76.06952);
   tmpMC__1->SetBinContent(17,56.45306);
   tmpMC__1->SetBinContent(18,46.43009);
   tmpMC__1->SetBinContent(19,32.71604);
   tmpMC__1->SetBinContent(20,24.6045);
   tmpMC__1->SetBinContent(21,25.25854);
   tmpMC__1->SetBinContent(22,21.22327);
   tmpMC__1->SetBinContent(23,19.98255);
   tmpMC__1->SetBinContent(24,17.33356);
   tmpMC__1->SetBinContent(25,20.07634);
   tmpMC__1->SetBinContent(26,15.46307);
   tmpMC__1->SetBinContent(27,14.31198);
   tmpMC__1->SetBinContent(28,11.33802);
   tmpMC__1->SetBinContent(29,13.29606);
   tmpMC__1->SetBinContent(30,8.070824);
   tmpMC__1->SetBinContent(31,204.5214);
   tmpMC__1->SetBinError(31,9.479102);
   tmpMC__1->SetMinimum(0);
   tmpMC__1->SetMaximum(445.5);
   tmpMC__1->SetEntries(9238);
   tmpMC__1->SetDirectory(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffcccc");
   tmpMC__1->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   tmpMC__1->SetLineColor(ci);
   tmpMC__1->SetMarkerStyle(0);
   tmpMC__1->GetXaxis()->SetTitle(" Muon Energy (MeV)");
   tmpMC__1->GetXaxis()->CenterTitle(true);
   tmpMC__1->GetXaxis()->SetLabelFont(42);
   tmpMC__1->GetXaxis()->SetLabelSize(0.05);
   tmpMC__1->GetXaxis()->SetTitleSize(0.05);
   tmpMC__1->GetXaxis()->SetTitleOffset(1.15);
   tmpMC__1->GetYaxis()->SetTitle(" Events");
   tmpMC__1->GetYaxis()->SetLabelFont(42);
   tmpMC__1->GetYaxis()->SetLabelSize(0.05);
   tmpMC__1->GetYaxis()->SetTitleSize(0.05);
   tmpMC__1->GetYaxis()->SetTitleOffset(1.15);
   tmpMC__1->GetZaxis()->SetLabelFont(42);
   tmpMC__1->GetZaxis()->SetLabelSize(0.035);
   tmpMC__1->GetZaxis()->SetTitleSize(0.035);
   tmpMC__1->GetZaxis()->SetTitleFont(42);
   tmpMC__1->Draw("E2");
   
   TH1D *tmpMC__2 = new TH1D("tmpMC__2","Muon Energy (MC) ",30,0,15000);
   tmpMC__2->SetBinContent(3,18.09518);
   tmpMC__2->SetBinContent(4,72.3713);
   tmpMC__2->SetBinContent(5,127.9094);
   tmpMC__2->SetBinContent(6,174.768);
   tmpMC__2->SetBinContent(7,218.6779);
   tmpMC__2->SetBinContent(8,235.5905);
   tmpMC__2->SetBinContent(9,257.4974);
   tmpMC__2->SetBinContent(10,242.5734);
   tmpMC__2->SetBinContent(11,230.1433);
   tmpMC__2->SetBinContent(12,208.3722);
   tmpMC__2->SetBinContent(13,166.7678);
   tmpMC__2->SetBinContent(14,124.6925);
   tmpMC__2->SetBinContent(15,92.58269);
   tmpMC__2->SetBinContent(16,76.06952);
   tmpMC__2->SetBinContent(17,56.45306);
   tmpMC__2->SetBinContent(18,46.43009);
   tmpMC__2->SetBinContent(19,32.71604);
   tmpMC__2->SetBinContent(20,24.6045);
   tmpMC__2->SetBinContent(21,25.25854);
   tmpMC__2->SetBinContent(22,21.22327);
   tmpMC__2->SetBinContent(23,19.98255);
   tmpMC__2->SetBinContent(24,17.33356);
   tmpMC__2->SetBinContent(25,20.07634);
   tmpMC__2->SetBinContent(26,15.46307);
   tmpMC__2->SetBinContent(27,14.31198);
   tmpMC__2->SetBinContent(28,11.33802);
   tmpMC__2->SetBinContent(29,13.29606);
   tmpMC__2->SetBinContent(30,8.070824);
   tmpMC__2->SetBinContent(31,204.5214);
   tmpMC__2->SetBinError(31,9.479102);
   tmpMC__2->SetMinimum(0);
   tmpMC__2->SetMaximum(445.5);
   tmpMC__2->SetEntries(9238);
   tmpMC__2->SetDirectory(0);
   tmpMC__2->SetLineColor(2);
   tmpMC__2->SetLineWidth(3);
   tmpMC__2->SetMarkerStyle(0);
   tmpMC__2->GetXaxis()->SetTitle(" Muon Energy (MeV)");
   tmpMC__2->GetXaxis()->CenterTitle(true);
   tmpMC__2->GetXaxis()->SetLabelFont(42);
   tmpMC__2->GetXaxis()->SetLabelSize(0.05);
   tmpMC__2->GetXaxis()->SetTitleSize(0.05);
   tmpMC__2->GetXaxis()->SetTitleOffset(1.15);
   tmpMC__2->GetYaxis()->SetTitle(" Events");
   tmpMC__2->GetYaxis()->SetLabelFont(42);
   tmpMC__2->GetYaxis()->SetLabelSize(0.05);
   tmpMC__2->GetYaxis()->SetTitleSize(0.05);
   tmpMC__2->GetYaxis()->SetTitleOffset(1.15);
   tmpMC__2->GetZaxis()->SetLabelFont(42);
   tmpMC__2->GetZaxis()->SetLabelSize(0.035);
   tmpMC__2->GetZaxis()->SetTitleSize(0.035);
   tmpMC__2->GetZaxis()->SetTitleFont(42);
   tmpMC__2->Draw("SAME HIST");
   
   TH1D *tmp_data__3 = new TH1D("tmp_data__3","Muon Energy (data)",30,0,15000);
   tmp_data__3->SetBinContent(3,28);
   tmp_data__3->SetBinContent(4,82);
   tmp_data__3->SetBinContent(5,153);
   tmp_data__3->SetBinContent(6,213);
   tmp_data__3->SetBinContent(7,270);
   tmp_data__3->SetBinContent(8,257);
   tmp_data__3->SetBinContent(9,297);
   tmp_data__3->SetBinContent(10,265);
   tmp_data__3->SetBinContent(11,243);
   tmp_data__3->SetBinContent(12,205);
   tmp_data__3->SetBinContent(13,153);
   tmp_data__3->SetBinContent(14,116);
   tmp_data__3->SetBinContent(15,95);
   tmp_data__3->SetBinContent(16,88);
   tmp_data__3->SetBinContent(17,56);
   tmp_data__3->SetBinContent(18,48);
   tmp_data__3->SetBinContent(19,33);
   tmp_data__3->SetBinContent(20,32);
   tmp_data__3->SetBinContent(21,31);
   tmp_data__3->SetBinContent(22,27);
   tmp_data__3->SetBinContent(23,18);
   tmp_data__3->SetBinContent(24,17);
   tmp_data__3->SetBinContent(25,17);
   tmp_data__3->SetBinContent(26,16);
   tmp_data__3->SetBinContent(27,14);
   tmp_data__3->SetBinContent(28,11);
   tmp_data__3->SetBinContent(29,15);
   tmp_data__3->SetBinContent(30,8);
   tmp_data__3->SetBinContent(31,210);
   tmp_data__3->SetBinError(3,5.291503);
   tmp_data__3->SetBinError(4,9.055385);
   tmp_data__3->SetBinError(5,12.36932);
   tmp_data__3->SetBinError(6,14.59452);
   tmp_data__3->SetBinError(7,16.43168);
   tmp_data__3->SetBinError(8,16.03122);
   tmp_data__3->SetBinError(9,17.23369);
   tmp_data__3->SetBinError(10,16.27882);
   tmp_data__3->SetBinError(11,15.58846);
   tmp_data__3->SetBinError(12,14.31782);
   tmp_data__3->SetBinError(13,12.36932);
   tmp_data__3->SetBinError(14,10.77033);
   tmp_data__3->SetBinError(15,9.746794);
   tmp_data__3->SetBinError(16,9.380832);
   tmp_data__3->SetBinError(17,7.483315);
   tmp_data__3->SetBinError(18,6.928203);
   tmp_data__3->SetBinError(19,5.744563);
   tmp_data__3->SetBinError(20,5.656854);
   tmp_data__3->SetBinError(21,5.567764);
   tmp_data__3->SetBinError(22,5.196152);
   tmp_data__3->SetBinError(23,4.242641);
   tmp_data__3->SetBinError(24,4.123106);
   tmp_data__3->SetBinError(25,4.123106);
   tmp_data__3->SetBinError(26,4);
   tmp_data__3->SetBinError(27,3.741657);
   tmp_data__3->SetBinError(28,3.316625);
   tmp_data__3->SetBinError(29,3.872983);
   tmp_data__3->SetBinError(30,2.828427);
   tmp_data__3->SetBinError(31,14.49138);
   tmp_data__3->SetEntries(3018);
   tmp_data__3->SetDirectory(0);
   tmp_data__3->SetMarkerStyle(20);
   tmp_data__3->GetXaxis()->SetTitle(" Muon Energy (MeV)");
   tmp_data__3->GetXaxis()->SetLabelFont(42);
   tmp_data__3->GetXaxis()->SetLabelSize(0.035);
   tmp_data__3->GetXaxis()->SetTitleSize(0.035);
   tmp_data__3->GetXaxis()->SetTitleFont(42);
   tmp_data__3->GetYaxis()->SetTitle(" Events");
   tmp_data__3->GetYaxis()->SetLabelFont(42);
   tmp_data__3->GetYaxis()->SetLabelSize(0.035);
   tmp_data__3->GetYaxis()->SetTitleSize(0.035);
   tmp_data__3->GetYaxis()->SetTitleFont(42);
   tmp_data__3->GetZaxis()->SetLabelFont(42);
   tmp_data__3->GetZaxis()->SetLabelSize(0.035);
   tmp_data__3->GetZaxis()->SetTitleSize(0.035);
   tmp_data__3->GetZaxis()->SetTitleFont(42);
   tmp_data__3->Draw("SAME E1 X0");
   
   TLegend *leg = new TLegend(0.18,0.794,0.528,0.89,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("tmp_data","Muon Energy (data)","lep");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("tmpMC","Muon Energy (MC) ","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   
   TH1D *tmpMC__4 = new TH1D("tmpMC__4","Muon Energy (MC) ",30,0,15000);
   tmpMC__4->SetBinContent(3,18.09518);
   tmpMC__4->SetBinContent(4,72.3713);
   tmpMC__4->SetBinContent(5,127.9094);
   tmpMC__4->SetBinContent(6,174.768);
   tmpMC__4->SetBinContent(7,218.6779);
   tmpMC__4->SetBinContent(8,235.5905);
   tmpMC__4->SetBinContent(9,257.4974);
   tmpMC__4->SetBinContent(10,242.5734);
   tmpMC__4->SetBinContent(11,230.1433);
   tmpMC__4->SetBinContent(12,208.3722);
   tmpMC__4->SetBinContent(13,166.7678);
   tmpMC__4->SetBinContent(14,124.6925);
   tmpMC__4->SetBinContent(15,92.58269);
   tmpMC__4->SetBinContent(16,76.06952);
   tmpMC__4->SetBinContent(17,56.45306);
   tmpMC__4->SetBinContent(18,46.43009);
   tmpMC__4->SetBinContent(19,32.71604);
   tmpMC__4->SetBinContent(20,24.6045);
   tmpMC__4->SetBinContent(21,25.25854);
   tmpMC__4->SetBinContent(22,21.22327);
   tmpMC__4->SetBinContent(23,19.98255);
   tmpMC__4->SetBinContent(24,17.33356);
   tmpMC__4->SetBinContent(25,20.07634);
   tmpMC__4->SetBinContent(26,15.46307);
   tmpMC__4->SetBinContent(27,14.31198);
   tmpMC__4->SetBinContent(28,11.33802);
   tmpMC__4->SetBinContent(29,13.29606);
   tmpMC__4->SetBinContent(30,8.070824);
   tmpMC__4->SetBinContent(31,204.5214);
   tmpMC__4->SetBinError(31,9.479102);
   tmpMC__4->SetMinimum(0);
   tmpMC__4->SetMaximum(445.5);
   tmpMC__4->SetEntries(9238);
   tmpMC__4->SetDirectory(0);

   ci = TColor::GetColor("#ffcccc");
   tmpMC__4->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   tmpMC__4->SetLineColor(ci);
   tmpMC__4->SetMarkerStyle(0);
   tmpMC__4->GetXaxis()->SetTitle(" Muon Energy (MeV)");
   tmpMC__4->GetXaxis()->CenterTitle(true);
   tmpMC__4->GetXaxis()->SetLabelFont(42);
   tmpMC__4->GetXaxis()->SetLabelSize(0.05);
   tmpMC__4->GetXaxis()->SetTitleSize(0.05);
   tmpMC__4->GetXaxis()->SetTitleOffset(1.15);
   tmpMC__4->GetYaxis()->SetTitle(" Events");
   tmpMC__4->GetYaxis()->SetLabelFont(42);
   tmpMC__4->GetYaxis()->SetLabelSize(0.05);
   tmpMC__4->GetYaxis()->SetTitleSize(0.05);
   tmpMC__4->GetYaxis()->SetTitleOffset(1.15);
   tmpMC__4->GetZaxis()->SetLabelFont(42);
   tmpMC__4->GetZaxis()->SetLabelSize(0.035);
   tmpMC__4->GetZaxis()->SetTitleSize(0.035);
   tmpMC__4->GetZaxis()->SetTitleFont(42);
   tmpMC__4->Draw("sameaxis");
   cEnergy->Modified();
   cEnergy->cd();
   cEnergy->SetSelected(cEnergy);
}
