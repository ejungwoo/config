/**
 * @author ejungwoo
 */

#ifndef EJUNGWOO_H
#define EJUNGWOO_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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

/**
 * @todo change global method to start with 'g'
 * @todo change histogram method to start with 'h'
 * @todo change creation method to start with 'c'
 * @todo change showing method to start with 's'
 * @todo change class to start with 't'
 */

namespace ejungwoo
{
    TString fVMarkText;

    bool fNaming=true;
    TString fHeader;
    TString fFooter;

    bool fSave=true;
    bool fWrite=true;
    bool fDraw=true;
     int fVerbose=1;
     int fVerboseG=0;
     int fGbOption=0;
     int fDefaultMake=1;
    bool fDarkMode=false;

    bool fUsePDGName=true;
     int fNumPDGs=26;

     int fNumColors=31;

 Color_t fColorList[] = {
   kOrange-4, kOrange+6, kOrange+8, kOrange-3, kOrange, kYellow,
   kSpring+8, kSpring+7, kSpring-5, kTeal+5, kSpring-6, kTeal+3, kCyan+3, kCyan+2, kCyan+1,
   kAzure+7, kBlue-4, kBlue, kBlue+1, kViolet+4, kViolet-6, kViolet-5,
   kPink+3, kRed+1, kRed, kRed-4, kPink-2, kPink+7, kOrange+3, kSpring+6, kSpring+1,
 };

 Color_t fColorCombi[] = {
   kRed-4,
   kBlue,
   kSpring-5,
   kOrange+3,
   kViolet-5,
   kCyan+1,
   kOrange-3,
   kGray+2,
 };

 TFile *fSaveGFile=nullptr;

 TString fVersion="";
 TString fFigDirName="figures";
 TString fDataDirName="data";

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

  double fWDefault2=0.18;
  double fWUnit2=0.009;
  double fHUnit2=0.06;

  double fWStat=0.30;
  double fHStat=0.25;
  double fXStat=0.95;
  double fYStat=0.88;

  double fTMargin=0.12;
  double fBMargin=0.16;
  double fLMargin=0.19;
  double fRMargin=0.055;
  double fRMarginH1=0.055;
  double fRMarginH2=0.155;

  double fMainTitleSize=0.08;
  double fAxisTitleSizes[] ={0.05 , 0.065, 0.09 , 0.11};
  double fAxisLabelSizes[] ={0.045, 0.05 , 0.07 , 0.09};
  double fZAxisLabelSizes[]={0.030, 0.035, 0.05 , 0.06};
  double fXTitleOffsets[] = {1.30 , 1.15 , 0.80 , 0.80};
  double fYTitleOffsets[] = {1.90 , 1.45 , 1.10 , 1.00};

  int fDefaultFont=132;

  int fNDivisions=508;
  int fNDivisions2=506;

  TObjArray *fFileArray;
  TObjArray *fACanvasArray;

  std::ifstream fIfStream;


  /********************************************************/

  void gvmark(TString vmtext=""); ///< Set flag for drawing version mark on the canavs
  TText *getvmark(bool draw=true, TString vmtext=""); ///< Get version mark text of default margin setting in this script

  void gheader(TString header); ///< Set header for file, drawing, acanvas, savings, and writings
  void gfooter(TString footer); ///< Set footer for file, drawing, acanvas, savings, and writings

  void gnaming(bool naming); /// set false to stop naming with header and footer
  TString makename(TString &name); ///< Make name = header + name + footer
  TString makename(const char *name); ///< Make name = header + name + footer

  /*
   * Graphic verbosity fVerbose
   *
   * @param verbose
   *   - 0: silent
   *   - 1: print minimum information (default)
   *   - 2: print more information (to be updated)
  */
  void gverbose(int verbose=1);

  /*
   * Graphic verbosity fVerboseG used in methods used in fitgsx_list and fitgsy_list
   *
   * @param verbose
   *   - 0: silent (default)
   *   - 1: draw all fit histograms
  */
  void gverboseG(int graphic=1);

  /*
   * Global option fGbOption used in tp method
   *
   * @param goption
   *   - 0: silent (default)
   *   - 1: draw objects created in method tp()
   *   - 2: draw and save objects created in method tp()
  */
  void goption(int goption=1);

  void gdark(bool dm = true); ///< dark mode (drawing)

  TFile *gfile(TString filename); ///< save graphic if fVerboseG>1

  bool isfile(TString filename); ///< does this file exist?

  void gstat (int opt); ///< equalivant to gStyle->SetOptStat(opt);
  void gstat (Option_t *opt); ///< equalivant to gStyle->SetOptStat(opt);
  void gfstat (int opt); ///< equalivant to gStyle->SetOptFit(opt);
  void gzcolor(int opt); ///< set z-palette color to 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale

  void colorwheel(); ///< show colorwheel
  void markers();    ///< show markers
  void colorlist();  ///< draw color list used in function colori()
  void colorcblist();  ///< draw color list used in function colori()

  Color_t colori(int icolor); ///< get selected list of root colors. Run function colorlist() to see color list. Or see fColorList.
  Color_t ccombi(int icolor);

  TCanvas *cv1 (TString nm="",double w=0,double h=0,TString l=""); ///<  500 x 550 for 1D
  TCanvas *cv2 (TString nm="",double w=0,double h=0,TString l=""); ///<  600 x 550 for 1D
  TCanvas *cv3 (TString nm="",double w=0,double h=0,TString l=""); ///<  680 x 550 for 1D
  TCanvas *cv  (TString nm="",double w=0,double h=0,TString l="") { return cv2(nm,w,h,l); } ///< cv2 equavalent
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

  TCanvas *div (TCanvas *c,int nx,int ny,Float_t xm=0.001,Float_t ym=0.001,int color=0); ///< Divide canvas
  TCanvas *div0(TCanvas *c,int nx,int ny); ///< Divide canvas with no margins no gaps

  void moss(TAttMarker *att, Color_t color=kBlack, Style_t style=20,   Size_t size=.8);
  void loss(TAttLine   *att, Color_t color=kBlack, Style_t style=1,    Width_t width=1);
  void toss(TAttText   *att, Color_t color=kBlack, Short_t align=22,   Size_t size=0.05, Font_t font=132);
  void toss(TAttText   *att, Color_t color=kBlack, TString align="cc", Size_t size=0.05, Font_t font=132);

     TObject *make (TObject *ob);      ///< make object stylish!,            jumpto_makeo
      TGraph *make (TGraph *gr, int mi=20, float ms=.8, int mc=24);       ///< make graph stylish!,             jumpto_makeg
TGraphErrors *make (TGraphErrors *gr, int mi=20, float ms=.8, int mc=24); ///< make error graph stylish!,       jumpto_makege
         TF1 *make (TF1 *f);           ///< make function stylish!,          jumpto_makef

         TH1 *make (int s, TH1 *h);  ///< make histogram stylish! (s)bigger!, jumpto_maken
         TH1 *make (TH1 *h);           ///< make histogram stylish!,          jumpto_makeh
         TH1 *make2(TH1 *h);           ///< make histogram stylish! bigger!,  jumpto_makeh2

   TPaveText *make (TPaveText *pave);            ///< make pave text stylish!, jumpto_makep
     TCanvas *make (TCanvas *cvs, TString vmtext=""); ///< make canvas stylish!,    jumpto_makec

     TLegend *make (TLegend *legend, double dx=0, double dy=0);  ///< make legend stylish!,        jumpto_makel
     TLegend *make2(TLegend *legend, double dx=0, double dy=0);  ///< make legend stylish! bigger! jumpto_makel2
     TLegend *makel(TLegend *legend, double dx=0, double dy=0);  ///< make legend stylish on left! jumpto_makell

     void nobox(TCanvas *cvs, TH1 *hist);

  TF1 *settitle(TF1 *f, TString title); ///< set title of function histogram

  TH1 *tohist(double *buffer, int n, TString name = "", TString title = ""); ///< make histogram with given buffer
  TH1 *tohist(double *buffer, int i, int f, TString name = "", TString title = ""); ///< make histogram with given buffer in range i->f

  TGraphErrors *tograph(TString filename); // TODO

  TCutG *cutg (TString f, TString cutname, TString x, TString y); ///< set TCutG from file name
  TCutG *cutg (TFile  *f, TString cutname, TString x, TString y); ///< set TCutG from file

  TH1   *cutg    (TH1 *h, TCutG *cut); ///< recreate histogram satisfying graphical cut
  TH1   *cutg_or (TH1 *h, TCutG *cut, TCutG *orcut); ///< recreate histogram satisfying cut or orcut
  TH1   *cutg_and(TH1 *h, TCutG *cut, TCutG *andcut); ///< recreate histogram satisfying cut and orcut

