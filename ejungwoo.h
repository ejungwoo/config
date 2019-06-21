/** ROOT ejungwoo macros
 *
 * - HOW TO USE
 *
 * #include "ejungwoo.h"
 * using namespace ejungwoo;
 */

#ifndef EJUNGWOO_H
#define EJUNGWOO_H

#include <vector>
#include <iostream>
#include <fstream>

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

namespace ejungwoo
{
  void v(int verbose=1); ///< verbosity "fVerbose" - 0:silent, 1:default
  void g(int graphic=1); ///< graphic verbosity "fVerboseG" - 0:silent(default), 1:draw-details
  void o(int goption=1);

  void dark(bool dm = true); ///< dark mode

  TFile *gfile(TString filename); ///< save graphic if fVerboseG>1

  bool isfile(TString filename); ///< does this file exist?

  void gstat (int opt); ///< equalivant to gStyle->SetOptStat(opt);
  void gstat (Option_t *opt);
  void fstat (int opt); ///< equalivant to gStyle->SetOptFit(opt);
  void zcolor(int opt); ///< set z-palette color to 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale

  void colorwheel(); ///< show colorwheel
  void markers();    ///< show markers
  void colorlist();

  Color_t colori(Int_t icolor);

  TCanvas *cv1 (TString nm="",double w=0,double h=0,TString l=""); ///<  500 x 550 for 1D
  TCanvas *cv2 (TString nm="",double w=0,double h=0,TString l=""); ///<  600 x 550 for 1D
  TCanvas *cv3 (TString nm="",double w=0,double h=0,TString l=""); ///<  680 x 550 for 1D
  TCanvas *cv  (TString nm="",double w=0,double h=0,TString l="") { return cv2(nm,w,h,l); } ///< cv1 equavalent
  TCanvas *cc1 (TString nm="",double w=0,double h=0,TString l=""); ///<  600 x 550 for 2D
  TCanvas *cc2 (TString nm="",double w=0,double h=0,TString l=""); ///<  680 x 550 for 2D
  TCanvas *cc3 (TString nm="",double w=0,double h=0,TString l=""); ///<  900 x 550 for 2D
  TCanvas *cc4 (TString nm="",double w=0,double h=0,TString l=""); ///< 1200 x 800 for 2D
  TCanvas *cc  (TString nm="",double w=0,double h=0,TString l="") { return cc1(nm,w,h,l); } ///< cc1 equavalent

  TCanvas *cv1 (TString l,TString nm,double w=0,double h=0) { return cv1 (nm,w,h,l); } ///< cv1 equavalent with log option as 1'st parameter
  TCanvas *cv2 (TString l,TString nm,double w=0,double h=0) { return cv2 (nm,w,h,l); } ///< cv2 equavalent with log option as 1'st parameter
  TCanvas *cv3 (TString l,TString nm,double w=0,double h=0) { return cv3 (nm,w,h,l); } ///< cv3 equavalent with log option as 1'st parameter
  TCanvas *cv  (TString l,TString nm,double w=0,double h=0) { return cv  (nm,w,h,l); } ///< cv  equavalent with log option as 1'st parameter
  TCanvas *cc1 (TString l,TString nm,double w=0,double h=0) { return cc1 (nm,w,h,l); } ///< cc1 equavalent with log option as 1'st parameter
  TCanvas *cc2 (TString l,TString nm,double w=0,double h=0) { return cc2 (nm,w,h,l); } ///< cc2 equavalent with log option as 1'st parameter
  TCanvas *cc3 (TString l,TString nm,double w=0,double h=0) { return cc3 (nm,w,h,l); } ///< cc3 equavalent with log option as 1'st parameter
  TCanvas *cc4 (TString l,TString nm,double w=0,double h=0) { return cc4 (nm,w,h,l); } ///< cc4 equavalent with log option as 1'st parameter
  TCanvas *cc  (TString l,TString nm,double w=0,double h=0) { return cc  (nm,w,h,l); } ///< cc  equavalent with log option as 1'st parameter

  TCanvas *div (TCanvas *c,Int_t nx,Int_t ny,Float_t xm=0.001,Float_t ym=0.001,Int_t color=0); ///< Divide canvas
  TCanvas *div0(TCanvas *c,Int_t nx,Int_t ny); ///< Divide canvas with no margins no gaps

     TObject *make (TObject *ob);      ///< make object stylish!,            jumpto_makeo
      TGraph *make (TGraph *gr);       ///< make graph stylish!,             jumpto_makeg
TGraphErrors *make (TGraphErrors *gr); ///< make error graph stylish!,       jumpto_makege
         TF1 *make (TF1 *f);           ///< make function stylish!,          jumpto_makef

         TH1 *make (Int_t s, TH1 *h);  ///< make histogram stylish! (s)bigger!, jumpto_maken
         TH1 *make (TH1 *h);           ///< make histogram stylish!,         jumpto_makeh
         TH1 *make2(TH1 *h);           ///< make histogram stylish! bigger!, jumpto_makeh2

   TPaveText *make (TPaveText *pave);            ///< make pave text stylish!, jumpto_makep
     TCanvas *make (TCanvas *cvs, TString l=""); ///< make canvas stylish!,    jumpto_makec

     TLegend *make (TLegend *legend, Double_t dx=0, Double_t dy=0);  ///< make legend stylish!,        jumpto_makel
     TLegend *make2(TLegend *legend, Double_t dx=0, Double_t dy=0);  ///< make legend stylish! bigger! jumpto_makel2

  TF1 *settitle(TF1 *f, TString title); ///< set title of function histogram

  TH1 *tohist(Double_t *buffer, Int_t n, TString name = "", TString title = ""); ///< make histogram with given buffer
  TH1 *tohist(Double_t *buffer, Int_t i, Int_t f, TString name = "", TString title = ""); ///< make histogram with given buffer in range i->f

  TGraphErrors *tograph(TString filename);

  TCutG *cutg (TString f, TString cutname, TString x, TString y); ///< set TCutG from file name
  TCutG *cutg (TFile  *f, TString cutname, TString x, TString y); ///< set TCutG from file

  TH1   *cutg    (TH1 *h, TCutG *cut); ///< recreate histogram with given graphical cut
  TH1   *cutg_or (TH1 *h, TCutG *cut, TCutG *orcut);
  TH1   *cutg_and(TH1 *h, TCutG *cut, TCutG *andcut);

  TH1 *inv(TH1 *h); ///< recreate histogram from "x vs y" to "y to x"
  TH1 *dndx(TH1 *h); ///< make graph y axis to dn/dx where n is number of entries
  TH1 *norm_max(TH1 *h, Double_t maxto = 1); ///< normalize maximum value of histogram to maxto(=1 by default)
  TH1 *norm_integral(TH1 *h, Double_t normto = 1); ///< normalize integral value of histogram to normto(=1 by default)

  void version(TString v); ///< if version is set, fVersion is used instead of doing verson control.
  TString version(); ///< return version

  void fig(TString name);

  void fsave(bool val); ///< set save canvas by save(TCanvas *)
  void  save(TVirtualPad *cvs, TString format="pdf", bool version_control = true); ///< save TVirtualPad. See as save(TCanvas *) for detail
  void  save(TCanvas *cvs, TString format="pdf", bool version_control = true); ///< save cavans ./figures/[canvas name].[version-automatically updated].[format]
  void  save(TString name, TCanvas *cvs, TString format="pdf", bool version_control = true); ///< save cavans ./figures/[name].[version-automatically updated].[format]

  void fwrite(bool val); ///< set write object by write(TObject *)
  void  write(TObject *obj, bool version_control = true); ///< write object ./data/[obj name].[version-automatically updated].root
  void  write(TString name, TNamed *obj, bool version_control = true); ///< write to file with name 'name'

  TGraph *sumf(std::vector<TF1*> &fs); ///< TODO create TF1 which is sum of TF1s in fs;

