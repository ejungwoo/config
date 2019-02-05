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
#include "TVirtualPad.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TLegendEntry.h"
#include "TObjArray.h"
#include "TObjString.h"
#include <vector>
#include <iostream>
using namespace std;

namespace style
{
  void v(int verbose=1); ///< verbosity "fVerbose" - 0:silent, 1:default
  void g(int graphic=1); ///< graphic verbosity "fVerboseG" - 0:silent(default), 1:draw-details

  TFile *gfile(TString filename); ///< save graphic if fVerboseG>1

  void gstat (int opt); ///< equalivant to gStyle->SetOptStat(opt);
  void fstat (int opt); ///< equalivant to gStyle->SetOptFit(opt);
  void zcolor(int opt); ///< set z-palette color to 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale
  void colorwheel(); ///< show colorwheel
  void markers(); ///< show markers

  TCanvas *cv1   (TString name="",double w=0,double h=0); ///<  500 x 550 - 1D style
  TCanvas *cv2   (TString name="",double w=0,double h=0); ///<  600 x 550 - 1D style
  TCanvas *cv3   (TString name="",double w=0,double h=0); ///<  680 x 550 - 1D style
  TCanvas *cv    (TString name="",double w=0,double h=0) { return cv2(name,w,h); }

  TCanvas *cc1  (TString name="",double w=0,double h=0); ///<  600 x 550 - 2D style
  TCanvas *cc2  (TString name="",double w=0,double h=0); ///<  680 x 550 - 2D style
  TCanvas *cc3  (TString name="",double w=0,double h=0); ///<  900 x 550 - 2D style
  TCanvas *cc4  (TString name="",double w=0,double h=0); ///< 1200 x 800 - 2D style
  TCanvas *cc   (TString name="",double w=0,double h=0) { return cc1(name,w,h); }

     TObject *make (TObject *o);       ///< make object stylish!
      TGraph *make (TGraph *gr);       ///< make graph stylish!
TGraphErrors *make (TGraphErrors *gr); ///< make error graph stylish!
         TH1 *make (TH1 *h);           ///< make histogram stylish!
         TH1 *make2(TH1 *h);           ///< make histogram stylish! with bigger fonts
         TF1 *make (TF1 *f);           ///< make function stylish!

     TLegend *make (TLegend *legend, Double_t dx=0, Double_t dy=0);  ///< make legend stylish!
     TLegend *make2(TLegend *legend, Double_t dx=0, Double_t dy=0);  ///< make legend stylish! with bigger contents
   TPaveText *make (TPaveText *pave);  ///< make pave text stylish!
     TCanvas *make (TCanvas *cvs);     ///< make canvas stylish!

  TF1 *settitle(TF1 *f, TString title); ///< set title of function histogram

  TH1 *tohist(Double_t *buffer, Int_t n, TString name = "", TString title = ""); ///< make histogram with given buffer
  TH1 *tohist(Double_t *buffer, Int_t i, Int_t f, TString name = "", TString title = ""); ///< make histogram with given buffer

  //TGraph *tograph(TString filename);

  TH1 *inv (TH1 *h); ///< recreate histogram from "x vs y" to "y to x"

  TCutG *cutg (TString f, TString cutname, TString x, TString y); ///< set TCutG from file name
  TCutG *cutg (TFile  *f, TString cutname, TString x, TString y); ///< set TCutG from file

  TH1   *cutg    (TH1  *h, TCutG *cut); ///< recreate histogram with given graphical cut
  TH1   *cutg_or (TH1 *h, TCutG *cut, TCutG *orcut);
  TH1   *cutg_and(TH1 *h, TCutG *cut, TCutG *andcut);

  TH1 *dndx(TH1 *h); ///< make graph y aixs to dn/dx where n is number of entries
  TH1 *norm_max(TH1 *h, Double_t maxto = 1); ///< normalize maximum value of histogram to maxto(=1 by default)
  TH1 *norm_integral(TH1 *h, Double_t normto = 1); ///< normalize integral value of histogram to normto(=1 by default)

  void version(TString v); ///< if version is set, fVersion is used instead of doing verson control.
  TString version(); ///< return version

  void fsave(bool val); ///< set save canvas by save(TCanvas *)
  void  save(TVirtualPad *cvs, TString format="png", bool version_control = true);
  void  save(TCanvas *cvs, TString format="png", bool version_control = true); ///< save cavans ./figures/[canvas name].[version-automatically updated].[format]
  void  save(TString name, TCanvas *cvs, TString format="png", bool version_control = true); ///< save cavans ./figures/[name].[version-automatically updated].[format]

  void fwrite(bool val); ///< set write object by write(TObject *)
  void  write(TObject *obj, bool version_control = true); ///< write object ./data/[obj name].[version-automatically updated].root
  void  write(TString name, TObject *obj, bool version_control = true); ///< write to file with name 'name'

  TGraph *sumf(vector<TF1*> &fs); ///< TODO create TF1 which is sum of TF1s in fs;

