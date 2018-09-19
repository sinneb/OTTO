#pragma once

#include "core/engines/engine.hpp"

#include "core/audio/faust.hpp"
#include "core/audio/voice_manager.hpp"

namespace otto::engines {

  using namespace core;
  using namespace core::engines;
  using namespace props;

  struct quadsawSynth : SynthEngine, EngineWithEnvelope {

    struct Props : Properties<> {

      Property<float> saw1   = {this, "saw1freq",     0,  has_limits::init(20, 1000),    steppable::init(10)};
      Property<float> saw2   = {this, "saw2freq", 0,  has_limits::init(20, 1000),    steppable::init(10)};
      Property<float> saw3   = {this, "saw3freq",      0,  has_limits::init(20, 1000),    steppable::init(10)};
      Property<float> saw4   = {this, "saw4freq",   0,  has_limits::init(20, 1000),    steppable::init(10)};

    } props;

    quadsawSynth();

    audio::ProcessData<1> process(audio::ProcessData<0>) override;

    ui::Screen& envelope_screen() override {
      return voice_mgr_.envelope_screen();
    }

    ui::Screen& voices_screen() override {
      return voice_mgr_.settings_screen();
    }

  private:
    audio::VoiceManager<6> voice_mgr_;
    audio::FaustWrapper<0, 1> faust_;
  };
} // namespace otto::engines