  TF1 *fitg (TH1 *h, Double_t c=2.5, Option_t *opt="RQ0"); ///< single gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *fitgg(TH1 *h, Double_t c=2.5, Option_t *opt="RQ0"); ///< double gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *fitng(Int_t n, TH1 *h, Double_t c=2.5, Option_t *opt="RQ0"); ///< n gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1    *gg(TF1 *f, Int_t i); ///< get i'th gaussian from multipule gaussian function f1

  void drawgg(TF1 *f, Option_t *opt="samel"); ///< Draw n-gaussian separately

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
      void print() { std::cout<<"n:"<<n<<"| xy:"<<x<<", "<<y<<"| dxy:"<<dx<<", "<<dy<<"| ddxy:"<<ddx<<", "<<ddy<<std::endl; }
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

  class drawing : public TObject {
    public:
      drawing(TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0)
      : fObj(obj), fOpt(opt), fType0(type0), fType1(type1), fType2(type2), fType3(type3) {}

      virtual void Draw(Option_t *opt="") {
        auto sopt = TString(opt);
             if (sopt.Index("t0")>=0&&!fType0) {std::cout<<fObj->GetName()<<" is not type0, therefore, omitted."<<std::endl;}
        else if (sopt.Index("t1")>=0&&!fType1) {std::cout<<fObj->GetName()<<" is not type1, therefore, omitted."<<std::endl;}
        else if (sopt.Index("t2")>=0&&!fType2) {std::cout<<fObj->GetName()<<" is not type2, therefore, omitted."<<std::endl;}
        else if (sopt.Index("t3")>=0&&!fType3) {std::cout<<fObj->GetName()<<" is not type3, therefore, omitted."<<std::endl;}
        else
          fObj->Draw(fOpt.Data());
      }

      TObject *fObj;
      TString fOpt;
      Bool_t fType0 = 0;
      Bool_t fType1 = 0;
      Bool_t fType2 = 0;
      Bool_t fType3 = 0;
  };

  class acanvas : public TObjArray {
    public:
      acanvas(TString name) { SetName(name); }
      void add(TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0) {
        if (opt.IsNull()&&GetEntries()!=0)
          opt="same";
        auto drawingo = new drawing(obj,opt,type0,type1,type2,type3);

        TString className = obj->ClassName();
        if (fFrameType==0) {
               if (className.Index("TH1")==0) fFrameType = 1;
          else if (className.Index("TH2")==0) fFrameType = 2;
        }

        ejungwoo::make(obj);
        TObjArray::Add(drawingo);
      }

      TCanvas *draw(TString opt="cvs") {
        if (opt.Index("cvs")>=0) {
          opt.ReplaceAll("cvs","");
          TCanvas *cvs = nullptr;
          if (fFrameType==2) cvs = cc(fName);
          else cvs = cv(fName);
        }
        Draw(opt);
        return (TCanvas *) gPad;
      }

      Int_t fFrameType = 0;
  };

  void add(                TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);
  void addto(int i,        TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);
  void addto(TString name, TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);
  void addto(acanvas *acv, TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);
  void draw(int i,TString opt="cvs");
  void draw(TString name,TString opt="cvs");
  void draw(const char* opt="cvs") { draw(0,opt); }


  /**
   * fit 2d histogram through x with given parameters and return list of histogram data
   * @param nDivision division number through x
   * @param c fit will perform in range of -c*sigma ~ c*sigma
   * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
   *
   * the histograms are written to fSaveGFile is g(2) is used,
   * fSaveGFile can be set by gfile(name) method.
   */
  TObjArray *fitgsx_list(TH1 *hist, Int_t nDivision=20, Double_t c=1.5, Int_t entry_cut=1000);
  /**
   * fit 2d histogram through y with given parameters and return list of histogram data
   * @param nDivision division number through y
   * @param c fit will perform in range of -c*sigma ~ c*sigma
   * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
   *
   * the histograms are written to fSaveGFile is g(2) is used,
   * fSaveGFile can be set by gfile(name) method.
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

  TH1 *tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1); ///< simple tree projection starting with tree, jumpto_tp0
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,const Double_t *xbins); ///< simple tree projection starting with name using xbins for x-axis, jumpto_tp1
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1); ///< simple tree projection starting with name, jumpto_tp2
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut="",TString title="",int nx=-1,int ny=-1); ///< tree projection with automatic bin range calculation default nx, ny is 200, jumpto_tp3
  /**
   * tree projection from tree with cuts
   * return array of histograms with applied cut
   *
   * cuts are used to create several histograms
   * using global "g" verbose to
   * - g(1) : draw histograms with applied cut
   * - g(2) : draw histograms with applied cut and save in .pdf
   *
   * jumpto_tp4
   */
  TObjArray *tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title,int nx,Double_t x1,Double_t x2,int ny=-1,Double_t y1=-1,Double_t y2=-1);
  /**
   * tree projection from tree with automatic bin range calculation with cuts
   * return array of histograms with applied cut
   *
   * cuts are used to create several histograms
   * using global "g" verbose to
   * - g(1) : draw histograms with applied cut
   * - g(2) : draw histograms with applied cut and save in .pdf
   *
   * jumpto_tp5
   */
  TObjArray *tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title="",int nx=-1,int ny=-1);

     Int_t max (Int_t *buffer, Int_t n); ///< get maximum value of buffer
  Double_t max (Double_t *buffer, Int_t n); ///< get maximum value of buffer
  Double_t max (TH1 *h); ///< get maximum value of histogram
  Double_t max (TH1 *h, Int_t &bin, Double_t &x); ///< get maximum value of histogram

  /**
   * calculate and return full width [ratio] maximum of function
   * the width is calculated at y which the data becomes [ratio] of maximum (=ratio*maximum)
   *
   * @param ratio width of function to be calculated at y=[ratio]*maximum 
   * @param ndx   set number of x-points to be created. larger ndx -> better quality q
   * @param x0    lower range value of x will be given
   * @param x1    upper range value of x will be given
   * @param q     quality of the fwrm
   */
  Double_t fwrm(TF1 *f, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q);
  Double_t fwhm(TF1 *f, Double_t &x0, Double_t &x1, Double_t &q); ///< FWHM(Full Width Half Maximum) of function. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q);
  Double_t fwhm(TF1 *f); ///< FWHM(Full Width Half Maximum) with function. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q) with no pull values

  /**
   * calculate and return full width [ratio] maximum of histogram
   * the width is calculated at y which the data becomes [ratio] of maximum (=ratio*maximum)
   *
   * @param ratio width of histogram to be calculated at y=[ratio]*maximum 
   * @param ndx   set number of x-points to be created. larger ndx -> better quality q
   * @param x0    lower range value of x will be given
   * @param x1    upper range value of x will be given
   * @param q     quality of the fwrm
   */
  Double_t fwrm(TH1 *h, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q); ///< full width [ratio] maximum : return width of histogram at y which the data becomes [ratio] of maximum (ratio*maximum)
  Double_t fwhm(TH1 *h, Double_t &x0, Double_t &x1, Double_t &q); ///< FWHM(Full Width Half Maximum) of histogram. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q);
  Double_t fwhm(TH1 *h); ///< FWHM(Full Width Half Maximum) with histogram. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q) with no pull values

  void pfname(TString str, TString &pathname, TString &filename, TString delim="/"); ///< get pathname=[path-name], filename=[file-name] after tonizing with delim
  TString firstname(TString str, TString delim="."); ///< get first name
  TString lastname(TString str, TString delim="/"); ///< get last name
  TString justname(TString str); ///< get name with no path and format. just name

  /********************************************************/

  void axisd(Int_t nd=506); ///< make axis ndivisions to nd!, (root default 510, default 508, axisd default 506 for TGraph2D)
  TH1 *free (TH1 *h); ///< make axis labels feel free!

  void cutt(Double_t r=0.04); ///< cut top margin to r=(0.04)
  void cutr(Double_t r=0.02); ///< cut right margin to r=(0.02)
  void cuttr(Double_t r=0.02); ///< cut right margin to r=(0.02)
  void cutall(Double_t r=0.02); ///< cut all margin to r=(0.02)

  /********************************************************/

  void init(); ///< Initialize gStyle setting. Should NOT be run by users.

  /********************************************************/

    bool fSave=true;
    bool fWrite=true;
     int fVerbose=1;
     int fVerboseG=0;
     int fGbOption=0;
    int fDefaultMake = 1;

    bool fDarkMode=false;

     int fNumColors=27;

 Color_t fColorList[] = {
   kBlue-4,   kBlue,     kBlue+1,   kAzure+7,
   kRed-4,    kRed,      kRed+1,
   kPink-2,   kPink+7,   kPink+3,
   kSpring+7, kSpring-5, kSpring-6,
   kCyan+1,   kCyan+2,   kCyan+3,
   kYellow,
   kOrange,   kOrange-3, kOrange+8, kOrange+6, kOrange-4, 
   kTeal+5,   kTeal+3,
   kViolet-5, kViolet-6, kViolet+4};

 TFile *fSaveGFile=nullptr;

 TString fVersion="";
 TString fFigDirName="figures";

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
  //double fWUnit=0.012;
  double fHUnit=0.05;

  double fWDefault2=0.2;
  double fWUnit2=0.010;
  double fHUnit2=0.07;

  double fWStat=0.25;
  double fHStat=0.18;
  double fXStat=0.95;
  double fYStat=0.88;

  double fTMargin=0.12;
  double fBMargin=0.16;
  double fLMargin=0.19;
  double fRMargin=0.055;
  double fRMarginH1=0.055;
  double fRMarginH2=0.155;

  double fMainTitleSize=0.08;
  double fAxisTitleSizes[]={0.05,0.065,0.09,0.11};
  double fAxisLabelSizes[]={0.045,0.05 ,0.07,0.09};
  double fXTitleOffsets[]= {1.30,1.15, 0.80,0.80};
  double fYTitleOffsets[]= {1.90,1.45, 1.10,1.00};

  int fDefaultFont=132;

  int fNDivisions=508;
  int fNDivisions2=506;

  TObjArray *fFileArray;
  TObjArray *fACanvasArray;
}; 