  TF1 *fitg (TH1 *h, Double_t c=1.5, Option_t *opt="RQ0"); ///< fast single gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *fitgg(TH1 *h, Double_t c=1.5, Option_t *opt="RQ0"); ///< fast double gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1    *gg(TF1 *f, Int_t i); ///< get i'th gaussian from multipule gaussian function f1

  TH1D *cuty(TH1 *hist, Int_t bin1, Int_t bin2); ///< TODO
  TH1D *cuty(TH1 *hist, Int_t bin1, Int_t bin2, TGraph *cut_area); ///< TODO
  TH1D *cutx(TH1 *hist, Int_t bin1, Int_t bin2); ///< cut TH2 histogram in x from x-bin = bin1~bin2 and project histogram to y
  TH1D *cutx(TH1 *hist, Int_t bin1, Int_t bin2, TGraph *cut_area); ///< same as above but TGraph *cut_area is set to area of cut region in h2;

  class hdata : public TObject {
    public:
      TH1D *hist;
      int n;
      double x=0,y=0,dx=0,ddx=0,dy=0,ddy=0;
      hdata(TH1D *h):TObject(),hist(h) {}
      virtual ~hdata() {}
      void print() { cout<<"n:"<<n<<"| xy:"<<x<<", "<<y<<"| dxy:"<<dx<<", "<<dy<<"| ddxy:"<<ddx<<", "<<ddy<<endl; }
      double error() { return sqrt(dx*dx+dy*dy); }
      double get(TString v) {
        double c = 1;
        if(v.Index(".5")>=0) c *= 0.5;
        if(v.Index("/2")>=0) c *= 0.5;
        if(v.Index("/sn")>=0) c *= 1./sqrt(n);
             if(v.Index("ddx")>=0) return c*ddx;
        else if(v.Index("ddy")>=0) return c*ddy;
        else if(v.Index("dx")>=0) return c*dx;
        else if(v.Index("dy")>=0) return c*dy;
        else if(v.Index("x")>=0) return c*x;
        else if(v.Index("y")>=0) return c*y;
        return 0;
      }
  };

  /**
   * fit 2d histogram through x with given parameters and return list of histogram data
   * @param nDivision division number through x
   * @param c fit will perform in range of -c*sigma ~ c*sigma
   * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
   */
  TObjArray *fitgsx_list(TH1 *hist, Int_t nDivision=20, Double_t c=1.5, Int_t entry_cut=1000);
  /**
   * fit 2d histogram through y with given parameters and return list of histogram data
   * @param nDivision division number through y
   * @param c fit will perform in range of -c*sigma ~ c*sigma
   * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
   */
  TObjArray *fitgsy_list(TH1 *hist, Int_t nDivision=20, Double_t c=1.5, Int_t entry_cut=1000);

  /**
   * Using the data from fitgsx_list
   * Draw error graph of point (xo,yo) and error (xoe,yoe)
   * variables must be one of x(fit mean), y(fit mean), dx(fit sigma), dy(fit sigma), ddx(fit sigma error), ddy(fit sigma error)
   */
  TGraphErrors *fitgsx(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, Int_t nDivision, Double_t c, Int_t entry_cut);
  /**
   * Using the data from fitgsy_list
   * Draw error graph of point (xo,yo) and error (xoe,yoe)
   * variables must be one of x(fit mean), y(fit mean), dx(fit sigma), dy(fit sigma), ddx(fit sigma error), ddy(fit sigma error)
   */
  TGraphErrors *fitgsy(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, Int_t nDivision, Double_t c, Int_t entry_cut);

  /**
   * Using the data from fitgsx_list
   * @param error_graph=true  will draw fitgsx(hist,"x","dy","","ddy")
   * @param error_graph=false will draw fitgsx(hist,"x","y","dx/2","dy")
   */
  TGraphErrors *fitgsx(TH1 *hist, Int_t nDivision=20, Double_t c=1.5, Int_t entry_cut=1000, bool error_graph = false);
  /**
   * Using the data from fitgsy_list
   * @param error_graph=true  will draw return fitgsy(hist,"y","dx","ddx","")
   * @param error_graph=false will draw return fitgsy(hist,"x","y","dx","dy/2")
   */
  TGraphErrors *fitgsy(TH1 *hist, Int_t nDivision=20, Double_t c=1.5, Int_t entry_cut=1000, bool error_graph = false);