  TH1 *inv(TH1 *h); ///< recreate histogram from "x vs y" to "y to x"
  TH1 *dndx(TH1 *h); ///< make graph y axis to dn/dx where n is number of entries
  TH1 *norm_max(TH1 *h, double maxto = 1); ///< normalize maximum value of histogram to maxto(=1 by default)
  TH1 *norm_integral(TH1 *h, double normto = 1); ///< normalize integral value of histogram to normto(=1 by default)

  TH1D *pdg_hist(const char *name="particleID", const char *title=";particles;");
  void gpdgname(bool usename);
  void pdg_axis(TAxis *axis);
  int pdg_idx(int pdg);

  void gversion(TString val); ///< if version is set, fVersion is used instead of doing verson control.
  TString version(); ///< return version

  void gfig(TString name); ///< Name the name of the figure file which is "figures" by default. Used in save() function.

  void gsave(bool val); ///< set save flag of saving canvas using method save()
  void  save(TVirtualPad *cvs, TString format="pdf", bool version_control = true); ///< save TVirtualPad. See as save(TCanvas *) for detail
  void  save(TCanvas *cvs, TString format="pdf", bool version_control = true); ///< save cavans ./figures/[canvas name].[version-automatically updated].[format]
  void  save(TString name, TCanvas *cvs, TString format="pdf", bool version_control = true); ///< save cavans ./figures/[name].[version-automatically updated].[format]

  void gwrite(bool val); ///< set write flag of writting object using method write(TObject *)
  void  write(TObject *obj, bool version_control = true); ///< write object ./data/[obj name].[version-automatically updated].root
  void  write(TString name, TNamed *obj, bool version_control = true); ///< write to file with name 'name'

  TGraph *sumf(std::vector<TF1*> &fs); ///< TODO create TF1 which is sum of TF1s in fs;

  TF1 *fitg (TF1 *f1, TH1 *h, double c=2.5, Option_t *opt="RQ0");
  TF1 *fitg (TH1 *h, double c=2.5, Option_t *opt="RQ0"); ///< single gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *fitgg(TH1 *h, double c=2.5, Option_t *opt="RQ0"); ///< double gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *fitng(int n, TH1 *h, double c=2.5, Option_t *opt="RQ0"); ///< n gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1    *gg(TF1 *f, int i); ///< get i'th gaussian from multipule gaussian function f1

  void drawgg(TF1 *f, Option_t *opt="samel"); ///< Draw n-gaussian separately

  TH1D *cuty(TH1 *hist, int bin1, int bin2); ///< TODO
  TH1D *cuty(TH1 *hist, int bin1, int bin2, TGraph *cut_area); ///< TODO
  TH1D *cutx(TH1 *hist, int bin1, int bin2); ///< cut TH2 histogram in x from x-bin = bin1~bin2 and project histogram to y
  TH1D *cutx(TH1 *hist, int bin1, int bin2, TGraph *cut_area); ///< same as above but TGraph *cut_area is set to area of cut region in h2;

  class hdata : public TObject {
    public:
      TH1D *hist;
      int n;
      double x=0,y=0,dx=0,ddx=0,dy=0,ddy=0;
      hdata(TH1D *h):TObject(),hist(h) {}
      virtual ~hdata() {}
      void print() { std::cout<<"n:"<<n<<"| xy:"<<x<<", "<<y<<"| dxy:"<<dx<<", "<<dy<<"| ddxy:"<<ddx<<", "<<ddy<<std::endl; }
      double error() { return sqrt(dx*dx+dy*dy); }
      double get(TString val) {
        double c = 1;
        if(val.Index(".5")>=0) c *= 0.5;
        if(val.Index("/2")>=0) c *= 0.5;
        if(val.Index("/sn")>=0) c *= 1./sqrt(n);
             if(val.Index("ddx")>=0) return c*ddx;
        else if(val.Index("ddy")>=0) return c*ddy;
        else if(val.Index("dx")>=0) return c*dx;
        else if(val.Index("dy")>=0) return c*dy;
        else if(val.Index("x")>=0) return c*x;
        else if(val.Index("y")>=0) return c*y;
        return 0;
      }
  };

  class drawing : public TObject {
    public:
      drawing(TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0)
      : fObj(obj), fOpt(opt), fType0(type0), fType1(type1), fType2(type2), fType3(type3) {}

      virtual void Draw(Option_t *opt="") { // draw_drawing
        auto sopt = TString(fOpt);
        sopt.ReplaceAll("logx","");
        sopt.ReplaceAll("logy","");
        sopt.ReplaceAll("logz","");

             if (sopt.Index("t0")>=0&&!fType0) {std::cout<<fObj->GetName()<<" is not type0, therefore, omitted."<<std::endl;}
        else if (sopt.Index("t1")>=0&&!fType1) {std::cout<<fObj->GetName()<<" is not type1, therefore, omitted."<<std::endl;}
        else if (sopt.Index("t2")>=0&&!fType2) {std::cout<<fObj->GetName()<<" is not type2, therefore, omitted."<<std::endl;}
        else if (sopt.Index("t3")>=0&&!fType3) {std::cout<<fObj->GetName()<<" is not type3, therefore, omitted."<<std::endl;}
        else
          fObj->Draw(sopt.Data());
      }

      TObject *fObj;
      TString fOpt;
      Bool_t fType0 = 0;
      Bool_t fType1 = 0;
      Bool_t fType2 = 0;
      Bool_t fType3 = 0;

      Bool_t fIsH1 = 0;
      Bool_t fIsH2 = 0;
  };

  class acanvas : public TObjArray {
    public:
      int fFrameType=0;
      TCanvas *fCanvas=nullptr;
      TString fVMarkTextForACvs;
      bool fGrid = 0;
      TH1 *fFirstHistogram=nullptr;

      acanvas(TString name) { SetName(name); }

      void add(TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0) {
        if (opt.Index("grid")>=0) {
          opt.ReplaceAll("grid","");
          fGrid = true;
        }
        if (opt.Index("same")<0&&GetEntries()>=1)
          opt+="same";
        auto dro = new drawing(obj,opt,type0,type1,type2,type3);

        TString className = obj->ClassName();
        if (fFrameType==0) {
               if (className.Index("TH1")==0) fFrameType = 1;
          else if (className.Index("TH2")==0) fFrameType = 2;
        }

        if (fFirstHistogram==nullptr) {
          if (className.Index("TH2")==0||className.Index("TH1")==0) fFirstHistogram = (TH1 *) obj;
        }

             if (className.Index("TH1")==0) dro->fIsH1=true;
        else if (className.Index("TH2")==0) dro->fIsH2=true;

        if (!ejungwoo::fVMarkText.IsNull()&&fVMarkTextForACvs.IsNull())
          fVMarkTextForACvs = fVMarkText;

        ejungwoo::make(obj);
        if(ejungwoo::fVerbose>=2) std::cout<<"add drawing:"<<obj->GetName()<<"(\""<<opt<<"\")"<<" to acvs:"<<fName<<std::endl;
        TObjArray::Add(dro);
      }

      TCanvas *draw(TString opt="cvs") {
        if (!ejungwoo::fDraw)
          return (TCanvas *) nullptr;

        if (opt.Index("cvs")>=0 || gPad == nullptr) {
          opt.ReplaceAll("cvs","");
          if (fFrameType==2) fCanvas = cc(fName);
          else fCanvas = cv(fName);
        }
        else
          fCanvas = (TCanvas *) gPad;

        bool logx = false;
        bool logy = false;
        bool logz = false;

        int numDrawings = GetEntries();
        if(ejungwoo::fVerbose>=2) std::cout<<"Drawing acanvas: "<<fName<<" containing "<<numDrawings<< " drawings" <<std::endl;

        fCanvas -> cd();

        int countH1 = 0;
        Double_t yMMax = 0.;
        TH1 *hist0 = nullptr;

        TLegend *lg = nullptr;
        for (auto idraw=0; idraw<numDrawings; ++idraw) {
          auto dro = (drawing *) At(idraw);
          auto droopt = dro->fOpt;

          if (droopt.Index("logx")>=0) logx = true;
          if (droopt.Index("logy")>=0) logy = true;
          if (droopt.Index("logz")>=0) logz = true;

          if (dro->fIsH1) {
            auto hist = (TH1 *) dro->fObj;
            if (hist0==nullptr) {
              hist0 = hist;
              lg = new TLegend();
            }
            lg -> AddEntry(hist,hist->GetTitle(),"f");
            hist -> SetLineColor(ejungwoo::ccombi(countH1));
            auto yMax = hist -> GetBinContent(hist -> GetMaximumBin());
            if (yMax > yMMax)
              yMMax = yMax;
            ++countH1;
          }
          dro->Draw();
        }

        if (hist0!=nullptr) {
          if (logy)
            hist0 -> SetMaximum(yMMax*3);
          else
            hist0 -> SetMaximum(yMMax*1.05);
        }

        if (countH1>1) {
          hist0 -> SetTitle("");
          make(lg) -> Draw();
        }

        if (logx) fCanvas->SetLogx();
        if (logy) fCanvas->SetLogy();
        if (logz) fCanvas->SetLogz();

        if (fGrid)
          fCanvas -> SetGrid(1,1);

        //Draw(opt);
        return make(fCanvas, fVMarkTextForACvs);
      }