void ejungwoo::v(int verbose=1) { fVerbose=verbose; }
void ejungwoo::g(int verbose=1) { fVerboseG=verbose; }
void ejungwoo::o(int goption=1) { fGbOption=goption; }

void ejungwoo::dark(bool dm = true) { fDarkMode = dm; }

void ejungwoo::gstat(int opt) {
  gStyle->SetOptStat(opt);
}

void ejungwoo::gstat(Option_t *opt) {
  gStyle->SetOptStat(opt);
}

void ejungwoo::fstat(int opt) {
  gStyle->SetOptFit(opt);
}

void ejungwoo::zcolor(int opt) {
  if(fVerbose>0) std::cout<<"zcolor("<<opt<<") >> 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale"<<std::endl;
       if(opt == 0) gStyle->SetPalette(kBird);
  else if(opt == 1) gStyle->SetPalette(kRainBow);
  else if(opt == 2) gStyle->SetPalette(kDeepSea);
  else if(opt == 3) gStyle->SetPalette(kAvocado);
  else if(opt == 4) gStyle->SetPalette(kBlueGreenYellow);
  else if(opt == 5) gStyle->SetPalette(kBrownCyan);
  else if(opt == 6) gStyle->SetPalette(kLightTemperature);
  else              gStyle->SetPalette(kGreyScale);
}

void ejungwoo::colorwheel() {
  TColorWheel *w=new TColorWheel();
  w->SetCanvas(cv("cw",700,700));
  w->Draw();
}

void ejungwoo::markers() {
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

void ejungwoo::colorlist() {
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
      auto m = new TMarker(x,y,20);
      m -> SetMarkerSize(3.5);
      m -> SetMarkerColor(colori(i));
      auto t = new TText(x,y-0.42,Form("%d",i));
      t -> SetTextSize(0.035);
      t -> SetTextAlign(22);
      m -> Draw();
      t -> Draw();
      i++;
      if (i>=fNumColors)
        return;
    }
  }
}

Color_t ejungwoo::colori(Int_t icolor)
{
  icolor = icolor - fNumColors*(icolor/fNumColors);
  return fColorList[icolor];
}

TGraph *ejungwoo::sumf(std::vector<TF1*> &fs)
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

Int_t ejungwoo::max(Int_t *buffer, Int_t n)
{
  Int_t val = -INT_MAX;
  for (auto i=0; i<n; ++i)
    if(buffer[i] > val)
      val = buffer[i];
  return val;
}

Double_t ejungwoo::max(Double_t *buffer, Int_t n)
{
  Double_t val = -DBL_MAX;
  for (auto i=0; i<n; ++i)
    if(buffer[i] > val)
      val = buffer[i];
  return val;
}

Double_t ejungwoo::max(TH1 *h) {
  Int_t bin;
  Double_t x;
  return max(h, bin, x);
}

Double_t ejungwoo::max (TH1 *h, Int_t &bin, Double_t &x) {
  bin=h->GetMaximumBin();
  x=h->GetXaxis()->GetBinCenter(bin);
  return h->GetBinContent(bin);
}

Double_t ejungwoo::fwrm(TF1 *f, Double_t ratio, Double_t nx, Double_t &x0, Double_t &x1, Double_t &q)
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
      if(fVerbose>0) std::cout<<"(valmax,xmax)=("<<valmax<<","<<xmax<<")"<<std::endl;
    }
  }
  auto rmax=ratio*valmax;

  double dy1=DBL_MAX, dy0=DBL_MAX;

  if(fVerbose>0) std::cout<<"=================================="<<std::endl;
  for (x=xmax;x<=xh;x+=dx) {
    auto y=f->Eval(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy1) {
      x1=x-dx;
      if(fVerbose>0) std::cout<<"x1="<<x1<<std::endl;
      break;
    }
    dy1=dy;
  }
  if(x==xh) {
    if(fVerbose>0) std::cout<<"x==xh ROOT NOT FOUND"<<std::endl;
    q=-1; x0=-1; x1=-1; return -1;
  }
  if(fVerbose>0) std::cout<<"=================================="<<std::endl;

  for (x=xmax;x>=xl;x-=dx) {
    auto y=f->Eval(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy0) {
      x0=dx;
      if(fVerbose>0) std::cout<<"x0="<<x1<<std::endl;
      break;
    }
    dy0=dy;
  }
  if(x==xl) {
    if(fVerbose>0) std::cout<<"x==xl ROOT NOT FOUND"<<std::endl;
    q=-1; x0=-1; x1=-1; return -1;
  }
  if(fVerbose>0) std::cout<<"=================================="<<std::endl;

  q=TMath::Sqrt(dy0*dy0 + dy1*dy1);

  return x1-x0;
}

Double_t ejungwoo::fwhm(TF1 *f, Double_t &x0, Double_t &x1, Double_t &q)
{
  return fwrm(f, 0.5, 10000, x0, x1, q);
}

Double_t ejungwoo::fwhm(TF1 *f)
{
  Double_t x0, x1 ,q;
  return fwhm(f, x0, x1, q);
}