  TH1 *tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1); ///< project from tree
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1); ///< project from tree
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,const Double_t *xbins); ///< project from tree with bin made from array of xbins

     Int_t max (Int_t *buffer, Int_t n); ///< get maximum value of buffer
  Double_t max (Double_t *buffer, Int_t n); ///< get maximum value of buffer
  Double_t max (TH1 *h); ///< get maximum value of histogram
  Double_t max (TH1 *h, Int_t &bin, Double_t &x); ///< get maximum value of histogram
  Double_t fwrm(TF1 *f, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q); ///< width function at y; given by ratio*[maximum value] with quality q
  Double_t fwhm(TF1 *f, Double_t &x0, Double_t &x1, Double_t &q); ///< FWHM(Full Width Half Maximum)
  Double_t fwhm(TF1 *f); ///< FWHM(Full Width Half Maximum)

  Double_t fwrm(TH1 *h, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q); ///< FWHM(Full Width Half Maximum) 
  Double_t fwhm(TH1 *h, Double_t &x0, Double_t &x1, Double_t &q); ///< Full Width Half Maximum
  Double_t fwhm(TH1 *h); ///< Full Width Half Maximum

  void pfname(TString str, TString &pathname, TString &filename, TString delim="/"); ///< get pathname=[path-name], filename=[file-name] after tonizing with delim
  TString firstname(TString str, TString delim="."); ///< get first name
  TString lastname(TString str, TString delim="/"); ///< get last name
  TString justname(TString str); ///< get name with no path and format. just name

  /********************************************************/

  void axisd(Int_t nd=506); ///< make axis ndivisions to nd!, (root default 510, style default 508, axisd default 506 - for TGraph2D)
  TH1 *free (TH1 *h); ///< make axis labels feel free!

  void cutt(); ///< cut top margin to 0.02
  void cutr(Double_t r=0.02); ///< cut right margin to 0.02
  void cuttr(Double_t r=0.02); ///< cut right margin to 0.02
  void cutall(Double_t r=0.02); ///< cut all margin to 0.02

  void init();

  /********************************************************/

    bool fSave=true;
    bool fWrite=true;
     int fVerbose=1;
     int fVerboseG=0;

 TFile *fSaveGFile=nullptr;

 TString fVersion="";

     int fICvs=0;
     int fIHist=0;

     int fWC1=500;
     int fWC2=600;
     int fWC3=680;
     int fHC3=550;
     int fWCC2=900;
     int fHCC2=550;
     int fWCC3=1200;
     int fHCC3=800;

     int fYCvs=0;

  double fWDefault=0.1;
  double fWUnit=0.008;
  double fHUnit=0.05;

  double fWDefault2=0.2;
  double fWUnit2=0.012;
  double fHUnit2=0.07;

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
  double fAxisLabelSize2=0.07;
  double fAxisTitleSize2=0.08;

  double fXTitleOffset=1.15;
  double fYTitleOffset=1.35;
  double fXTitleOffset2=0.80;
  //double fYTitleOffset2=1.30;
  double fYTitleOffset2=1.00;

  int fNDivisions=508;
  int fNDivisions2=506;

  TObjArray *fArray;
}; 

void style::v(int verbose=1) { fVerbose=verbose; }
void style::g(int verbose=1) { fVerboseG=verbose; }

void style::gstat(int opt) {
  gStyle->SetOptStat(opt);
}

void style::fstat(int opt) {
  gStyle->SetOptFit(opt);
}

void style::zcolor(int opt) {
  if(fVerbose>0) cout<<"zcolor("<<opt<<") >> 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale"<<endl;
       if(opt == 0) gStyle->SetPalette(kBird);
  else if(opt == 1) gStyle->SetPalette(kRainBow);
  else if(opt == 2) gStyle->SetPalette(kDeepSea);
  else if(opt == 3) gStyle->SetPalette(kAvocado);
  else if(opt == 4) gStyle->SetPalette(kBlueGreenYellow);
  else if(opt == 5) gStyle->SetPalette(kBrownCyan);
  else              gStyle->SetPalette(kGreyScale);
}

void style::colorwheel() {
  TColorWheel *w=new TColorWheel();
  w->SetCanvas(cv("cw",700,700));
  w->Draw();
}

void style::markers() {
  gStyle -> SetOptStat(0);
  auto cvs = new TCanvas("markers","",600,400);
  cvs->SetMargin(0.02,0.02,0.02,0.02);
  auto hist = new TH2D("hist","",100,0.2,10.8,100,0.1,5.6);
  hist->SetStats(0);
  hist->GetXaxis()->SetLabelOffset(100);
  hist->GetYaxis()->SetLabelOffset(100);
  hist->GetXaxis()->SetNdivisions(0);
  hist->GetYaxis()->SetNdivisions(0);
  hist->Draw();
  int i=0;
  for (auto y=5; y>=1; --y) {
    for (auto x=1; x<=10; ++x) {
      if (i==0) { i++; continue; }
      auto m = new TMarker(x,y,i);
      m -> SetMarkerSize(3.5);
      auto t = new TText(x,y-0.42,Form("%d",i));
      t -> SetTextSize(0.035);
      t -> SetTextAlign(22);
      if ((i>=20&&i<=29)||i==33||i==34) t -> SetTextColor(kBlue);
      if ((i>=24&&i<=28)||i==30||i==32) t -> SetTextColor(kRed);
      if (i>=9&&i<=19) {
        t -> SetTextColor(kGray);
        m -> SetMarkerColor(kGray);
      }
      m -> Draw();
      t -> Draw();
      i++;
    }
  }
}

TGraph *style::sumf(vector<TF1*> &fs)
{
  auto graph=new TGraph();
  Double_t x,xl,xh;
  fs.at(0)->GetRange(xl, xh);
  auto dx=(xh-xl)/1000;

  for (auto x=xl;x<=xh;x+=dx) {
    auto val=0.;
    for (auto f:fs) {
      val+=f->Eval(x);
    }
    graph->SetPoint(graph->GetN(),x,val);
  }
  return graph;
}