      void save(TString opt="") {
        ejungwoo::save(fCanvas,opt);
      }
  };

  /**
   * add drawing object (TH1*, TF1, TGraph, TText, TLine, TLegend, etc.)
   * to acanvas. One acanvas is created by default
   * in case non of [i], [name], [acv] is not set.
   *
   * @param obj   The drawing object to be added.
   * @param opt   The option used when drawing (by draw())
   * @param type0 set true if this object should be shown by drawing type0
   * @param type1 set true if this object should be shown by drawing type1
   * @param type2 set true if this object should be shown by drawing type2
   * @param type3 set true if this object should be shown by drawing type3
   */
  void add(TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);

  /**
   * add drawing object (TH1*, TF1, TGraph, TText, TLine, TLegend, etc.)
   * to new acanvas. New acanvas is created by with next index of acanvas array.
   *
   * @param obj   The drawing object to be added.
   * @param opt   The option used when drawing (by draw())
   * @param type0 set true if this object should be shown by drawing type0
   * @param type1 set true if this object should be shown by drawing type1
   * @param type2 set true if this object should be shown by drawing type2
   * @param type3 set true if this object should be shown by drawing type3
   */
  void addnew(TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3);

  /**
   * add drawing object (TH1*, TF1, TGraph, TText, TLine, TLegend, etc.)
   *
   * @param i     add the object to the i'th acanvas
   * @param obj   The drawing object to be added.
   * @param opt   The option used when drawing (by draw())
   * @param type0 set true if this object should be shown by drawing type0
   * @param type1 set true if this object should be shown by drawing type1
   * @param type2 set true if this object should be shown by drawing type2
   * @param type3 set true if this object should be shown by drawing type3
   */
  void addto(int i, TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);

  /**
   * add drawing object (TH1*, TF1, TGraph, TText, TLine, TLegend, etc.)
   *
   * @param name  add the object to the acanvas having name [name]
   * @param obj   The drawing object to be added.
   * @param opt   The option used when drawing (by draw())
   * @param type0 set true if this object should be shown by drawing type0
   * @param type1 set true if this object should be shown by drawing type1
   * @param type2 set true if this object should be shown by drawing type2
   * @param type3 set true if this object should be shown by drawing type3
   */
  void addto(TString name, TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);

  /**
   * add drawing object (TH1*, TF1, TGraph, TText, TLine, TLegend, etc.)
   *
   * @param acv   add the object to the acanvas pointer *acv
   * @param obj   The drawing object to be added.
   * @param opt   The option used when drawing (by draw())
   * @param type0 set true if this object should be shown by drawing type0
   * @param type1 set true if this object should be shown by drawing type1
   * @param type2 set true if this object should be shown by drawing type2
   * @param type3 set true if this object should be shown by drawing type3
   */
  void addto(acanvas *acv, TObject *obj, TString opt="", Bool_t type0=0, Bool_t type1=0, Bool_t type2=0, Bool_t type3=0);
  
  void clearall(); ///< clear all acanvas
  void clearc(int i=0); ///< clear acanvas of index i
  void clearc(TString name); ///< clear acanvas of name name

  void fdraw(bool val); ///< set draw flag of drawing acanvas using method draw()

  TCanvas *draw(int i,TString opt="cvs"); ///< draw objects in acanvas of index i collected by add()/addto().
  TCanvas *draw(TString name,TString opt="cvs"); ///< draw objects in acanvas of name name collected by add()/addto().
  TCanvas *draw(const char* opt="cvs") { return draw(0,opt); } ///< draw objects in acanvas of index o collected by add()/addto().
  void drawall();
  void saveall(TString opt="pdf");


  /**
   * fit 2d histogram through x with given parameters and return list of histogram data
   *
   * @param hist input histogram
   * @param nDivision division number through x
   * @param c fit will perform in range of -c*sigma ~ c*sigma
   * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
   *
   * the histograms are written to fSaveGFile is gverboseG(2) is used,
   * fSaveGFile can be set by gfile(name) method.
   */
  TObjArray *fitgsx_list(TH1 *hist, int nDivision=20, double c=1.5, int entry_cut=1000);
  /**
   * fit 2d histogram through y with given parameters and return list of histogram data
   *
   * @param hist input histogram
   * @param nDivision division number through y
   * @param c fit will perform in range of -c*sigma ~ c*sigma
   * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
   *
   * the histograms are written to fSaveGFile is gverboseG(2) is used,
   * fSaveGFile can be set by gfile(name) method.
   */
  TObjArray *fitgsy_list(TH1 *hist, int nDivision=20, double c=1.5, int entry_cut=1000);

  /**
   * Using the data from fitgsx_list
   * Draw error graph of point (xo,yo) and error (xoe,yoe)
   * variables must be one of x(fit mean), y(fit mean), dx(fit sigma), dy(fit sigma), ddx(fit sigma error), ddy(fit sigma error)
   */
  TGraphErrors *fitgsx(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int nDivision, double c, int entry_cut);
  /**
   * Using the data from fitgsy_list
   * Draw error graph of point (xo,yo) and error (xoe,yoe)
   * variables must be one of x(fit mean), y(fit mean), dx(fit sigma), dy(fit sigma), ddx(fit sigma error), ddy(fit sigma error)
   */
  TGraphErrors *fitgsy(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int nDivision, double c, int entry_cut);

  /**
   * Using the data from fitgsx_list
   *
   * @param hist input histogram for analysis
   * @param nDivision number of division through x
   * @param c c*sigma become the range of the fit
   * @param entry_cut the fit is ignored if the histogram entry is smaller than this cut
   * @param error_graph
   *   - true  will draw fitgsx(hist,"x","dy","","ddy")
   *   - false will draw fitgsx(hist,"x","y","dx/2","dy")
   */
  TGraphErrors *fitgsx(TH1 *hist, int nDivision=20, double c=1.5, int entry_cut=1000, bool error_graph = false);

  /**
   * Using the data from fitgsy_list
   *
   * @param hist input histogram for analysis
   * @param nDivision number of division through y
   * @param c c*sigma become the range of the fit
   * @param entry_cut the fit is ignored if the histogram entry is smaller than this cut
   * @param error_graph
   *   - true  will draw return fitgsy(hist,"y","dx","ddx","")
   *   - false will draw return fitgsy(hist,"x","y","dx","dy/2")
   */
  TGraphErrors *fitgsy(TH1 *hist, int nDivision=20, double c=1.5, int entry_cut=1000, bool error_graph = false);

  void gdata(TString path) { fDataDirName=path; }
  TChain *chain(TString treename, TString filename, int from=0, int to=0, int *rmlist={}, int numrm=0);
  TChain *chain(TString filename, int from=0, int to=0, TString treename="data") { return chain(treename,filename,from,to); }

  TH1 *tppdg(TString name,TTree *tree,TString formula="pdg",TCut cut="");