Double_t ejungwoo::fwrm(TH1 *h, Double_t ratio, Double_t ndx, Double_t &x0, Double_t &x1, Double_t &q)
{
  if(fVerbose>0) std::cout<<"assuming histogram "<<h->GetName()<<" is smooth"<<std::endl;

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
    std::cout<<"binmax = "<<binmax<<std::endl;
    std::cout<<"xmax = "<<xmax<<std::endl;
    std::cout<<"n  = "<<n<<std::endl;
    std::cout<<"xl = "<<xl<<std::endl;
    std::cout<<"xh = "<<xh<<std::endl;
    std::cout<<"nn = "<<nn<<std::endl;
  }

  double x, dy1=DBL_MAX, dy0=DBL_MAX;
  for (x=xmax;x<=xh;x+=nn) {
    if(fVerbose>0) std::cout<<x<<std::endl;
    auto y=hist->Interpolate(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy1) {
      x1=x-nn;
      if(fVerbose>0) std::cout<<"x1="<<x1<<std::endl;
      break;
    }
    dy1=dy;
  }
  if(x==xh) {
    q=-1; x0=-1; x1=-1; return -1;
    if(fVerbose>0) std::cout<<"x==xh ROOT NOT FOUND"<<std::endl;
  }
  if(fVerbose>0) std::cout<<"=================================="<<std::endl;

  for (x=xmax;x>=xl;x-=nn) {
    auto y=hist->Interpolate(x);
    auto dy=TMath::Abs(y-rmax);
    if(dy>dy0) {
      x0=x+nn;
      if(fVerbose>0) std::cout<<"x0="<<x1<<std::endl;
      break;
    }
    dy0=dy;
  }
  if(x==xl) {
    q=-1; x0=-1; x1=-1; return -1;
    if(fVerbose>0) std::cout<<"x==xh ROOT NOT FOUND"<<std::endl;
  }
  if(fVerbose>0) std::cout<<"=================================="<<std::endl;

  q=TMath::Sqrt(dy0*dy0 + dy1*dy1);

  return x1-x0;
}

Double_t ejungwoo::fwhm(TH1 *h, Double_t &x0, Double_t &x1, Double_t &q)
{
  return fwrm(h, 0.5, 0.1, x0, x1, q);
}

Double_t ejungwoo::fwhm(TH1 *h)
{
  Double_t x0, x1 ,q;
  return fwhm(h, x0, x1, q);
}

void ejungwoo::cutt(Double_t r) { fTMargin = r; }
void ejungwoo::cutr(Double_t r) { fRMarginH1 = r; fRMarginH2 = r; }
void ejungwoo::cuttr(Double_t r) { fTMargin = r; fRMarginH1 = r; fRMarginH2 = r; }
void ejungwoo::cutall(Double_t r) { fTMargin = r; fRMarginH1 = r; fRMarginH2 = r; fBMargin = r; fLMargin = r; }

void ejungwoo::init() {
  fXStat=1.-fRMargin;
  fYStat=1.-fTMargin;
  gStyle->SetStatStyle(0);
  gStyle->SetStatW(fWStat);
  gStyle->SetStatH(fHStat);
  gStyle->SetStatX(fXStat);
  gStyle->SetStatY(fYStat);
  gStyle->SetTitleFontSize(fMainTitleSize);

  gStyle -> SetLegendFont(fDefaultFont);
  gStyle -> SetStatFont(fDefaultFont);
}

TCanvas *ejungwoo::cv1(TString name,double w,double h,TString logs) {
  fRMargin=fRMarginH1;
  init();
  if(w==0) w=fWC1;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs,logs); ++fICvs;
  return cvs;
}

TCanvas *ejungwoo::cv2(TString name,double w,double h,TString logs) {
  fRMargin=fRMarginH1;
  init();
  if(w==0) w=fWC2;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs,logs); ++fICvs;
  return cvs;
}

TCanvas *ejungwoo::cv3(TString name,double w,double h,TString logs) {
  fRMargin=fRMarginH1;
  init();
  if(w==0) w=fWC3;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs,logs); ++fICvs;
  return cvs;
}

TCanvas *ejungwoo::cc3(TString name,double w,double h,TString logs) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWCC2;
  if(h==0) h=fHCC2;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs,logs); ++fICvs;
  return cvs;
}

TCanvas *ejungwoo::cc4(TString name,double w,double h,TString logs) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWCC3;
  if(h==0) h=fHCC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs,logs); ++fICvs;
  return cvs;
}

TCanvas *ejungwoo::cc1(TString name,double w,double h,TString logs) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWC2;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs,logs); ++fICvs;
  return cvs;
}

TCanvas *ejungwoo::cc2(TString name,double w,double h,TString logs) {
  fRMargin=fRMarginH2;
  init();
  if(w==0) w=fWC3;
  if(h==0) h=fHC3;
  if(name.IsNull()) name=Form("canvas-%d",fICvs);
  auto cvs=new TCanvas(name,name,(fICvs+1)*20,(fICvs+1)*20+fYCvs,w,h);
  make(cvs,logs); ++fICvs;
  return cvs;
}

TCanvas *ejungwoo::div(TCanvas *c,Int_t nx,Int_t ny,Float_t xm,Float_t ym,Int_t color)
{
  c->Divide(nx,ny,xm,ym,color);
  for (auto i=1; i<=nx*ny; ++i)
    c->cd(i)->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);
  return c;
}

TCanvas *ejungwoo::div0(TCanvas *c,Int_t nx,Int_t ny)
{
  // TODO
  c->Divide(nx,ny,0,0);
  for (auto ix=1; ix<=nx; ++ix) {
    for (auto iy=1; iy<=ny; ++iy) {
      auto i = ix + nx*(iy-1);
      if (iy==1&&iy==ny) {
             if (ix==1)  c->cd(i)->SetMargin(fLMargin,       0,fBMargin,fTMargin);
        else if (ix==nx) c->cd(i)->SetMargin(       0,fRMargin,fBMargin,fTMargin);
        else             c->cd(i)->SetMargin(       0,       0,fBMargin,fTMargin);
      }
      else if (iy==1) {
        if (ix==1&&ix==nx) c->cd(i)->SetMargin(fLMargin,fRMargin,0,fTMargin);
        else if (ix==1)    c->cd(i)->SetMargin(fLMargin,       0,0,fTMargin);
        else if (ix==nx)   c->cd(i)->SetMargin(       0,fRMargin,0,fTMargin);
        else               c->cd(i)->SetMargin(       0,       0,0,fTMargin);
      }
      else if (iy==ny) {
        if (ix==1&&ix==nx) c->cd(i)->SetMargin(fLMargin,fRMargin,fBMargin,0);
        else if (ix==1)    c->cd(i)->SetMargin(fLMargin,       0,fBMargin,0);
        else if (ix==nx)   c->cd(i)->SetMargin(       0,fRMargin,fBMargin,0);
        else               c->cd(i)->SetMargin(       0,       0,fBMargin,0);
      }
      else c->cd(i)->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);
    }
  }
  return c;
}

TObject *ejungwoo::make(TObject *ob) { //jumpto_makeo
  if(ob->InheritsFrom("TGraph"))  make((TGraph*)ob);
  if(ob->InheritsFrom("TGraphErrors"))  make((TGraphErrors*)ob);
  if(ob->InheritsFrom("TH1"))     make((TH1*)ob);
  if(ob->InheritsFrom("TF1"))     make((TF1*)ob);
  if(ob->InheritsFrom("TLegend")) make((TLegend*)ob);
  if(ob->InheritsFrom("TPaveText")) make((TLegend*)ob);
  if(ob->InheritsFrom("TCanvas")) make((TCanvas*)ob);
  return ob;
}

