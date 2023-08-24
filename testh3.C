#include <cassert>
#include <cmath>
#include "TH2.h"
#include "TH2D.h"
#include "TCanvas.h"
#include "TRandom.h"
TCanvas *testh3()
{
   TH3F *h = new TH3F("hist", "Histogram with cut", 100, -10., 10., 100, -10., 10., 100, -10., 10.);
   gRandom->SetSeed();
   for (int i = 0; i < 100000; i++)
      h->Fill(gRandom->Gaus(0., 3.), gRandom->Gaus(0., 3.), gRandom->Gaus(0., 3.));
   // get the slice of h
   TH3* hc = h->Slice(-5,5,-5,5,-5,5);
   // draw histogram together with the slice
   TCanvas* c = new TCanvas;
   c->Divide(1,2);
   c->cd(1);
   h->Draw("LEGO1");
   c->cd(2);
   hc->Draw("LEGO1");
   c->Update();
   return c;
}
