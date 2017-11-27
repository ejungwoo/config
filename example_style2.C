#include "style.h"
using namespace style;

void example_style2()
{
  auto h = new TH2D("example histogram","2D;x;n",100,-50,50,100,-50,50);
  for (auto i = 0; i < 100000; ++i) h -> Fill(gRandom -> Gaus(0,10),gRandom -> Gaus(0,10));

  cc();
  make(h) -> Draw("contz");
}