TCanvas *ejungwoo::make(TCanvas *cvs,TString logs) { //jumpto_makec
  cvs -> Modified();
  cvs -> Update();

  if (fDarkMode) cvs -> SetFillColor(kGray);

  cvs->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);
  logs.ToLower();
  if (logs.Index("x")>=0) cvs -> SetLogx();
  if (logs.Index("y")>=0) cvs -> SetLogy();
  if (logs.Index("z")>=0) cvs -> SetLogz();

  auto pmtvs=cvs->GetListOfPrimitives();
  if (pmtvs!=nullptr)
  {
    auto pvtt=(TPaveText*)pmtvs->FindObject("title");
    if (pvtt!=nullptr) pvtt->SetTextFont(fDefaultFont);

    TObject *obj2;
    TIter next(pmtvs);
    while ((obj2 = next())) {
      //make(obj2);
      if (obj2->InheritsFrom(TPad::Class())) {
        auto innercvs=(TPad*)obj2;
        if (fDarkMode) innercvs -> SetFillColor(kGray);
        innercvs -> Modified();
        innercvs -> Update();
        auto pmtvs2=innercvs->GetListOfPrimitives();
        auto pvtt2=(TPaveText*)pmtvs2->FindObject("title");
        if (pvtt2!=nullptr) pvtt2->SetTextFont(fDefaultFont);
        innercvs -> Modified();
        innercvs -> Update();

        TObject *obj3;
        TIter next2(pmtvs2);
        while ((obj3 = next2())) {
          //make(obj3);
          if (obj3->InheritsFrom(TPad::Class())) {
            auto innnercvs=(TPad*)obj3;
            if (fDarkMode) innnercvs -> SetFillColor(kGray);
            innnercvs -> Modified();
            innnercvs -> Update();
            auto pmtvs3=innnercvs->GetListOfPrimitives();
            auto pvtt3=(TPaveText*)pmtvs3->FindObject("title");
            if (pvtt3!=nullptr) pvtt3->SetTextFont(fDefaultFont);
            innnercvs -> Modified();
            innnercvs -> Update();
          }
        }
      }
    }
  }

  cvs -> Modified();
  cvs -> Update();
  return cvs;
}

TGraph *ejungwoo::make(TGraph *graph) { //jumpto_makeg
  init();
  if(graph->GetMarkerStyle()==1) {
    graph->SetMarkerStyle(20);
    //graph->SetMarkerSize(0.5);
    graph->SetMarkerSize(1);
  }
  make(graph->GetHistogram());
  return graph;
}

TGraphErrors *ejungwoo::make(TGraphErrors *graph) //jumpto_makege
{
  return (TGraphErrors *) make((TGraph *) graph);
}

TH1 *ejungwoo::make(Int_t s, TH1 *h) { //jumpto_maken
  init();
  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(fXTitleOffsets[s]);
  h->GetXaxis()->SetTitleSize(fAxisTitleSizes[s]);
  h->GetXaxis()->SetLabelSize(fAxisLabelSizes[s]);
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(fYTitleOffsets[s]);
  h->GetYaxis()->SetTitleSize(fAxisTitleSizes[s]);
  h->GetYaxis()->SetLabelSize(fAxisLabelSizes[s]);
  h->GetZaxis()->CenterTitle();
  //h->GetZaxis()->SetTitleOffset(fYTitleOffsets[s]);
  h->GetZaxis()->SetTitleSize(fAxisTitleSizes[s]);
  h->GetZaxis()->SetLabelSize(fAxisLabelSizes[s]);

  h->GetXaxis()->SetTitleFont(fDefaultFont);
  h->GetYaxis()->SetTitleFont(fDefaultFont);
  h->GetZaxis()->SetTitleFont(fDefaultFont);
  h->GetXaxis()->SetLabelFont(fDefaultFont);
  h->GetYaxis()->SetLabelFont(fDefaultFont);
  h->GetZaxis()->SetLabelFont(fDefaultFont);

  free(h);
  return h;
}

TH1 *ejungwoo::make(TH1 *h) { return ejungwoo::make(0,h); } //jumpto_makeh
TH1 *ejungwoo::make2(TH1 *h) { return ejungwoo::make(2,h); } //jumpto_makeh2 

TLegend *ejungwoo::make(TLegend *legend, Double_t dx, Double_t dy) { //jumpto_makel
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
  if (y1 < 0.5) y1 = 0.5;
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
  legend->SetTextFont(fDefaultFont);
  return legend;
}

TLegend *ejungwoo::make2(TLegend *legend, Double_t dx, Double_t dy) { //jumpto_makel2
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
  legend->SetTextFont(fDefaultFont);
  return legend;
}

TPaveText *ejungwoo::make(TPaveText *pave) { //jumpto_makep
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
  pave->SetTextFont(fDefaultFont);
  return pave;
}

TF1 *ejungwoo::make(TF1 *f) { //jumpto_makef
  make(f->GetHistogram());
  f->SetNpx(1000);
  return f;
}

TF1 *ejungwoo::settitle(TF1 *f, TString title)
{
  f -> GetHistogram() -> SetTitle(title);
  return f;
}

TGraphErrors *tograph(TString filename)
{
  //TODO
  std::ifstream file(filename);
  file.close();
  auto graph = new TGraphErrors();
  return graph;
}

TH1 *ejungwoo::tohist(Double_t *buffer, Int_t n, TString name, TString title)
{
  if(name.IsNull()) name=Form("hist-%d",fIHist);
  auto hist = new TH1D(name, title, n, 0, n+1);
  for (auto i = 0; i < n; ++i)
    hist -> SetBinContent(i+1,buffer[i]);
  ++fIHist;
  return make(fDefaultMake,hist);
}

TH1 *ejungwoo::tohist(Double_t *buffer, Int_t i, Int_t f, TString name, TString title)
{
  if(name.IsNull()) name=Form("hist-%d",fIHist);
  auto hist = new TH1D(name, title, f-i+1, i, f+1);
  for (auto bin = i; bin < f+1; ++bin)
    hist -> SetBinContent(bin+1-i,buffer[bin]);
  ++fIHist;
  return make(fDefaultMake,hist);
}

void ejungwoo::axisd(Int_t nd) { fNDivisions=nd; }

TH1 *ejungwoo::free(TH1 *h) {
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

TH1 *ejungwoo::dndx(TH1 *h)
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

TH1 *ejungwoo::norm_max(TH1 *h, Double_t maxto)
{
  auto hist = (TH1 *) h -> Clone();
  auto valmax = max(hist);
  auto nbins = hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin)
    hist -> SetBinContent(bin,hist->GetBinContent(bin)*maxto/valmax);
  hist -> SetTitle(Form(";%s;Normalized Max",h->GetXaxis()->GetTitle()));

  return hist;
}

TH1 *ejungwoo::norm_integral(TH1 *h, Double_t normto)
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

void ejungwoo::version(TString v) {
  fVersion = v;
  if(fVerbose>0) std::cout<<"fVersion=["<<fVersion<<"]"<<std::endl;
}

TString ejungwoo::version() { return fVersion; }

TFile *ejungwoo::gfile(TString filename) {
  if(filename.Index(".root")<0)
    filename=filename+".root";
  if(!fVersion.IsNull())
    filename.ReplaceAll(".root",TString(".")+fVersion+".root");

  if(fSaveGFile==nullptr)
    fSaveGFile = new TFile(filename,"recreate");
  return fSaveGFile;
}

bool ejungwoo::isfile(TString filename) {
  TString name=gSystem->Which(".",filename.Data());
  if (name.IsNull())
    return false;
  return true;
}

void ejungwoo::fsave(bool val) {
  fSave=val;
  if(fVerbose>0) {
    if(fSave) std::cout<<"fSave=true; TCanvas will be written by ejungwoo::save(TCanvas *) method."<<std::endl;
    else      std::cout<<"fSave=false; TCanvas will NOT!! be written by ejungwoo::save(TCanvas *) method."<<std::endl;
  }
}

void ejungwoo::fig(TString name) { fFigDirName = name; }

void ejungwoo::save(TVirtualPad *cvs, TString format, bool version_control) {
  save(((TCanvas *)cvs), format, version_control);
}

void ejungwoo::save(TCanvas *cvs, TString format, bool version_control) {
  if(!fSave) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/"+fFigDirName+"/";
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
    if(fVerbose>0&&version_idx%10==0) std::cout<<"[Warning] More than "<<version_idx<<" versions of "<<name<<"exist!"<<std::endl;
  }
}

