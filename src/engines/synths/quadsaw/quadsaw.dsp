//Front-panel controls are "saw1freq" "saw2freq", "saw3freq", "saw4freq", and the ADSR envelope.

import("stdfaust.lib");

// voices allocation, leave like this. OTTO does the voicehandling itself
process = hgroup("voices", vgroup("0", voice) + vgroup("3", voice) +
                           vgroup("1", voice) + vgroup("4", voice) +
                           vgroup("2", voice) + vgroup("5", voice)) :  _ ;

// single voice definition. Listen to midi, send to mixer * envelope
voice = hgroup("midi", mixer :> *(envelope))
  
with {
  midigate	= button ("trigger");
  midifreq	= hslider("freq", 440, 20, 1000, 1);
  midigain	= hslider("velocity", 0.5, 0, 1, 1/127);
  
  saw1freq = hslider("/saw1freq", 440, 20, 1000, 1);
  saw1 = os.sawtooth(saw1freq + midifreq);

  saw2freq = hslider("/saw2freq", 440, 20, 1000, 1);
  saw2 = os.sawtooth(saw2freq + midifreq);

  saw3freq = hslider("/saw3freq", 440, 20, 1000, 1);
  saw3 = os.sawtooth(saw3freq + midifreq);
  
  saw4freq = hslider("/saw4freq", 440, 20, 1000, 1);
  saw4 = os.sawtooth(saw4freq + midifreq);

  mixer = (saw1, saw2, saw3, saw4);

  //ADSR envelope----------------------------
  envelope = en.adsre(a,d,s,r,midigate)*(midigain);
  a = hslider("/v:envelope/Attack", 0.001, 0.001, 4, 0.001);
  d = hslider("/v:envelope/Decay", 0.0, 0.0, 4, 0.001);
  s = hslider("/v:envelope/Sustain", 1.0, 0.0, 1.0, 0.01);
  r = hslider("/v:envelope/Release", 0.0, 0.0, 4.0, 0.01);

};
