/* ROOT plot style sheet
 *
 * - HOW TO USE

#include "style.h"
using namespace style;

*/

#include "TF1.h"
#include "TH1.h"
#include "TH1D.h"
#include "TCutG.h"
#include "TMath.h"
#include "TNamed.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TObjArray.h"
#include "TObjString.h"
#include <vector>
#include <iostream>
using namespace std;

namespace style
{
   void v(int verbose=1); ///< verbosity - 0:silent, 1:default

   TCanvas *c    (TString name="",double w=0,double h=0); ///<  680 x 550 - 1D style
   TCanvas *cc   (TString name="",double w=0,double h=0); ///<  680 x 550 - 2D style
   TCanvas *cc2  (TString name="",double w=0,double h=0); ///<  900 x 550 - 2D style
   TCanvas *cc3  (TString name="",double w=0,double h=0); ///< 1200 x 800 - 2D style

   TObject *make (TObject *o);      ///< make object stylish! - graph, histogram, function, legend, canvas
    TGraph *make (TGraph  *graph);
       TH1 *make (TH1     *h);
       TF1 *make (TF1     *f);
   TLegend *make (TLegend *legend);
   TCanvas *make (TCanvas *cvs);
     TCutG *cutg (TString f, TString c, TString x, TString y); ///< set TCutG from file name
     TCutG *cutg (TFile  *f, TString c, TString x, TString y); ///< set TCutG from file

       TH1 *free (TH1 *h); // make axis labels feel free!

       TH1 *dndx(TH1 *h);
       TH1 *norm_max(TH1 *h, Double_t maxto = 1);
       TH1 *norm_integral(TH1 *h, Double_t normto = 1);

      void fsave (bool val);
      void save  (TCanvas *cvs, TString format="png"); ///< save cavans ./figures/[canvas name].[version-automatically updated].[format]

      void gstat (int opt); ///< equalivant to gStyle->SetOptStat(opt);
      void fstat (int opt); ///< equalivant to gStyle->SetOptFit(opt);
      void zcolor(int opt); ///< set z-palette color to 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale

      void colorwheel();

       TF1 *sumf(vector<TF1*> &fs);

       TF1 *fitg (TH1 *h, Double_t c=1.5, Option_t *opt="RQ0"); ///< fast single gaussian fit of histogram in range of -c*sigma ~ +c*sigma
       TF1 *fitgg(TH1 *h, Double_t c=1.5, Option_t *opt="RQ0"); ///< fast double gaussian fit of histogram in range of -c*sigma ~ +c*sigma
       TF1 *gg(TF1 *f1, Int_t i); // get i'th gaussian from multipule gaussian function f1

       TH1D *cutx(TH1 *hist, Int_t bin1, Int_t bin2);
       TH1D *cutx(TH1 *hist, Int_t bin1, Int_t bin2, TGraph *cut_area);
       TGraphErrors *fitgsx(TH1* hist, Int_t nDivision=20, Double_t c=1.5);
       TGraphErrors *fitgsy(TH1* hist, Int_t nDivision=20, Double_t c=1.5);

       TH1 *tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1); ///< draw from tree
       TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1); ///< draw from tree

  Double_t max (TH1 *h);                             ///< maximum value of histogram
  Double_t max (TH1 *h, Double_t &bin, Double_t &x); ///< maximum value of histogram
  Double_t fwrm(TF1 *f, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q);
  Double_t fwhm(TF1 *f, Double_t &x0, Double_t &x1, Double_t &q);
  Double_t fwhm(TF1 *f);

  Double_t fwrm(TH1 *h, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q); ///< Full Width at ratio of maximum
  Double_t fwhm(TH1 *h, Double_t &x0, Double_t &x1, Double_t &q); ///< Full Width Half Maximum
  Double_t fwhm(TH1 *h);                                          ///< Full Width Half Maximum

  void pfname(TString str, TString &pathname, TString &filename, TString delim="/");
  TString firstname(TString str, TString delim=".");
  TString lastname(TString str, TString delim="/");
  TString justname(TString str);

  /********************************************************/

  void init();

    bool fSave=true;
     int fVerbose=1;

     int fICvs=0;
     int fWCvs=680;
     int fHCvs=550;
     int fWCvs2=900;
     int fHCvs2=550;
     int fWCvs3=1200;
     int fHCvs3=800;
     int fYCvs=0;

  double fWDefault=0.1;
  double fWUnit=0.008;
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