void ejungwoo::save(TString name, TCanvas *cvs, TString format, bool version_control) {
  if(!fSave) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/"+fFigDirName+"/";
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
    if(fVerbose>0&&version_idx%10==0) std::cout<<"[Warning] More than "<<version_idx<<" versions of "<<name<<"exist!"<<std::endl;
  }
}

void ejungwoo::fwrite(bool val) {
  fWrite=val;
  if(fVerbose>0) {
    if(fWrite) std::cout<<"fWrite=true; TObject will be written by ejungwoo::write(TObject *) method."<<std::endl;
    else       std::cout<<"fWrite=false; TObject will NOT!! be written by ejungwoo::write(TObject *) method."<<std::endl;
  }
}

void ejungwoo::write(TObject *obj, bool version_control) {
  if(!fWrite) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/data/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString name=obj->GetName();
  TString full_name=name+".root";
  if(!fVersion.IsNull()) {
    full_name=name+"."+fVersion+".root";
    auto file = new TFile(path+full_name,"recreate");
    obj->Write();
    if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
    file->Close();
    return;
  }
  int version_idx=0;
  while (version_control) {
    char* c=gSystem->Which(path.Data(),full_name.Data());
    if(TString(c).IsNull()) {
      auto file = new TFile(path+full_name,"recreate");
      obj->Write();
      if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
      file->Close();
      return;
    }
    full_name=name+"."+TString::Itoa(++version_idx,10)+".root";
    if(fVerbose>0&&version_idx%10==0) std::cout<<"[Warning] More than "<<version_idx<<" versions of "<<full_name<<"exist!"<<std::endl;
  }
}

void ejungwoo::write(TString name, TNamed *obj, bool version_control = true){
  if(!fWrite) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/data/";
  gSystem->Exec(TString("mkdir -p ")+path);
  obj -> SetName(name);
  TString full_name=name+".root";
  if(!fVersion.IsNull())
    name=name+"."+fVersion;

  if(fFileArray == nullptr)
    fFileArray = new TObjArray();

  TFile *file = nullptr;
  for (auto i=0; i<fFileArray->GetEntries(); ++i)
  {
    auto file0 = (TFile *) fFileArray->At(i);
    if(TString(file0->GetName()).Index(name)>0) {
      file = file0;
      break;
    }
  }

  if(file!=nullptr) {
    obj->Write();
    if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<file->GetName()<<std::endl;
    return;
  }
  else {
    if(!fVersion.IsNull()) {
      full_name=name+".root";
      file = new TFile(path+full_name,"recreate");
      fFileArray->Add(file);
      obj->Write();
      if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
      return;
    }
    int version_idx=0;
    while (version_control) {
      char* c=gSystem->Which(path.Data(),full_name.Data());
      if(TString(c).IsNull()) {
        file = new TFile(path+full_name,"recreate");
        fFileArray->Add(file);
        obj->Write();
        if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
        return;
      }
      full_name=name+"."+TString::Itoa(++version_idx,10)+".root";
      if(fVerbose>0&&version_idx%10==0) std::cout<<"[Warning] More than "<<version_idx<<" versions of "<<full_name<<"exist!"<<std::endl;
    }
  }
}


TF1 *ejungwoo::fitg(TH1 *h,Double_t c,Option_t *opt) {
  if(fVerbose>1) {
    if(!TString(opt).IsNull()) std::cout<<"fg "<<h->GetName()<<": ["<<c<<"-sigma],[o:"<<TString(opt)<<"]->";
    else                       std::cout<<"fg "<<h->GetName()<<": ["<<c<<"-sigma]->";
  }
  auto binmax=h->GetMaximumBin();
  auto max=h->GetBinContent(binmax);
  auto xmax=h->GetXaxis()->GetBinCenter(binmax);
  auto xerr=h->GetStdDev();
  auto f=new TF1(Form("%s_fitg",h->GetName()),"gaus(0)",xmax-xerr*c,xmax+xerr*c);
  f->SetParameters(max,xmax,xerr);
  h->Fit(f,opt);
  xmax=f->GetParameter(1);
  xerr=f->GetParameter(2);

  Int_t fitcount = 1;
  Double_t xerr2 = 0.;
  while (fitcount<20&&TMath::Abs(xerr-xerr2)/xerr>0.2) {
    xerr2=xerr;
    f->SetRange(xmax-c*xerr2,xmax+c*xerr2);
    h->Fit(f,opt);
    xmax=f->GetParameter(1);
    xerr=f->GetParameter(2);
    ++fitcount;
  }

  if(fVerbose>1)std::cout<<"[a:"<<f->GetParameter(0)<<", m:"<<f->GetParameter(1)<<", s:"<<f->GetParameter(2)<<"] ("<<fitcount<<")"<<std::endl;
  return f;
}

TF1 *ejungwoo::fitgg(TH1 *h,Double_t c,Option_t *opt) {
  auto binmax=h->GetMaximumBin();
  auto max=h->GetBinContent(binmax);
  auto xmax=h->GetXaxis()->GetBinCenter(binmax);
  auto xerr=h->GetStdDev();

  auto f=new TF1("f1","gaus(0)+gaus(3)",xmax-xerr*c,xmax+xerr*c);
  f->SetParameters(0.8*max,xmax,0.5*xerr,0.2*max,xmax,1.5*xerr);
  h->Fit(f,opt);

  auto xmax1=f->GetParameter(1);
  auto xmax2=f->GetParameter(4);
  xmax=.5*(xmax1+xmax2);
  auto dxmax=abs(xmax1-xmax2);

  auto xerr1=f->GetParameter(2);
  auto xerr2=f->GetParameter(5);
  xerr=(xerr1>xerr2)?xerr1:xerr2;

  Int_t fitcount = 1;
  Double_t pxerr1 = 0.;
  Double_t pxerr2 = 0.;
  while (fitcount<10&&TMath::Abs(xerr2-pxerr1)/xerr2>0.2&&TMath::Abs(xerr2-pxerr2)/xerr2>0.2) {
    pxerr1=xerr1;
    pxerr2=xerr2;
    xerr=(xerr1>xerr2)?xerr1:xerr2;
    f->SetRange(xmax-.5*dxmax-c*xerr,xmax+.5*dxmax+c*xerr);
    h->Fit(f,opt);
    xmax1=f->GetParameter(1);
    xmax2=f->GetParameter(4);
    xmax=.5*(xmax1+xmax2);
    dxmax=abs(xmax1-xmax2);
    xerr1=f->GetParameter(2);
    xerr2=f->GetParameter(5);
    ++fitcount;
  }

  if(fVerbose>1) {
    std::cout<<"fitgg num-iteration:"<<fitcount<<std::endl;
    std::cout<<" [1 a:"<<f->GetParameter(0)<<", m:"<<f->GetParameter(1)<<", s:"<<f->GetParameter(2)<<"]"<< std::endl;
    std::cout<<" [2 a:"<<f->GetParameter(3)<<", m:"<<f->GetParameter(4)<<", s:"<<f->GetParameter(5)<<"]"<< std::endl;
  }

  f->SetLineColor(kBlack);

  return f;
}