  TH1 *tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,double x1,double x2,int ny=-1,double y1=-1,double y2=-1); ///< simple tree projection starting with tree, jumpto_tp0
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,const double *xbins); ///< simple tree projection starting with name using xbins for x-axis, jumpto_tp1
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,double x1,double x2,int ny=-1,double y1=-1,double y2=-1); ///< simple tree projection starting with name, jumpto_tp2
  TH1 *tp(TString name,TTree *tree,TString formula="",TCut cut="",TString title="",int nx=-1,int ny=-1); ///< tree projection with automatic bin range calculation default nx, ny is 200, jumpto_tp3
  /**
   * tree projection from tree with cuts
   * return array of histograms with applied cut
   *
   * cuts are used to create several histograms
   * using global "gverboseG" verbose to
   * - gverboseG(1) : draw histograms with applied cut
   * - gverboseG(2) : draw histograms with applied cut and save in .pdf
   *
   * jumpto_tp4
   */
  TObjArray *tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title,int nx,double x1,double x2,int ny=-1,double y1=-1,double y2=-1);
  /**
   * tree projection from tree with automatic bin range calculation with cuts
   * return array of histograms with applied cut
   *
   * cuts are used to create several histograms
   * using global "gverboseG" verbose to
   * - gverboseG(1) : draw histograms with applied cut
   * - gverboseG(2) : draw histograms with applied cut and save in .pdf
   *
   * jumpto_tp5
   */
  TObjArray *tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title="",int nx=-1,int ny=-1);

     int max (int *buffer, int n); ///< get maximum value of buffer
  double max (double *buffer, int n); ///< get maximum value of buffer
  double max (TH1 *h); ///< get maximum value of histogram
  double max (TH1 *h, int &bin, double &x); ///< get maximum value of histogram

  /**
   * calculate and return full width [ratio] maximum of function
   * the width is calculated at y which the data becomes [ratio] of maximum (=ratio*maximum)
   *
   * @param f     input function
   * @param ratio width of function to be calculated at y=[ratio]*maximum 
   * @param ndx   set number of x-points to be created. larger ndx -> better quality q
   * @param x0    lower range value of x will be given
   * @param x1    upper range value of x will be given
   * @param q     quality of the fwrm
   */
  double fwrm(TF1 *f, double ratio, double ndx, double &x0, double &x1, double &q);
  double fwhm(TF1 *f, double &x0, double &x1, double &q); ///< FWHM(Full Width Half Maximum) of function. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q);
  double fwhm(TF1 *f); ///< FWHM(Full Width Half Maximum) with function. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q) with no pull values

  /**
   * calculate and return full width [ratio] maximum of histogram
   * the width is calculated at y which the data becomes [ratio] of maximum (=ratio*maximum)
   *
   * @param h     input histogram
   * @param ratio width of histogram to be calculated at y=[ratio]*maximum 
   * @param ndx   set number of x-points to be created. larger ndx -> better quality q
   * @param x0    lower range value of x will be given
   * @param x1    upper range value of x will be given
   * @param q     quality of the fwrm
   */
  double fwrm(TH1 *h, double ratio, double ndx, double &x0, double &x1, double &q); ///< full width [ratio] maximum : return width of histogram at y which the data becomes [ratio] of maximum (ratio*maximum)
  double fwhm(TH1 *h, double &x0, double &x1, double &q); ///< FWHM(Full Width Half Maximum) of histogram. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q);
  double fwhm(TH1 *h); ///< FWHM(Full Width Half Maximum) with histogram. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q) with no pull values

  std::ifstream& ofile(TString name); ///< open file as ifstream
  TString readline(std::ifstream& infile); ///< read line and return as TString of stream infile
  TString readline(); ///< read line and return as TString of stream open by ofile
  void cfile(); /// close stream open by ofile

  TObjArray *csv(TString line); ///< tokenize scv format to array of TObjString. Use tok to get TString of each TObjString
  TString tok(TObjArray *line, int i); ///< Get TString from TObjString "line" of index i

  void pfname(TString str, TString &pathname, TString &filename, TString delim="/"); ///< get pathname=[path-name], filename=[file-name] after tonizing with delim
  TString firstname(TString str, TString delim="."); ///< get first name
  TString lastname(TString str, TString delim="/"); ///< get last name
  TString justname(TString str); ///< get name with no path and format. just name

  /********************************************************/

  void axisd(int nd=506); ///< make axis ndivisions to nd!, (root default 510, default 508, axisd default 506 for TGraph2D)
  TH1 *free (TH1 *h); ///< make axis labels feel free!

  void cutt(double r=0.04); ///< cut top margin to r=(0.04)
  void cutr(double r=0.02); ///< cut right margin to r=(0.02)
  void cuttr(double r=0.02); ///< cut right margin to r=(0.02)
  void cutall(double r=0.02); ///< cut all margin to r=(0.02)

  /********************************************************/

  void init(); ///< Initialize gStyle setting. Should NOT be run by users.
}; 

void ejungwoo::gvmark(TString vmtext) {
  if (vmtext.IsNull()) fVMarkText = fVersion;
  else fVMarkText = vmtext;
  if(fVerbose>0)
    std::cout<<"Version mark >> "<<fVMarkText<<std::endl;
}

TText *ejungwoo::getvmark(bool dodraw, TString vmtext) {
  TString text;
  TLatex *ttVMark = nullptr;

  if (!vmtext.IsNull())
    text = vmtext;
  else if (!fVMarkText.IsNull())
    text = fVMarkText;
  else
    return ttVMark;

  ttVMark = new TLatex();
  ttVMark->SetTextColor(colori(27));
  ttVMark->SetTextSize(0.04);
  ttVMark->SetTextFont(132);
  ttVMark->SetNDC();

  //ttVMark->SetTextAlign(11);
  //ttVMark->SetText(0.+fLMargin,1.-fTMargin+0.01,text);

  ttVMark->SetTextAlign(31);
  ttVMark->SetText(1-fRMargin,1.-fTMargin+0.01,text);

  if (dodraw)
    ttVMark->Draw();

  return ttVMark;
}

void ejungwoo::gheader(TString header) { fHeader = header; }
void ejungwoo::gfooter(TString footer) { fFooter = footer; }

void ejungwoo::gnaming(bool naming) { fNaming = naming; }
TString ejungwoo::makename(TString &name) {
  if (fNaming) {
    if ( name.Index(fHeader)!=0) name = fHeader + name;
    if (!name.EndsWith(fFooter)) name = name + fFooter;
  }
  return name;
}
TString ejungwoo::makename(const char *name){
  return makename(TString(name));
}

void ejungwoo::gverbose(int verbose=1) { fVerbose=verbose; }
void ejungwoo::gverboseG(int verbose=1) { fVerboseG=verbose; }
void ejungwoo::goption(int goption=1) { fGbOption=goption; }

void ejungwoo::gdark(bool dm = true) { fDarkMode = dm; }

void ejungwoo::gstat(int opt) {
  gStyle->SetOptStat(opt);
}

void ejungwoo::gstat(Option_t *opt) {
  gStyle->SetOptStat(opt);
}

void ejungwoo::gfstat(int opt) {
  gStyle->SetOptFit(opt);
}

void ejungwoo::gzcolor(int opt) {
  if(fVerbose>0) std::cout<<"gzcolor("<<opt<<") >> 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale"<<std::endl;
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
  gStyle->SetOptStat(0);
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
      m->SetMarkerSize(3.5);
      auto t = new TText(x,y-0.42,Form("%d",i));
      t->SetTextSize(0.035);
      t->SetTextAlign(22);
      if ((i>=20&&i<=29)||i==33||i==34) t->SetTextColor(kBlue);
      if ((i>=24&&i<=28)||i==30||i==32) t->SetTextColor(kRed);
      if (i>=9&&i<=19) {
        t->SetTextColor(kGray);
        m->SetMarkerColor(kGray);
      }
      m->Draw();
      t->Draw();
      i++;
    }
  }
}

void ejungwoo::colorlist() {
  gStyle->SetOptStat(0);
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
      m->SetMarkerSize(3.5);
      m->SetMarkerColor(colori(i));
      auto t = new TText(x,y-0.42,Form("%d",i));
      t->SetTextSize(0.035);
      t->SetTextAlign(22);
      m->Draw();
      t->Draw();
      i++;
      if (i>=fNumColors)
        return;
    }
  }
}

void ejungwoo::colorcblist() {
  gStyle->SetOptStat(0);
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
      m->SetMarkerSize(3.5);
      m->SetMarkerColor(ccombi(i));
      auto t = new TText(x,y-0.42,Form("%d",i));
      t->SetTextSize(0.035);
      t->SetTextAlign(22);
      m->Draw();
      t->Draw();
      i++;
      if (i>=9)
        return;
    }
  }
}

Color_t ejungwoo::colori(int icolor)
{
  icolor = icolor - fNumColors*(icolor/fNumColors);
  return fColorList[icolor];
}

Color_t ejungwoo::ccombi(int icolor)
{
  return fColorCombi[icolor];
}

