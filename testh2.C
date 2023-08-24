#include <cassert>
#include <cmath>
#include "TH2.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TRandom.h"
TCanvas *testh2()
{
   TH2F *h = new TH2F("hist", "Histogram with cut", 100, -10., 10., 100, -10., 10.);
   gRandom->SetSeed();
   for (int i = 0; i < 100000; i++)
      h->Fill(gRandom->Gaus(0., 3.), gRandom->Gaus(0., 3.));
   // get the slice of h
   TH2* hc = h->Slice(-5,5,-5,5,"_slice");
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