Int_t style::max(Int_t *buffer, Int_t n)
{
  Int_t val = -INT_MAX;
  for (auto i=0; i<n; ++i)
    if(buffer[i] > val)
      val = buffer[i];
  return val;
}

Double_t style::max(Double_t *buffer, Int_t n)
{
  Double_t val = -DBL_MAX;
  for (auto i=0; i<n; ++i)
    if(buffer[i] > val)
      val = buffer[i];
  return val;
}

Double_t style::max(TH1 *h) {
  Int_t bin;
  Double_t x;
  return max(h, bin, x);
}

Double_t style::max (TH1 *h, Int_t &bin, Double_t &x) {
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
  Int_t binmax;
  Double_t xmax;
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
    if(fVerbose>0) cout<<x<<endl;
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

void style::cutt() { fTMargin = 0.04; }
void style::cutr(Double_t r) { fRMarginH1 = r; fRMarginH2 = r; }
void style::cuttr(Double_t r) { fTMargin = r; fRMarginH1 = r; fRMarginH2 = r; }
void style::cutall(Double_t r) { fTMargin = r; fRMarginH1 = r; fRMarginH2 = r; fBMargin = r; fLMargin = r; }

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

TCanvas *style::cv1(TString name,double w,double h) {
  fRMargin=fRMarginH1;
  init();
  if(w==0) w=fWC1;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs); ++fICvs;
  return cvs;
}

TCanvas *style::cv2(TString name,double w,double h) {
  fRMargin=fRMarginH1;
  init();
  if(w==0) w=fWC2;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs); ++fICvs;
  return cvs;
}

TCanvas *style::cv3(TString name,double w,double h) {
  fRMargin=fRMarginH1;
  init();
  if(w==0) w=fWC3;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs); ++fICvs;
  return cvs;
}

TCanvas *style::cc3(TString name,double w,double h) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWCC2;
  if(h==0) h=fHCC2;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs); ++fICvs;
  return cvs;
}

TCanvas *style::cc4(TString name,double w,double h) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWCC3;
  if(h==0) h=fHCC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs); ++fICvs;
  return cvs;
}

TCanvas *style::cc1(TString name,double w,double h) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWC2;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs); ++fICvs;
  return cvs;
}

TCanvas *style::cc2(TString name,double w,double h) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWC3;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs); ++fICvs;
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
  //++fICvs;
  return cvs;
}

TGraph *style::make(TGraph *graph) {
  init();
  if(graph->GetMarkerStyle()==1) {
    graph->SetMarkerStyle(20);
    //graph->SetMarkerSize(0.5);
    graph->SetMarkerSize(1);
  }
  make(graph->GetHistogram());
  return graph;
}

TGraphErrors *style::make(TGraphErrors *graph)
{
  return (TGraphErrors *) make((TGraph *) graph);
}

TH1 *style::make2(TH1 *h) {
  init();
  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(fXTitleOffset2);
  h->GetXaxis()->SetTitleSize(fAxisTitleSize2);
  h->GetXaxis()->SetLabelSize(fAxisLabelSize2);
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(fYTitleOffset2);
  h->GetYaxis()->SetTitleSize(fAxisTitleSize2);
  h->GetYaxis()->SetLabelSize(fAxisLabelSize2);
  h->GetZaxis()->CenterTitle();
  h->GetZaxis()->SetTitleOffset(fYTitleOffset2);
  h->GetZaxis()->SetTitleSize(fAxisTitleSize2);
  h->GetZaxis()->SetLabelSize(fAxisLabelSize2);
  free(h);
  return h;
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
  h->GetZaxis()->CenterTitle();
  h->GetZaxis()->SetTitleOffset(fYTitleOffset);
  h->GetZaxis()->SetTitleSize(fAxisTitleSize);
  h->GetZaxis()->SetLabelSize(fAxisLabelSize);
  free(h);
  return h;
}

TLegend *style::make(TLegend *legend, Double_t dx, Double_t dy) {
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
  legend->SetX1(x1+dx);
  legend->SetX2(x2+dx);
  legend->SetY1(y1+dy);
  if(y2<0.2)
    y2=0.2;
  legend->SetY2(y2+dy);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  return legend;
}

TLegend *style::make2(TLegend *legend, Double_t dx, Double_t dy) {
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
  
  auto y1=y2-legend->GetNRows()*fHUnit2;
  auto x2=1.-fRMargin;
  auto x1=x2-lmax*fWUnit2 - fWDefault2;
  if(x1>x2-fWStat) x1=x2-fWStat;
  legend->SetX1(x1+dx);
  legend->SetX2(x2+dx);
  legend->SetY1(y1+dy);
  if(y2<0.2)
    y2=0.2;
  legend->SetY2(y2+dy);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);
  return legend;
}