void style::v(int verbose=1) { fVerbose=verbose; }

void style::gstat(int opt) {
  gStyle->SetOptStat(opt);
}

void style::fstat(int opt) {
  gStyle->SetOptFit(opt);
}

void style::zcolor(int opt) {
  if(fVerbose>0) cout << "zcolor(" << opt << ") >> 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale" << endl;
       if(opt == 0) gStyle->SetPalette(kBird);
  else if(opt == 1) gStyle->SetPalette(kRainBow);
  else if(opt == 2) gStyle->SetPalette(kDeepSea);
  else if(opt == 3) gStyle->SetPalette(kAvocado);
  else if(opt == 4) gStyle->SetPalette(kBlueGreenYellow);
  else if(opt == 5) gStyle->SetPalette(kBrownCyan);
  else               gStyle->SetPalette(kGreyScale);
}

void style::colorwheel() {
  TColorWheel *w=new TColorWheel();
  w->SetCanvas(c("cw",800,800));
  w->Draw();
}

Double_t style::max(TH1 *h) {
  Double_t bin, x;
  return max(h, bin, x);
}

Double_t style::max (TH1 *h, Double_t &bin, Double_t &x) {
  bin=h->GetMaximumBin();
  x=h->GetXaxis()->GetBinCenter(bin);
  return h->GetBinContent(bin);
}

Double_t style::fwrm(TF1 *f, Double_t ratio, Double_t nx, Double_t &x0, Double_t &x1, Double_t &q)
{
  Double_t x, xl, xh;
  f->GetRange(xl, xh);
  auto dx=(xh-xl)/nx;

  auto valmax=-DBL_MAX;
  auto xmax=xl;

  for (x=xl;x<=xh;x+=dx) {
    auto y=f->Eval(x);
    if(valmax < y) {
      valmax=y;
      xmax=x;
      if(fVerbose>0) cout<<"(valmax,xmax)=("<<valmax<<","<<xmax<<")"<<endl;
    }
  }
  auto rmax=ratio*valmax;

  double dy1=DBL_MAX, dy0=DBL_MAX;

  if(fVerbose>0) cout<<"=================================="<<endl;
  for (x=xmax;x<=xh;x+=dx) {
    auto y=f->Eval(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy1) {
      x1=x-dx;
      if(fVerbose>0) cout<<"x1="<<x1<<endl;
      break;
    }
    dy1=dy;
  }
  if(x==xh) {
    if(fVerbose>0) cout<<"x==xh ROOT NOT FOUND"<<endl;
    q=-1; x0=-1; x1=-1; return -1;
  }
  if(fVerbose>0) cout<<"=================================="<<endl;

  for (x=xmax;x>=xl;x-=dx) {
    auto y=f->Eval(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy0) {
      x0=dx;
      if(fVerbose>0) cout<<"x0="<<x1<<endl;
      break;
    }
    dy0=dy;
  }
  if(x==xl) {
    if(fVerbose>0) cout<<"x==xl ROOT NOT FOUND"<<endl;
    q=-1; x0=-1; x1=-1; return -1;
  }
  if(fVerbose>0) cout<<"=================================="<<endl;

  q=TMath::Sqrt(dy0*dy0 + dy1*dy1);

  return x1-x0;
}

Double_t style::fwhm(TF1 *f, Double_t &x0, Double_t &x1, Double_t &q)
{
  return fwrm(f, 0.5, 10000, x0, x1, q);
}

Double_t style::fwhm(TF1 *f)
{
  Double_t x0, x1 ,q;
  return fwhm(f, x0, x1, q);
}

