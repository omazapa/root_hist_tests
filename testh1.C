#include <cassert>
#include <cmath>
#include "TH1.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TRandom.h"
TCanvas *testh1()
{
   TH1* h = new TH1D("h", "h", 100, -5., 5.);
   gRandom->SetSeed();
   h->FillRandom("gaus", 1u << 16);
   // get the slice of h
   TH1* hc = h->Slice(-2,2,"_slice");
   // draw histogram together with the slice
   TCanvas* c = new TCanvas;
   c->Divide(1,2);
   c->cd(1);
   h->Draw();
   c->cd(2);
   hc->Draw();
   c->Update();
   return c;
}
