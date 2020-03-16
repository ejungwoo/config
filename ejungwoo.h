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

namespace ejungwoo
{
  class t_meanerror;
  class t_wrapper;
  class t_canvas;

  TString fVersionIn;
  TString fVersionOut;
  TString fFigDirName = "figures";
  TString fDataDirName = "data";
  TString fVMarkText;
  TString fHeader;
  TString fFooter;

  bool fAllowSave = true;
  bool fAllowWrite = true;
  bool fAllowDrawC = true;
  bool fNaming = true;
  bool fDarkMode = false;
  bool fUsePDGName = true;
  bool fFixStatsboxSize = false;
  int fVerbose = 0;
  int fVerboseG = 0;
  int fVerboseS = 0;
  int fXInitCvs = 0;
  int fYInitCvs = 0;
  int fCountCvs = 0;
  int fCountCvsXIdx = 0;
  int fCountCvsYIdx = 0;
  int fCountHist = 0;
  int fCountGraph = 0;
  int fCountFrame = 0;
  int fTextFont = 132;
  int fNumAxisPDGs = 26;
  int fFillStylePave = 0;
  int fBorderSizePave = 1;
  int fFillStyleLegend = 0;
  int fBorderSizeLegend = 1;
  int fFillStyleStatsbox = 0;
  int fBorderSizeStatsbox = 1;
  int fAxisNDivisions = 506;
  double fdXStatsboxByRatio = .4;
  double fdYStatsboxByRatio = .28;
  double fXOffStatsbox = 0;
  double fYOffStatsbox = 0;
  double fWidthDefaultPave = 0.18;
  double fWidthPerLengthPave = 0.009;
  double fHeightPerEntryPave = 0.06;
  double fWidthDefaultLegend = 0.18;
  double fWidthPerLengthLegend = 0.009;
  double fHeightPerEntryLegend = 0.06;
  double fTMargin = 0.12;
  double fBMargin = 0.16;
  double fLMargin = 0.19;
  double fRMargin = 0.055;
  double fRMargin1 = 0.055;
  double fRMarginWithz = 0.155;
  double fTopMainTitleSize = 0.08; // top title
  double fAxisTitleSizes[]  = {0.05 ,  0.065, 0.075, 0.09, 0.11};
  double fAxisLabelSizes[]  = {0.045,  0.05 , 0.055, 0.07, 0.09};
  double fZAxisLabelSizes[] = {0.030,  0.035, 0.045, 0.05, 0.06};
  double fXTitleOffsets[]   = {1.30 ,  1.15 , 1.00 , 0.80, 0.80};
  double fYTitleOffsets[]   = {1.90 ,  1.45 , 1.30 , 1.10, 1.00};

  int fNumColors = 31;
  Color_t fColorList[] = {
    kOrange-4, kOrange+6, kOrange+8, kOrange-3, kOrange, kYellow,
    kSpring+8, kSpring+7, kSpring-5, kTeal+5, kSpring-6, kTeal+3, kCyan+3, kCyan+2, kCyan+1,
    kAzure+7, kBlue-4, kBlue, kBlue+1, kViolet+4, kViolet-6, kViolet-5,
    kPink+3, kRed+1, kRed, kRed-4, kPink-2, kPink+7, kOrange+3, kSpring+6, kSpring+1,
  };

  int fNumCbColors = 8;
  Color_t fColorCombi[] = { kBlack, kRed-4, kBlue, kSpring-5, kViolet-5, kCyan+1, kOrange-3, kGray+2, };

  TObjArray *fWrittenFileArray;
  TObjArray *fEJCanvasArray;
  std::ifstream fDummyIfstream;
  TFile *fFileDummyGraphics = nullptr;


  /********************************************************/


  // global
  void gverbose(int verbose=1); ///< print verbosity, 0: silent, 1: print, 2: print more
  void gverboseG(int verbose=1); ///< graphic verbosity, 0: silent, 1: draw fits
  void gverbosePS(int verbose=1); ///< graphic verbosity, 0: silent, 1: draw from tree, 2: save from tree
  void gender(TString header, TString footer); ///< Set header and footer for file, t_canvas, savings, and writings
  void gheader(TString header); ///< Set header for file, t_canvas, savings, and writings
  void gfooter(TString footer); ///< Set footer for file, t_canvas, savings, and writings
  void gnaming(bool naming); ///< Set false to stop naming with header and footer
  void gdark(bool dm = true); ///< dark mode (drawing)
  void ginitstyle(); ///< Initialize gStyle setting. Should NOT be run by users.
  void gstat(Option_t *opt); ///< equalivant to gStyle->SetOptStat(opt);
  void gstat(int opt); ///< equalivant to gStyle->SetOptStat(opt);
  void gfstat(int opt); ///< equalivant to gStyle->SetOptFit(opt);
  void gzcolor(int opt); ///< set z-palette color to 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale
  void gfill(int style); ///< set fill style for pavetext
  void gfont(int textfont); ///< set default font
  void gstatpos(double xoff, double yoff=0); ///< set statsbox position offset
  void gstatsize(double dx_byratio = 0.4, double dy_byratio = 0.28); ///< force statsbox size
  void gfixstatsize(bool val); ///< reset force-statsbox-size
  void gcvspos(double xoff, double yoff=0); ///< set initial canvas position in the monitor
  void gresetcvsx(); ///< reset canvas x-position to initial position
  void gresetcvsy(); ///< reset canvas y-position to initial position
  void gversion(TString val); ///< if version is set, fVersion is used instead of doing verson control.
  void gversionin(TString val); ///< if version is set, fVersion is used instead of doing verson control.
  void gversionout(TString val); ///< if version is set, fVersion is used instead of doing verson control.
  void gvmark(TString vmtext); ///< Set flag for drawing version mark on the canavs
  void gdata(TString name=""); ///< Set name of the data file ("data" by default).
  void gfig(TString name=""); ///< Set name of the figure file ("figures" by default).
  void gsave(bool val); ///< set save flag of saving canvas using method save()
  void gwrite(bool val); ///< set write flag of writting object using method write(TObject *)
  void gpdgname(bool usename); // set use pdgname
  void gdraw(bool val); ///< set drawc flag of drawing t_canvas using method drawc()
  void gcutt(double r=0.04); ///< cut canvas top margin to r=(0.04)
  void gcutr(double r=0.02); ///< cut canvas right margin to r=(0.02)
  void gcutl(double r=0.02); ///< cut canvas right margin to r=(0.02)
  void gcutb(double r=0.02); ///< cut canvas right margin to r=(0.02)
  void gcuttr(double r=0.02); ///< cut canvas right margin to r=(0.02)
  void gcutall(double r=0.02); ///< cut canvas all margin to r=(0.02)
  void gndiv(int nd=506); ///< make axis ndivisions to nd!, (root default 510, namespace default 506)


  // version
  TString version(); ///< return version
  TString versionin(); ///< return version
  TString versionout(); ///< return version
  const char *versioncc(); ///< return version
  const char *versionincc(); ///< return version
  const char *versionoutcc(); ///< return version
  TText *getvmark(bool draw=true, TString vmtext=""); ///< Get version mark text of default margin setting in this script TODO with cvs


  // naming
  void pfname(TString str, TString &pathname, TString &filename, TString delim="/"); ///< get pathname=[path-name], filename=[file-name] after tonizing with delim
  TString firstname(TString str, TString delim="."); ///< get first name
  TString lastname(TString str, TString delim="/"); ///< get last name
  TString justname(TString str); ///< get name with no path and format. just name
  TString toname(TString str);
  TString makename(const char *name); ///< Make name = header + name + footer
  TString makename(TString name); ///< Make name = header + name + footer
  TString name_fig(); // get name figures directory
  TString name_data(); // get name data directory
  TString name_file(TString name); // give name to file 
  TString name_full(TString name); // give full path name to file 


  // file
  bool isfile(TString filename); ///< does this file exist?
  TFile *gfile(TString filename); ///< save graphic if fVerboseG>1


  // colors
  void colorwheel(); ///< show colorwheel
  void markers(); ///< show markers
  void colorlist(); ///< draw color list used in function colori()
  void colorcblist(); ///< draw color list used in function colori()
  Color_t colori(int icolor); ///< get selected list of root colors. Run function colorlist() to see color list. Or see fColorList.
  Color_t ccombi(int icolor);


  // Option_t 
  bool check_option(TString from_this, const char *find_this);
  bool check_option(Option_t *from_this, const char *find_this) { return check_option(TString(from_this),find_this); }


  // TObject 
  TObject *make(TObject *ob); ///< make object stylish!, jumpto_makeo
  TFile *write(TObject *obj, bool version_control = true); ///< write object ./data/[obj name].[version-automatically updated].root
  TFile *write(TString name, TNamed *obj, bool version_control = true); ///< write to file with name 'name'

  // TCanvas 
  TCanvas* make_c(TCanvas *cvs, TString vmtext=""); // jumpto_makec
  TCanvas* new_c(TString name="", TString title="", double w=0, double h=0, bool withz=0, TString options=""/*"xyz"*/); // jumpto_new_c
  TCanvas* new_c(TString name="", double w=0, double h=0, bool withz=0, TString options=""/*"xyz"*/) { return new_c(name,name,w,h,withz,options); }
  TCanvas* cv(TString name="", double w=600, double h=500, TString options="") { return new_c(name, w, h, false, options); }
  TCanvas* cc(TString name="", double w=600, double h=500, TString options="") { return new_c(name, w, h, true,  options); }
  TCanvas* cv1(TString name="") { return new_c(name, 500, 550, false); }
  TCanvas* cv2(TString name="") { return new_c(name, 600, 550, false); }
  TCanvas* cv3(TString name="") { return new_c(name, 680, 550, false); }
  TCanvas* cc1(TString name="") { return new_c(name, 600, 550, true ); }
  TCanvas* cc2(TString name="") { return new_c(name, 680, 550, true ); }
  TCanvas* cc3(TString name="") { return new_c(name, 900, 550, true ); }
  TCanvas* cc4(TString name="") { return new_c(name,1200, 800, true ); }
  TCanvas* cdraw13(TString name="", TH1 *h1=nullptr,  TH1 *h2=nullptr, TH1 *h3=nullptr, double size_ratio=1., Option_t *drawopt="hist"); //    jumpto_cdraw13
  TCanvas* cdraw13(TCanvas *cvs, int idx, TH1 *hist, Option_t *drawopt="hist"); //    jumpto_cdraw13_
  TCanvas* cdraw12(TString name="", TH1 *h1=nullptr,  TH1 *h2=nullptr, double size_ratio=1., Option_t *drawopt="hist"); //    jumpto_cdraw12
  TCanvas* cdraw12(TCanvas *cvs, int idx, TH1 *hist, Option_t *drawopt="hist");  // jumpto_cdraw12_
  TCanvas* div(TCanvas *c,int nx,int ny,Float_t xm=0.001,Float_t ym=0.001,int color=0); ///< Divide canvas
  TCanvas* div0(TCanvas *c,int nx,int ny); ///< Divide canvas with no margins no gaps
  void save(TVirtualPad *cvs, TString format="pdf", bool version_control = true); ///< save TVirtualPad. See as save(TCanvas *) for detail
  void save(TCanvas *cvs, TString format="pdf", bool version_control = true); ///< save cavans ./figures__[version]/[canvas name].[version-automatically updated].[format]
  void save(TString name, TCanvas *cvs, TString format="pdf", bool version_control = true); ///< save cavans ./figures__[version]/[name].[version-automatically updated].[format]