Double_t style::fwrm(TH1 *h, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q)
{
  if(fVerbose>0) cout<<"assuming histogram "<<h->GetName()<<" is smooth"<<endl;

  auto hist=(TH1D *) h;
  Double_t binmax, xmax;
  auto valmax=max(hist,binmax,xmax);
  auto rmax=ratio*valmax;

  auto n=hist->GetNbinsX();
  auto xl=hist->GetXaxis()->GetBinLowEdge(1);
  auto xh=hist->GetXaxis()->GetBinUpEdge(n);
  auto nn=ndx*(xh-xl)/n;
  if(fVerbose>0) {
    cout<<"binmax = "<<binmax<<endl;
    cout<<"xmax = "<<xmax<<endl;
    cout<<"n  = "<<n<<endl;
    cout<<"xl = "<<xl<<endl;
    cout<<"xh = "<<xh<<endl;
    cout<<"nn = "<<nn<<endl;
  }

  double x, dy1=DBL_MAX, dy0=DBL_MAX;
  for (x=xmax;x<=xh;x+=nn) {
    if(fVerbose>0) cout << x << endl;
    auto y=hist->Interpolate(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy1) {
      x1=x-nn;
      if(fVerbose>0) cout<<"x1="<<x1<<endl;
      break;
    }
    dy1=dy;
  }
  if(x==xh) {
    q=-1; x0=-1; x1=-1; return -1;
    if(fVerbose>0) cout<<"x==xh ROOT NOT FOUND"<<endl;
  }
  if(fVerbose>0) cout<<"=================================="<<endl;

  for (x=xmax;x>=xl;x-=nn) {
    auto y=hist->Interpolate(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy0) {
      x0=x+nn;
      if(fVerbose>0) cout<<"x0="<<x1<<endl;
      break;
    }
    dy0=dy;
  }
  if(x==xl) {
    q=-1; x0=-1; x1=-1; return -1;
    if(fVerbose>0) cout<<"x==xh ROOT NOT FOUND"<<endl;
  }
  if(fVerbose>0) cout<<"=================================="<<endl;

  q=TMath::Sqrt(dy0*dy0 + dy1*dy1);

  return x1-x0;
}

Double_t style::fwhm(TH1 *h, Double_t &x0, Double_t &x1, Double_t &q)
{
  return fwrm(h, 0.5, 0.1, x0, x1, q);
}

Double_t style::fwhm(TH1 *h)
{
  Double_t x0, x1 ,q;
  return fwhm(h, x0, x1, q);
}

void style::init() {
  fXStat=1.-fRMargin;
  fYStat=1.-fTMargin;
  //gStyle->SetStatStyle(0);
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
  if(o->InheritsFrom("TGraph"))  make((TGraph*)o);
  if(o->InheritsFrom("TH1"))     make((TH1*)o);
  if(o->InheritsFrom("TF1"))     make((TF1*)o);
  if(o->InheritsFrom("TLegend")) make((TLegend*)o);
  if(o->InheritsFrom("TCanvas")) make((TCanvas*)o);
  return o;
}

TCanvas *style::make(TCanvas *cvs) {
  cvs->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);
  ++fICvs;
  return cvs;
}

TGraph *style::make(TGraph *graph) {
  init();
  if(graph->GetMarkerStyle()==1) {
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.5);
  }
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
  free(h);
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
  if(y2<0.2)
    y2=0.2;
  legend->SetY2(y2);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  return legend;
}

TF1 *style::make(TF1 *f) {
  f->SetNpx(1000);
  return f;
}

TH1 *style::free(TH1 *h) {
  h->GetXaxis()->SetNdivisions(508);
  h->GetYaxis()->SetNdivisions(508);
  return h;
}

TH1 *style::dndx(TH1 *h)
{
  auto hist = (TH1 *) h -> Clone();
  auto nbins = hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin) {
    auto x1=hist->GetXaxis()->GetBinLowEdge(bin);
    auto x2=hist->GetXaxis()->GetBinUpEdge(bin);
    auto dx=x2-x1;
    hist -> SetBinContent(bin,hist->GetBinContent(bin)/dx);
  }
  hist -> SetTitle(Form(";%s;dN/dx",h->GetXaxis()->GetTitle()));
  return hist;
}