TPaveText *style::make(TPaveText *pave) {
  init();
  auto y2=1.-fTMargin;
  if(gStyle->GetOptStat() != 0) y2=gStyle->GetStatY()-gStyle->GetStatH();
  auto lmax=0;
  TIter next(pave->GetListOfLines());
  TLatex *text;
  while ((text=(TLatex *) next())) {
    auto l=TString(text->GetTitle()).Length();
    if(lmax<l) lmax=l;
  }
  
  auto y1=y2-pave->GetSize()*fHUnit;
  auto x2=1.-fRMargin;
  auto x1=x2-lmax*fWUnit - fWDefault;
  if(x1>x2-fWStat) x1=x2-fWStat;
  pave->SetX1(x1);
  pave->SetX2(x2);
  pave->SetY1(y1);
  if(y2<0.2)
    y2=0.2;
  pave->SetY2(y2);
  pave->SetFillStyle(0);
  pave->SetBorderSize(0);
  return pave;
}

TF1 *style::make(TF1 *f) {
  make(f->GetHistogram());
  f->SetNpx(1000);
  return f;
}

TF1 *style::settitle(TF1 *f, TString title)
{
  f -> GetHistogram() -> SetTitle(title);
  return f;
}

TH1 *style::tohist(Double_t *buffer, Int_t n, TString name, TString title)
{
  if(name.IsNull()) name=Form("hist-%d",fIHist);
  auto hist = new TH1D(name, title, n, 0, n+1);
  for (auto i = 0; i < n; ++i)
    hist -> SetBinContent(i+1,buffer[i]);
  ++fIHist;
  return make(hist);
}

TH1 *style::tohist(Double_t *buffer, Int_t i, Int_t f, TString name, TString title)
{
  if(name.IsNull()) name=Form("hist-%d",fIHist);
  auto hist = new TH1D(name, title, f-i+1, i, f+1);
  for (auto bin = i; bin < f+1; ++bin)
    hist -> SetBinContent(bin+1-i,buffer[bin]);
  ++fIHist;
  return make(hist);
}

void style::axisd(Int_t nd) { fNDivisions=nd; }

