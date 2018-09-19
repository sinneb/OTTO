/* ------------------------------------------------------------
name: "untitled"
Code generated with Faust 2.8.0 (https://faust.grame.fr)
Compilation options: cpp, -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fButton0;
	int iRec1[2];
	int fSamplingFreq;
	float fConst0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst1;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec0[2];
	float fConst2;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	float fRec2[2];
	FAUSTFLOAT fHslider7;
	float fRec4[2];
	FAUSTFLOAT fHslider8;
	float fRec6[2];
	FAUSTFLOAT fHslider9;
	float fRec8[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fButton1;
	int iRec11[2];
	float fRec10[2];
	FAUSTFLOAT fHslider11;
	float fRec12[2];
	float fRec14[2];
	float fRec16[2];
	float fRec18[2];
	FAUSTFLOAT fHslider12;
	FAUSTFLOAT fButton2;
	int iRec21[2];
	float fRec20[2];
	FAUSTFLOAT fHslider13;
	float fRec22[2];
	float fRec24[2];
	float fRec26[2];
	float fRec28[2];
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fButton3;
	int iRec31[2];
	float fRec30[2];
	FAUSTFLOAT fHslider15;
	float fRec32[2];
	float fRec34[2];
	float fRec36[2];
	float fRec38[2];
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fButton4;
	int iRec41[2];
	float fRec40[2];
	FAUSTFLOAT fHslider17;
	float fRec42[2];
	float fRec44[2];
	float fRec46[2];
	float fRec48[2];
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fButton5;
	int iRec51[2];
	float fRec50[2];
	FAUSTFLOAT fHslider19;
	float fRec52[2];
	float fRec54[2];
	float fRec56[2];
	float fRec58[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.0");
		m->declare("filename", "untitled");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "untitled");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
		
	}
	virtual int getNumOutputs() {
		return 1;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min(192000.0f, std::max(1.0f, float(fSamplingFreq)));
		fConst1 = (6.90999985f / fConst0);
		fConst2 = (1.0f / fConst0);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.001f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(440.0f);
		fHslider6 = FAUSTFLOAT(440.0f);
		fHslider7 = FAUSTFLOAT(440.0f);
		fHslider8 = FAUSTFLOAT(440.0f);
		fHslider9 = FAUSTFLOAT(440.0f);
		fHslider10 = FAUSTFLOAT(0.5f);
		fButton1 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(440.0f);
		fHslider12 = FAUSTFLOAT(0.5f);
		fButton2 = FAUSTFLOAT(0.0f);
		fHslider13 = FAUSTFLOAT(440.0f);
		fHslider14 = FAUSTFLOAT(0.5f);
		fButton3 = FAUSTFLOAT(0.0f);
		fHslider15 = FAUSTFLOAT(440.0f);
		fHslider16 = FAUSTFLOAT(0.5f);
		fButton4 = FAUSTFLOAT(0.0f);
		fHslider17 = FAUSTFLOAT(440.0f);
		fHslider18 = FAUSTFLOAT(0.5f);
		fButton5 = FAUSTFLOAT(0.0f);
		fHslider19 = FAUSTFLOAT(440.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iRec1[l0] = 0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec2[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec4[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec6[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec8[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			iRec11[l6] = 0;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec10[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec12[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec14[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec16[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec18[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec21[l12] = 0;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec20[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec22[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec24[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec26[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			fRec28[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			iRec31[l18] = 0;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec30[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec32[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec34[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec36[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec38[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			iRec41[l24] = 0;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec40[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec42[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec44[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec46[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec48[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			iRec51[l30] = 0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec50[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec52[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fRec54[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec56[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec58[l35] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("untitled");
		ui_interface->openVerticalBox("envelope");
		ui_interface->addHorizontalSlider("Attack", &fHslider1, 0.00100000005f, 0.00100000005f, 4.0f, 0.00100000005f);
		ui_interface->addHorizontalSlider("Decay", &fHslider4, 0.0f, 0.0f, 4.0f, 0.00100000005f);
		ui_interface->addHorizontalSlider("Release", &fHslider3, 0.0f, 0.0f, 4.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("Sustain", &fHslider2, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->closeBox();
		ui_interface->addHorizontalSlider("saw1freq", &fHslider8, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addHorizontalSlider("saw2freq", &fHslider9, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addHorizontalSlider("saw3freq", &fHslider5, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addHorizontalSlider("saw4freq", &fHslider7, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->openHorizontalBox("voices");
		ui_interface->openVerticalBox("0");
		ui_interface->openHorizontalBox("midi");
		ui_interface->addHorizontalSlider("freq", &fHslider13, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addButton("trigger", &fButton2);
		ui_interface->addHorizontalSlider("velocity", &fHslider12, 0.5f, 0.0f, 1.0f, 0.00787401572f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("1");
		ui_interface->openHorizontalBox("midi");
		ui_interface->addHorizontalSlider("freq", &fHslider17, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addButton("trigger", &fButton4);
		ui_interface->addHorizontalSlider("velocity", &fHslider16, 0.5f, 0.0f, 1.0f, 0.00787401572f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("2");
		ui_interface->openHorizontalBox("midi");
		ui_interface->addHorizontalSlider("freq", &fHslider6, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addButton("trigger", &fButton0);
		ui_interface->addHorizontalSlider("velocity", &fHslider0, 0.5f, 0.0f, 1.0f, 0.00787401572f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("3");
		ui_interface->openHorizontalBox("midi");
		ui_interface->addHorizontalSlider("freq", &fHslider11, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addButton("trigger", &fButton1);
		ui_interface->addHorizontalSlider("velocity", &fHslider10, 0.5f, 0.0f, 1.0f, 0.00787401572f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("4");
		ui_interface->openHorizontalBox("midi");
		ui_interface->addHorizontalSlider("freq", &fHslider15, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addButton("trigger", &fButton3);
		ui_interface->addHorizontalSlider("velocity", &fHslider14, 0.5f, 0.0f, 1.0f, 0.00787401572f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->openVerticalBox("5");
		ui_interface->openHorizontalBox("midi");
		ui_interface->addHorizontalSlider("freq", &fHslider19, 440.0f, 20.0f, 1000.0f, 1.0f);
		ui_interface->addButton("trigger", &fButton5);
		ui_interface->addHorizontalSlider("velocity", &fHslider18, 0.5f, 0.0f, 1.0f, 0.00787401572f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = float(fHslider0);
		int iSlow1 = (float(fButton0) > 0.0f);
		float fSlow2 = float(fHslider1);
		int iSlow3 = int((fConst0 * fSlow2));
		float fSlow4 = float(fHslider2);
		float fSlow5 = (fSlow4 * float(iSlow1));
		float fSlow6 = float(fHslider3);
		float fSlow7 = float(fHslider4);
		float fSlow8 = float(fHslider5);
		float fSlow9 = float(fHslider6);
		float fSlow10 = std::max(1.00000001e-07f, std::fabs((fSlow8 + fSlow9)));
		float fSlow11 = (fConst2 * fSlow10);
		float fSlow12 = (1.0f - (fConst0 / fSlow10));
		float fSlow13 = float(fHslider7);
		float fSlow14 = std::max(1.00000001e-07f, std::fabs((fSlow13 + fSlow9)));
		float fSlow15 = (fConst2 * fSlow14);
		float fSlow16 = (1.0f - (fConst0 / fSlow14));
		float fSlow17 = float(fHslider8);
		float fSlow18 = std::max(1.00000001e-07f, std::fabs((fSlow17 + fSlow9)));
		float fSlow19 = (fConst2 * fSlow18);
		float fSlow20 = (1.0f - (fConst0 / fSlow18));
		float fSlow21 = float(fHslider9);
		float fSlow22 = std::max(1.00000001e-07f, std::fabs((fSlow21 + fSlow9)));
		float fSlow23 = (fConst2 * fSlow22);
		float fSlow24 = (1.0f - (fConst0 / fSlow22));
		float fSlow25 = float(fHslider10);
		int iSlow26 = (float(fButton1) > 0.0f);
		float fSlow27 = (fSlow4 * float(iSlow26));
		float fSlow28 = float(fHslider11);
		float fSlow29 = std::max(1.00000001e-07f, std::fabs((fSlow8 + fSlow28)));
		float fSlow30 = (fConst2 * fSlow29);
		float fSlow31 = (1.0f - (fConst0 / fSlow29));
		float fSlow32 = std::max(1.00000001e-07f, std::fabs((fSlow13 + fSlow28)));
		float fSlow33 = (fConst2 * fSlow32);
		float fSlow34 = (1.0f - (fConst0 / fSlow32));
		float fSlow35 = std::max(1.00000001e-07f, std::fabs((fSlow17 + fSlow28)));
		float fSlow36 = (fConst2 * fSlow35);
		float fSlow37 = (1.0f - (fConst0 / fSlow35));
		float fSlow38 = std::max(1.00000001e-07f, std::fabs((fSlow21 + fSlow28)));
		float fSlow39 = (fConst2 * fSlow38);
		float fSlow40 = (1.0f - (fConst0 / fSlow38));
		float fSlow41 = float(fHslider12);
		int iSlow42 = (float(fButton2) > 0.0f);
		float fSlow43 = (fSlow4 * float(iSlow42));
		float fSlow44 = float(fHslider13);
		float fSlow45 = std::max(1.00000001e-07f, std::fabs((fSlow8 + fSlow44)));
		float fSlow46 = (fConst2 * fSlow45);
		float fSlow47 = (1.0f - (fConst0 / fSlow45));
		float fSlow48 = std::max(1.00000001e-07f, std::fabs((fSlow13 + fSlow44)));
		float fSlow49 = (fConst2 * fSlow48);
		float fSlow50 = (1.0f - (fConst0 / fSlow48));
		float fSlow51 = std::max(1.00000001e-07f, std::fabs((fSlow17 + fSlow44)));
		float fSlow52 = (fConst2 * fSlow51);
		float fSlow53 = (1.0f - (fConst0 / fSlow51));
		float fSlow54 = std::max(1.00000001e-07f, std::fabs((fSlow21 + fSlow44)));
		float fSlow55 = (fConst2 * fSlow54);
		float fSlow56 = (1.0f - (fConst0 / fSlow54));
		float fSlow57 = float(fHslider14);
		int iSlow58 = (float(fButton3) > 0.0f);
		float fSlow59 = (fSlow4 * float(iSlow58));
		float fSlow60 = float(fHslider15);
		float fSlow61 = std::max(1.00000001e-07f, std::fabs((fSlow8 + fSlow60)));
		float fSlow62 = (fConst2 * fSlow61);
		float fSlow63 = (1.0f - (fConst0 / fSlow61));
		float fSlow64 = std::max(1.00000001e-07f, std::fabs((fSlow13 + fSlow60)));
		float fSlow65 = (fConst2 * fSlow64);
		float fSlow66 = (1.0f - (fConst0 / fSlow64));
		float fSlow67 = std::max(1.00000001e-07f, std::fabs((fSlow17 + fSlow60)));
		float fSlow68 = (fConst2 * fSlow67);
		float fSlow69 = (1.0f - (fConst0 / fSlow67));
		float fSlow70 = std::max(1.00000001e-07f, std::fabs((fSlow21 + fSlow60)));
		float fSlow71 = (fConst2 * fSlow70);
		float fSlow72 = (1.0f - (fConst0 / fSlow70));
		float fSlow73 = float(fHslider16);
		int iSlow74 = (float(fButton4) > 0.0f);
		float fSlow75 = (fSlow4 * float(iSlow74));
		float fSlow76 = float(fHslider17);
		float fSlow77 = std::max(1.00000001e-07f, std::fabs((fSlow8 + fSlow76)));
		float fSlow78 = (fConst2 * fSlow77);
		float fSlow79 = (1.0f - (fConst0 / fSlow77));
		float fSlow80 = std::max(1.00000001e-07f, std::fabs((fSlow13 + fSlow76)));
		float fSlow81 = (fConst2 * fSlow80);
		float fSlow82 = (1.0f - (fConst0 / fSlow80));
		float fSlow83 = std::max(1.00000001e-07f, std::fabs((fSlow17 + fSlow76)));
		float fSlow84 = (fConst2 * fSlow83);
		float fSlow85 = (1.0f - (fConst0 / fSlow83));
		float fSlow86 = std::max(1.00000001e-07f, std::fabs((fSlow21 + fSlow76)));
		float fSlow87 = (fConst2 * fSlow86);
		float fSlow88 = (1.0f - (fConst0 / fSlow86));
		float fSlow89 = float(fHslider18);
		int iSlow90 = (float(fButton5) > 0.0f);
		float fSlow91 = (fSlow4 * float(iSlow90));
		float fSlow92 = float(fHslider19);
		float fSlow93 = std::max(1.00000001e-07f, std::fabs((fSlow8 + fSlow92)));
		float fSlow94 = (fConst2 * fSlow93);
		float fSlow95 = (1.0f - (fConst0 / fSlow93));
		float fSlow96 = std::max(1.00000001e-07f, std::fabs((fSlow13 + fSlow92)));
		float fSlow97 = (fConst2 * fSlow96);
		float fSlow98 = (1.0f - (fConst0 / fSlow96));
		float fSlow99 = std::max(1.00000001e-07f, std::fabs((fSlow17 + fSlow92)));
		float fSlow100 = (fConst2 * fSlow99);
		float fSlow101 = (1.0f - (fConst0 / fSlow99));
		float fSlow102 = std::max(1.00000001e-07f, std::fabs((fSlow21 + fSlow92)));
		float fSlow103 = (fConst2 * fSlow102);
		float fSlow104 = (1.0f - (fConst0 / fSlow102));
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec1[0] = (iSlow1 * (iRec1[1] + 1));
			int iTemp0 = (iRec1[0] < iSlow3);
			float fTemp1 = std::exp((0.0f - (fConst1 / (iSlow1?(iTemp0?fSlow2:fSlow7):fSlow6))));
			fRec0[0] = (((iSlow1?(iTemp0?float(iSlow1):fSlow5):0.0f) * (1.0f - fTemp1)) + (fRec0[1] * fTemp1));
			float fTemp2 = (fSlow11 + (fRec2[1] + -1.0f));
			int iTemp3 = (fTemp2 < 0.0f);
			float fTemp4 = (fSlow11 + fRec2[1]);
			fRec2[0] = (iTemp3?fTemp4:fTemp2);
			float fRec3 = (iTemp3?fTemp4:(fSlow11 + (fRec2[1] + (fSlow12 * fTemp2))));
			float fTemp5 = (fSlow15 + (fRec4[1] + -1.0f));
			int iTemp6 = (fTemp5 < 0.0f);
			float fTemp7 = (fSlow15 + fRec4[1]);
			fRec4[0] = (iTemp6?fTemp7:fTemp5);
			float fRec5 = (iTemp6?fTemp7:(fSlow15 + (fRec4[1] + (fSlow16 * fTemp5))));
			float fTemp8 = (fSlow19 + (fRec6[1] + -1.0f));
			int iTemp9 = (fTemp8 < 0.0f);
			float fTemp10 = (fSlow19 + fRec6[1]);
			fRec6[0] = (iTemp9?fTemp10:fTemp8);
			float fRec7 = (iTemp9?fTemp10:(fSlow19 + (fRec6[1] + (fSlow20 * fTemp8))));
			float fTemp11 = (fSlow23 + (fRec8[1] + -1.0f));
			int iTemp12 = (fTemp11 < 0.0f);
			float fTemp13 = (fSlow23 + fRec8[1]);
			fRec8[0] = (iTemp12?fTemp13:fTemp11);
			float fRec9 = (iTemp12?fTemp13:(fSlow23 + (fRec8[1] + (fSlow24 * fTemp11))));
			iRec11[0] = (iSlow26 * (iRec11[1] + 1));
			int iTemp14 = (iRec11[0] < iSlow3);
			float fTemp15 = std::exp((0.0f - (fConst1 / (iSlow26?(iTemp14?fSlow2:fSlow7):fSlow6))));
			fRec10[0] = (((iSlow26?(iTemp14?float(iSlow26):fSlow27):0.0f) * (1.0f - fTemp15)) + (fRec10[1] * fTemp15));
			float fTemp16 = (fSlow30 + (fRec12[1] + -1.0f));
			int iTemp17 = (fTemp16 < 0.0f);
			float fTemp18 = (fSlow30 + fRec12[1]);
			fRec12[0] = (iTemp17?fTemp18:fTemp16);
			float fRec13 = (iTemp17?fTemp18:(fSlow30 + (fRec12[1] + (fSlow31 * fTemp16))));
			float fTemp19 = (fSlow33 + (fRec14[1] + -1.0f));
			int iTemp20 = (fTemp19 < 0.0f);
			float fTemp21 = (fSlow33 + fRec14[1]);
			fRec14[0] = (iTemp20?fTemp21:fTemp19);
			float fRec15 = (iTemp20?fTemp21:(fSlow33 + (fRec14[1] + (fSlow34 * fTemp19))));
			float fTemp22 = (fSlow36 + (fRec16[1] + -1.0f));
			int iTemp23 = (fTemp22 < 0.0f);
			float fTemp24 = (fSlow36 + fRec16[1]);
			fRec16[0] = (iTemp23?fTemp24:fTemp22);
			float fRec17 = (iTemp23?fTemp24:(fSlow36 + (fRec16[1] + (fSlow37 * fTemp22))));
			float fTemp25 = (fSlow39 + (fRec18[1] + -1.0f));
			int iTemp26 = (fTemp25 < 0.0f);
			float fTemp27 = (fSlow39 + fRec18[1]);
			fRec18[0] = (iTemp26?fTemp27:fTemp25);
			float fRec19 = (iTemp26?fTemp27:(fSlow39 + (fRec18[1] + (fSlow40 * fTemp25))));
			iRec21[0] = (iSlow42 * (iRec21[1] + 1));
			int iTemp28 = (iRec21[0] < iSlow3);
			float fTemp29 = std::exp((0.0f - (fConst1 / (iSlow42?(iTemp28?fSlow2:fSlow7):fSlow6))));
			fRec20[0] = (((iSlow42?(iTemp28?float(iSlow42):fSlow43):0.0f) * (1.0f - fTemp29)) + (fRec20[1] * fTemp29));
			float fTemp30 = (fSlow46 + (fRec22[1] + -1.0f));
			int iTemp31 = (fTemp30 < 0.0f);
			float fTemp32 = (fSlow46 + fRec22[1]);
			fRec22[0] = (iTemp31?fTemp32:fTemp30);
			float fRec23 = (iTemp31?fTemp32:(fSlow46 + (fRec22[1] + (fSlow47 * fTemp30))));
			float fTemp33 = (fSlow49 + (fRec24[1] + -1.0f));
			int iTemp34 = (fTemp33 < 0.0f);
			float fTemp35 = (fSlow49 + fRec24[1]);
			fRec24[0] = (iTemp34?fTemp35:fTemp33);
			float fRec25 = (iTemp34?fTemp35:(fSlow49 + (fRec24[1] + (fSlow50 * fTemp33))));
			float fTemp36 = (fSlow52 + (fRec26[1] + -1.0f));
			int iTemp37 = (fTemp36 < 0.0f);
			float fTemp38 = (fSlow52 + fRec26[1]);
			fRec26[0] = (iTemp37?fTemp38:fTemp36);
			float fRec27 = (iTemp37?fTemp38:(fSlow52 + (fRec26[1] + (fSlow53 * fTemp36))));
			float fTemp39 = (fSlow55 + (fRec28[1] + -1.0f));
			int iTemp40 = (fTemp39 < 0.0f);
			float fTemp41 = (fSlow55 + fRec28[1]);
			fRec28[0] = (iTemp40?fTemp41:fTemp39);
			float fRec29 = (iTemp40?fTemp41:(fSlow55 + (fRec28[1] + (fSlow56 * fTemp39))));
			iRec31[0] = (iSlow58 * (iRec31[1] + 1));
			int iTemp42 = (iRec31[0] < iSlow3);
			float fTemp43 = std::exp((0.0f - (fConst1 / (iSlow58?(iTemp42?fSlow2:fSlow7):fSlow6))));
			fRec30[0] = (((iSlow58?(iTemp42?float(iSlow58):fSlow59):0.0f) * (1.0f - fTemp43)) + (fRec30[1] * fTemp43));
			float fTemp44 = (fSlow62 + (fRec32[1] + -1.0f));
			int iTemp45 = (fTemp44 < 0.0f);
			float fTemp46 = (fSlow62 + fRec32[1]);
			fRec32[0] = (iTemp45?fTemp46:fTemp44);
			float fRec33 = (iTemp45?fTemp46:(fSlow62 + (fRec32[1] + (fSlow63 * fTemp44))));
			float fTemp47 = (fSlow65 + (fRec34[1] + -1.0f));
			int iTemp48 = (fTemp47 < 0.0f);
			float fTemp49 = (fSlow65 + fRec34[1]);
			fRec34[0] = (iTemp48?fTemp49:fTemp47);
			float fRec35 = (iTemp48?fTemp49:(fSlow65 + (fRec34[1] + (fSlow66 * fTemp47))));
			float fTemp50 = (fSlow68 + (fRec36[1] + -1.0f));
			int iTemp51 = (fTemp50 < 0.0f);
			float fTemp52 = (fSlow68 + fRec36[1]);
			fRec36[0] = (iTemp51?fTemp52:fTemp50);
			float fRec37 = (iTemp51?fTemp52:(fSlow68 + (fRec36[1] + (fSlow69 * fTemp50))));
			float fTemp53 = (fSlow71 + (fRec38[1] + -1.0f));
			int iTemp54 = (fTemp53 < 0.0f);
			float fTemp55 = (fSlow71 + fRec38[1]);
			fRec38[0] = (iTemp54?fTemp55:fTemp53);
			float fRec39 = (iTemp54?fTemp55:(fSlow71 + (fRec38[1] + (fSlow72 * fTemp53))));
			iRec41[0] = (iSlow74 * (iRec41[1] + 1));
			int iTemp56 = (iRec41[0] < iSlow3);
			float fTemp57 = std::exp((0.0f - (fConst1 / (iSlow74?(iTemp56?fSlow2:fSlow7):fSlow6))));
			fRec40[0] = (((iSlow74?(iTemp56?float(iSlow74):fSlow75):0.0f) * (1.0f - fTemp57)) + (fRec40[1] * fTemp57));
			float fTemp58 = (fSlow78 + (fRec42[1] + -1.0f));
			int iTemp59 = (fTemp58 < 0.0f);
			float fTemp60 = (fSlow78 + fRec42[1]);
			fRec42[0] = (iTemp59?fTemp60:fTemp58);
			float fRec43 = (iTemp59?fTemp60:(fSlow78 + (fRec42[1] + (fSlow79 * fTemp58))));
			float fTemp61 = (fSlow81 + (fRec44[1] + -1.0f));
			int iTemp62 = (fTemp61 < 0.0f);
			float fTemp63 = (fSlow81 + fRec44[1]);
			fRec44[0] = (iTemp62?fTemp63:fTemp61);
			float fRec45 = (iTemp62?fTemp63:(fSlow81 + (fRec44[1] + (fSlow82 * fTemp61))));
			float fTemp64 = (fSlow84 + (fRec46[1] + -1.0f));
			int iTemp65 = (fTemp64 < 0.0f);
			float fTemp66 = (fSlow84 + fRec46[1]);
			fRec46[0] = (iTemp65?fTemp66:fTemp64);
			float fRec47 = (iTemp65?fTemp66:(fSlow84 + (fRec46[1] + (fSlow85 * fTemp64))));
			float fTemp67 = (fSlow87 + (fRec48[1] + -1.0f));
			int iTemp68 = (fTemp67 < 0.0f);
			float fTemp69 = (fSlow87 + fRec48[1]);
			fRec48[0] = (iTemp68?fTemp69:fTemp67);
			float fRec49 = (iTemp68?fTemp69:(fSlow87 + (fRec48[1] + (fSlow88 * fTemp67))));
			iRec51[0] = (iSlow90 * (iRec51[1] + 1));
			int iTemp70 = (iRec51[0] < iSlow3);
			float fTemp71 = std::exp((0.0f - (fConst1 / (iSlow90?(iTemp70?fSlow2:fSlow7):fSlow6))));
			fRec50[0] = (((iSlow90?(iTemp70?float(iSlow90):fSlow91):0.0f) * (1.0f - fTemp71)) + (fRec50[1] * fTemp71));
			float fTemp72 = (fSlow94 + (fRec52[1] + -1.0f));
			int iTemp73 = (fTemp72 < 0.0f);
			float fTemp74 = (fSlow94 + fRec52[1]);
			fRec52[0] = (iTemp73?fTemp74:fTemp72);
			float fRec53 = (iTemp73?fTemp74:(fSlow94 + (fRec52[1] + (fSlow95 * fTemp72))));
			float fTemp75 = (fSlow97 + (fRec54[1] + -1.0f));
			int iTemp76 = (fTemp75 < 0.0f);
			float fTemp77 = (fSlow97 + fRec54[1]);
			fRec54[0] = (iTemp76?fTemp77:fTemp75);
			float fRec55 = (iTemp76?fTemp77:(fSlow97 + (fRec54[1] + (fSlow98 * fTemp75))));
			float fTemp78 = (fSlow100 + (fRec56[1] + -1.0f));
			int iTemp79 = (fTemp78 < 0.0f);
			float fTemp80 = (fSlow100 + fRec56[1]);
			fRec56[0] = (iTemp79?fTemp80:fTemp78);
			float fRec57 = (iTemp79?fTemp80:(fSlow100 + (fRec56[1] + (fSlow101 * fTemp78))));
			float fTemp81 = (fSlow103 + (fRec58[1] + -1.0f));
			int iTemp82 = (fTemp81 < 0.0f);
			float fTemp83 = (fSlow103 + fRec58[1]);
			fRec58[0] = (iTemp82?fTemp83:fTemp81);
			float fRec59 = (iTemp82?fTemp83:(fSlow103 + (fRec58[1] + (fSlow104 * fTemp81))));
			output0[i] = FAUSTFLOAT((((fSlow0 * (fRec0[0] * (0.0f - (2.0f * (2.0f - (fRec3 + (fRec5 + (fRec7 + fRec9)))))))) + ((fSlow25 * (fRec10[0] * (0.0f - (2.0f * (2.0f - (fRec13 + (fRec15 + (fRec17 + fRec19)))))))) + ((fSlow41 * (fRec20[0] * (0.0f - (2.0f * (2.0f - (fRec23 + (fRec25 + (fRec27 + fRec29)))))))) + ((fSlow57 * (fRec30[0] * (0.0f - (2.0f * (2.0f - (fRec33 + (fRec35 + (fRec37 + fRec39)))))))) + (fSlow73 * (fRec40[0] * (0.0f - (2.0f * (2.0f - (fRec43 + (fRec45 + (fRec47 + fRec49)))))))))))) + (fSlow89 * (fRec50[0] * (0.0f - (2.0f * (2.0f - (fRec53 + (fRec55 + (fRec57 + fRec59))))))))));
			iRec1[1] = iRec1[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			iRec11[1] = iRec11[0];
			fRec10[1] = fRec10[0];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec16[1] = fRec16[0];
			fRec18[1] = fRec18[0];
			iRec21[1] = iRec21[0];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			iRec31[1] = iRec31[0];
			fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			fRec34[1] = fRec34[0];
			fRec36[1] = fRec36[0];
			fRec38[1] = fRec38[0];
			iRec41[1] = iRec41[0];
			fRec40[1] = fRec40[0];
			fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			fRec46[1] = fRec46[0];
			fRec48[1] = fRec48[0];
			iRec51[1] = iRec51[0];
			fRec50[1] = fRec50[0];
			fRec52[1] = fRec52[0];
			fRec54[1] = fRec54[0];
			fRec56[1] = fRec56[0];
			fRec58[1] = fRec58[0];
			
		}
		
	}

	
};

#endif