TH1 *style::norm_max(TH1 *h, Double_t maxto)
{
  auto hist = (TH1 *) h -> Clone();
  auto valmax = max(hist);
  auto nbins = hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin)
    hist -> SetBinContent(bin,hist->GetBinContent(bin)*maxto/valmax);
  hist -> SetTitle(Form(";%s;Normalized Max",h->GetXaxis()->GetTitle()));

  return hist;
}

TH1 *style::norm_integral(TH1 *h, Double_t normto)
{
  auto hist = (TH1 *) h -> Clone();
  auto integral = hist -> Integral();
  auto nbins = hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin) {
    auto x1=hist->GetXaxis()->GetBinLowEdge(bin);
    auto x2=hist->GetXaxis()->GetBinUpEdge(bin);
    auto dx=x2-x1;
    hist -> SetBinContent(bin,hist->GetBinContent(bin)*normto/dx/integral);
  }
  hist -> SetTitle(Form(";%s;Normalized Integral",h->GetXaxis()->GetTitle()));
  return hist;
}

void style::fsave (bool val) {
  fSave=val;
  if(fVerbose>0) {
    if(fSave) cout << "fSave=true; Canvas will be written with style::save(TCanvas *) method." << endl; 
    else      cout << "fSave=false; Canvas will NOT!! be written with style::save(TCanvas *) method." << endl; 
  }
}

void style::save(TCanvas *cvs,TString format) {
  if(!fSave) return;
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

TF1 *style::gg(TF1 *f1, Int_t i) {
  double min,max;
  f1->GetRange(min,max);
  auto f=new TF1(Form("%s_%d",f1->GetName(),i),"gaus(0)",min,max);
  f->SetParameters(f1->GetParameter(3*i),f1->GetParameter(3*i+1),f1->GetParameter(3*i+2));
  return f;
}

TH1D *style::cutx(TH1 *hist, Int_t bin1, Int_t bin2) {
  TGraph graph;
  return cutx(hist,bin1,bin2,&graph);
}

TH1D *style::cutx(TH1 *hist, Int_t bin1, Int_t bin2, TGraph *cut_area) {
  auto h2=(TH2 *)hist;
  auto x1=h2->GetXaxis()->GetBinLowEdge(bin1);
  auto x2=h2->GetXaxis()->GetBinUpEdge(bin2);
  {
    auto y1=h2->GetYaxis()->GetBinLowEdge(1);
    auto y2=h2->GetYaxis()->GetBinUpEdge(h2->GetYaxis()->GetNbins());
    cut_area->SetPoint(0,x1,y1);
    cut_area->SetPoint(1,x1,y2);
    cut_area->SetPoint(2,x2,y2);
    cut_area->SetPoint(3,x2,y1);
    cut_area->SetPoint(4,x2,y1);
    cut_area->SetLineColor(kRed);
    cut_area->SetLineWidth(2);
  }
  auto histp=((TH2 *)h2)->ProjectionY(TString(h2->GetName())+Form("_%.2f>>%.2f",x1,x2),bin1,bin2);
  return histp;
}

TGraphErrors *style::fitgsx(TH1* hist, Int_t nDivision, Double_t c) {
  auto h2=(TH2 *)hist;
  auto nbins=h2->GetXaxis()->GetNbins();
  auto dbin=nbins/nDivision;
  auto graph=new TGraphErrors();
  for (auto idxProjection=0;idxProjection<nDivision;++idxProjection) {
    auto bin1=(idxProjection+1)*dbin;
    auto bin2=(idxProjection+2)*dbin;
    auto x=(h2->GetXaxis()->GetBinCenter(bin1)+h2->GetXaxis()->GetBinCenter(bin2))/2.;
    auto histp=((TH2 *)h2)->ProjectionY(TString(h2->GetName())+Form("_%d",idxProjection),bin1,bin2);
    auto f1=fitg(histp,c);
    auto y=f1->GetParameter(1);
    auto s=f1->GetParameter(2);
    auto n=graph->GetN();
    //graph->SetPoint(n,x,y);
    //graph->SetPointError(n,0,s);
    graph->SetPoint(n,x,s);
    graph->SetPointError(n,0,f1->GetParError(2));///sqrt(histp->GetEntries()));
  }
  return graph;
}

TGraphErrors *style::fitgsy(TH1* hist, Int_t nDivision, Double_t c) {
  auto h2=(TH2 *) hist;
  auto nbins=h2->GetYaxis()->GetNbins();
  auto dbin=nbins/nDivision;
  auto graph=new TGraphErrors();
  for (auto idxProjection=0;idxProjection<nDivision;++idxProjection) {
    auto bin1=(idxProjection+1)*dbin;
    auto bin2=(idxProjection+2)*dbin;
    auto y=(h2->GetYaxis()->GetBinCenter(bin1)+h2->GetYaxis()->GetBinCenter(bin2))/2.;
    auto histp=((TH2 *)h2)->ProjectionX(TString(h2->GetName())+Form("_%d",idxProjection),bin1,bin2);
    auto f1=fitg(histp,c);
    auto x=f1->GetParameter(1);
    auto s=f1->GetParameter(2);
    auto n=graph->GetN();
    graph->SetPoint(n,x,y);
    graph->SetPointError(n,s,0);
  }
  return graph;
}

TH1 *style::tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,Double_t x1,Double_t x2,int ny,Double_t y1,Double_t y2) {
  if(fVerbose>0)cout<<name<<": "<<tree->GetName()<<"->[formula:"<<formula<<"],[cut:"<<TString(cut)<<"]->";
  TH1 *h;
  if(ny<0) h=new TH1D(name,title,nx,x1,x2);
  else     h=new TH2D(name,title,nx,x1,x2,ny,y1,y2);
  auto n=tree->Project(name,formula,cut);
  if(fVerbose>0)cout<<n<<endl;
  return make(h);
};