TGraph *ejungwoo::sumf(std::vector<TF1*> &fs)
{
  auto graph=new TGraph();
  double x,xl,xh;
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

int ejungwoo::max(int *buffer, int n)
{
  int val = -INT_MAX;
  for (auto i=0; i<n; ++i)
    if(buffer[i] > val)
      val = buffer[i];
  return val;
}

double ejungwoo::max(double *buffer, int n)
{
  double val = -DBL_MAX;
  for (auto i=0; i<n; ++i)
    if(buffer[i] > val)
      val = buffer[i];
  return val;
}

double ejungwoo::max(TH1 *h) {
  int bin;
  double x;
  return max(h, bin, x);
}

double ejungwoo::max (TH1 *h, int &bin, double &x) {
  bin=h->GetMaximumBin();
  x=h->GetXaxis()->GetBinCenter(bin);
  return h->GetBinContent(bin);
}

double ejungwoo::fwrm(TF1 *f, double ratio, double nx, double &x0, double &x1, double &q)
{
  double x, xl, xh;
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

double ejungwoo::fwhm(TF1 *f, double &x0, double &x1, double &q)
{
  return fwrm(f, 0.5, 10000, x0, x1, q);
}

double ejungwoo::fwhm(TF1 *f)
{
  double x0, x1 ,q;
  return fwhm(f, x0, x1, q);
}

double ejungwoo::fwrm(TH1 *h, double ratio, double ndx, double &x0, double &x1, double &q)
{
  if(fVerbose>0) std::cout<<"assuming histogram "<<h->GetName()<<" is smooth"<<std::endl;

  auto hist=(TH1D *) h;
  int binmax;
  double xmax;
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

double ejungwoo::fwhm(TH1 *h, double &x0, double &x1, double &q)
{
  return fwrm(h, 0.5, 0.1, x0, x1, q);
}

double ejungwoo::fwhm(TH1 *h)
{
  double x0, x1 ,q;
  return fwhm(h, x0, x1, q);
}

void ejungwoo::cutt(double r) { fTMargin = r; }
void ejungwoo::cutr(double r) { fRMarginH1 = r; fRMarginH2 = r; }
void ejungwoo::cuttr(double r) { fTMargin = r; fRMarginH1 = r; fRMarginH2 = r; }
void ejungwoo::cutall(double r) { fTMargin = r; fRMarginH1 = r; fRMarginH2 = r; fBMargin = r; fLMargin = r; }

void ejungwoo::init() {
  fXStat=1.-fRMargin;
  fYStat=1.-fTMargin;
  auto x1=0.+fLMargin; auto x2=1.-fRMargin; auto dx=x2-x1;
  auto y1=0.+fBMargin; auto y2=1.-fTMargin; auto dy=y2-y1;
  gStyle->SetStatStyle(0);
  gStyle->SetStatW(dx*fWStat);
  gStyle->SetStatH(dy*fHStat);
  gStyle->SetStatX(fXStat);
  gStyle->SetStatY(fYStat);
  gStyle->SetTitleFontSize(fMainTitleSize);

  gStyle->SetLegendFont(fDefaultFont);
  gStyle->SetStatFont(fDefaultFont);
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

TCanvas *ejungwoo::div(TCanvas *c,int nx,int ny,Float_t xm,Float_t ym,int color)
{
  c->Divide(nx,ny,xm,ym,color);
  for (auto i=1; i<=nx*ny; ++i)
    c->cd(i)->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);
  return c;
}

TCanvas *ejungwoo::div0(TCanvas *c,int nx,int ny)
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

void ejungwoo::moss(TAttMarker *att, Color_t color, Style_t style, Size_t size)
{
  att->SetMarkerColor(color);
  att->SetMarkerStyle(style);
  att->SetMarkerSize(size);
}

void ejungwoo::loss(TAttLine *att, Color_t color, Style_t style, Width_t width)
{
  att->SetLineColor(color);
  att->SetLineStyle(style);
  att->SetLineWidth(width);
}

void ejungwoo::toss(TAttText *att, Color_t color, Short_t align, Size_t size, Font_t font)
{
  att->SetTextColor(color);
  att->SetTextAlign(align);
  att->SetTextSize(size);
  att->SetTextFont(font);
}

void ejungwoo::toss(TAttText *att, Color_t color, TString align, Size_t size, Font_t font)
{
  att->SetTextColor(color);

  Short_t aligni = 0;
       if (align.Index("l")>=0) aligni += 10;
  else if (align.Index("r")>=0) aligni += 30;
  else                          aligni += 20;
       if (align.Index("t")>=0) aligni += 1;
  else if (align.Index("b")>=0) aligni += 3;
  else                          aligni += 2;

  att->SetTextAlign(aligni);
  att->SetTextSize(size);
  att->SetTextFont(font);
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

TCanvas *ejungwoo::make(TCanvas *cvs,TString vmtext) { //jumpto_makec
  cvs->Modified();
  cvs->Update();

  if (fDarkMode) cvs->SetFillColor(kGray);

  cvs->SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);

  if (vmtext.IsNull())
    vmtext = fVMarkText;

  auto pmtvs=cvs->GetListOfPrimitives();
  if (pmtvs!=nullptr)
  {
    auto pvtt=(TPaveText*)pmtvs->FindObject("title");
    if (pvtt!=nullptr) pvtt->SetTextFont(fDefaultFont);

    auto mgLeft = cvs->GetLeftMargin();
    auto mgRight = cvs->GetRightMargin();
    auto mgBottom = cvs->GetBottomMargin();
    auto mgTop = cvs->GetTopMargin();

    TObject *obj2;
    TIter next(pmtvs);
    while ((obj2 = next())) {
      //make(obj2);
      if (obj2->InheritsFrom(TH1::Class())) {
        cvs->cd();
        getvmark(true, vmtext);
        auto h = (TH1D *) obj2;
        auto statsbox = dynamic_cast<TPaveStats*>(h->FindObject("stats"));
        if (statsbox != nullptr)
        {
          auto x1=0.+mgLeft; auto x2=1.-mgRight; auto dx=x2-x1;
          auto y1=0.+mgBottom; auto y2=1.-mgTop; auto dy=y2-y1;
          auto numLines=statsbox->GetListOfLines()->GetEntries();
          double xratio, yratio;

               if (numLines<9)  { xratio = 0.400; yratio=0.06*numLines; }
          else if (numLines<15) { xratio = 0.325; yratio=0.04*numLines; }
          else if (numLines<20) { xratio = 0.350; yratio=0.03*numLines; }
          else                  { xratio = 0.375; yratio=0.6;           }
          statsbox->SetX1NDC(x2-dx*xratio);
          statsbox->SetY1NDC(y2-dx*yratio);
          statsbox->SetX2NDC(x2);
          statsbox->SetY2NDC(y2);
          statsbox->SetTextFont(fDefaultFont);
        }
      }
      if (obj2->InheritsFrom(TPad::Class())) {
        auto innercvs=(TPad*)obj2;
        if (fDarkMode) innercvs->SetFillColor(kGray);
        innercvs->Modified();
        innercvs->Update();
        auto pmtvs2=innercvs->GetListOfPrimitives();
        auto pvtt2=(TPaveText*)pmtvs2->FindObject("title");
        if (pvtt2!=nullptr) pvtt2->SetTextFont(fDefaultFont);
        innercvs->Modified();
        innercvs->Update();

        auto mgiLeft = innercvs->GetLeftMargin();
        auto mgiRight = innercvs->GetRightMargin();
        auto mgiBottom = innercvs->GetBottomMargin();
        auto mgiTop = innercvs->GetTopMargin();

        TObject *obj3;
        TIter next2(pmtvs2);
        while ((obj3 = next2())) {
          //make(obj3);
          if (obj3->InheritsFrom(TH1::Class())) {
            innercvs->cd();
            getvmark(true, vmtext);
            auto h = (TH1D *) obj2;
            auto statsbox = dynamic_cast<TPaveStats*>(h->FindObject("stats"));
            if (statsbox != nullptr)
            {
              auto x1=0.+mgLeft; auto x2=1.-mgRight; auto dx=x2-x1;
              auto y1=0.+mgBottom; auto y2=1.-mgTop; auto dy=y2-y1;
              auto numLines=statsbox->GetListOfLines()->GetEntries();
              double xratio, yratio;
              if (numLines<5)  { xratio = 0.300; yratio=0.05*numLines; }
              else if (numLines<15) { xratio = 0.325; yratio=0.04*numLines; }
              else if (numLines<20) { xratio = 0.350; yratio=0.03*numLines; }
              else                  { xratio = 0.375; yratio=0.6;           }
              statsbox->SetX1NDC(x2-dx*xratio);
              statsbox->SetY1NDC(y2-dx*yratio);
              statsbox->SetX2NDC(x2);
              statsbox->SetY2NDC(y2);
              statsbox->SetTextFont(fDefaultFont);
            }
          }
          if (obj3->InheritsFrom(TPad::Class())) {
            auto innnercvs=(TPad*)obj3;
            if (fDarkMode) innnercvs->SetFillColor(kGray);
            innnercvs->Modified();
            innnercvs->Update();
            auto pmtvs3=innnercvs->GetListOfPrimitives();
            auto pvtt3=(TPaveText*)pmtvs3->FindObject("title");
            if (pvtt3!=nullptr) pvtt3->SetTextFont(fDefaultFont);
            innnercvs->Modified();
            innnercvs->Update();
          }
        }
      }
    }
  }

  cvs->Modified();
  cvs->Update();
  return cvs;
}

TGraph *ejungwoo::make(TGraph *graph, int mi, float ms, int mc) { //jumpto_makeg
  init();
  if(graph->GetMarkerStyle()==1) {
    graph->SetMarkerStyle(mi);
    graph->SetMarkerSize(ms);
    //graph->SetMarkerColor(colori(mc));
  }
  make(graph->GetHistogram());
  return graph;
}

TGraphErrors *ejungwoo::make(TGraphErrors *graph, int mi, float ms, int mc) //jumpto_makege
{
  return (TGraphErrors *) make((TGraph *) graph, mi, ms, mc);
}

TH1 *ejungwoo::make(int s, TH1 *h) { //jumpto_maken
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
  h->GetZaxis()->SetLabelSize(fZAxisLabelSizes[s]);

  h->GetXaxis()->SetTitleFont(fDefaultFont);
  h->GetYaxis()->SetTitleFont(fDefaultFont);
  h->GetZaxis()->SetTitleFont(fDefaultFont);
  h->GetXaxis()->SetLabelFont(fDefaultFont);
  h->GetYaxis()->SetLabelFont(fDefaultFont);
  h->GetZaxis()->SetLabelFont(fDefaultFont);

  free(h);

  return h;
}

TH1 *ejungwoo::make(TH1 *h) { return ejungwoo::make(1,h); } //jumpto_makeh
TH1 *ejungwoo::make2(TH1 *h) { return ejungwoo::make(2,h); } //jumpto_makeh2 

TLegend *ejungwoo::makel(TLegend *legend, double dx, double dy) { //jumpto_makell
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
  auto x1=fLMargin;
  auto x2=x1+lmax*fWUnit+fWDefault;
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

void ejungwoo::nobox(TCanvas *cvs, TH1 *hist)
{
  cvs -> SetFrameLineColor(0);
  auto xa = hist -> GetXaxis();
  auto ya = hist -> GetYaxis();
  for (auto a : {xa, ya}) {
    a -> SetAxisColor(0);
    a -> SetTickLength(0);
    a -> SetTickSize(0);
    a -> SetLabelOffset(1);
    a -> SetTitleOffset(1);
  }
}

TLegend *ejungwoo::make(TLegend *legend, double dx, double dy) { //jumpto_makel
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

TLegend *ejungwoo::make2(TLegend *legend, double dx, double dy) { //jumpto_makel2
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
  f->GetHistogram()->SetTitle(title);
  return f;
}

TGraphErrors *ejungwoo::tograph(TString filename)
{
  //TODO
  std::ifstream file(filename);
  file.close();
  auto graph = new TGraphErrors();
  return graph;
}

TH1 *ejungwoo::tohist(double *buffer, int n, TString name, TString title)
{
  if(name.IsNull()) name=Form("hist-%d",fIHist);
  auto hist = new TH1D(name, title, n, 0, n+1);
  for (auto i = 0; i < n; ++i)
    hist->SetBinContent(i+1,buffer[i]);
  ++fIHist;
  return make(fDefaultMake,hist);
}

TH1 *ejungwoo::tohist(double *buffer, int i, int f, TString name, TString title)
{
  if(name.IsNull()) name=Form("hist-%d",fIHist);
  auto hist = new TH1D(name, title, f-i+1, i, f+1);
  for (auto bin = i; bin < f+1; ++bin)
    hist->SetBinContent(bin+1-i,buffer[bin]);
  ++fIHist;
  return make(fDefaultMake,hist);
}

void ejungwoo::axisd(int nd) { fNDivisions=nd; }

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
  auto hist = (TH1 *) h->Clone();
  auto nbins = hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin) {
    auto x1=hist->GetXaxis()->GetBinLowEdge(bin);
    auto x2=hist->GetXaxis()->GetBinUpEdge(bin);
    auto dx=x2-x1;
    hist->SetBinContent(bin,hist->GetBinContent(bin)/dx);
  }
  hist->SetTitle(Form(";%s;dN/dx",h->GetXaxis()->GetTitle()));
  return hist;
}

TH1 *ejungwoo::norm_max(TH1 *h, double maxto)
{
  auto hist = (TH1 *) h->Clone();
  auto valmax = max(hist);
  auto nbins = hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin)
    hist->SetBinContent(bin,hist->GetBinContent(bin)*maxto/valmax);
  //hist->SetTitle(Form(";%s;Normalized Max",h->GetXaxis()->GetTitle()));
  hist->SetTitle(h->GetTitle());

  return hist;
}

TH1 *ejungwoo::norm_integral(TH1 *h, double normto)
{
  auto hist = (TH1 *) h->Clone();
  auto integral = hist->Integral();
  auto nbins = hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin) {
    auto x1=hist->GetXaxis()->GetBinLowEdge(bin);
    auto x2=hist->GetXaxis()->GetBinUpEdge(bin);
    auto dx=x2-x1;
    hist->SetBinContent(bin,hist->GetBinContent(bin)*normto/dx/integral);
  }
  hist->SetTitle(Form(";%s;Normalized Integral",h->GetXaxis()->GetTitle()));
  return hist;
}

TH1D *ejungwoo::pdg_hist(const char *name, const char *title)
{
  auto hist = new TH1D(name,title,fNumPDGs,0,fNumPDGs);
  pdg_axis(hist -> GetXaxis());
  return hist;
}

void ejungwoo::gpdgname(bool usename) { fUsePDGName = usename; }

void ejungwoo::pdg_axis(TAxis *axis)
{
  if (fUsePDGName) {
    axis -> SetBinLabel( 1, "others");
    axis -> SetBinLabel( 2, "nu_e_bar");
    axis -> SetBinLabel( 3, "e+");
    axis -> SetBinLabel( 4, "e-");
    axis -> SetBinLabel( 5, "gamma");
    axis -> SetBinLabel( 6, "neutron");
    axis -> SetBinLabel( 7, "proton");
    axis -> SetBinLabel( 8, "deuteron");
    axis -> SetBinLabel( 9, "triton");
    axis -> SetBinLabel(10, "He3");
    axis -> SetBinLabel(11, "He4");
    axis -> SetBinLabel(12, "Li6");
    axis -> SetBinLabel(13, "Li7");
    axis -> SetBinLabel(14, "Be7");
    axis -> SetBinLabel(15, "Be9");
    axis -> SetBinLabel(16, "Be10");
    axis -> SetBinLabel(17, "Bo10");
    axis -> SetBinLabel(18, "Bo11");
    axis -> SetBinLabel(19, "C11");
    axis -> SetBinLabel(20, "C12");
    axis -> SetBinLabel(21, "C13");
    axis -> SetBinLabel(22, "C14");
    axis -> SetBinLabel(23, "N13");
    axis -> SetBinLabel(24, "N14");
    axis -> SetBinLabel(25, "N15");
    axis -> SetBinLabel(26, "O16");
  }
  else {
    axis -> SetBinLabel( 1, "others");
    axis -> SetBinLabel( 2, "-12");
    axis -> SetBinLabel( 3, "-11");
    axis -> SetBinLabel( 4, "11");
    axis -> SetBinLabel( 5, "22");
    axis -> SetBinLabel( 6, "2112");
    axis -> SetBinLabel( 7, "2212");
    axis -> SetBinLabel( 8, "_10020");
    axis -> SetBinLabel( 9, "_10030");
    axis -> SetBinLabel(10, "_20030");
    axis -> SetBinLabel(11, "_20040");
    axis -> SetBinLabel(12, "_30060");
    axis -> SetBinLabel(13, "_30070");
    axis -> SetBinLabel(14, "_40070");
    axis -> SetBinLabel(15, "_40090");
    axis -> SetBinLabel(16, "_40100");
    axis -> SetBinLabel(17, "_50100");
    axis -> SetBinLabel(18, "_50110");
    axis -> SetBinLabel(19, "_60110");
    axis -> SetBinLabel(20, "_60120");
    axis -> SetBinLabel(21, "_60130");
    axis -> SetBinLabel(22, "_60140");
    axis -> SetBinLabel(23, "_70130");
    axis -> SetBinLabel(24, "_70140");
    axis -> SetBinLabel(25, "_70150");
    axis -> SetBinLabel(26, "_80160");
    axis -> SetLabelSize(0.01);
  }
  axis -> LabelsOption("v");
}

int ejungwoo::pdg_idx(int pdg)
{
  switch (pdg)
  {
    case -12        : return 1;  // nu_e_bar
    case -11        : return 2;  // e+
    case 11         : return 3;  // e-
    case 22         : return 4;  // gamma
    case 2112       : return 5;  // neutron
    case 2212       : return 6;  // proton
    case 1000010020 : return 7;  // deuteron
    case 1000010030 : return 8;  // triton
    case 1000020030 : return 9;  // He3
    case 1000020040 : return 10; // He4
    case 1000030060 : return 11; // Li6
    case 1000030070 : return 12; // Li7
    case 1000040070 : return 13; // Be7
    case 1000040090 : return 14; // Be9
    case 1000040100 : return 15; // Be10
    case 1000050100 : return 16; // Bo10
    case 1000050110 : return 17; // Bo11
    case 1000060110 : return 18; // C11
    case 1000060120 : return 19; // C12
    case 1000060130 : return 20; // C13
    case 1000060140 : return 21; // C14
    case 1000070130 : return 22; // N13
    case 1000070140 : return 23; // N14
    case 1000070150 : return 24; // N15
    case 1000080160 : return 25; // O16
    default         : return 0;
  }
}

void ejungwoo::gversion(TString val) {
  fVersion = val;
  if(fVerbose>0) std::cout<<"fVersion=["<<fVersion<<"]"<<std::endl;

  fFigDirName = "figures_"+fVersion;
  fDataDirName = "data_"+fVersion;
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

void ejungwoo::gsave(bool val) {
  fSave=val;
  if(fVerbose>0) {
    if(fSave) std::cout<<"fSave=true; TCanvas will be written by ejungwoo::save(TCanvas *) method."<<std::endl;
    else      std::cout<<"fSave=false; TCanvas will NOT!! be written by ejungwoo::save(TCanvas *) method."<<std::endl;
  }
}

void ejungwoo::gfig(TString name) { fFigDirName = name; }

void ejungwoo::save(TVirtualPad *cvs, TString format, bool version_control) {
  save(((TCanvas *)cvs), format, version_control);
}

void ejungwoo::save(TCanvas *cvs, TString format, bool version_control) {
  if(!fSave||cvs==nullptr) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/"+fFigDirName+"/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString name=cvs->GetName();
  TString full_name=name+"."+format;
  if(!fVersion.IsNull()) {
    full_name=name+"__"+fVersion+"."+format;
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
  if(!fSave||cvs==nullptr) return;
  TString path=TString(gSystem->Getenv("PWD"))+"/"+fFigDirName+"/";
  gSystem->Exec(TString("mkdir -p ")+path);
  TString full_name=name+"."+format;
  if(!fVersion.IsNull()) {
    full_name=name+"__"+fVersion+"."+format;
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

void ejungwoo::gwrite(bool val) {
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
  obj->SetName(name);
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


TF1 *ejungwoo::fitg(TF1 *f, TH1 *h,double c,Option_t *opt) {
  if(fVerbose>1) {
    if(!TString(opt).IsNull()) std::cout<<"fg "<<h->GetName()<<": ["<<c<<"-sigma],[o:"<<TString(opt)<<"]->";
    else                       std::cout<<"fg "<<h->GetName()<<": ["<<c<<"-sigma]->";
  }
  //auto binmax=h->GetMaximumBin();
  //auto max=h->GetBinContent(binmax);
  //auto xmax=h->GetXaxis()->GetBinCenter(binmax);
  //auto xerr=h->GetStdDev();
  auto max=f->GetParameter(0);
  auto xmax=f->GetParameter(1);
  auto xerr=f->GetParameter(2);
  //auto f=new TF1(Form("%s_fitg",h->GetName()),"gaus(0)",xmax-xerr*c,xmax+xerr*c);
  //f->SetParameters(max,xmax,xerr);
  h->Fit(f,opt);
  xmax=f->GetParameter(1);
  xerr=f->GetParameter(2);

  int fitcount = 1;
  double xerr2 = 0.;
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

TF1 *ejungwoo::fitg(TH1 *h,double c,Option_t *opt) {
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

  int fitcount = 1;
  double xerr2 = 0.;
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

TF1 *ejungwoo::fitgg(TH1 *h,double c,Option_t *opt) {
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

  int fitcount = 1;
  double pxerr1 = 0.;
  double pxerr2 = 0.;
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

TF1 *ejungwoo::fitng(int n, TH1 *h,double c,Option_t *opt) {
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

  int fitcount = 1;
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

TF1 *ejungwoo::gg(TF1 *f1, int i) {
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
  int np = f->GetNpar();
  int ng = int(np/3);
  for (auto ig=0;ig<ng;++ig)
    gg(f,ig)->Draw(opt);
  f->Draw(opt);
}

TH1D *ejungwoo::cutx(TH1 *h2, int bin1, int bin2) {
  TGraph graph;
  return cutx(h2,bin1,bin2,&graph);
}

TH1D *ejungwoo::cutx(TH1 *hist, int bin1, int bin2, TGraph *cut_area) {
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
void ejungwoo::addnew(TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  if(fACanvasArray==nullptr)
    fACanvasArray=new TObjArray();

  int idx=fACanvasArray->GetEntries();
  auto name=makename(Form("acvs%d",idx));
  auto acvs=new acanvas(name);
  fACanvasArray->AddAt(acvs,idx);

  addto(acvs, obj, opt, type0, type1, type2, type3);
}
void ejungwoo::addto(acanvas *acvs, TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  if (opt.Index(";")>=0 && obj->InheritsFrom("TNamed")) {
    TObjArray *tokens=opt.Tokenize(";");
    if (tokens->GetEntries()==2) {
      TString name=((TObjString *) tokens->At(0))->GetString();
      ((TNamed *)obj)->SetName(name);
      opt = ((TObjString *)tokens->At(1))->GetString();
    }
    else if (opt.EndsWith(";")) {
      opt.Resize(opt.Sizeof()-2);
      TString name=opt;
      ((TNamed *)obj)->SetName(name);
      opt="";
    }
  }
  acvs->add(obj, opt, type0, type1, type2, type3);
  return;
}
void ejungwoo::addto(int i, TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  if(fACanvasArray==nullptr)
    fACanvasArray=new TObjArray();

  acanvas *acvs = nullptr;
  int numACanvases = fACanvasArray->GetEntries();
  if (numACanvases<=i) {
    auto name = makename(Form("acvs%d",i));
    acvs=new acanvas(name);
    fACanvasArray->AddAt(acvs,i);
  }
  else
    acvs = (acanvas *) fACanvasArray->At(i);

  addto(acvs, obj, opt, type0, type1, type2, type3);
}
void ejungwoo::addto(TString name, TObject *obj, TString opt, Bool_t type0, Bool_t type1, Bool_t type2, Bool_t type3) {
  if(fACanvasArray==nullptr)
    fACanvasArray=new TObjArray();

  makename(name);

  auto acvs=(acanvas *)fACanvasArray->FindObject(name);
  if (acvs==nullptr) {
    acvs=new acanvas(name);
    fACanvasArray->Add(acvs);
  }

  addto(acvs, obj, opt, type0, type1, type2, type3);
}

void ejungwoo::clearall() {
  if (fACanvasArray==nullptr)
    return;
  fACanvasArray->Clear();
}

void ejungwoo::clearc(int i) {
  if (fACanvasArray==nullptr)
    return;
  auto acvs=(acanvas *)fACanvasArray->At(i);
  if (acvs==nullptr)
    return;
  acvs->Clear();
}

void ejungwoo::clearc(TString name) {
  if (fACanvasArray==nullptr)
    return;
  auto acvs=(acanvas *)fACanvasArray->FindObject(name);
  if (acvs==nullptr)
    return;
  acvs->Clear();
}

void ejungwoo::fdraw(bool val) {
  fDraw=val;
  if(fVerbose>0) {
    if(fDraw) std::cout<<"fDraw=true; TCanvas will be written by ejungwoo::save(TCanvas *) method."<<std::endl;
    else      std::cout<<"fDraw=false; TCanvas will NOT!! be written by ejungwoo::save(TCanvas *) method."<<std::endl;
  }
}
TCanvas *ejungwoo::draw(int i,TString opt) {
  auto acvs=(acanvas*)fACanvasArray->At(i);
  if(acvs!=nullptr)
    return acvs->draw(opt);
  return (TCanvas *) nullptr;
}
TCanvas *ejungwoo::draw(TString name,TString opt) {
  auto acvs=(acanvas*)fACanvasArray->FindObject(name);
  if(acvs!=nullptr)
    return acvs->draw(opt);
  return (TCanvas *) nullptr;
}

void ejungwoo::drawall() {
  if (fACanvasArray==nullptr) return;
  auto navcvs = fACanvasArray->GetEntries();
  for(auto iacvs=0;iacvs<navcvs;++iacvs) {
    auto acvs=(acanvas*)fACanvasArray->At(iacvs);
    acvs->draw();
  }
}

void ejungwoo::saveall(TString opt) {
  if (fACanvasArray==nullptr) return;
  auto navcvs = fACanvasArray->GetEntries();
  for(auto iacvs=0;iacvs<navcvs;++iacvs) {
    auto acvs=(acanvas*)fACanvasArray->At(iacvs);
    acvs->save(opt);
  }
}

TObjArray *ejungwoo::fitgsx_list(TH1 *hist, int nDivision, double c, int entry_cut) {
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

TObjArray *ejungwoo::fitgsy_list(TH1 *hist, int nDivision, double c, int entry_cut) {
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

TGraphErrors *ejungwoo::fitgsx(TH1 *hist, int nDivision, double c, int entry_cut, bool error_graph) {
  if(error_graph)
    return fitgsx(hist,"x","dy","dx/2","ddy",nDivision,c,entry_cut);
  return fitgsx(hist,"x","y","dx/2","dy",nDivision,c,entry_cut);
}

TGraphErrors *ejungwoo::fitgsy(TH1 *hist, int nDivision, double c, int entry_cut, bool error_graph) {
  if(error_graph)
    return fitgsy(hist,"y","dx","ddx","",nDivision,c,entry_cut);
  return fitgsy(hist,"x","y","dx","dy/2",nDivision,c,entry_cut);
}

TGraphErrors *ejungwoo::fitgsx(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int nDivision, double c, int entry_cut) {
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

TGraphErrors *ejungwoo::fitgsy(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int nDivision, double c, int entry_cut) {
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

TObjArray *ejungwoo::tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title,int nx,double x1,double x2,int ny,double y1,double y2) { //jumpto_tp4
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
  if (formula.IsNull()) formula=name;
  if(nx==-1)nx=200;
  if(ny==-1)ny=200;
  if(formula.Index(":")>=0) return tp(tree,formula,cut,name,title,nx,0,0,ny,-1,-1);
  else                      return tp(tree,formula,cut,name,title,nx,0,0,-1,-1,-1);
}

TChain *ejungwoo::chain(TString treename, TString filename, int from=0, int to=0, int *rmlist, int numrm) {
  auto tree=new TChain(treename);
  if(fVerbose>0) {
    TString message = Form("%s",filename.Data());
    TString ms_range = Form("[%d-%d",from,to);
    for(auto irm=0;irm<numrm;++irm)
      ms_range = ms_range + TString(Form(",x%d",rmlist[irm]));
    ms_range = ms_range + "]";
    message.ReplaceAll("IDX",ms_range);
    std::cout<<"chain: "<<message<<std::endl;
  }
  if (filename.Index("IDX")>=0)
    for(auto i=from;i<to;++i) {
      bool good = true;
      for(auto irm=0;irm<numrm;++irm) {
        if (i==rmlist[irm]) {
          good = false;
          break;
        }
      }
      if (!good)
        continue;
      TString filenamei = filename;
      if (!fDataDirName.IsNull()) {
        if (filenamei[0]!='/'||filenamei[0]!='~'||filenamei[0]!='.')
          filenamei = fDataDirName + "/" + filenamei;
      }
      filenamei.ReplaceAll("IDX",TString::Itoa(i,10));
      if(fVerbose>0)std::cout<<"       ++ "<<filenamei<<std::endl;
      tree->Add(filenamei);
    }
  else tree->Add(filename);
  return tree;
}

TH1 *ejungwoo::tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,double x1,double x2,int ny,double y1,double y2) { //jumpto_tp0
  makename(name);
  if(fVerbose>0) {
    if(!TString(cut).IsNull()) std::cout<<"tpj "<<name<<": "<<tree->GetName()<<"->[f:"<<formula<<"],[c:"<<TString(cut)<<"]->";
    else                       std::cout<<"tpj "<<name<<": "<<tree->GetName()<<"->[f:"<<formula<<"]->";
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

TH1 *ejungwoo::tppdg(TString name,TTree *tree,TString formula,TCut cut)
{
  auto hist = tp(tree,Form("ejungwoo::pdg_idx(%s)",formula.Data()),cut,name,";particles;",fNumPDGs,0,fNumPDGs);
  pdg_axis(hist -> GetXaxis());
  return hist;
}

TH1 *ejungwoo::tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,double x1,double x2,int ny,double y1,double y2) { //jumpto_tp2
  return tp(tree,formula,cut,name,title,nx,x1,x2,ny,y1,y2);
};

TH1 *ejungwoo::tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,const double *xbins) //jumpto_tp1
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
  auto hnew = (TH2 *) h2->Clone();
  hnew->Reset();
  auto nx=h2->GetXaxis()->GetNbins();
  auto ny=h2->GetYaxis()->GetNbins();
  for (auto binx=1;binx<=nx;++binx) {
    for (auto biny=1;biny<=ny;++biny) {
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      if(cut->IsInside(x,y)==1) {
        int n=h2->GetBinContent(binx,biny);
        //hnew->SetBinContent(binx,biny,h2->GetBinContent(binx,biny));
        if (n<1)
          hnew->Fill(x,y,h2->GetBinContent(binx,biny));
        else
          for (auto i=0;i<int(n);++i) hnew->Fill(x,y);
      }
    }
  }
  return (TH1 *) hnew;
}

TH1 *ejungwoo::cutg_or(TH1 *h, TCutG *cut, TCutG *orcut) {
  auto h2 = (TH2 *) h;
  auto hnew = (TH2 *) h2->Clone();
  hnew->Reset();
  auto nx=h2->GetXaxis()->GetNbins();
  auto ny=h2->GetYaxis()->GetNbins();
  for (auto binx=1;binx<=nx;++binx) {
    for (auto biny=1;biny<=ny;++biny) {
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      if(cut->IsInside(x,y)==1 || orcut->IsInside(x,y)) {
        int n=h2->GetBinContent(binx,biny);
        //hnew->SetBinContent(binx,biny,h2->GetBinContent(binx,biny));
        if (n<1)
          hnew->Fill(x,y,h2->GetBinContent(binx,biny));
        else
          for (auto i=0;i<int(n);++i) hnew->Fill(x,y);
      }
    }
  }
  return (TH1 *) hnew;
}

TH1 *ejungwoo::cutg_and(TH1 *h, TCutG *cut, TCutG *andcut) {
  auto h2 = (TH2 *) h;
  auto hnew = (TH2 *) h2->Clone();
  hnew->Reset();
  auto nx=h2->GetXaxis()->GetNbins();
  auto ny=h2->GetYaxis()->GetNbins();
  for (auto binx=1;binx<=nx;++binx) {
    for (auto biny=1;biny<=ny;++biny) {
      auto x=h2->GetXaxis()->GetBinCenter(binx);
      auto y=h2->GetYaxis()->GetBinCenter(biny);
      if(cut->IsInside(x,y)==1 && andcut->IsInside(x,y)) {
        int n=h2->GetBinContent(binx,biny);
        //hnew->SetBinContent(binx,biny,h2->GetBinContent(binx,biny));
        if (n<1)
          hnew->Fill(x,y,h2->GetBinContent(binx,biny));
        else
          for (auto i=0;i<int(n);++i) hnew->Fill(x,y);
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
      int n=h2->GetBinContent(binx,biny);
      for (auto i=0;i<n;++i)
        hnew->Fill(y,x);
    }
  return make(fDefaultMake,(TH1 *)hnew);
}

std::ifstream& ejungwoo::ofile(TString name) {
  fIfStream.open(name);
  return fIfStream;
}

TString ejungwoo::readline(std::ifstream& infile) {
  std::string line;
  if (std::getline(infile, line))
    return TString(line);
  else
    return TString("EOF");
}

TString ejungwoo::readline() {
  return readline(fIfStream);
}

void ejungwoo::cfile() {
  fIfStream.close();
}

TObjArray *ejungwoo::csv(TString line) {
  return line.Tokenize(",");
}

TString ejungwoo::tok(TObjArray *line, int i) {
  return ((TObjString *) line->At(i))->GetString();
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
