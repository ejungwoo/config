#include "style.h"
using namespace style;

void example_style1()
{
  auto h = new TH1D("example histogram","1D;x;n",100,-50,50);
  auto f = new TF1("gaussian function","100000*TMath::Gaus(x,0,10,true)",-50,50);
  auto l = new TLegend();
  l -> AddEntry(f,"function", "l");
  l -> AddEntry(h,"histogram", "fl");

  for (auto i = 0; i < 100000; ++i) h -> Fill(gRandom -> Gaus(0,10));

  stat(0);
  c();
  make(h) -> Draw();
  make(f) -> Draw("same");
  make(l) -> Draw();
}