TH1 *style::free(TH1 *h) {
  /*
  Set the number of divisions for this axis.

  if optim = kTRUE (default), the number of divisions will be optimized around the specified value.
  if optim = kFALSE, or n < 0, the axis will be forced to use exactly n divisions.

    n = n1 + 100*n2 + 10000*n3
  Where n1 is the number of primary divisions, n2 is the number of second order divisions and n3 is the number of third order divisions.

  e.g. 512 means 12 primary and 5 secondary divisions.

  If the number of divisions is "optimized" (see above) n1, n2, n3 are maximum values.
   */
  h->GetXaxis()->SetNdivisions(/*n=*/fNDivisions2/*,optim=true*/);
  h->GetYaxis()->SetNdivisions(/*n=*/fNDivisions2/*,optim=true*/);
  h->GetZaxis()->SetNdivisions(/*n=*/fNDivisions2/*,optim=true*/);
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

void style::version(TString v) {
  fVersion = v;
  if(fVerbose>0) cout<<"fVersion=["<<fVersion<<"]"<<endl;
}

TString style::version() { return fVersion; }

TFile *style::gfile(TString filename) {
  if(filename.Index(".root")<0)
    filename=filename+".root";
  if(!fVersion.IsNull())
    filename.ReplaceAll(".root",TString(".")+fVersion+".root");

  if(fSaveGFile==nullptr)
    fSaveGFile = new TFile(filename,"recreate");
  return fSaveGFile;
}
void style::fsave(bool val) {
  fSave=val;
  if(fVerbose>0) {
    if(fSave) cout<<"fSave=true; TCanvas will be written by style::save(TCanvas *) method."<<endl;
    else      cout<<"fSave=false; TCanvas will NOT!! be written by style::save(TCanvas *) method."<<endl;
  }
}

void style::save(TVirtualPad *cvs, TString format, bool version_control) {
  save(((TCanvas *)cvs), format, version_control);
}

void style::save(TCanvas *cvs, TString format, bool version_control) {
  if(!fSave) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/figures/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString name=cvs->GetName();
  TString full_name=name+"."+format;
  if(!fVersion.IsNull()) {
    full_name=name+"."+fVersion+"."+format;
    cvs->SaveAs(path+full_name);
    return;
  }
  int version_idx=0;
  while (version_control) {
    char* c=gSystem->Which(path.Data(),full_name.Data());
    if(TString(c).IsNull()) {
      cvs->SaveAs(path+full_name);
      break;
    }
    full_name=name+"."+TString::Itoa(++version_idx,10)+"."+format;
    if(fVerbose>0&&version_idx%10==0) cout<<"[Warning] More than "<<version_idx<<" versions of "<<name<<"exist!"<<endl;
  }
}

void style::save(TString name, TCanvas *cvs, TString format, bool version_control) {
  if(!fSave) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/figures/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString full_name=name+"."+format;
  if(!fVersion.IsNull()) {
    full_name=name+"."+fVersion+"."+format;
    cvs->SaveAs(path+full_name);
    return;
  }
  int version_idx=0;
  while (version_control) {
    char* c=gSystem->Which(path.Data(),full_name.Data());
    if(TString(c).IsNull()) {
      cvs->SaveAs(path+full_name);
      break;
    }
    full_name=name+"."+TString::Itoa(++version_idx,10)+"."+format;
    if(fVerbose>0&&version_idx%10==0) cout<<"[Warning] More than "<<version_idx<<" versions of "<<name<<"exist!"<<endl;
  }
}

void style::fwrite(bool val) {
  fWrite=val;
  if(fVerbose>0) {
    if(fWrite) cout<<"fWrite=true; TObject will be written by style::write(TObject *) method."<<endl;
    else       cout<<"fWrite=false; TObject will NOT!! be written by style::write(TObject *) method."<<endl;
  }
}

void style::write(TObject *obj, bool version_control) {
  if(!fWrite) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/data/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString name=obj->GetName();
  TString full_name=name+".root";
  if(!fVersion.IsNull()) {
    full_name=name+"."+fVersion+".root";
    auto file = new TFile(path+full_name,"recreate");
    obj->Write();
    if(fVerbose>0) cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<endl;
    file->Close();
    return;
  }
  int version_idx=0;
  while (version_control) {
    char* c=gSystem->Which(path.Data(),full_name.Data());
    if(TString(c).IsNull()) {
      auto file = new TFile(path+full_name,"recreate");
      obj->Write();
      if(fVerbose>0) cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<endl;
      file->Close();
      return;
    }
    full_name=name+"."+TString::Itoa(++version_idx,10)+".root";
    if(fVerbose>0&&version_idx%10==0) cout<<"[Warning] More than "<<version_idx<<" versions of "<<full_name<<"exist!"<<endl;
  }
}

void style::write(TString name, TObject *obj, bool version_control = true){
  if(!fWrite) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/data/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString full_name=name+".root";
  if(!fVersion.IsNull())
    name=name+"."+fVersion;

  if(fArray == nullptr)
    fArray = new TObjArray();

  TFile *file = nullptr;
  for (auto i=0; i<fArray->GetEntries(); ++i)
  {
    auto file0 = (TFile *) fArray->At(i);
    if(TString(file0->GetName()).Index(name)>0) {
      file = file0;
      break;
    }
  }

  if(file!=nullptr) {
    obj->Write();
    if(fVerbose>0) cout<<"Writing "<<obj->GetName()<<" to "<<file->GetName()<<endl;
    return;
  }
  else {
    if(!fVersion.IsNull()) {
      full_name=name+".root";
      file = new TFile(path+full_name,"recreate");
      fArray->Add(file);
      obj->Write();
      if(fVerbose>0) cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<endl;
      return;
    }
    int version_idx=0;
    while (version_control) {
      char* c=gSystem->Which(path.Data(),full_name.Data());
      if(TString(c).IsNull()) {
        file = new TFile(path+full_name,"recreate");
        fArray->Add(file);
        obj->Write();
        if(fVerbose>0) cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<endl;
        return;
      }
      full_name=name+"."+TString::Itoa(++version_idx,10)+".root";
      if(fVerbose>0&&version_idx%10==0) cout<<"[Warning] More than "<<version_idx<<" versions of "<<full_name<<"exist!"<<endl;
    }
  }
}


TF1 *style::fitg(TH1 *h,Double_t c,Option_t *opt) {
  auto binmax=h->GetMaximumBin();
  auto max=h->GetBinContent(binmax);
  auto xmax=h->GetXaxis()->GetBinCenter(binmax);
  auto xerr=h->GetStdDev();
  auto f=new TF1(Form("%s_fitg",h->GetName()),"gaus(0)",xmax-xerr*c,xmax+xerr*c);
  f->SetParameters(max,xmax,xerr);
  h->Fit(f,opt);

  xmax=f->GetParameter(1);
  xerr=f->GetParameter(2);
  f->SetRange(xmax-c*xerr,xmax+c*xerr);
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

TH1D *style::cutx(TH1 *h2, Int_t bin1, Int_t bin2) {
  TGraph graph;
  return cutx(h2,bin1,bin2,&graph);
}

TH1D *style::cutx(TH1 *hist, Int_t bin1, Int_t bin2, TGraph *cut_area) {
  auto h2 = (TH2 *) hist;
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
  auto hp=((TH2 *)h2)->ProjectionY(TString(h2->GetName())+Form("_%.2f>>%.2f",x1,x2),bin1,bin2);
  return hp;
}

TObjArray *style::fitgsx_list(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut) {
  auto h2 = (TH2 *) hist;
  auto nbins=h2->GetXaxis()->GetNbins();
  auto dbin=nbins/nDivision;
  TObjArray *array=new TObjArray();
  TString oxtitle = hist->GetXaxis()->GetTitle(); if(oxtitle.IsNull()) oxtitle="xvar";
  TString oytitle = hist->GetYaxis()->GetTitle(); if(oytitle.IsNull()) oytitle="yvar";
  for (auto idxProjection=0;idxProjection<nDivision;++idxProjection) {
    auto bin1=(idxProjection)*dbin+1;
    auto bin2=(idxProjection+1)*dbin;
    auto x1=h2->GetXaxis()->GetBinLowEdge(bin1);
    auto x2=h2->GetXaxis()->GetBinUpEdge(bin2);
    auto hp=((TH2 *)h2)->ProjectionY(TString(h2->GetName())+Form("_%d",idxProjection),bin1,bin2);
    TString value1 = Form("%.2f",x1); value1.ReplaceAll(".00","");
    TString value2 = Form("%.2f",x2); value2.ReplaceAll(".00","");
    hp->SetTitle(TString(Form("%s=%s~%s;%s",oxtitle.Data(),value1.Data(),value2.Data(),oytitle.Data())));
    auto n=hp->GetEntries();
    if(n<entry_cut) continue;
    auto f1=fitg(hp,c);

    if(fVerboseG>0) {
      style::cv1();
      make(hp)->Draw();
      f1->Draw("same");
      if(fVerboseG>1&&fSaveGFile!=nullptr) {
        fSaveGFile->cd();
        hp->Write();
      }
    }

    auto hd=new style::hdata(hp);
    array->Add(hd);
    hd->n=n;
    hd->x=(x1+x2)/2;
    hd->dx=x2-x1;
    hd->y=f1->GetParameter(1);
    //hd->y=hp->GetMean();
    hd->dy=f1->GetParameter(2);
    hd->ddy=f1->GetParError(2);
    if(fVerbose>1)
      hd->print();
  }
  return array;
}

TObjArray *style::fitgsy_list(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut) {
  auto h2 = (TH2 *) hist;
  auto nbins=h2->GetYaxis()->GetNbins();
  auto dbin=nbins/nDivision;
  TObjArray *array=new TObjArray();
  TString oxtitle = hist->GetXaxis()->GetTitle(); if(oxtitle.IsNull()) oxtitle="xvar";
  TString oytitle = hist->GetYaxis()->GetTitle(); if(oytitle.IsNull()) oytitle="yvar";
  for (auto idxProjection=0;idxProjection<nDivision;++idxProjection) {
    auto bin1=(idxProjection)*dbin+1;
    auto bin2=(idxProjection+1)*dbin;
    auto y1=h2->GetYaxis()->GetBinLowEdge(bin1);
    auto y2=h2->GetYaxis()->GetBinUpEdge(bin2);
    auto hp=((TH2 *)h2)->ProjectionX(TString(h2->GetName())+Form("_%d",idxProjection),bin1,bin2);
    TString value1 = Form("%.2f",y1); value1.ReplaceAll(".00","");
    TString value2 = Form("%.2f",y2); value2.ReplaceAll(".00","");
    hp->SetTitle(TString(Form("%s=%s~%s;%s",oytitle.Data(),value1.Data(),value2.Data(),oxtitle.Data())));
    auto n=hp->GetEntries();
    if(n<entry_cut) continue;
    auto f1=fitg(hp,c);

    if(fVerboseG>0) {
      style::cv1();
      make(hp)->Draw();
      f1->Draw("same");
      if(fVerboseG>1&&fSaveGFile!=nullptr) {
        fSaveGFile->cd();
        hp->Write();
      }
    }

    auto hd=new style::hdata(hp);
    array->Add(hd);
    hd->n=n;
    hd->y=(y1+y2)/2;
    hd->dy=y2-y1;
    hd->x=f1->GetParameter(1);
    hd->dx=f1->GetParameter(2);
    if(fVerbose>1)
      hd->print();
  }
  return array;
}

TGraphErrors *style::fitgsx(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut, bool error_graph) {
  if(error_graph)
    return fitgsx(hist,"x","dy","","ddy",nDivision,c,entry_cut);
  return fitgsx(hist,"x","y","dx/2","dy",nDivision,c,entry_cut);
}

TGraphErrors *style::fitgsy(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut, bool error_graph) {
  if(error_graph)
    return fitgsy(hist,"y","dx","ddx","",nDivision,c,entry_cut);
  return fitgsy(hist,"x","y","dx","dy/2",nDivision,c,entry_cut);
}

TGraphErrors *style::fitgsx(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, Int_t nDivision, Double_t c, Int_t entry_cut) {
  auto h2 = (TH2 *) hist;
  auto graph=new TGraphErrors();
  auto array=fitgsx_list(h2,nDivision,c,entry_cut);
  if(fVerbose>1)
    cout << "graph info. " << xo << " " << yo << " " << xoe << " " << yoe << endl;
  for (auto i=0; i<array->GetEntries(); ++i) {
    auto h=(style::hdata*)array->At(i);
    graph->SetPoint(i,h->get(xo),h->get(yo));
    graph->SetPointError(i,h->get(xoe),h->get(yoe));
    if(fVerbose>1)
      cout << h->get(xo) << " " << h->get(yo) << " " << h->get(xoe) << " " << h->get(yoe) << endl;
  }
  return make(graph);
}

TGraphErrors *style::fitgsy(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, Int_t nDivision, Double_t c, Int_t entry_cut) {
  auto h2 = (TH2 *) hist;
  auto graph=new TGraphErrors();
  auto array=fitgsy_list(h2,nDivision,c,entry_cut);
  if(fVerbose>1)
    cout << "graph info. " << xo << " " << yo << " " << xoe << " " << yoe << endl;
  for (auto i=0; i<array->GetEntries(); ++i) {
    auto h=(style::hdata*)array->At(i);
    graph->SetPoint(i,h->get(xo),h->get(yo));
    graph->SetPointError(i,h->get(xoe),h->get(yoe));
    if(fVerbose>1)
      cout << h->get(xo) << " " << h->get(yo) << " " << h->get(xoe) << " " << h->get(yoe) << endl;
  }
  return make(graph);
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
  return tp(tree,formula,cut,name,title,nx,x1,x2,ny,y1,y2);
};

TH1 *style::tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,const Double_t *xbins)
{
  if(fVerbose>0)cout<<name<<": "<<tree->GetName()<<"->[formula:"<<formula<<"],[cut:"<<TString(cut)<<"]->";
  TH1 *h=new TH1D(name,title,nx,xbins);
  auto n=tree->Project(name,formula,cut);
  if(fVerbose>0)cout<<n<<endl;
  return make(h);
}

TCutG *style::cutg(TString f, TString cutname, TString x, TString y) {
  auto file=new TFile(f.Data(),"read");
  auto cg=(TCutG *) file->Get(cutname.Data());
  cg->SetVarX(x.Data());
  cg->SetVarY(y.Data());
  return cg;
}

TCutG *style::cutg(TFile *file, TString cutname, TString x, TString y) {
  auto cg=(TCutG *) file->Get(cutname.Data());
  cg->SetVarX(x.Data());
  cg->SetVarY(y.Data());
  return cg;
}

TH1 *style::cutg(TH1 *h, TCutG *cut) {
  auto h2 = (TH2 *) h;
  auto hnew = (TH2 *) h2 -> Clone();
  hnew -> Reset();
  auto nx=h2->GetXaxis()->GetNbins();
  auto ny=h2->GetYaxis()->GetNbins();
  for (auto binx=1;binx<=nx;++binx) {
    for (auto biny=1;biny<=ny;++biny) {
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      if(cut->IsInside(x,y)==1) {
        //hnew->SetBinContent(binx,biny,h2->GetBinContent(binx,biny));
        Int_t n=h2->GetBinContent(binx,biny);
        for (auto i=0;i<n;++i)
          hnew->Fill(x,y);
      }
    }
  }
  return (TH1 *) hnew;
}

TH1 *style::cutg_or(TH1 *h, TCutG *cut, TCutG *orcut) {
  auto h2 = (TH2 *) h;
  auto hnew = (TH2 *) h2 -> Clone();
  hnew -> Reset();
  auto nx=h2->GetXaxis()->GetNbins();
  auto ny=h2->GetYaxis()->GetNbins();
  for (auto binx=1;binx<=nx;++binx) {
    for (auto biny=1;biny<=ny;++biny) {
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      if(cut->IsInside(x,y)==1 || orcut->IsInside(x,y)) {
        //hnew->SetBinContent(binx,biny,h2->GetBinContent(binx,biny));
        Int_t n=h2->GetBinContent(binx,biny);
        for (auto i=0;i<n;++i)
          hnew->Fill(x,y);
      }
    }
  }
  return (TH1 *) hnew;
}

TH1 *style::cutg_and(TH1 *h, TCutG *cut, TCutG *andcut) {
  auto h2 = (TH2 *) h;
  auto hnew = (TH2 *) h2 -> Clone();
  hnew -> Reset();
  auto nx=h2->GetXaxis()->GetNbins();
  auto ny=h2->GetYaxis()->GetNbins();
  for (auto binx=1;binx<=nx;++binx) {
    for (auto biny=1;biny<=ny;++biny) {
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      if(cut->IsInside(x,y)==1 && andcut->IsInside(x,y)) {
        //hnew->SetBinContent(binx,biny,h2->GetBinContent(binx,biny));
        Int_t n=h2->GetBinContent(binx,biny);
        for (auto i=0;i<n;++i)
          hnew->Fill(x,y);
      }
    }
  }
  return (TH1 *) hnew;
}

TH1 *style::inv(TH1 *h) {
  auto h2 = (TH2 *) h;
  auto nx=h2->GetXaxis()->GetNbins();
  auto xl=h2->GetXaxis()->GetBinLowEdge(1);
  auto xh=h2->GetXaxis()->GetBinUpEdge(nx);
  auto ny=h2->GetYaxis()->GetNbins();
  auto yl=h2->GetYaxis()->GetBinLowEdge(1);
  auto yh=h2->GetYaxis()->GetBinUpEdge(ny);
  TString name = TString(h2->GetName())+"_Inv";
  TString title = Form("%s;%s;%s",firstname(h2->GetTitle(),";").Data(),h2->GetYaxis()->GetTitle(),h2->GetXaxis()->GetTitle());
  auto hnew = new TH2D(name,title,ny,yl,yh,nx,xl,xh);
  for (auto binx=1;binx<=nx;++binx)
    for (auto biny=1;biny<=ny;++biny) {
      //hnew->SetBinContent(biny,binx,h2->GetBinContent(binx,biny));
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      Int_t n=h2->GetBinContent(binx,biny);
      for (auto i=0;i<n;++i)
        hnew->Fill(y,x);
    }
  return make((TH1 *)hnew);
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
  if(str.Index(delim)<=0)
    return TString();
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