  //TH1
  TH1 *make_h(int s, TH1 *h, double xc=1., double yc=1.); ///< make histogram stylish! (s)bigger!, jumpto_maken
  TH1 *make_h(TH1 *h) { return ejungwoo::make_h(2,h); } ///< make histogram stylish!, jumpto_makeh
  TH1D *new_h(double x1, double x2); ///< make dummy histogram frame
  TH2D *new_h(double x1, double x2, double y1, double y2); ///< make dummy histogram frame
  TH2D *new_h(TGraph *graph); ///< make dummy histogram frame from range computed from the graph
  TH1 *tohist(double *buffer, int n, TString name = "", TString title = ""); ///< make histogram with given buffer
  TH1 *tohist(double *buffer, int i, int f, TString name = "", TString title = ""); ///< make histogram with given buffer in range i->f
  TH1 *inv(TH1 *h); ///< recreate histogram from "x vs y" to "y to x"
  TH1 *dndx(TH1 *h); ///< make graph y axis to dn/dx where n is number of entries
  TH1 *norm_max(TH1 *h, double maxto = 1); ///< normalize maximum value of histogram to maxto(=1 by default)
  TH1 *norm_integral(TH1 *h, double normto = 1); ///< normalize integral value of histogram to normto(=1 by default)
  TH1D *cuty(TH1 *hist, int bin1, int bin2); ///< TODO
  TH1D *cuty(TH1 *hist, int bin1, int bin2, TGraph *cut_area); ///< TODO
  TH1D *cutx(TH1 *hist, int bin1, int bin2); ///< cut TH2 histogram in x from x-bin = bin1~bin2 and project histogram to y
  TH1D *cutx(TH1 *hist, int bin1, int bin2, TGraph *cut_area); ///< same as above but TGraph *cut_area is set to area of cut region in h2;
  TH1D *fold0(TH1D *h);
  TH2D *fold0(TH2D *h);
  TH1D *pdg_hist(const char *name="particleID", const char *title=";particles;");
  void nobox(TCanvas *cvs, TH1 *hist);
  void pdg_axis(TAxis *axis);
  int  pdg_idx(int pdg);
  double max(TH1 *h); ///< get maximum value of histogram
  double max(TH1 *h, int &bin, double &x); ///< get maximum value of histogram
  TObjArray *fitgsx_list(TH1 *hist, int ndivisions=20, double c=1.5, int entry_cut=1000);
  TObjArray *fitgsy_list(TH1 *hist, int ndivisions=20, double c=1.5, int entry_cut=1000);
  TGraphErrors *fitgsx(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int ndivisions, double c, int entry_cut);
  TGraphErrors *fitgsy(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int ndivisions, double c, int entry_cut);
  TGraphErrors *fitgsx(TH1 *hist, int ndivisions=20, double c=1.5, int entry_cut=1000);
  TGraphErrors *fitgsy(TH1 *hist, int ndivisions=20, double c=1.5, int entry_cut=1000);
  double fwrm(TH1 *h, double ratio, double ndx, double &x0, double &x1, double &q); ///< full width [ratio] maximum : return width of histogram at y which the data becomes [ratio] of maximum (ratio*maximum)
  double fwhm(TH1 *h, double &x0, double &x1, double &q); ///< FWHM(Full Width Half Maximum) of histogram. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q);
  double fwhm(TH1 *h); ///< FWHM(Full Width Half Maximum) with histogram. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q) with no pull values
  TH1 *free (TH1 *h); ///< make axis labels feel free!
  TH1D *subtract(TH1D *hist,TF1 *f1);


  // TGraph 
  TGraph *new_g(TString name=""); ///< jumpto_newg
  TGraph *make_g(TGraph *gr, int mi=20, float ms=.8, int mc=1); ///< make graph stylish!, jumpto_makeg
  double x1_g(TGraph* graph);
  double x2_g(TGraph* graph);
  double y1_g(TGraph* graph);
  double y2_g(TGraph* graph);
  TGraphErrors *new_ge(TString name=""); ///< jumpto_new_ge
  TGraphErrors *make_ge(TGraphErrors *gr, int mi=20, float ms=.8, int mc=1); ///< make error graph stylish!, jumpto_makege
  TGraphErrors *tograph(TString filename); // TODO
  TGraph *sumf(std::vector<TF1*> &fs); ///< TODO create TF1 which is sum of TF1s in fs;


  // TF1
  TF1 *make_f(TF1 *f); ///< make function stylish!, jumpto_makef
  TF1 *settitle(TF1 *f, TString title); ///< set title of function histogram
  TF1 *fitg(TGraph *g, TH1 *h, double c=2.5, Option_t *opt="RQ0");
  TF1 *fitg(TF1 *f1, TH1 *h, double c=2.5, Option_t *opt="RQ0");
  TF1 *fitg(TH1 *h, double c=2.5, Option_t *opt="RQ0"); ///< single gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *fitgg(TH1 *h, double c=2.5, Option_t *opt="RQ0"); ///< double gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *fitng(int n, TH1 *h, double c=2.5, Option_t *opt="RQ0"); ///< n gaussian fit of histogram in range of -c*sigma ~ +c*sigma
  TF1 *gg(TF1 *f, int i); ///< get i'th gaussian from multipule gaussian function f1
  TObjArray *infog(TF1 *f, int cmax=5, vector<int> guideCS={0,1});
  void drawgg(TF1 *f, Option_t *opt="samel"); ///< Draw n-gaussian separately
  double fwrm(TF1 *f, double ratio, double ndx, double &x0, double &x1, double &q); ///< calculate and return full width [ratio] maximum of function
  double fwhm(TF1 *f, double &x0, double &x1, double &q); ///< FWHM(Full Width Half Maximum) of function. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q);
  double fwhm(TF1 *f); ///< FWHM(Full Width Half Maximum) with function. ndx=0.5 of fwrm(f,ration,ndx,x0,x1,q) with no pull values
  TString expf1(TF1 *f1, TString expx="x", int digits = 2);
  TF1 *clonef1(TF1 *f1, TString name="", int icopy=0);


  // TText
  TText *make_t(TText *tt, Short_t a=22);
  void toss(TText *att, Color_t color=kBlack, TString align="cc", Size_t size=0.05, Font_t font=132);


  // statsbox
  TPaveStats *find_statsbox(TCanvas *cvs);
  TPaveStats *make_s(TCanvas *cvs, TPaveStats *statsbox);
  TPaveStats *make_s(TPaveStats *statsbox);
  TPaveText *make_p(TPaveText *pave); ///< make pave text stylish!, jumpto_makep


  // TLegend
  TLegend *make_l(TCanvas *cvs, TLegend *legend, double x_offset=0, double y_offset=0, double width_fixed=0, double height_fixed=0); // jumpto_makel
  TLegend *make_l(TLegend *legend, double x_offset=0, double y_offset=0, double width_fixed=0, double height_fixed=0);


  // TCutG
  TCutG *cutg(TString f, TString cutname, TString x="x", TString y="y"); ///< set TCutG from file name
  TCutG *cutg(TFile  *f, TString cutname, TString x="x", TString y="y"); ///< set TCutG from file
  TH1 *cutg(TH1 *h, TCutG *cut); ///< recreate histogram satisfying graphical cut
  TH1 *cutg_or(TH1 *h, TCutG *cut, TCutG *orcut); ///< recreate histogram satisfying cut or orcut
  TH1 *cutg_and(TH1 *h, TCutG *cut, TCutG *andcut); ///< recreate histogram satisfying cut and orcut


  // file
  std::ifstream& ofile(TString name); ///< open file as ifstream
  TString readline(std::ifstream& infile); ///< read line and return as TString of stream infile
  TString readline(); ///< read line and return as TString of stream open by ofile
  void cfile(); /// close stream open by ofile


  // t_canvas
  void add(TObject *obj, TString options_draw=""); ///< add objects to 1'st t_canvas with option
  void addnew(TObject *obj, TString options_draw=""); ///< add objects to new t_canvas with option
  void addto(int ith, TObject *obj, TString options_draw=""); ///< add objects to ith t_canvas with option
  void addto(TString name, TObject *obj, TString options_draw=""); ///< add objects to t_canvas with name option
  void addto(t_canvas *ejcv, TObject *obj, TString options_draw=""); ///< add objects to ejcv option
  void clearall(); ///< clear all t_canvas
  void clearc(int i=0); ///< clear t_canvas of index i
  void clearc(TString name); ///< clear t_canvas of name name
  TCanvas *drawc(int i,TString opt="cvs"); ///< draw objects in t_canvas of index i collected by add()/addto(). jump_to_drawc1
  TCanvas *drawc(TString name,TString opt="cvs"); ///< draw objects in t_canvas of name name collected by add()/addto(). jump_to_drawc2
  void drawall();
  void saveall(TString opt="pdf");


  // TTree
  TChain *chain(TChain *c, TString treename, TString filename, int from=0, int to=0, int *rmlist={}, int numrm=0);
  TChain *chain(TString treename, TString filename, int from=0, int to=0, int *rmlist={}, int numrm=0);
  TChain *chain(TString filename, int from=0, int to=0, TString treename="data") { return chain(treename,filename,from,to); }
  TH1 *tppdg(TString name,TTree *tree,TString formula="pdg",TCut cut=""); ///< draw pdg distribution from PDG incoding
  TH1 *tp(TTree *tree,TString formula,TCut cut,TString name,TString title,int nx,double x1,double x2,int ny=-1,double y1=-1,double y2=-1); ///< simple tree projection starting with tree, jumpto_tp0
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,const double *xbins); ///< simple tree projection starting with name using xbins for x-axis, jumpto_tp1
  TH1 *tp(TString name,TTree *tree,TString formula,TCut cut,TString title,int nx,double x1,double x2,int ny=-1,double y1=-1,double y2=-1); ///< simple tree projection starting with name, jumpto_tp2
  TH1 *tp(TString name,TTree *tree,TString formula="",TCut cut="",TString title="",int nx=-1,int ny=-1); ///< tree projection with automatic bin range calculation default nx, ny is 200, jumpto_tp3
  TObjArray *tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title,int nx,double x1,double x2,int ny=-1,double y1=-1,double y2=-1); ///< tree projection from tree with cuts, return array of histograms with applied cut jumpto_tp4
  TObjArray *tp(TString name,TTree *tree,TString formula,std::vector<TCut> cuts,TString title="",int nx=-1,int ny=-1); ///< tree projection from tree with automatic bin range calculation with cuts return array of histograms with applied cut jumpto_tp5


  // buffer
  int max(int *buffer, int n); ///< get maximum value of buffer
  double max(double *buffer, int n); ///< get maximum value of buffer


  // name
  TObjArray *tok(TString line, TString token); ///< tokenize scv format to array of TObjString. Use tok to get TString of each TObjString
  TString tok(TString line, TString token, int i);
  TString tok(TObjArray *line, int i); ///< Get TString from TObjString "line" of index i
}; 

class ejungwoo::t_meanerror : public TObject {
  public:
    TH1D *hist;
    double fdX = 0;
    double fdY = 0;
    double fMeanX = 0;
    double fMeanY = 0;
    double fSigmaX = 0;
    double fSigmaY = 0;

    t_meanerror(TH1D *h): TObject(),hist(h) {}
    virtual ~t_meanerror() {}

    double get_value(TString val) {
      /**/ if (val.Index("x")>=0) return fMeanX;
      else if (val.Index("y")>=0) return fMeanY;
      else if (val.Index("dx")>=0) return fdX;
      else if (val.Index("dy")>=0) return fdY;
      else if (val.Index("dxh")>=0) return fdX/2.;
      else if (val.Index("dyh")>=0) return fdY/2.;
      else if (val.Index("sigx")>=0) return fSigmaX;
      else if (val.Index("sigy")>=0) return fSigmaY;
      return 0;
    }
};

class ejungwoo::t_wrapper : public TNamed {
  private:
    TObject *fObject;
    TString fDrawOption;
    TString fLegendOption;
    int fIdxInCanvas = -1;
    int fObjectType = 0;
    double fX1Range, fX2Range, fY1Range, fY2Range;
    bool fLogx = false, fLogy = false, fLogz = false;
    bool fOmitDraw = false;

  public:
    t_wrapper(TObject *obj, TString draw_option="")
      : fObject(obj), fDrawOption(draw_option)
    {
      SetName(obj->GetName());

      if (fDrawOption.Index("logx")>=0) { fDrawOption.ReplaceAll("logx",""); fLogx = true; }
      if (fDrawOption.Index("logy")>=0) { fDrawOption.ReplaceAll("logy",""); fLogy = true; }
      if (fDrawOption.Index("logz")>=0) { fDrawOption.ReplaceAll("logz",""); fLogz = true; }

      if (fObject->InheritsFrom(TH2::Class())) {
        auto hist = (TH2 *) make_h((TH2 *) fObject);
        SetTitle(hist->GetTitle());

        fObjectType = 2;
        if (fDrawOption=="frame") {}
        else if (fDrawOption.Index("col")<0) fDrawOption = fDrawOption + " colz";
        fLegendOption = "";

        fX1Range = hist -> GetXaxis() -> GetBinLowEdge(1);
        fX2Range = hist -> GetXaxis() -> GetBinUpEdge(hist -> GetNbinsX());
        fY1Range = hist -> GetYaxis() -> GetBinLowEdge(1);
        fY2Range = hist -> GetYaxis() -> GetBinUpEdge(hist -> GetNbinsY());
      }
      else if (fObject->InheritsFrom(TH1::Class())) {
        auto hist = make_h((TH1 *) fObject);
        SetTitle(hist->GetTitle());

        fObjectType = 1;
        fLegendOption =  "f";

        fX1Range = hist -> GetXaxis() -> GetBinLowEdge(1);
        fX2Range = hist -> GetXaxis() -> GetBinUpEdge(hist -> GetNbinsX());
        fY1Range = hist -> GetMinimum();
        fY2Range = hist -> GetMaximum();
      }
      else if (fObject->InheritsFrom(TF2::Class())) {
        auto function = (TF2 *) make_f((TF2 *) fObject);
        SetTitle(function->GetName());

        fObjectType = 4;
        fLegendOption =  "l";
        if (fDrawOption.IsNull()) fDrawOption = "l";

        fX1Range = function -> GetXmin();
        fX2Range = function -> GetXmax();
        fY1Range = function -> GetYmin();
        fY2Range = function -> GetYmax();
      }
      else if (fObject->InheritsFrom(TF1::Class())) {
        auto function = make_f((TF1 *) fObject);
        SetTitle(function->GetName());

        fObjectType = 3;
        fLegendOption =  "l";
        if (fDrawOption.IsNull()) fDrawOption = "l";

        fX1Range = function -> GetXmin();
        fX2Range = function -> GetXmax();
        fY1Range = function -> GetMaximum();
        fY2Range = function -> GetMinimum();
      }
      else if (fObject->InheritsFrom(TGraph::Class())) {
        auto graph = make_g((TGraph *) fObject);
        SetTitle(graph->GetTitle());

        fObjectType = 5;
        fLegendOption =  "l";
        if (fDrawOption.IsNull()) fDrawOption = "pl";

        graph -> ComputeRange(fX1Range, fY1Range, fX2Range, fY2Range);
      }
      else
        fObjectType = 0;

      fDrawOption.ToLower();
    }