TF1 *ejungwoo::fitng(Int_t n, TH1 *h,Double_t c,Option_t *opt) {
  if (n<1) return nullptr;
  else if (n==1) return fitg(h,c,opt);
  else if (n==2) return fitgg(h,c,opt);

  auto binmax=h->GetMaximumBin();
  auto max=h->GetBinContent(binmax);
  auto xmax0=h->GetXaxis()->GetBinCenter(binmax);
  auto xerr0=h->GetStdDev();

  TString expression;
  for (auto i=0; i<n; ++i) {
    if (i==0)
      expression += "gaus(0)";
    else
      expression += Form("+gaus(%d)",i*3);
  }

  auto f=new TF1(Form("f%dgaus",n),expression,xmax0-xerr0*c,xmax0+xerr0*c);

  for (auto i=0; i<n; ++i) {
    f->SetParameter(i*3+0, (1./n)*max);
    f->SetParameter(i*3+1, xmax0);
    f->SetParameter(i*3+2, .5*xerr0);
  }
  h->Fit(f,opt);

  std::vector<double> xmax;
  std::vector<double> xerr;
  std::vector<double> pxerr;

  for (auto i=0; i<n; ++i) {
    xmax.push_back(f->GetParameter(i*3+1));
    xerr.push_back(f->GetParameter(i*3+2));
    pxerr.push_back(0);
  }

  Int_t fitcount = 1;
  while (fitcount<10)
  {
    bool good_to_break = true;
    for (auto i=0; i<n; ++i) {
      if (TMath::Abs(xerr[i]-pxerr[i])/xerr[i]>0.2) {
        good_to_break = false;
        break;
      }
    }
    if (good_to_break)
      break;

    for (auto i=0; i<n; ++i)
      pxerr[i]=xerr[i];

    auto xerr_range=xerr[0];
    for (auto i=0; i<n; ++i)
      if (xerr_range<xerr[i])
        xerr_range=xerr[i];

    auto xmax_mean = 0;
    auto dxmax = 0;
    auto count = 0;
    for (auto i=0; i<n; ++i) {
      xmax_mean += xmax[i];
      for (auto j=0; j<n; ++j) {
        if (i==j || i>j)
          continue;
        dxmax += abs(xmax[i]-xmax[j]);
        ++count;
      }
    }
    xmax_mean = xmax_mean/n;
    dxmax = dxmax/count;

    f->SetRange(xmax_mean-.5*dxmax-c*xerr_range,xmax_mean+.5*dxmax+c*xerr_range);
    h->Fit(f,opt);

    xmax.clear();
    xerr.clear();
    for (auto i=0; i<n; ++i) {
      xmax.push_back(f->GetParameter(i*3+1));
      xerr.push_back(f->GetParameter(i*3+2));
    }

    ++fitcount;
  }

  if(fVerbose>1) {
    std::cout<<"fit"<<n<<"g num-iteration:"<<fitcount<<std::endl;
    for (auto i=0; i<n; ++i)
      std::cout<<" ["<<i<<" a:"<<f->GetParameter(i*3+0)<<", m:"<<f->GetParameter(i*3+1)<<", s:"<<f->GetParameter(i*3+2)<<"]"<< std::endl;
  }

  f->SetLineColor(kBlack);

  return f;
}

TF1 *ejungwoo::gg(TF1 *f1, Int_t i) {
  double min,max;
  f1->GetRange(min,max);
  auto f=new TF1(Form("%s_%d",f1->GetName(),i),"gaus(0)",min,max);
  f->SetParameters(f1->GetParameter(3*i),f1->GetParameter(3*i+1),f1->GetParameter(3*i+2));
  if(i==0) f->SetLineColor(kRed);
  else if(i==1) f->SetLineColor(kBlue);
  else if(i==2) f->SetLineColor(kGreen+1);
  else if(i==3) f->SetLineColor(kOrange+2);
  else if(i==4) f->SetLineColor(kCyan+2);
  else
    f->SetLineColor(kGray);
  return f;
}

void ejungwoo::drawgg(TF1 *f, Option_t *opt)
{
  Int_t np = f -> GetNpar();
  Int_t ng = Int_t(np/3);
  for (auto ig=0;ig<ng;++ig)
    gg(f,ig)->Draw(opt);
  f -> Draw(opt);
}

TH1D *ejungwoo::cutx(TH1 *h2, Int_t bin1, Int_t bin2) {
  TGraph graph;
  return cutx(h2,bin1,bin2,&graph);
}

TH1D *ejungwoo::cutx(TH1 *hist, Int_t bin1, Int_t bin2, TGraph *cut_area) {
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

void ejungwoo::add(TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  addto(0,obj, opt, type0, type1, type2, type3);
}
void ejungwoo::addto(acanvas *acvs, TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  acvs->add(obj, opt, type0, type1, type2, type3);
  if(fVerbose>0) std::cout<<"Drawing "<<obj->GetName()<<" to "<<acvs->GetName()<<std::endl;
  return;
}
void ejungwoo::addto(int i, TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  if(fACanvasArray==nullptr)
    fACanvasArray=new TObjArray();

  auto acvs=(acanvas *)fACanvasArray->At(i);
  if (acvs==nullptr) {
    acvs=new acanvas(Form("acvs%d",i));
    fACanvasArray->AddAt(acvs,i);
  }

  addto(acvs, obj, opt, type0, type1, type2, type3);
}
void ejungwoo::addto(TString name, TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  if(fACanvasArray==nullptr)
    fACanvasArray=new TObjArray();

  auto acvs=(acanvas *)fACanvasArray->FindObject(name);
  if (acvs==nullptr) {
    acvs=new acanvas(name);
    fACanvasArray->Add(acvs);
  }

  addto(acvs, obj, opt, type0, type1, type2, type3);
}
void ejungwoo::draw(int i,TString opt) {
  auto acvs=(acanvas*)fACanvasArray->At(i);
  if(acvs!=nullptr)
    acvs->draw(opt);
}
void ejungwoo::draw(TString name,TString opt) {
  auto acvs=(acanvas*)fACanvasArray->FindObject(name);
  if(acvs!=nullptr)
    acvs->draw(opt);
}

TObjArray *ejungwoo::fitgsx_list(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut) {
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
      ejungwoo::cv1();
      make(hp)->Draw();
      f1->Draw("same");
      if(fVerboseG>1&&fSaveGFile!=nullptr) {
        fSaveGFile->cd();
        hp->Write();
      }
    }

    auto hd=new ejungwoo::hdata(hp);
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

TObjArray *ejungwoo::fitgsy_list(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut) {
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
      ejungwoo::cv1();
      make(hp)->Draw();
      f1->Draw("same");
      if(fVerboseG>1&&fSaveGFile!=nullptr) {
        fSaveGFile->cd();
        hp->Write();
      }
    }

    auto hd=new ejungwoo::hdata(hp);
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

TGraphErrors *ejungwoo::fitgsx(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut, bool error_graph) {
  if(error_graph)
    return fitgsx(hist,"x","dy","dx/2","ddy",nDivision,c,entry_cut);
  return fitgsx(hist,"x","y","dx/2","dy",nDivision,c,entry_cut);
}

TGraphErrors *ejungwoo::fitgsy(TH1 *hist, Int_t nDivision, Double_t c, Int_t entry_cut, bool error_graph) {
  if(error_graph)
    return fitgsy(hist,"y","dx","ddx","",nDivision,c,entry_cut);
  return fitgsy(hist,"x","y","dx","dy/2",nDivision,c,entry_cut);
}

TGraphErrors *ejungwoo::fitgsx(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, Int_t nDivision, Double_t c, Int_t entry_cut) {
  auto h2 = (TH2 *) hist;
  auto graph=new TGraphErrors();
  auto array=fitgsx_list(h2,nDivision,c,entry_cut);
  if(fVerbose>1)
    std::cout << "graph info. " << xo << " " << yo << " " << xoe << " " << yoe << std::endl;
  for (auto i=0; i<array->GetEntries(); ++i) {
    auto h=(ejungwoo::hdata*)array->At(i);
    graph->SetPoint(i,h->get(xo),h->get(yo));
    graph->SetPointError(i,h->get(xoe),h->get(yoe));
    if(fVerbose>1)
      std::cout << h->get(xo) << " " << h->get(yo) << " " << h->get(xoe) << " " << h->get(yoe) << std::endl;
  }
  return make(graph);
}

TGraphErrors *ejungwoo::fitgsy(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, Int_t nDivision, Double_t c, Int_t entry_cut) {
  auto h2 = (TH2 *) hist;
  auto graph=new TGraphErrors();
  auto array=fitgsy_list(h2,nDivision,c,entry_cut);
  if(fVerbose>1)
    std::cout << "graph info. " << xo << " " << yo << " " << xoe << " " << yoe << std::endl;
  for (auto i=0; i<array->GetEntries(); ++i) {
    auto h=(ejungwoo::hdata*)array->At(i);
    graph->SetPoint(i,h->get(xo),h->get(yo));
    graph->SetPointError(i,h->get(xoe),h->get(yoe));
    if(fVerbose>1)
      std::cout << h->get(xo) << " " << h->get(yo) << " " << h->get(xoe) << " " << h->get(yoe) << std::endl;
  }
  return make(graph);
}

TObjArray *ejungwoo::tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title,int nx,Double_t x1,Double_t x2,int ny,Double_t y1,Double_t y2) { //jumpto_tp4
  int count=0;
  auto histograms = new TObjArray();
  for (TCut cut : cuts) {
    TString cname = cut.GetName();
    if(cname.IsNull()||cname=="CUT") cname = name+"_"+TString::Itoa(count, 10);
    else                             cname = name+"_"+cname;
    if(formula.Index(":")>=0) {
      auto hist=tp(tree,formula,cut,cname,title,nx,x1,x2,ny,y1,y2);
      histograms->Add(hist);
      if(fGbOption>0) {
        auto cvs=cc(cname);
        make(hist)->Draw("colz");
        if(fGbOption>1)
          save(cvs,"pdf");
      }
    }
    else {
      auto hist=tp(tree,formula,cut,cname,title,nx,x1,x2,-1,-1,-1);
      histograms->Add(hist);
      if(fGbOption>0) {
        auto cvs=cv(cname);
        make(hist)->Draw();
        if(fGbOption>1)
          save(cvs,"pdf");
      }
    }
    ++count;
  }
  return histograms;
}

