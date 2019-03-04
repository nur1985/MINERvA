void GetPOT(char *filename){

  /* Opening the file */
  char path[200];
  sprintf(path,"%s",filename);
  TFile *f = new TFile(path);
  cout <<path<<endl;

  /* Loading the tree */
  TTree *t = (TTree*)f->Get("Meta");
  
  double POT_Used, POT_Total, efficiency;

  /* linking with tree */
  t->SetBranchAddress("POT_Used",&POT_Used);  
  t->SetBranchAddress("POT_Total",&POT_Total);  
  
  /* Declaring the variables */
  double sumPOTUsedAll,sumPOTTotalAll,efficiency = 0.0;

  int n_entries = t->GetEntries();
  
  for (int i=0; i < n_entries; i++){
    t->GetEntry(i);
    TLeaf *POT_UsedAll = t->GetLeaf("POT_Used");
    TLeaf *POT_TotalAll = t->GetLeaf("POT_Total");
    
    sumPOTUsedAll = sumPOTUsedAll + POT_UsedAll->GetValue();
    sumPOTTotalAll = sumPOTTotalAll + POT_TotalAll->GetValue();    
  }
  efficiency = sumPOTUsedAll/sumPOTTotalAll;

  cout <<"POT Used"<<"\t"<<"POT Total"<<"\t"<<"Efficiency"<<endl;
  cout <<sumPOTUsedAll<<"\t"<<sumPOTTotalAll<<"\t"<<efficiency<<endl;
//  cout <<std::setprecision(4)<<sumPOTUsedAll<<"\t"<<std::setprecision(4)<<sumPOTTotalAll<<"\t"<<std::setprecision(4)<<efficiency<<endl;

}