    virtual void Draw(Option_t *draw_option="") {
      if (!fOmitDraw)
        fObject -> Draw(fDrawOption);
    }

    TObject *GetObject() { return fObject; }

    TString GetDrawOption() { return fDrawOption; }
    void SetDrawOption(TString draw_option) { fDrawOption = draw_option; }
    bool Withz() { if (fDrawOption.Index("z")>=0) return true; return false; }

    void SetIdxInCanvas(int val) {
      fIdxInCanvas = val;
      if (fIdxInCanvas==0 && fDrawOption.Index("same")>=0)
        fDrawOption.ReplaceAll("same","");
      else if (fIdxInCanvas!=0 && fDrawOption.Index("same")<0)
        fDrawOption = fDrawOption + " same";
    }

    int GetType()     { return fObjectType; }
    int IsHistogram() { if (fObjectType==1||fObjectType==2) return true; return false; }
    int IsFunction()  { if (fObjectType==3||fObjectType==4) return true; return false; }
    int IsGraph()     { if (fObjectType==5)                 return true; return false; }
    int IsOther()     { if (fObjectType==0)                 return true; return false; }
    int IsRanged()    { if (fObjectType!=0)                 return true; return false; }
    int IsH2()        { if (fObjectType==2)                 return true; return false; }

    double GetX1() { return fX1Range; }
    double GetX2() { return fX2Range; }
    double GetY1() { return fY1Range; }
    double GetY2() { return fY2Range; }
    void SetRangeUser(double y1, double y2) {
      if (IsHistogram())
        ((TH1 *) fObject) -> GetYaxis() -> SetRangeUser(y1, y2);
    }

    bool IsLogx() { return fLogx; }
    bool IsLogy() { return fLogy; }
    bool IsLogz() { return fLogz; }

    void OmitDraw(bool val=true) { fOmitDraw = val; }

    void AddToLegend(TLegend *legend)
    {
      if (!fLegendOption.IsNull())
        legend -> AddEntry(fObject,fTitle,fLegendOption);
    }
};

class ejungwoo::t_canvas : public TObjArray
{
  private:
    TCanvas *fCanvas = nullptr;
    TString fVMarkTextForEJCvs;

  public:
    t_canvas(TString name, TString vmark="") {
      SetName(name);
      fVMarkTextForEJCvs = vmark;
    }

    /****************************************************************/
    void add(TObject *object, TString canvas_option="")
    {
      auto wrap = new t_wrapper(object,canvas_option);

      if (!ejungwoo::fVMarkText.IsNull() && fVMarkTextForEJCvs.IsNull())
        fVMarkTextForEJCvs = fVMarkText;

      if (ejungwoo::fVerbose>=1)
        std::cout << "add t_wrapper:" << object->GetName() << "(\"" << canvas_option << "\")" << " to ej_canvas:" << fName << std::endl;

      TObjArray::Add(wrap);
    }

    /****************************************************************/
    TCanvas *drawc(TString cvs_option="cvs")
    {
      if (!ejungwoo::fAllowDrawC)
        return (TCanvas *) nullptr;

      int numDrawings = GetEntries();
      if (ejungwoo::fVerbose>=2)
        std::cout << "Drawing t_canvas: " << fName << " containing " << numDrawings <<  " drawings"  << std::endl;

      double y1_user = DBL_MAX;
      double y2_user = -DBL_MAX;
      double x1_user = DBL_MAX;
      double x2_user = -DBL_MAX;

      bool set_logx = false;
      bool set_logy = false;
      bool set_logz = false;

      vector<t_wrapper *> list_histograms;
      vector<t_wrapper *> list_functions;
      vector<t_wrapper *> list_graphs;
      vector<t_wrapper *> list_others;

      t_wrapper *frame_wrap = nullptr;
      auto legend = new TLegend();

      for (auto idraw=0; idraw<numDrawings; ++idraw)
      {
        auto wrap = (t_wrapper *) At(idraw);
        if (wrap->IsHistogram())  {
          if (frame_wrap == nullptr) frame_wrap = wrap;
          list_histograms.push_back(wrap);
        }
        else if (wrap->IsFunction()) list_functions.push_back(wrap);
        else if (wrap->IsGraph()) list_graphs.push_back(wrap);
        else list_others.push_back(wrap);

        if (wrap->IsRanged()) {
          if (x1_user < wrap -> GetX1()) x1_user = wrap -> GetX1();
          if (x2_user > wrap -> GetX2()) x2_user = wrap -> GetX2();
          if (y1_user < wrap -> GetY1()) y1_user = wrap -> GetY1();
          if (y2_user > wrap -> GetY2()) y2_user = wrap -> GetY2();
          wrap -> AddToLegend(legend);
        }

        if (wrap -> IsLogx()) set_logx = true;
        if (wrap -> IsLogy()) set_logy = true;
        if (wrap -> IsLogz()) set_logz = true;
      }

      y2_user = 1.05 * y2_user;
      y1_user = 0.95 * y1_user;
      x2_user = 1.05 * x2_user;
      x1_user = 0.95 * x1_user;


      if (frame_wrap==nullptr) {
        auto frame_hist = new TH2D(fName+"_frame","",200,x1_user,x2_user,200,y1_user,y2_user);
        frame_wrap = new t_wrapper(frame_hist,"frame");
      }
      frame_wrap -> SetIdxInCanvas(0);
      if (set_logy) frame_wrap -> SetRangeUser(y1_user/2.,y2_user*10.);
      else frame_wrap -> SetRangeUser(y1_user,y2_user);


      if (cvs_option.Index("cvs")>=0 || gPad == nullptr) {
        if (frame_wrap->Withz())
          fCanvas = cc(fName);
        else fCanvas = cv(fName);
      }
      else
        fCanvas = (TCanvas *) gPad;
      fCanvas -> cd();

      frame_wrap -> Draw();
      frame_wrap -> OmitDraw();



      int fCountDraw = 1;
      for (auto list : {list_histograms,list_functions,list_graphs,list_others}) {
        for (auto wrap : list) {
          wrap -> SetIdxInCanvas(fCountDraw++);
          wrap -> Draw();
        }
      }

      make_l(legend) -> Draw("same");

      if (set_logx) fCanvas -> SetLogx();
      if (set_logy) fCanvas -> SetLogy();
      if (set_logz) fCanvas -> SetLogz();

      return make_c(fCanvas, fVMarkTextForEJCvs);
    }

    void save(TString opt="") {
      ejungwoo::save(fCanvas,opt);
    }
};

void ejungwoo::gverbose(int verbose=1) { fVerbose = verbose; }
void ejungwoo::gverboseG(int verbose=1) { fVerboseG = verbose; }
void ejungwoo::gverbosePS(int verbose=1) { fVerboseS = verbose; }
void ejungwoo::gender(TString header, TString footer) { fHeader = header; fFooter = footer; }
void ejungwoo::gheader(TString header) { fHeader = header; }
void ejungwoo::gfooter(TString footer) { fFooter = footer; }
void ejungwoo::gnaming(bool naming) { fNaming = naming; }
void ejungwoo::gdark(bool dm = true) { fDarkMode = dm; }
void ejungwoo::gstat(int opt) { gStyle -> SetOptStat(opt); }
void ejungwoo::gstat(Option_t *opt) { gStyle -> SetOptStat(opt); }
void ejungwoo::gfstat(int opt) { gStyle -> SetOptFit(opt); }
void ejungwoo::gzcolor(int opt) {
  if(fVerbose>0) std::cout<<"gzcolor("<<opt<<") >> 0:kBird, 1:kRainBow, 2:kDeepSea, 3:kAvocado, 4:kBlueGreenYellow, 5:kBrownCyan, else:kGreyScale"<<std::endl;
  /**/ if(opt == 0) gStyle->SetPalette(kBird);
  else if(opt == 1) gStyle -> SetPalette(kRainBow);
  else if(opt == 2) gStyle -> SetPalette(kDeepSea);
  else if(opt == 3) gStyle -> SetPalette(kAvocado);
  else if(opt == 4) gStyle -> SetPalette(kBlueGreenYellow);
  else if(opt == 5) gStyle -> SetPalette(kBrownCyan);
  else if(opt == 6) gStyle -> SetPalette(kLightTemperature);
  else              gStyle -> SetPalette(kGreyScale);
}
void ejungwoo::gfill(int style) { fFillStylePave = style; }
void ejungwoo::gfont(int textfont) { fTextFont = textfont; }
void ejungwoo::gstatpos(double xoff, double yoff) {
  fXOffStatsbox = xoff;
  fYOffStatsbox = yoff;
}
void ejungwoo::gstatsize(double dx_byratio, double dy_byratio) {
  fFixStatsboxSize = true;
  fdXStatsboxByRatio = dx_byratio;
  fdYStatsboxByRatio = dy_byratio;
}
void ejungwoo::gfixstatsize(bool val) { fFixStatsboxSize = val; }
void ejungwoo::gcvspos(double xoff, double yoff) { fXInitCvs = xoff; fYInitCvs = yoff; }
void ejungwoo::gresetcvsx() { fCountCvsXIdx = 0; }
void ejungwoo::gresetcvsy() { fCountCvsYIdx = 0; }
void ejungwoo::gversion(TString val) {
  gversionout(val);
  gversionin(val);
}
void ejungwoo::gversionin(TString val) {
  fVersionIn = val;
  gfig();
  gdata();
  if (fVerbose>0) std::cout<<"fVersionIn =["<<fVersionIn<<"]"<<std::endl;
}
void ejungwoo::gversionout(TString val) {
  fVersionOut = val;
  gfig();
  gdata();
  if (fVerbose>0) std::cout<<"fVersionOut=["<<fVersionOut<<"]"<<std::endl;
}
void ejungwoo::gvmark(TString vmtext) {
  if (vmtext.IsNull()) fVMarkText = fVersionOut;
  else fVMarkText = vmtext;
  if (fVerbose>0)
    std::cout<<"Version mark >> "<<fVMarkText<<std::endl;
}
void ejungwoo::gdata(TString name) {
  if (name.IsNull()) {
    /**/ if (!fVersionIn.IsNull() &&!fVersionOut.IsNull()) {
      if (fVersionIn==fVersionOut) fFigDirName = "figures__"+fVersionIn;
      else                         fFigDirName = "figures__"+fVersionIn+"__"+fVersionOut;
    }
    else if (!fVersionIn.IsNull() && fVersionOut.IsNull()) fFigDirName = "figures__"+fVersionIn;
    else if ( fVersionIn.IsNull() &&!fVersionOut.IsNull()) fFigDirName = "figures__"+fVersionOut;
    else                                                   fFigDirName = "figures";
  }
  else 
    fFigDirName = name;
}
void ejungwoo::gfig(TString name)  {
  if (name.IsNull()) {
    /**/ if (!fVersionIn.IsNull() &&!fVersionOut.IsNull()) {
      if (fVersionIn==fVersionOut) fDataDirName = "data__"+fVersionIn;
      else                         fDataDirName = "data__"+fVersionIn+"__"+fVersionOut;
    }
    else if (!fVersionIn.IsNull() && fVersionOut.IsNull()) fDataDirName = "data__"+fVersionIn;
    else if ( fVersionIn.IsNull() &&!fVersionOut.IsNull()) fDataDirName = "data__"+fVersionOut;
    else                                                   fDataDirName = "data";
  }
  else 
    fDataDirName = name;
}
void ejungwoo::gsave(bool val) {
  fAllowSave=val;
  if(fVerbose>0) {
    if(fAllowSave) std::cout<<"Allow save; TCanvas will be written by ejungwoo::save(TCanvas *) method."<<std::endl;
    else std::cout<<"DO NOT Allow save; TCanvas will NOT!! be written by ejungwoo::save(TCanvas *) method."<<std::endl;
  }
}
void ejungwoo::gwrite(bool val) {
  fAllowWrite=val;
  if(fVerbose>0) {
    if(fAllowWrite) std::cout<<"Allow write TObject will be written by ejungwoo::write(TObject *) method."<<std::endl;
    else std::cout<<"DO NOT Allow write; TObject will NOT!! be written by ejungwoo::write(TObject *) method."<<std::endl;
  }
}
void ejungwoo::gpdgname(bool usename) { fUsePDGName = usename; } 
void ejungwoo::gdraw(bool val) {
  fAllowDrawC=val;
  if(fVerbose>0) {
    if(fAllowDrawC) std::cout<<"Allow draw ejcvs; TCanvas will be written by ejungwoo::save(TCanvas *) method."<<std::endl;
    else std::cout<<"DO NOT Allow draw ejcvs;; TCanvas will NOT!! be written by ejungwoo::save(TCanvas *) method."<<std::endl;
  }
}
void ejungwoo::gcutt(double r) { fTMargin = r; }
void ejungwoo::gcutr(double r) { fRMargin1 = r; fRMarginWithz = r; }
void ejungwoo::gcutl(double r) { fLMargin = r; }
void ejungwoo::gcutb(double r) { fBMargin = r; }
void ejungwoo::gcuttr(double r) { fTMargin = r; fRMargin1 = r; fRMarginWithz = r; }
void ejungwoo::gcutall(double r) { fTMargin = r; fRMargin1 = r; fRMarginWithz = r; fBMargin = r; fLMargin = r; }
void ejungwoo::gndiv(int nd) { fAxisNDivisions = nd; }


