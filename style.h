// ROOT plot style sheet

#include "TF1.h"
#include "TH1.h"
#include "TH1D.h"
#include "TCutG.h"
#include "TNamed.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include <iostream>
using namespace std;

namespace style
{
   void v(int verbose = 1);

   TCanvas *c    (TString name="",double w=0,double h=0);
   TCanvas *cc   (TString name="",double w=0,double h=0);
   TCanvas *cc2  (TString name="",double w=0,double h=0);
   TCanvas *cc3  (TString name="",double w=0,double h=0);

   TObject *make (TObject *o);
    TGraph *make (TGraph  *graph);
       TH1 *make (TH1     *h);
       TF1 *make (TF1     *f);
   TLegend *make (TLegend *legend);
   TCanvas *make (TCanvas *cvs);
     TCutG *cutg (TString f, TString c, TString x, TString y);
     TCutG *cutg (TFile  *f, TString c, TString x, TString y);

       TH1 *free (TH1     *h);
       TH1 *fm   (TH1 *h);

      void save  (TCanvas *cvs, TString format="png");

      void gstat (int opt);
      void fstat (int opt);
      void zcolor(int opt);

       TF1 *fitg (TH1 *h, Double_t c=1.5, Option_t *opt="RQ0");
       TF1 *fitgg(TH1 *h, Double_t c=1.5, Option_t *opt="RQ0");

       TH1 *tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1);

  Double_t max(TH1 *h);

  /********************************************************/

  void init();

     int fVerbose = 1;

     int fICvs=0;
     int fWCvs=680;
     int fHCvs=550;
     int fWCvs2=900;
     int fHCvs2=550;
     int fWCvs3=1200;
     int fHCvs3=800;
     int fYCvs=0;

  double fWDefault=0.1;
  double fWUnit=0.012;
  double fHUnit=0.05;

  double fWStat=0.25;
  double fHStat=0.18;
  double fXStat=0.95;
  double fYStat=0.88;

  double fTMargin=0.12;
  double fBMargin=0.15;
  double fLMargin=0.17;
  double fRMargin=0.055;
  double fRMarginH1=0.055;
  double fRMarginH2=0.155;

  double fMainTitleSize=0.08;
  double fAxisLabelSize=0.05;
  double fAxisTitleSize=0.06;

  double fXTitleOffset=1.15;
  double fYTitleOffset=1.35;
}; 

void style::v(int verbose = 1) { fVerbose = verbose; }

void style::gstat(int opt) {
  gStyle->SetOptStat(opt);
}

void style::fstat(int opt) {
  gStyle->SetOptFit(opt);
}

void style::zcolor(int opt) {
  if (opt == 0)
    gStyle -> SetPalette(kBird);
  else if (opt == 1)
    gStyle -> SetPalette(kRainBow);
  else if (opt == 2)
    gStyle -> SetPalette(kDeepSea);
  else if (opt == 3)
    gStyle -> SetPalette(kAvocado);
  else if (opt == 4)
    gStyle -> SetPalette(kBlueGreenYellow);
  else if (opt == 5)
    gStyle -> SetPalette(kBrownCyan);
  else
    gStyle -> SetPalette(kGreyScale);
}

Double_t style::max(TH1 *h) {
  auto bin = h -> GetMaximumBin();
  return h -> GetBinContent(bin);
}

void style::init() {
  fXStat=1.-fRMargin;
  fYStat=1.-fTMargin;
  gStyle->SetStatStyle(0);
  gStyle->SetStatW(fWStat);
  gStyle->SetStatH(fHStat);
  gStyle->SetStatX(fXStat);
  gStyle->SetStatY(fYStat);
  gStyle->SetTitleFontSize(fMainTitleSize);
}

TCanvas *style::c(TString name,double w,double h) {
  fRMargin=fRMarginH1;
  init();
  if(w==0) w=fWCvs;
  if(h==0) h=fHCvs;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs);
  return cvs;
}

TCanvas *style::cc2(TString name,double w,double h) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWCvs2;
  if(h==0) h=fHCvs2;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs);
  return cvs;
}

TCanvas *style::cc3(TString name,double w,double h) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWCvs3;
  if(h==0) h=fHCvs3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs);
  return cvs;
}

TCanvas *style::cc(TString name,double w,double h) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWCvs;
  if(h==0) h=fHCvs;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs);
  return cvs;
}

TObject *style::make(TObject *o) {
  if (o->InheritsFrom("TGraph"))  make((TGraph*)o);
  if (o->InheritsFrom("TH1"))     make((TH1*)o);
  if (o->InheritsFrom("TF1"))     make((TF1*)o);
  if (o->InheritsFrom("TLegend")) make((TLegend*)o);
  if (o->InheritsFrom("TCanvas")) make((TCanvas*)o);
  return o;
}