TH1 *style::tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,Double_t x1,Double_t x2,int ny,Double_t y1,Double_t y2) {
  if(fVerbose>0)cout<<name<<": "<<tree->GetName()<<"->[formula:"<<formula<<"],[cut:"<<TString(cut)<<"]->";
  TH1 *h;
  if(ny<0) h=new TH1D(name,title,nx,x1,x2);
  else     h=new TH2D(name,title,nx,x1,x2,ny,y1,y2);
  auto n=tree->Project(name,formula,cut);
  if(fVerbose>0)cout<<n<<endl;
  return make(h);
};

TCutG *style::cutg(TString f, TString c, TString x, TString y) {
  auto file=new TFile(f.Data(),"read");
  auto cg=(TCutG *) file->Get(c.Data());
  cg->SetVarX(x.Data());
  cg->SetVarY(y.Data());
  return cg;
}

TCutG *cutg(TFile  *file, TString c, TString x, TString y) {
  auto cg=(TCutG *) file->Get(c.Data());
  cg->SetVarX(x.Data());
  cg->SetVarY(y.Data());
  return cg;
}

void style::pfname(TString str, TString &pathname, TString &filename, TString delim="/") {
  TObjArray *tokens=str.Tokenize(delim);
  auto n=tokens->GetEntries();
  pathname="";
  pathname=((TObjString *) tokens->At(0))->GetString();
  if(n-1>1)
    for (auto i=1;i<n-1;++i)
      pathname=pathname+delim+(((TObjString *) tokens->At(i))->GetString());
  filename=((TObjString *) tokens->At(n-1))->GetString();
}

TString style::firstname(TString str, TString delim=".") {
  TObjArray *tokens=str.Tokenize(delim);
  return ((TObjString *) tokens->At(0))->GetString();
}

TString style::lastname(TString str, TString delim="/") {
  TObjArray *tokens=str.Tokenize(delim);
  return ((TObjString *) tokens->At(tokens->GetEntries()-1))->GetString();
}

TString style::justname(TString str) {
  return firstname(lastname(str));
}