TString ejungwoo::makename(const char *name){
  return makename(TString(name));
}
TString ejungwoo::makename(TString name) {
  if (fNaming) {
    if ( name.Index(fHeader)!=0) name = fHeader + name;
    if (!name.EndsWith(fFooter)) name = name + fFooter;
  }
  return name;
}

void ejungwoo::colorwheel() {
  TColorWheel *w = new TColorWheel();
  w -> SetCanvas(cv("cw",590,610));
  w -> Draw();
}

void ejungwoo::markers() {
  gStyle->SetOptStat(0);
  auto cvs = new TCanvas("markers","",600,400);
  cvs->SetMargin(0.02,0.02,0.02,0.02);
  auto hist = new TH2D("hist","",100,0.2,10.8,100,0.1,5.6);
  hist -> SetStats(0);
  hist -> GetXaxis() -> SetLabelOffset(100);
  hist -> GetYaxis() -> SetLabelOffset(100);
  hist -> GetXaxis() -> SetNdivisions(0);
  hist -> GetYaxis() -> SetNdivisions(0);
  hist -> Draw();
  int i = 0;
  for (auto y=5; y>=1; --y) {
    for (auto x=1; x<=10; ++x) {
      if (i==0) { i++; continue; }
      auto m = new TMarker(x,y,i);
      m -> SetMarkerSize(3.5);
      auto t = new TText(x,y-0.42,Form("%d",i));
      t -> SetTextSize(0.035);
      t -> SetTextAlign(22);
      if ((i>=20&&i<=29)||i==33||i==34) t -> SetTextColor(kBlue);
      if ((i>=24&&i<=28)||i==30||i==32) t->SetTextColor(kRed);
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

void ejungwoo::colorlist()
{
  gStyle -> SetOptStat(0);
  auto cvs = new TCanvas("colorlist","",600,400);
  cvs -> SetMargin(0.02,0.02,0.02,0.02);
  auto hist = new TH2D("hist","",100,0.2,10.8,100,0.1,5.6);
  hist -> SetStats(0);
  hist -> GetXaxis() -> SetLabelOffset(100);
  hist -> GetYaxis() -> SetLabelOffset(100);
  hist -> GetXaxis() -> SetNdivisions(0);
  hist -> GetYaxis() -> SetNdivisions(0);
  hist -> Draw();
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
  gStyle -> SetOptStat(0);
  auto cvs = new TCanvas("colorcblist","",600,400);
  cvs -> SetMargin(0.02,0.02,0.02,0.02);
  auto hist = new TH2D("hist","",100,0.2,10.8,100,0.1,5.6);
  hist -> SetStats(0);
  hist -> GetXaxis() -> SetLabelOffset(100);
  hist -> GetYaxis() -> SetLabelOffset(100);
  hist -> GetXaxis() -> SetNdivisions(0);
  hist -> GetYaxis() -> SetNdivisions(0);
  hist -> Draw();
  int i=0;
  for (auto y=5; y>=1; --y) {
    for (auto x=1; x<=10; ++x) {
      auto m = new TMarker(x,y,20);
      m -> SetMarkerSize(3.5);
      m -> SetMarkerColor(ccombi(i));
      auto t = new TText(x,y-0.42,Form("%d",i));
      t -> SetTextSize(0.035);
      t -> SetTextAlign(22);
      m -> Draw();
      t -> Draw();
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
  icolor = icolor - fNumCbColors*(icolor/fNumCbColors);
  return fColorCombi[icolor];
}

TGraph *ejungwoo::sumf(std::vector<TF1*> &fs)
{
  auto graph = new TGraph();
  double x,xl,xh;
  fs.at(0) -> GetRange(xl, xh);
  auto dx=(xh-xl)/1000;

  for (auto x=xl;x<=xh;x+=dx) {
    auto val=0.;
    for (auto f:fs) {
      val += f -> Eval(x);
    }
    graph->SetPoint(graph->GetN(),x,val);
  }
  return graph;
}

double ejungwoo::x1_g(TGraph* graph) { double x1,x2,y1,y2; graph->ComputeRange(x1,y1,x2,y2); return x1; }
double ejungwoo::x2_g(TGraph* graph) { double x1,x2,y1,y2; graph->ComputeRange(x1,y1,x2,y2); return x2; }
double ejungwoo::y1_g(TGraph* graph) { double x1,x2,y1,y2; graph->ComputeRange(x1,y1,x2,y2); return y1; }
double ejungwoo::y2_g(TGraph* graph) { double x1,x2,y1,y2; graph->ComputeRange(x1,y1,x2,y2); return y2; }
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

void ejungwoo::ginitstyle() {
  gStyle->SetTitleFontSize(fTopMainTitleSize);
}

bool ejungwoo::check_option(TString from_this, const char *find_this)
{
  if (from_this.Index(find_this)>=0)
    return true;
  return false;
}

TCanvas *ejungwoo::new_c(TString name, TString title, double width, double height, bool withz, TString options) // jumpto_new_c
{
  ginitstyle();

  fRMargin = withz ? fRMarginWithz : fRMargin1;
  name = makename((name.IsNull() ? Form("canvas_%d", fCountCvs) : name));
  name = makename(name);

  if (width==0) width = 600;
  if (height==0) height = 550;

  auto cvs = new TCanvas(name, title, (fCountCvsXIdx+1)*20 + fXInitCvs, (fCountCvsYIdx+1)*20 + fYInitCvs, width, height);

  ++fCountCvs;
  ++fCountCvsXIdx;
  ++fCountCvsYIdx;

  make_c(cvs);

  if (check_option(options,"x")) cvs -> SetLogx();
  if (check_option(options,"y")) cvs -> SetLogy();
  if (check_option(options,"z")) cvs -> SetLogz();

  return cvs;
}

TCanvas *ejungwoo::cdraw13(TString name,TH1 *h1, TH1 *h2, TH1 *h3, double size_ratio, Option_t *drawopt) //    jumpto_cdraw13
{
  fRMargin = fRMargin1;
  ginitstyle();

  auto width = 480 * size_ratio;
  auto height = 720 * size_ratio;

  if(name.IsNull())
    name=Form("cvs1x3_%d",fCountCvs);
  name = makename(name);

  auto cvs = new_c(name, name, width, height);
  cvs -> SetLeftMargin(0.01);
  cvs -> Divide(1,3,0.01,0.001);

  cdraw13(cvs,1,h1,drawopt);
  cdraw13(cvs,2,h2,drawopt);
  cdraw13(cvs,3,h3,drawopt);

  cvs -> Modified();
  cvs -> Update();

  return cvs;
}

TCanvas* ejungwoo::cdraw13(TCanvas *cvs, int idx, TH1 *hist, Option_t *drawopt)  // jumpto_cdraw13_
{
  auto tmargin_innercvs = 0.04;
  auto bmargin_innercvs = 0.28;
  auto lmargin_innercvs = 0.20;
  auto rmargin_innercvs = 0.05;

  auto innercvs = (TCanvas *) cvs -> cd(idx);
  innercvs -> SetMargin(lmargin_innercvs, rmargin_innercvs, bmargin_innercvs,tmargin_innercvs);

  if (hist!=nullptr)
  {
    hist -> GetXaxis() -> CenterTitle();
    hist -> GetXaxis() -> SetTitleOffset(1.05);
    hist -> GetXaxis() -> SetTitleSize(0.115);
    hist -> GetXaxis() -> SetLabelSize(0.10);
    hist -> GetXaxis() -> SetNdivisions(506);
    hist -> GetYaxis() -> CenterTitle();
    hist -> GetYaxis() -> SetTitleOffset(0.80);
    hist -> GetYaxis() -> SetTitleSize(0.12);
    if (TString(hist->GetYaxis()->GetTitle()).Index("frac")>=0) {
      hist -> GetYaxis() -> SetTitleOffset(0.90);
      hist -> GetYaxis() -> SetTitleSize(0.09);
    }
    hist -> GetYaxis() -> SetLabelSize(0.10);
    hist -> GetYaxis() -> SetNdivisions(506);
    hist -> GetYaxis() -> SetNdivisions(506);
    hist -> Draw(drawopt);

    innercvs -> Modified();
    innercvs -> Update();

    auto statsbox = dynamic_cast<TPaveStats*>(hist->FindObject("stats"));
    if (statsbox != nullptr) {
      if (!fFixStatsboxSize) {
        gstatsize(0.4, 0.28);
        make_s(innercvs, statsbox);
        gfixstatsize(false);
      }
      else
        make_s(innercvs, statsbox);
    }
  }

  innercvs -> Modified();
  innercvs -> Update();

  return innercvs;
}

TCanvas* ejungwoo::cdraw12(TString name, TH1 *h1, TH1 *h2, double size_ratio, Option_t *drawopt) // jumpto_cdraw12
{
  fRMargin = fRMargin1;
  ginitstyle();

  auto width = 500 * size_ratio;
  auto height = 650 * size_ratio;

  if(name.IsNull())
    name=Form("cvs1x3_%d",fCountCvs);
  name = makename(name);

  auto cvs = new_c(name, name, width, height);
  cvs -> SetLeftMargin(0.01);
  cvs -> Divide(1,2,0.01,0.001);

  cdraw12(cvs,1,h1,drawopt);
  cdraw12(cvs,2,h2,drawopt);

  cvs -> Modified();
  cvs -> Update();

  return cvs;
}

TCanvas* ejungwoo::cdraw12(TCanvas *cvs, int idx, TH1 *hist, Option_t *drawopt)  // jumpto_cdraw12_
{
  auto tmargin_innercvs = 0.04;
  auto bmargin_innercvs = 0.21;
  auto lmargin_innercvs = 0.20;
  auto rmargin_innercvs = 0.05;

  auto innercvs = (TCanvas *) cvs -> cd(idx);
  innercvs ->  SetMargin(lmargin_innercvs, rmargin_innercvs, bmargin_innercvs,tmargin_innercvs);

  if (hist!=nullptr)
  {
    hist -> GetXaxis() -> CenterTitle();
    hist -> GetXaxis() -> SetTitleOffset(0.95);
    hist -> GetXaxis() -> SetTitleSize(0.10);
    hist -> GetXaxis() -> SetLabelSize(0.08);
    hist -> GetXaxis() -> SetNdivisions(506);
    hist -> GetYaxis() -> CenterTitle();
    hist -> GetYaxis() -> SetTitleOffset(0.95);
    hist -> GetYaxis() -> SetTitleSize(0.095);
    if (TString(hist->GetYaxis()->GetTitle()).Index("frac")>=0) {
      hist -> GetYaxis() -> SetTitleOffset(1.10);
      hist -> GetYaxis() -> SetTitleSize(0.078);
    }
    hist -> GetYaxis() -> SetLabelSize(0.08);
    hist -> GetYaxis() -> SetNdivisions(506);
    hist -> GetYaxis() -> SetNdivisions(506);
    hist -> Draw(drawopt);

    innercvs -> Modified();
    innercvs -> Update();

    auto statsbox = dynamic_cast<TPaveStats*>(hist->FindObject("stats"));
    if (statsbox != nullptr) {
      if (!fFixStatsboxSize) {
        gstatsize(0.4, 0.24);
        make_s(innercvs, statsbox);
        gfixstatsize(false);
      }
      else
        make_s(innercvs, statsbox);
    }
  }

  innercvs -> Modified();
  innercvs -> Update();

  return innercvs;
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
        if (ix==1)       c->cd(i)->SetMargin(fLMargin,       0,fBMargin,0);//fTMargin);
        else if (ix==nx) c->cd(i)->SetMargin(       0,fRMargin,fBMargin,0);//fTMargin);
        else             c->cd(i)->SetMargin(       0,       0,fBMargin,0);//fTMargin);
      }
      else if (iy==1) {
        if (ix==1&&ix==nx) c->cd(i)->SetMargin(fLMargin,fRMargin,0,0);//fTMargin);
        else if (ix==1)    c->cd(i)->SetMargin(fLMargin,       0,0,0);//fTMargin);
        else if (ix==nx)   c->cd(i)->SetMargin(       0,fRMargin,0,0);//fTMargin);
        else               c->cd(i)->SetMargin(       0,       0,0,0);//fTMargin);
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

void ejungwoo::toss(TText *att, Color_t color, TString align, Size_t size, Font_t font)
{
  att->SetTextColor(color);

  Short_t aligni = 0;
  if (align.Index("l")>=0) aligni += 10;
  else if (align.Index("r")>=0) aligni += 30;
  else aligni += 20;
  if (align.Index("t")>=0) aligni += 1;
  else if (align.Index("b")>=0) aligni += 3;
  else aligni += 2;

  att->SetTextAlign(aligni);
  att->SetTextSize(size);
  att->SetTextFont(font);
}

TObject *ejungwoo::make(TObject *ob) { //jumpto_makeo
  if (ob->InheritsFrom(         TH1::Class())) make_h(          (TH1*)ob);
  if (ob->InheritsFrom(         TF1::Class())) make_f(          (TF1*)ob);
  if (ob->InheritsFrom(      TGraph::Class())) make_g(       (TGraph*)ob);
  if (ob->InheritsFrom(     TCanvas::Class())) make_c(      (TCanvas*)ob);
  if (ob->InheritsFrom(     TLegend::Class())) make_l(      (TLegend*)ob);
  if (ob->InheritsFrom(   TPaveText::Class())) make_p(    (TPaveText*)ob);
  if (ob->InheritsFrom(TGraphErrors::Class())) make_ge((TGraphErrors*)ob);
  return ob;
}

TText *ejungwoo::make_t(TText *tt, Short_t a)
{
  tt->SetTextAlign(a);
  tt->SetTextSize(0.05);
  tt->SetTextFont(fTextFont);
  return tt;
}

TPaveStats *ejungwoo::make_s(TCanvas *cvs, TPaveStats *statsbox)
{
  auto lmargin_cvs = fLMargin;
  auto rmargin_cvs = fRMargin;
  auto bmargin_cvs = fBMargin;
  auto tmargin_cvs = fTMargin;
  if (cvs != nullptr) {
    lmargin_cvs = cvs -> GetLeftMargin();
    rmargin_cvs = cvs -> GetRightMargin();
    bmargin_cvs = cvs -> GetBottomMargin();
    tmargin_cvs = cvs -> GetTopMargin();
  }
  else if (gPad != nullptr) {
    lmargin_cvs = ((TCanvas *) gPad) -> GetLeftMargin();
    rmargin_cvs = ((TCanvas *) gPad) -> GetRightMargin();
    bmargin_cvs = ((TCanvas *) gPad) -> GetBottomMargin();
    tmargin_cvs = ((TCanvas *) gPad) -> GetTopMargin();
  }

  auto x1_box =     lmargin_cvs;
  auto x2_box = 1.- rmargin_cvs;
  auto y1_box =     bmargin_cvs;
  auto y2_box = 1.- tmargin_cvs;
  auto unit_x = x2_box - x1_box;
  auto unit_y = y2_box - y1_box;

  auto numLines = statsbox -> GetListOfLines() -> GetEntries();
  double dx_byratio, dy_byratio;
  if (fFixStatsboxSize) {
    dx_byratio = fdXStatsboxByRatio;
    dy_byratio = fdYStatsboxByRatio;
  } else {
    dx_byratio = 0.380;
    dy_byratio = 0.065*numLines;
  }

  auto y2_stats = y2_box;
  auto y1_stats = y2_stats - dy_byratio*unit_y;
  auto x2_stats = x2_box;
  auto x1_stats = x2_stats - dx_byratio*unit_x;

  statsbox -> SetX1NDC(x1_stats + fXOffStatsbox*unit_x);
  statsbox -> SetX2NDC(x2_stats + fXOffStatsbox*unit_x);

  statsbox -> SetY1NDC(y1_stats + fYOffStatsbox*unit_y);
  statsbox -> SetY2NDC(y2_stats + fYOffStatsbox*unit_y);

  statsbox -> SetTextFont(fTextFont);

  if (fFillStyleStatsbox>-1)
    statsbox -> SetFillStyle(fFillStyleStatsbox);
  statsbox -> SetBorderSize(fBorderSizeStatsbox);

  return statsbox;
}

TPaveStats *ejungwoo::make_s(TPaveStats *statsbox)
{
  return ejungwoo::make_s((TCanvas *)nullptr,statsbox);
}

TCanvas *ejungwoo::make_c(TCanvas *cvs,TString vmtext) //jumpto_makec
{
  if (cvs == nullptr)
    return cvs;

  cvs -> Modified();
  cvs -> Update();

  if (fDarkMode) cvs -> SetFillColor(kGray);

  cvs -> SetMargin(fLMargin,fRMargin,fBMargin,fTMargin);

  if (vmtext.IsNull())
    vmtext = fVMarkText;

  auto list_primitive = cvs -> GetListOfPrimitives();
  auto toptitle = (TPaveText*) list_primitive -> FindObject("title");
  if (toptitle!=nullptr)
    toptitle -> SetTextFont(fTextFont);

  TObject *object;
  TIter next(list_primitive);
  while ((object = next()))
  {
    if (object->InheritsFrom(TH1::Class())) {
      getvmark(true, vmtext);
      auto hist = (TH1D *) object;
      make_h(hist);
      auto statsbox = dynamic_cast<TPaveStats*>(hist->FindObject("stats"));
      if (statsbox!= nullptr)
        make_s(cvs,statsbox);
    }
    else if (object->InheritsFrom(TPad::Class())) {
      auto innercvs = (TCanvas *) object;
      make_c(innercvs);
    }
  }

  cvs->Modified();
  cvs->Update();

  return cvs;
}

TGraph *ejungwoo::make_g(TGraph *graph, int mi, float ms, int mc) { //jumpto_makeg
  ginitstyle();
  if(graph->GetMarkerStyle()==1) {
    graph->SetMarkerStyle(mi);
    graph->SetMarkerSize(ms);
    graph->SetMarkerColor(mc);
  }
  auto hist = graph->GetHistogram();
  hist -> SetTitle(graph->GetName());
  make_h(hist);
  return graph;
}

TH1D *ejungwoo::new_h(double x1, double x2)
{
  auto h = new TH1D(Form("frame_%d",fCountFrame++),"", 200, x1, x2);
  return (TH1D *) make_h(h);
}

TH2D *ejungwoo::new_h(double x1, double x2, double y1, double y2)
{
  auto h = new TH2D(Form("frame_%d",fCountFrame++),"", 200, x1, x2, 200, y1, y2);
  return (TH2D *) make_h(h);
}

TH2D *ejungwoo::new_h(TGraph *graph)
{
  double x1, x2, y1, y2;
  graph -> ComputeRange(x1,y1,x2,y2);
  double offx = (x2-x1)/10;
  double offy = (y2-y1)/10;
  x1 = x1 - offx;
  x2 = x2 + offx;
  y1 = y1 - offy;
  y2 = y2 + offy;
  if (x2<=x1) { x1 = 0; x2 = 1; }
  if (y2<=y1) { y1 = 0; y2 = 1; }
  return new_h(x1, x2, y1, y2);
}

TGraph *ejungwoo::new_g(TString name) { //jumpto_newg
  auto graph = new TGraph();
  if (name=="") {
    name=Form("graph_%d",fCountGraph);
    fCountGraph;
  }
  graph -> SetName(name);
  make_g(graph);
  return graph;
}

TGraphErrors *ejungwoo::new_ge(TString name) { //jumpto_new_ge
  auto graph = new TGraphErrors();
  if (name=="") {
    name=Form("graph_%d",fCountGraph);
    fCountGraph;
  }
  graph -> SetName(name);
  make_ge(graph);
  return graph;
}

TGraphErrors *ejungwoo::make_ge(TGraphErrors *graph, int mi, float ms, int mc) //jumpto_makege
{
  return (TGraphErrors *) make_g((TGraph *) graph, mi, ms, mc);
}

TH1 *ejungwoo::make_h(int s, TH1 *h, double xc, double yc) { //jumpto_maken
  ginitstyle();
  h->SetLabelOffset(xc*0.005,"X");
  h->SetLabelOffset(yc*0.005,"Y");

  h->GetXaxis()->CenterTitle();
  h->GetXaxis()->SetTitleOffset(xc*fXTitleOffsets[s]); // ?? 
  h->GetXaxis()->SetTitleSize(fAxisTitleSizes[s]);
  h->GetXaxis()->SetLabelSize(fAxisLabelSizes[s]);

  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleOffset(yc*fYTitleOffsets[s]);
  h->GetYaxis()->SetTitleSize(fAxisTitleSizes[s]);
  h->GetYaxis()->SetLabelSize(fAxisLabelSizes[s]);

  h->GetZaxis()->CenterTitle();
  h->GetZaxis()->SetTitleSize(fAxisTitleSizes[s]);
  h->GetZaxis()->SetLabelSize(fZAxisLabelSizes[s]);

  h->GetXaxis()->SetTitleFont(fTextFont);
  h->GetYaxis()->SetTitleFont(fTextFont);
  h->GetZaxis()->SetTitleFont(fTextFont);
  h->GetXaxis()->SetLabelFont(fTextFont);
  h->GetYaxis()->SetLabelFont(fTextFont);
  h->GetZaxis()->SetLabelFont(fTextFont);

  free(h);

  return h;
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

TPaveStats *ejungwoo::find_statsbox(TCanvas *cvs)
{
  TObject *object;
  auto list_primitive = cvs -> GetListOfPrimitives();
  TIter next_primitive(list_primitive);
  while ((object = next_primitive())) {
    if (object->InheritsFrom(TH1::Class())) {
      auto statsbox = dynamic_cast<TPaveStats*>(((TH1D*)object)->FindObject("stats"));
      return statsbox;
    }
  }

  return (TPaveStats *) nullptr;
}

TLegend *ejungwoo::make_l(TCanvas *cvs, TLegend *legend, double x_offset, double y_offset, double width_fixed, double height_fixed) // jumpto_makel
{
  ginitstyle();

  auto lmargin_cvs = fLMargin;
  auto rmargin_cvs = fRMargin;
  auto bmargin_cvs = fBMargin;
  auto tmargin_cvs = fTMargin;
  if (cvs != nullptr) {
    lmargin_cvs = cvs -> GetLeftMargin();
    rmargin_cvs = cvs -> GetRightMargin();
    bmargin_cvs = cvs -> GetBottomMargin();
    tmargin_cvs = cvs -> GetTopMargin();
  }
  else if (gPad != nullptr) {
    lmargin_cvs = ((TCanvas *) gPad) -> GetLeftMargin();
    rmargin_cvs = ((TCanvas *) gPad) -> GetRightMargin();
    bmargin_cvs = ((TCanvas *) gPad) -> GetBottomMargin();
    tmargin_cvs = ((TCanvas *) gPad) -> GetTopMargin();
  }

  auto x1_box =     lmargin_cvs;
  auto x2_box = 1.- rmargin_cvs;
  auto y1_box =     bmargin_cvs;
  auto y2_box = 1.- tmargin_cvs;
  auto unit_x = x2_box - x1_box;
  auto unit_y = y2_box - y1_box;

  auto y1_stat = 1.;
  TPaveStats *statsbox = nullptr;
  if (cvs!=nullptr) statsbox = find_statsbox(cvs);
  else if (gPad!=nullptr) statsbox = find_statsbox((TCanvas *) gPad);
  if (statsbox!=nullptr) y1_stat = statsbox -> GetY2NDC();

  auto length_text_max = 0;
  TIter next_entry(legend->GetListOfPrimitives());
  TLegendEntry *label;
  while ((label=(TLegendEntry *) next_entry())) {
    auto lenth_text = TString(label->GetLabel()).Length();
    if (length_text_max<lenth_text)
      length_text_max = lenth_text;
  }

  auto y2_legend = y1_stat;
  auto y1_legend = y2_legend - legend->GetNRows() * fHeightPerEntryLegend;
  if (height_fixed>0) y1_legend = y2_legend - height_fixed;

  auto x2_legend = x2_box; //1. - fRMargin;
  auto x1_legend = x2_legend - (length_text_max * fWidthPerLengthLegend) - fWidthDefaultLegend*unit_x;
  if (width_fixed>0) x1_legend = x2_legend - width_fixed*unit_y;

  legend -> SetX1(x1_legend + x_offset*unit_x);
  legend -> SetX2(x2_legend + x_offset*unit_x);
  legend -> SetY1(y1_legend + y_offset*unit_y);
  legend -> SetY2(y2_legend + y_offset*unit_y);

  legend -> SetFillStyle(fFillStyleLegend);
  legend -> SetBorderSize(fBorderSizeLegend);
  legend -> SetTextFont(fTextFont);

  return legend;
}

TLegend *ejungwoo::make_l(TLegend *legend, double x_offset=0, double y_offset=0, double width_fixed=0, double height_fixed=0) {
  return make_l((TCanvas *) nullptr, legend, x_offset, y_offset, width_fixed, height_fixed);
}

TPaveText *ejungwoo::make_p(TPaveText *pave) { //jumpto_makep
  ginitstyle();
  auto y2=1.-fTMargin;
  if(gStyle->GetOptStat() != 0) y2=gStyle->GetStatY()-gStyle->GetStatH();
  auto lmax=0;
  TIter next(pave->GetListOfLines());
  TLatex *text;
  while ((text=(TLatex *) next())) {
    auto l=TString(text->GetTitle()).Length();
    if(lmax<l) lmax=l;
  }

  auto y1=y2-pave->GetSize()*fHeightPerEntryPave;
  auto x2=1.-fRMargin;
  auto x1=x2-lmax*fWidthPerLengthPave - fWidthDefaultPave;
  pave->SetX1(x1 + fXOffStatsbox);
  pave->SetX2(x2 + fXOffStatsbox);
  pave->SetY1(y1 + fYOffStatsbox);
  if(y2<0.2)
    y2=0.2;
  pave->SetY2(y2 + fYOffStatsbox);
  if (fFillStylePave>-1)
    pave->SetFillStyle(fFillStylePave);
  pave->SetBorderSize(fBorderSizePave);
  pave->SetTextFont(fTextFont);

  return pave;
}

TF1 *ejungwoo::make_f(TF1 *f) { //jumpto_makef
  make_h(f->GetHistogram());
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
  if(name.IsNull()) name=Form("hist-%d",fCountHist);
  auto hist = new TH1D(name, title, n, 0, n+1);
  for (auto i = 0; i < n; ++i)
    hist->SetBinContent(i+1,buffer[i]);
  ++fCountHist;
  return make_h(hist);
}

TH1 *ejungwoo::tohist(double *buffer, int i, int f, TString name, TString title)
{
  if(name.IsNull()) name=Form("hist-%d",fCountHist);
  auto hist = new TH1D(name, title, f-i+1, i, f+1);
  for (auto bin = i; bin < f+1; ++bin)
    hist->SetBinContent(bin+1-i,buffer[bin]);
  ++fCountHist;
  return make_h(hist);
}

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
  h->GetXaxis()->SetNdivisions(/*n=*/fAxisNDivisions/*,optim=true*/);
  h->GetYaxis()->SetNdivisions(/*n=*/fAxisNDivisions/*,optim=true*/);
  h->GetZaxis()->SetNdivisions(/*n=*/fAxisNDivisions/*,optim=true*/);
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

TH1D *ejungwoo::fold0(TH1D *h)
{
  auto hist = (TH1 *) h;
  auto bin0 = hist -> FindBin(0);
  auto nbins = hist->GetXaxis()->GetNbins();

  auto nn = nbins-bin0+1;
  auto x1 = hist->GetXaxis()->GetBinLowEdge(bin0);
  auto x2 = hist->GetXaxis()->GetBinUpEdge(nbins);

  auto fold = new TH1D(Form("%s_fold0",h->GetName()),h->GetTitle(),nn,x1,x2);

  for (auto ibin=0; ibin<=nn; ++ibin)
  {
    auto binL = bin0-1-ibin;
    auto binR = bin0+ibin;
    if (binL<1 || binR > nbins) break;
    auto valueL = hist -> GetBinContent(binL);
    auto valueR = hist -> GetBinContent(binR);
    fold -> SetBinContent(ibin,valueL+valueR);
  }
  return fold;
}

TH1D *ejungwoo::pdg_hist(const char *name, const char *title)
{
  auto hist = new TH1D(name,title,fNumAxisPDGs,0,fNumAxisPDGs);
  pdg_axis(hist -> GetXaxis());
  return hist;
}

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

TString ejungwoo::version() { return fVersionIn; }
TString ejungwoo::versionin() { return fVersionIn; }
TString ejungwoo::versionout() { return fVersionOut; }
const char *ejungwoo::versioncc() { return fVersionIn.Data(); }
const char *ejungwoo::versionincc() { return fVersionIn.Data(); }
const char *ejungwoo::versionoutcc() { return fVersionOut.Data(); }

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
  ttVMark->SetTextAlign(11);
  ttVMark->SetTextSize(0.04);
  ttVMark->SetTextFont(fTextFont);
  ttVMark->SetText(0.+fLMargin,1.-fTMargin+0.01,text);
  ttVMark->SetNDC();

  //ttVMark->SetTextAlign(11);
  //ttVMark->SetText(0.+fLMargin,1.-fTMargin+0.01,text);

  ttVMark->SetTextAlign(31);
  ttVMark->SetText(1-fRMargin,1.-fTMargin+0.01,text);

  if (dodraw)
    ttVMark->Draw();

  return ttVMark;
}


TFile *ejungwoo::gfile(TString filename) {
  if(filename.Index(".root")<0)
    filename=filename+".root";
  if(!fVersionOut.IsNull())
    filename.ReplaceAll(".root",TString(".")+fVersionOut+".root");

  if(fFileDummyGraphics==nullptr)
    fFileDummyGraphics = new TFile(filename,"recreate");
  return fFileDummyGraphics;
}

bool ejungwoo::isfile(TString filename) {
  TString name=gSystem->Which(".",filename.Data());
  if (name.IsNull())
    return false;
  return true;
}

void ejungwoo::save(TVirtualPad *cvs, TString format, bool version_control) {
  save(((TCanvas *)cvs), format, version_control);
}

void ejungwoo::save(TCanvas *cvs, TString format, bool version_control) {
  if(!fAllowSave||cvs==nullptr) return;
  TString path=name_fig();
  gSystem->Exec(TString("mkdir -p ")+path);
  TString name=cvs->GetName();
  TString full_name=name+"."+format;
  if(!fVersionOut.IsNull()) {
    full_name=name+"__"+fVersionOut+"."+format;
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
  if(!fAllowSave||cvs==nullptr) return;
  TString path=name_fig();
  gSystem->Exec(TString("mkdir -p ")+path);
  TString full_name=name+"."+format;
  if(!fVersionOut.IsNull()) {
    full_name=name+"__"+fVersionOut+"."+format;
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

TString ejungwoo::name_fig() { return TString(TString(gSystem->Getenv("PWD"))+"/"+fFigDirName+"/"); }
TString ejungwoo::name_data() { return TString(TString(gSystem->Getenv("PWD"))+"/"+fDataDirName+"/"); }
TString ejungwoo::name_file(TString name) { return TString(name+"."+fVersionOut+".root"); }
TString ejungwoo::name_full(TString name) { return TString(name_data()+name_file(name)); }

TFile *ejungwoo::write(TObject *obj, bool version_control) {
  TFile *file = nullptr;
  if(!fAllowWrite) return file;
  TString path=name_data();
  gSystem->Exec(TString("mkdir -p ")+path);
  TString name=obj->GetName();
  TString full_name=name+".root";
  if(!fVersionOut.IsNull()) {
    full_name=name+"."+fVersionOut+".root";
    file = new TFile(path+full_name,"recreate");
    obj->Write();
    if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
    file->Close();
    return file;
  }
  int version_idx=0;
  while (version_control) {
    char* c=gSystem->Which(path.Data(),full_name.Data());
    if(TString(c).IsNull()) {
      file = new TFile(path+full_name,"recreate");
      obj->Write();
      if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
      file->Close();
      return file;
    }
    full_name=name+"."+TString::Itoa(++version_idx,10)+".root";
    if(fVerbose>0&&version_idx%10==0) std::cout<<"[Warning] More than "<<version_idx<<" versions of "<<full_name<<"exist!"<<std::endl;
  }
  return file;
}

TFile *ejungwoo::write(TString name, TNamed *obj, bool version_control = true) {
  TFile *file = nullptr;
  if(!fAllowWrite) return file;
  TString path=name_data();
  gSystem->Exec(TString("mkdir -p ")+path);
  obj->SetName(name);
  TString full_name=name+".root";
  if(!fVersionOut.IsNull())
    name=name+"."+fVersionOut;

  if(fWrittenFileArray == nullptr)
    fWrittenFileArray = new TObjArray();

  for (auto i=0; i<fWrittenFileArray->GetEntries(); ++i)
  {
    auto file0 = (TFile *) fWrittenFileArray->At(i);
    if(TString(file0->GetName()).Index(name)>0) {
      file = file0;
      break;
    }
  }

  if(file!=nullptr) {
    obj->Write();
    if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<file->GetName()<<std::endl;
    return file;
  }
  else {
    if(!fVersionOut.IsNull()) {
      full_name=name+".root";
      file = new TFile(path+full_name,"recreate");
      fWrittenFileArray->Add(file);
      obj->Write();
      if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
      return file;
    }
    int version_idx=0;
    while (version_control) {
      char* c=gSystem->Which(path.Data(),full_name.Data());
      if(TString(c).IsNull()) {
        file = new TFile(path+full_name,"recreate");
        fWrittenFileArray->Add(file);
        obj->Write();
        if(fVerbose>0) std::cout<<"Writing "<<obj->GetName()<<" to "<<path+full_name<<std::endl;
        return file;
      }
      full_name=name+"."+TString::Itoa(++version_idx,10)+".root";
      if(fVerbose>0&&version_idx%10==0) std::cout<<"[Warning] More than "<<version_idx<<" versions of "<<full_name<<"exist!"<<std::endl;
    }
  }
  return file;
}

TObjArray *ejungwoo::infog(TF1 *f, int cmax, vector<int> guideCS)
{
  auto array = new TObjArray();

  auto a = f -> GetParameter(0);
  auto m = f -> GetParameter(1);
  auto s = f -> GetParameter(2);

  double x1, x2;
  f -> GetRange(x1, x2);

  auto fc = (TF1 *) f->Clone();
  fc -> SetRange(m-cmax*s,m+cmax*s);
  fc -> SetLineColor(f->GetLineColor());
  fc -> SetDrawOption("samel");
  array -> Add(fc);

  auto y1 = fc -> Eval(x1);
  auto lrange = new TArrow(x1,y1,x2,y1,0.05,"<>");
  lrange -> SetLineColor(kGray+1);
  lrange -> SetDrawOption("samel");
  //array -> Add(lrange);

  for (auto c : guideCS) {
    if (c==0) {
      auto lc = new TLine(m,0,m,a);
      lc -> SetLineColor(kGray);
      lc -> SetDrawOption("samel");
      array -> Add(lc);
    }
    else {
      auto ac = fc->Eval(m-c*s);
      auto l1 = new TLine(m-c*s,0,m-c*s,ac);
      auto l2 = new TLine(m+c*s,0,m+c*s,ac);
      l1 -> SetLineColor(kGray);
      l2 -> SetLineColor(kGray);
      l1 -> SetLineStyle(2);
      l2 -> SetLineStyle(2);
      l1 -> SetDrawOption("samel");
      l2 -> SetDrawOption("samel");

      array -> Add(l1);
      array -> Add(l2);
    }
  }

  return array;
}

TF1 *ejungwoo::fitg(TF1 *f, TH1 *h,double c,Option_t *opt) {
  if(fVerbose>1) {
    if(!TString(opt).IsNull()) std::cout<<"fitg "<<h->GetName()<<": ["<<c<<" sigma],["<<TString(opt)<<"]";
    else                       std::cout<<"fitg "<<h->GetName()<<": ["<<c<<" sigma]";
  }

  auto max=f->GetParameter(0);
  auto xmax=f->GetParameter(1);
  auto xerr=f->GetParameter(2);

  double frange1, frange2;
  double dfrangeCut = (frange2 - frange1)/3.;

  auto nbins = h->GetXaxis()->GetNbins();
  auto hrange1 = h->GetXaxis()->GetBinLowEdge(1);
  auto hrange2 = h->GetXaxis()->GetBinUpEdge(nbins);
  bool outofrange;

  outofrange = false;
  f->GetRange(frange1, frange2);
  if (frange1 < hrange1) {
    if (frange2 < hrange1) outofrange = true;
    else if (frange2 - hrange1 < dfrangeCut) outofrange = true;
    else frange1 = hrange1;
  } else if (frange2 > hrange2) {
    if (frange1 > hrange2) outofrange = true;
    else if (hrange2 - frange1 < dfrangeCut) outofrange = true;
    else frange2 = hrange2;
  } f->SetRange(frange1, frange2);

  if (outofrange) {
    if(fVerbose>1) std::cout<<" fit-range:("<<frange1<<","<<frange2<<") out of hist-range:("<<hrange1<<","<<hrange2<<")"<<endl;
    f -> SetParameters(0,0,0);
    return f;
  }

  h->Fit(f,opt);
  xmax=f->GetParameter(1);
  xerr=f->GetParameter(2);
  f->SetRange(xmax-c*xerr,xmax+c*xerr);

  outofrange = false;
  f->GetRange(frange1, frange2);
  if (frange1 < hrange1) {
    if (frange2 < hrange1) outofrange = true;
    else if (frange2 - hrange1 < dfrangeCut) outofrange = true;
    else frange1 = hrange1;
  } else if (frange2 > hrange2) {
    if (frange1 > hrange2) outofrange = true;
    else if (hrange2 - frange1 < dfrangeCut) outofrange = true;
    else frange2 = hrange2;
  } f->SetRange(frange1, frange2);

  if (outofrange) {
    if(fVerbose>1) std::cout<<" fit-range:("<<frange1<<","<<frange2<<") out of hist-range:("<<hrange1<<","<<hrange2<<")"<<endl;
    f -> SetParameters(0,0,0);
    return f;
  }

  int fitcount = 1;
  double xerr2 = 0.;
  while (fitcount<20&&TMath::Abs(xerr-xerr2)/xerr>0.2) {
    xerr2=xerr;
    f->SetRange(xmax-c*xerr2,xmax+c*xerr2);
    {
      f->GetRange(frange1, frange2);

      nbins = h->GetXaxis()->GetNbins();
      hrange1 = h->GetXaxis()->GetBinLowEdge(1);
      hrange2 = h->GetXaxis()->GetBinUpEdge(nbins);

      outofrange = false;
      f->GetRange(frange1, frange2);
      if (frange1 < hrange1) {
        if (frange2 < hrange1) outofrange = true;
        else if (frange2 - hrange1 < dfrangeCut) outofrange = true;
        else frange1 = hrange1;
      } else if (frange2 > hrange2) {
        if (frange1 > hrange2) outofrange = true;
        else if (hrange2 - frange1 < dfrangeCut) outofrange = true;
        else frange2 = hrange2;
      } f->SetRange(frange1, frange2);
      if (outofrange)
        break;
    }
    h->Fit(f,opt);
    xmax=f->GetParameter(1);
    xerr=f->GetParameter(2);
    ++fitcount;
  }

  if(fVerbose>1)std::cout<<"->[a:"<<f->GetParameter(0)<<", m:"<<f->GetParameter(1)<<", s:"<<f->GetParameter(2)<<"] ("<<fitcount<<")"<<std::endl;
  return f;
}

TF1 *ejungwoo::fitg(TH1 *h,double c,Option_t *opt) {
  auto binmax=h->GetMaximumBin();
  auto max=h->GetBinContent(binmax);
  auto xmax=h->GetXaxis()->GetBinCenter(binmax);
  auto xerr=h->GetStdDev();
  auto f=new TF1(Form("%s_fitg",h->GetName()),"gaus(0)",xmax-xerr*c,xmax+xerr*c);
  f->SetParameters(max,xmax,xerr);
  return fitg(f,h,c,opt);
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

void ejungwoo::add(TObject *obj, TString opt) {
  addto(0,obj, opt);
}
void ejungwoo::addnew(TObject *obj, TString opt) {
  if(fEJCanvasArray==nullptr)
    fEJCanvasArray=new TObjArray();

  int idx=fEJCanvasArray->GetEntries();
  auto name=makename(Form("ej_canvas_%d",idx));
  auto ejcvs=new t_canvas(name);
  fEJCanvasArray->AddAt(ejcvs,idx);

  addto(ejcvs, obj, opt);
}
void ejungwoo::addto(t_canvas *ejcvs, TObject *obj, TString opt) {
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
  ejcvs->add(obj, opt);
  return;
}
void ejungwoo::addto(int i, TObject *obj, TString opt) {
  if(fEJCanvasArray==nullptr)
    fEJCanvasArray=new TObjArray();

  t_canvas *ejcvs = nullptr;
  int numACanvases = fEJCanvasArray->GetEntries();
  if (numACanvases<=i) {
    auto name = makename(Form("ej_canvas_%d",i));
    ejcvs=new t_canvas(name);
    fEJCanvasArray->AddAt(ejcvs,i);
  }
  else
    ejcvs = (t_canvas *) fEJCanvasArray->At(i);

  addto(ejcvs, obj, opt);
}
void ejungwoo::addto(TString name, TObject *obj, TString opt) {
  if(fEJCanvasArray==nullptr)
    fEJCanvasArray=new TObjArray();

  name = makename(name);

  auto ejcvs=(t_canvas *)fEJCanvasArray->FindObject(name);
  if (ejcvs==nullptr) {
    ejcvs=new t_canvas(name);
    fEJCanvasArray->Add(ejcvs);
  }

  addto(ejcvs, obj, opt);
}

void ejungwoo::clearall() {
  if (fEJCanvasArray==nullptr)
    return;
  fEJCanvasArray->Clear();
}

void ejungwoo::clearc(int i) {
  if (fEJCanvasArray==nullptr)
    return;
  auto ejcvs=(t_canvas *)fEJCanvasArray->At(i);
  if (ejcvs==nullptr)
    return;
  ejcvs->Clear();
}

void ejungwoo::clearc(TString name) {
  if (fEJCanvasArray==nullptr)
    return;
  auto ejcvs=(t_canvas *)fEJCanvasArray->FindObject(name);
  if (ejcvs==nullptr)
    return;
  ejcvs->Clear();
}

TCanvas *ejungwoo::drawc(int i,TString opt) { //jump_to_drawc1
  auto ejcvs=(t_canvas*)fEJCanvasArray->At(i);
  if(ejcvs!=nullptr)
    return ejcvs->drawc(opt);
  return (TCanvas *) nullptr;
}
TCanvas *ejungwoo::drawc(TString name,TString opt) { //jump_to_drawc2
  auto ejcvs=(t_canvas*)fEJCanvasArray->FindObject(name);
  if(ejcvs!=nullptr)
    return ejcvs->drawc(opt);
  return (TCanvas *) nullptr;
}

void ejungwoo::drawall() {
  if (fEJCanvasArray==nullptr) return;
  auto navcvs = fEJCanvasArray->GetEntries();
  for(auto iacvs=0;iacvs<navcvs;++iacvs) {
    auto ejcvs=(t_canvas*)fEJCanvasArray->At(iacvs);
    ejcvs->drawc();
  }
}

void ejungwoo::saveall(TString opt) {
  if (fEJCanvasArray==nullptr) return;
  auto navcvs = fEJCanvasArray->GetEntries();
  for(auto iacvs=0;iacvs<navcvs;++iacvs) {
    auto ejcvs=(t_canvas*)fEJCanvasArray->At(iacvs);
    ejcvs->save(opt);
  }
}

/**
 * fit 2d histogram through x with given parameters and return list of histogram data
 *
 * @param hist input histogram
 * @param ndivisions division number through x
 * @param c fit will perform in range of -c*sigma ~ c*sigma
 * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
 *
 * the histograms are written to fFileDummyGraphics is gverboseG(2) is used,
 * fFileDummyGraphics can be set by gfile(name) method.
 */
TObjArray *ejungwoo::fitgsx_list(TH1 *hist, int ndivisions, double c, int entry_cut)
{
  auto hist2D = (TH2 *) hist;
  auto nbinsx = hist2D -> GetXaxis() -> GetNbins();
  auto nbinsy = hist2D -> GetYaxis() -> GetNbins();
  auto dbinx = nbinsx/ndivisions;

  TObjArray *array = new TObjArray();

  TString oxtitle = hist -> GetXaxis() -> GetTitle(); if (oxtitle.IsNull()) oxtitle = "xvar";
  TString oytitle = hist -> GetYaxis() -> GetTitle(); if (oytitle.IsNull()) oytitle = "yvar";

  auto y1 = hist2D -> GetYaxis() -> GetBinLowEdge(1);
  auto y2 = hist2D -> GetYaxis() -> GetBinUpEdge(nbinsy);

  for (auto idxProjection=0; idxProjection<ndivisions; ++idxProjection)
  {
    auto binx1 = (idxProjection)*dbinx+1;
    auto binx2 = (idxProjection+1)*dbinx;
    auto hist_projected = hist2D -> ProjectionY(TString(hist2D->GetName())+Form("_%d",idxProjection),binx1,binx2);

    auto x1 = hist2D -> GetXaxis() -> GetBinLowEdge(binx1);
    auto x2 = hist2D -> GetXaxis() -> GetBinUpEdge(binx2);
    TString x1_string = Form("%.2f",x1); x1_string.ReplaceAll(".00","");
    TString x2_string = Form("%.2f",x2); x2_string.ReplaceAll(".00","");

    hist_projected -> SetTitle(Form("%s=%s~%s;Count",oxtitle.Data(),x1_string.Data(),x2_string.Data()));
    auto entries = hist_projected -> Integral();
    if (entries<entry_cut)
      continue;

    auto fit = fitg(hist_projected,c);

    if (fVerboseG>0) {
      ejungwoo::cv1();
      make_h(hist_projected) -> Draw();
      fit -> Draw("same");

      if (fVerboseG>1&&fFileDummyGraphics!=nullptr) {
        fFileDummyGraphics -> cd();
        hist_projected -> Write();
      }
    }

    if (fit->GetParameter(0)==0 && fit->GetParameter(2)==0)
      continue;

    auto meanerror = new ejungwoo::t_meanerror(hist_projected);
    meanerror -> fdX     = x2 - x1;
    meanerror -> fMeanX  = (x1 + x2)/2;
    meanerror -> fSigmaX = 0;
    meanerror -> fdY     = y2 - y1;
    meanerror -> fMeanY  = fit -> GetParameter(1);
    meanerror -> fSigmaY = fit -> GetParameter(2);

    array -> Add(meanerror);
  }
  return array;
}


/**
 * fit 2d histogram through y with given parameters and return list of histogram data
 *
 * @param hist input histogram
 * @param ndivisions division number through y
 * @param c fit will perform in range of -c*sigma ~ c*sigma
 * @param entry_cut if histogram entry is smaller than entry_cut, histogram and fit is ignored
 *
 * the histograms are written to fFileDummyGraphics is gverboseG(2) is used,
 * fFileDummyGraphics can be set by gfile(name) method.
 */
TObjArray *ejungwoo::fitgsy_list(TH1 *hist, int ndivisions, double c, int entry_cut) 
{
  auto hist2D = (TH2 *) hist;
  auto nbinsx = hist2D -> GetXaxis() -> GetNbins();
  auto nbinsy = hist2D -> GetYaxis() -> GetNbins();
  auto dbiny = nbinsy/ndivisions;

  TObjArray *array = new TObjArray();

  TString oxtitle = hist -> GetXaxis() -> GetTitle(); if (oxtitle.IsNull()) oxtitle = "xvar";
  TString oytitle = hist -> GetYaxis() -> GetTitle(); if (oytitle.IsNull()) oytitle = "yvar";

  auto x1 = hist2D -> GetXaxis() -> GetBinLowEdge(1);
  auto x2 = hist2D -> GetXaxis() -> GetBinUpEdge(nbinsx);

  for (auto idxProjection=0; idxProjection<ndivisions; ++idxProjection)
  {
    auto biny1 = (idxProjection)*dbiny+1;
    auto biny2 = (idxProjection+1)*dbiny;
    auto hist_projected = hist2D -> ProjectionX(TString(hist2D->GetName())+Form("_%d",idxProjection),biny1,biny2);

    auto y1 = hist2D -> GetYaxis() -> GetBinLowEdge(biny1);
    auto y2 = hist2D -> GetYaxis() -> GetBinUpEdge(biny2);
    TString y1_string = Form("%.2f",y1); y1_string.ReplaceAll(".00","");
    TString y2_string = Form("%.2f",y2); y2_string.ReplaceAll(".00","");

    hist_projected -> SetTitle(Form("%s=%s~%s;Count",oytitle.Data(),y1_string.Data(),y2_string.Data()));
    auto entries = hist_projected -> Integral();
    if (entries<entry_cut)
      continue;

    auto fit = fitg(hist_projected,c);

    if (fVerboseG>0) {
      ejungwoo::cv1();
      make_h(hist_projected) -> Draw();
      fit -> Draw("same");

      if (fVerboseG>1&&fFileDummyGraphics!=nullptr) {
        fFileDummyGraphics -> cd();
        hist_projected -> Write();
      }
    }

    if (fit->GetParameter(0)==0 && fit->GetParameter(2)==0)
      continue;

    auto meanerror = new ejungwoo::t_meanerror(hist_projected);
    meanerror -> fdY     = y2 - y1;
    meanerror -> fMeanY  = (y1 + y2)/2;
    meanerror -> fSigmaY = 0;
    meanerror -> fdX     = x2 - x1;
    meanerror -> fMeanX  = fit -> GetParameter(1);
    meanerror -> fSigmaX = fit -> GetParameter(2);

    array -> Add(meanerror);
  }
  return array;
}


/**
 * Using the data from fitgsx_list
 *
 * @param hist input histogram for analysis
 * @param ndivisions number of division through x
 * @param c c*sigma become the range of the fit
 * @param entry_cut the fit is ignored if the histogram entry is smaller than this cut
 *   - true  will draw fitgsx(hist,"x","dy","","ddy")
 *   - false will draw fitgsx(hist,"x","y","dx/2","dy")
 */
TGraphErrors *ejungwoo::fitgsx(TH1 *hist, int ndivisions, double c, int entry_cut) {
  return fitgsx(hist,"x","y","dyx","sigy",ndivisions,c,entry_cut);
}


/**
 * Using the data from fitgsy_list
 *
 * @param hist input histogram for analysis
 * @param ndivisions number of division through y
 * @param c c*sigma become the range of the fit
 * @param entry_cut the fit is ignored if the histogram entry is smaller than this cut
 *   - true  will draw return fitgsy(hist,"y","dx","ddx","")
 *   - false will draw return fitgsy(hist,"x","y","dx","dy/2")
 */
TGraphErrors *ejungwoo::fitgsy(TH1 *hist, int ndivisions, double c, int entry_cut) {
  return fitgsy(hist,"x","y","sigx","dyh",ndivisions,c,entry_cut);
}

/**
 * Using the data from fitgsx_list
 * Draw error graph of point (xo,yo) and error (xoe,yoe)
 * variables must be one of x(fit mean), y(fit mean), dx(fit sigma), dy(fit sigma), ddx(fit sigma error), ddy(fit sigma error)
 */
TGraphErrors *ejungwoo::fitgsx(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int ndivisions, double c, int entry_cut) {
  auto h2 = (TH2 *) hist;
  auto graph=new TGraphErrors();
  auto array=fitgsx_list(h2,ndivisions,c,entry_cut);
  for (auto i=0; i<array->GetEntries(); ++i) {
    auto h=(ejungwoo::t_meanerror*)array->At(i);
    graph->SetPoint(i,h->get_value(xo),h->get_value(yo));
    graph->SetPointError(i,h->get_value(xoe),h->get_value(yoe));
  }
  return make_ge(graph);
}

/**
 * Using the data from fitgsy_list
 * Draw error graph of point (xo,yo) and error (xoe,yoe)
 * variables must be one of x(fit mean), y(fit mean), dx(fit sigma), dy(fit sigma), ddx(fit sigma error), ddy(fit sigma error)
 */
TGraphErrors *ejungwoo::fitgsy(TH1 *hist, TString xo, TString yo, TString xoe, TString yoe, int ndivisions, double c, int entry_cut) {
  auto h2 = (TH2 *) hist;
  auto graph=new TGraphErrors();
  auto array=fitgsy_list(h2,ndivisions,c,entry_cut);
  for (auto i=0; i<array->GetEntries(); ++i) {
    auto h=(ejungwoo::t_meanerror*)array->At(i);
    graph->SetPoint(i,h->get_value(xo),h->get_value(yo));
    graph->SetPointError(i,h->get_value(xoe),h->get_value(yoe));
  }
  return make_ge(graph);
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
      if(fVerboseS>0) {
        auto cvs=cc(cname);
        make_h(hist)->Draw("colz");
        if(fVerboseS>1)
          save(cvs,"pdf");
      }
    }
    else {
      auto hist=tp(tree,formula,cut,cname,title,nx,x1,x2,-1,-1,-1);
      histograms->Add(hist);
      if(fVerboseS>0) {
        auto cvs=cv(cname);
        make_h(hist)->Draw();
        if(fVerboseS>1)
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

TChain *ejungwoo::chain(TChain *c, TString treename, TString filename, int from=0, int to=0, int *rmlist={}, int numrm=0)
{
  if(fVerbose>0) {
    TString message = Form("%s",filename.Data());
    TString ms_range = Form("[%d-%d",from,to);
    for(auto irm=0;irm<numrm;++irm)
      ms_range = ms_range + TString(Form(",x%d",rmlist[irm]));
    ms_range = ms_range + "]";
    message.ReplaceAll("IDX",ms_range);
    message.ReplaceAll("VERSION",fVersionIn);
    std::cout<<"chain: "<<message<<std::endl;
  }
  if (filename.Index("VERSION")>=0)
    filename.ReplaceAll("VERSION",fVersionIn);
  if (filename.Index("IDX")>=0)
    for(auto i=from;i<=to;++i) {
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
        //if (filenamei[0]!='/'||filenamei[0]!='~'||filenamei[0]!='.')
        if (0)
          filenamei = fDataDirName + "/" + filenamei;
      }
      filenamei.ReplaceAll("IDX",TString::Itoa(i,10));
      if(fVerbose>0)std::cout<<"       ++ "<<filenamei<<std::endl;
      c->Add(filenamei);
    }
  else c->Add(filename);
  return c;
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
    message.ReplaceAll("VERSION",fVersionIn);
    std::cout<<"chain: "<<message<<std::endl;
  }
  if (filename.Index("VERSION")>=0)
    filename.ReplaceAll("VERSION",fVersionIn);
  if (filename.Index("IDX")>=0)
    for(auto i=from;i<=to;++i) {
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
  name = makename(name);
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
      else if (title.Index(";")<0)
        title=title+";"+bnamex+";"+bnamey;
      h=new TH2D(name,title,nx,x1,x2,ny,y1,y2);
    }
  }
  auto n=tree->Project(name,formula,cut);
  if(fVerbose>0)std::cout<<n<<std::endl;
  return make_h(h);
};

TH1 *ejungwoo::tppdg(TString name,TTree *tree,TString formula,TCut cut)
{
  auto hist = tp(tree,Form("ejungwoo::pdg_idx(%s)",formula.Data()),cut,name,";particles;",fNumAxisPDGs,0,fNumAxisPDGs);
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
  return make_h(h);
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
  std::cout<<"cutg->["<<hnew->GetName()<<"],[c:"<<cut->GetName()<<"]->"<<hnew->GetEntries()<<endl;
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
  return make_h((TH1 *)hnew);
}

std::ifstream& ejungwoo::ofile(TString name) {
  fDummyIfstream.open(name);
  return fDummyIfstream;
}

TString ejungwoo::readline(std::ifstream& infile) {
  std::string line;
  if (std::getline(infile, line))
    return TString(line);
  else
    return TString("EOF");
}

TString ejungwoo::readline() {
  return readline(fDummyIfstream);
}

void ejungwoo::cfile() {
  fDummyIfstream.close();
}

TObjArray *ejungwoo::tok(TString line, TString token) {
  return line.Tokenize(token);
}

TString ejungwoo::tok(TString line, TString token, int i)
{
  return tok(line.Tokenize(token),i);
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

TString ejungwoo::toname(TString str) {
  TString name = str;
  name.ReplaceAll("+","_Plus_");
  name.ReplaceAll("-","_Minus_");
  name.ReplaceAll("/","_Ov_");
  name.ReplaceAll("*","_Mult_");

  name.ReplaceAll(">=","_ELt_");
  name.ReplaceAll("<=","_ESt_");
  name.ReplaceAll(">","_Lt_");
  name.ReplaceAll("<","_St_");
  name.ReplaceAll("=","_Eq_");

  name.ReplaceAll(".","_P_");
  name.ReplaceAll(":","_VS_");
  name.ReplaceAll("()","");
  name.ReplaceAll("(","L_");
  name.ReplaceAll(")","_R");

  return name;
}

TH1D *ejungwoo::subtract(TH1D *h, TF1 *f1)
{
  auto hist = (TH1D *) h->Clone(TString(h->GetName())+"_sub_"+f1->GetName());
  auto nbins=hist->GetXaxis()->GetNbins();
  for (auto bin = 1; bin <= nbins; ++bin) {
    auto value = hist->GetBinContent(bin) - f1->Eval(hist->GetBinCenter(bin));
    if (value<0)
      value = 0;
    hist->SetBinContent(bin,value);
  }

  return hist;
}

TString ejungwoo::expf1(TF1 *f1, TString expx, int digits)
{
  auto numPar = f1 -> GetNpar();
  TString expression = f1 -> GetExpFormula();
  for (auto iPar=0; iPar<numPar; ++iPar) {
    if (digits==0) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.0e",f1->GetParameter(iPar)));
    if (digits==1) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.1e",f1->GetParameter(iPar)));
    if (digits==2) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.2e",f1->GetParameter(iPar)));
    if (digits==3) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.3e",f1->GetParameter(iPar)));
    if (digits==4) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.4e",f1->GetParameter(iPar)));
    if (digits==5) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.5e",f1->GetParameter(iPar)));
    if (digits==6) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.6e",f1->GetParameter(iPar)));
    if (digits==7) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.7e",f1->GetParameter(iPar)));
    if (digits==8) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.8e",f1->GetParameter(iPar)));
    if (digits==9) expression.ReplaceAll(Form("[p%d]",iPar),Form("%.9e",f1->GetParameter(iPar)));
  }
  expression.ReplaceAll("--","+");
  expression.ReplaceAll("x",expx);

  int ipow = 0;
  auto sizeExpression = expression.Sizeof();

  while (ipow < sizeExpression) {
    ipow = expression.Index("pow(");
    if (ipow<0)
      break;

    TString strPow1;
    TString strPow2;

    auto istart = ipow+4;
    auto icomma = istart;
    for (; icomma<sizeExpression; ++icomma) {
      auto t1 = expression[icomma];
      if (t1==',') {
        strPow1 = TString(expression(istart ,icomma-istart));
        break;
      }
    }

    auto imid = icomma+1;
    auto iend = imid;
    for (; iend<sizeExpression; ++iend) {
      auto t1 = expression[iend];
      if (t1==')') {
        strPow2 = TString(expression(imid ,iend-imid));
        break;
      }
    }

    auto lenPow = iend-ipow+1;
    if (strPow2.IsDigit()) {
      if (strPow1.Sizeof()>2)
        strPow1 = Form("(%s)",strPow1.Data());
      int power = strPow2.Atoi();
      TString strReplace = strPow1;
      for (auto idx=1; idx<power; ++idx)
        strReplace = strReplace + "*" + strPow1;
      expression.Replace(ipow,lenPow,strReplace);
    }
  }

  return expression;
}

TF1 *ejungwoo::clonef1(TF1 *f1, TString name, int icopy)
{
  if (name.IsNull())
    name = Form("%s_c%d",f1->GetName(),icopy);

  TString expression = f1 -> GetExpFormula();
  if (icopy==0)
    expression = expression + "+0";
  else
    expression = expression + Form("+%d*0",icopy);

  double xmin, xmax;
  f1 -> GetRange(xmin, xmax);

  auto f1clone = new TF1(name,expression,xmin,xmax);
  auto npar = f1 -> GetNpar();
  for (auto ipar=0; ipar<npar; ++ipar)
    f1clone -> SetParameter(ipar, f1->GetParameter(ipar));

  return f1clone;
}

#endif