TCanvas *style::make(TCanvas *cvs) {
  cvs->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);
  ++fICvs;
  return cvs;
}

TGraph *style::make(TGraph *graph) {
  init();
  if(graph->GetMarkerStyle()==1)
    graph->SetMarkerStyle(20);
  make(graph->GetHistogram());
  return graph;
}

TH1 *style::make(TH1 *h) {
  init();
  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(fXTitleOffset);
  h->GetXaxis()->SetTitleSize(fAxisTitleSize);
  h->GetXaxis()->SetLabelSize(fAxisLabelSize);
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(fYTitleOffset);
  h->GetYaxis()->SetTitleSize(fAxisTitleSize);
  h->GetYaxis()->SetLabelSize(fAxisLabelSize);
  h->GetZaxis()->SetLabelSize(fAxisLabelSize);
  return h;
}

TLegend *style::make(TLegend *legend) {
  init();
  auto y2=1.-fTMargin;
  if(gStyle->GetOptStat() != 0) y2=gStyle->GetStatY()-gStyle->GetStatH();
  auto lmax=0;
  TIter next(legend->GetListOfPrimitives());
  TLegendEntry *label;
  while ((label=(TLegendEntry *) next())) {
    auto l=TString(label->GetLabel()).Length();
    if(lmax<l) lmax=l;
  }
  
  auto y1=y2-legend->GetNRows()*fHUnit;
  auto x2=1.-fRMargin;
  auto x1=x2-lmax*fWUnit - fWDefault;
  if(x1>x2-fWStat) x1=x2-fWStat;
  legend->SetX1(x1);
  legend->SetX2(x2);
  legend->SetY1(y1);
  legend->SetY2(y2);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  return legend;
}

TF1 *style::make(TF1 *f) {
  f -> SetNpx(1000);
  return f;
}

TH1 *style::free(TH1 *h) {
  h -> GetXaxis() -> SetNdivisions(508);
  h -> GetYaxis() -> SetNdivisions(508);
  return h;
}

TH1 *style::fm(TH1 *h) { return free(make(h)); }

void style::save(TCanvas *cvs,TString format) {
  TString path=TString(gSystem->Getenv("PWD"))+"/figures/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString head=cvs->GetName();
  TString name=head+"."+format;
  int version=0;
  while (1) {
    char* c=gSystem->Which(path.Data(),name.Data());
    if(TString(c).IsNull()) {
      cvs->SaveAs(path+name);
      break;
    }
    name=head+"."+TString::Itoa(++version,36)+"."+format;
  } 
}

TF1 *style::fitg(TH1 *h,Double_t c,Option_t *opt) {
  auto binmax=h->GetMaximumBin();
  auto max=h->GetBinContent(binmax);
  auto xmax=h->GetXaxis()->GetBinCenter(binmax);
  auto xerr=h->GetStdDev();
  auto f=new TF1("f1","gaus(0)",xmax-xerr*c,xmax+xerr*c);
  f->SetParameters(max,xmax,xerr);
  h->Fit(f,opt);
  return f;
}

TF1 *style::fitgg(TH1 *h,Double_t c,Option_t *opt) {
  auto binmax=h->GetMaximumBin();
  auto max=h->GetBinContent(binmax);
  auto xmax=h->GetXaxis()->GetBinCenter(binmax);
  auto xerr=h->GetStdDev();

  auto f=new TF1("f1","gaus(0)+gaus(3)",xmax-xerr*c,xmax+xerr*c);
  f->SetParameters(0.8*max,xmax,0.5*xerr,0.2*max,xmax,1.5*xerr);
  h->Fit(f,opt);
  return f;
}

TH1 *style::tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,Double_t x1,Double_t x2,int ny,Double_t y1,Double_t y2) {
  if(fVerbose>0)cout<<name<<": "<<tree -> GetName()<<"->[formula:"<<formula<<"],[cut:"<<TString(cut)<<"]->";
  TH1 *h;
  if(ny<0) h=new TH1D(name,title,nx,x1,x2);
  else     h=new TH2D(name,title,nx,x1,x2,ny,y1,y2);
  auto n=tree->Project(name,formula,cut);
  if(fVerbose>0)cout<<n<<endl;
  return fm(h);
};

TCutG *style::cutg(TString f, TString c, TString x, TString y) {
  auto file = new TFile(f.Data(),"read");
  auto cg = (TCutG *) file -> Get(c.Data());
  cg -> SetVarX(x.Data());
  cg -> SetVarY(y.Data());
  return cg;
}

TCutG *cutg(TFile  *file, TString c, TString x, TString y) {
  auto cg = (TCutG *) file -> Get(c.Data());
  cg -> SetVarX(x.Data());
  cg -> SetVarY(y.Data());
  return cg;
}