TObjArray *ejungwoo::tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title,int nx,int ny) { //jumpto_tp5
  if(nx==-1)nx=200;
  if(ny==-1)ny=200;
  if(formula.Index(":")>=0) return tp(name,tree,formula,cuts,title,nx,0,0,ny,-1,-1);
  else                      return tp(name,tree,formula,cuts,title,nx,0,0,-1,-1,-1);
}

TH1 *ejungwoo::tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,int ny) { //jumpto_tp3
  if(nx==-1)nx=200;
  if(ny==-1)ny=200;
  if(formula.Index(":")>=0) return tp(tree,formula,cut,name,title,nx,0,0,ny,-1,-1);
  else                      return tp(tree,formula,cut,name,title,nx,0,0,-1,-1,-1);
}

TH1 *ejungwoo::tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,Double_t x1,Double_t x2,int ny,Double_t y1,Double_t y2) { //jumpto_tp0
  if(fVerbose>0) {
    if(!TString(cut).IsNull()) std::cout<<"tp "<<name<<": "<<tree->GetName()<<"->[f:"<<formula<<"],[c:"<<TString(cut)<<"]->";
    else                       std::cout<<"tp "<<name<<": "<<tree->GetName()<<"->[f:"<<formula<<"]->";
  }
  TH1 *h;
  if(x1==0&&x2==0) {
    if(formula.Index(":")>=0){
      TObjArray *tokens = formula.Tokenize(":");
      TString bnamex=((TObjString *)tokens->At(1))->GetString();
      TString bnamey=((TObjString *)tokens->At(0))->GetString();
      x1=tree->GetMinimum(bnamex);
      x2=tree->GetMaximum(bnamex);
      auto x3=(x2-x1)/10.;
      x2=x2+x3;
      x1=x1-x3;
      y1=tree->GetMinimum(bnamey);
      y2=tree->GetMaximum(bnamey);
      auto y3=(y2-y1)/10.;
      y2=y2+y3;
      y1=y1-y3;
      if(title.IsNull()) title=name+";"+bnamex+";"+bnamey;
      h=new TH2D(name,title,nx,x1,x2,ny,y1,y2);
    }
    else {
      x1=tree->GetMinimum(formula);
      x2=tree->GetMaximum(formula);
      auto x3=(x2-x1)/10.;
      x2=x2+x3;
      x1=x1-x3;
      if(title.IsNull()) title=name+";"+formula;
      h=new TH1D(name,title,nx,x1,x2);
    }
  }
  else {
    if(ny<0) {
      if(title.IsNull()) title=name+";"+formula;
      h=new TH1D(name,title,nx,x1,x2);
    }
    else {
      TObjArray *tokens = formula.Tokenize(":");
      TString bnamex=((TObjString *)tokens->At(1))->GetString();
      TString bnamey=((TObjString *)tokens->At(0))->GetString();
      if(title.IsNull()) title=name+";"+bnamex+";"+bnamey;
      h=new TH2D(name,title,nx,x1,x2,ny,y1,y2);
    }
  }
  auto n=tree->Project(name,formula,cut);
  if(fVerbose>0)std::cout<<n<<std::endl;
  return make(fDefaultMake,h);
};

TH1 *ejungwoo::tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,Double_t x1,Double_t x2,int ny,Double_t y1,Double_t y2) { //jumpto_tp2
  return tp(tree,formula,cut,name,title,nx,x1,x2,ny,y1,y2);
};

TH1 *ejungwoo::tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,const Double_t *xbins) //jumpto_tp1
{
  if(fVerbose>0) {
    if(!TString(cut).IsNull()) std::cout<<"tp "<<name<<": "<<tree->GetName()<<"->[f:"<<formula<<"],[c:"<<TString(cut)<<"]->";
    else                       std::cout<<"tp "<<name<<": "<<tree->GetName()<<"->[f:"<<formula<<"]->";
  }
  TH1 *h=new TH1D(name,title,nx,xbins);
  auto n=tree->Project(name,formula,cut);
  if(fVerbose>0)std::cout<<n<<std::endl;
  return make(fDefaultMake,h);
}

TCutG *ejungwoo::cutg(TString f, TString cutname, TString x, TString y) {
  auto file=new TFile(f.Data(),"read");
  auto cg=(TCutG *) file->Get(cutname.Data());
  cg->SetVarX(x.Data());
  cg->SetVarY(y.Data());
  return cg;
}

TCutG *ejungwoo::cutg(TFile *file, TString cutname, TString x, TString y) {
  auto cg=(TCutG *) file->Get(cutname.Data());
  cg->SetVarX(x.Data());
  cg->SetVarY(y.Data());
  return cg;
}

TH1 *ejungwoo::cutg(TH1 *h, TCutG *cut) {
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

TH1 *ejungwoo::cutg_or(TH1 *h, TCutG *cut, TCutG *orcut) {
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

TH1 *ejungwoo::cutg_and(TH1 *h, TCutG *cut, TCutG *andcut) {
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

TH1 *ejungwoo::inv(TH1 *h) {
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
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      Int_t n=h2->GetBinContent(binx,biny);
      for (auto i=0;i<n;++i)
        hnew->Fill(y,x);
    }
  return make(fDefaultMake,(TH1 *)hnew);
}

void ejungwoo::pfname(TString str, TString &pathname, TString &filename, TString delim="/") {
  TObjArray *tokens=str.Tokenize(delim);
  auto n=tokens->GetEntries();
  pathname="";
  pathname=((TObjString *) tokens->At(0))->GetString();
  if(n-1>1)
    for (auto i=1;i<n-1;++i)
      pathname=pathname+delim+(((TObjString *) tokens->At(i))->GetString());
  filename=((TObjString *) tokens->At(n-1))->GetString();
}

TString ejungwoo::firstname(TString str, TString delim=".") {
  if(str.Index(delim)<=0)
    return TString();
  TObjArray *tokens=str.Tokenize(delim);
  return ((TObjString *) tokens->At(0))->GetString();
}

TString ejungwoo::lastname(TString str, TString delim="/") {
  TObjArray *tokens=str.Tokenize(delim);
  return ((TObjString *) tokens->At(tokens->GetEntries()-1))->GetString();
}

TString ejungwoo::justname(TString str) {
  return firstname(lastname(str));
}

#endif
