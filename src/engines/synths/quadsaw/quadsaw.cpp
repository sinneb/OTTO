#include "quadsaw.hpp"

#include "core/globals.hpp"
#include "core/ui/vector_graphics.hpp"

#include "quadsaw.faust.hpp"

namespace otto::engines {

  using namespace ui;
  using namespace ui::vg;

  /*
   * Declarations
   */

  struct quadsawSynthScreen : EngineScreen<quadsawSynth> {
    void draw(Canvas& ctx) override;
    bool keypress(Key key) override;
    void rotary(RotaryEvent e) override;

    using EngineScreen<quadsawSynth>::EngineScreen;

    void draw_interface(Canvas& ctx);
    void draw_power(Canvas& ctx);
    void draw_key(Canvas& ctx);
    void draw_dots(Canvas& ctx);
    void draw_bars(Canvas& ctx);
    void draw_aux(Canvas& ctx);
    void draw_wave(Canvas& ctx);
    void draw_Q(Canvas& ctx);
    void draw_sights(Canvas& ctx);
  };

  // NukeSynth ////////////////////////////////////////////////////////////////

  quadsawSynth::quadsawSynth()
    : SynthEngine("quadsaw", props, std::make_unique<quadsawSynthScreen>(this)),
      voice_mgr_(props),
      faust_(std::make_unique<FAUSTCLASS>(), props)
  {}

  audio::ProcessData<1> quadsawSynth::process(audio::ProcessData<0> data)
  {
    voice_mgr_.process_before(data);
    auto res = faust_.process(data);
    voice_mgr_.process_after(data);
    return res;
  }

  /*
   * quadsawSynthScreen
   */

  bool quadsawSynthScreen::keypress(Key key)
  {
    return false;
  }

  void quadsawSynthScreen::rotary(RotaryEvent e)
  {
    switch (e.rotary) {
    case Rotary::Blue:
      engine.props.saw1.step(e.clicks);
      break;
    case Rotary::Green:
      engine.props.saw2.step(e.clicks);
      break;
    case Rotary::White:
      engine.props.saw3.step(e.clicks);
      break;
    case Rotary::Red:
      engine.props.saw4.step(e.clicks);
      break;
    }
  }

  using namespace ui::vg;

  void quadsawSynthScreen::draw(Canvas& ctx)
  {
    draw_interface(ctx);
  }

  void quadsawSynthScreen::draw_interface(Canvas& ctx)
  {

    ctx.save();
    ctx.font(Fonts::Bold, 18.0);
    ctx.textAlign(TextAlign::Center, TextAlign::Baseline);
    ctx.fillText("quadsaw", 40,20);
    
    ctx.beginPath();
    ctx.moveTo(0,27);
    ctx.lineTo(400,27);
    ctx.closePath();
    ctx.lineWidth(1.0);
    ctx.strokeStyle(Colour::bytes(255, 255, 255));
    ctx.lineCap(Canvas::LineCap::ROUND);
    ctx.lineJoin(Canvas::LineJoin::ROUND);
    ctx.stroke();

    
    ctx.beginPath();
    ctx.moveTo(20,200);
    ctx.lineTo(20,200-(engine.props.saw1/10));
    ctx.lineTo(30,200-(engine.props.saw1/10));
    ctx.lineTo(30,200);
    ctx.lineTo(20,200);
    ctx.closePath();
    ctx.lineWidth(2.0);
    ctx.strokeStyle(Colour::bytes(0, 0, 255));
    ctx.lineCap(Canvas::LineCap::ROUND);
    ctx.lineJoin(Canvas::LineJoin::ROUND);
    ctx.stroke();
    
    ctx.beginPath();
    ctx.moveTo(50,200);
    ctx.lineTo(50,200-(engine.props.saw2/10));
    ctx.lineTo(60,200-(engine.props.saw2/10));
    ctx.lineTo(60,200);
    ctx.lineTo(50,200);
    ctx.closePath();
    ctx.lineWidth(2.0);
    ctx.strokeStyle(Colour::bytes(0, 255, 0));
    ctx.lineCap(Canvas::LineCap::ROUND);
    ctx.lineJoin(Canvas::LineJoin::ROUND);
    ctx.stroke();
    
    ctx.beginPath();
    ctx.moveTo(80,200);
    ctx.lineTo(80,200-(engine.props.saw3/10));
    ctx.lineTo(90,200-(engine.props.saw3/10));
    ctx.lineTo(90,200);
    ctx.lineTo(80,200);
    ctx.closePath();
    ctx.lineWidth(2.0);
    ctx.strokeStyle(Colour::bytes(255, 255, 0));
    ctx.lineCap(Canvas::LineCap::ROUND);
    ctx.lineJoin(Canvas::LineJoin::ROUND);
    ctx.stroke();
    
    ctx.beginPath();
    ctx.moveTo(110,200);
    ctx.lineTo(110,200-(engine.props.saw4/10));
    ctx.lineTo(120,200-(engine.props.saw4/10));
    ctx.lineTo(120,200);
    ctx.lineTo(110,200);
    ctx.closePath();
    ctx.lineWidth(2.0);
    ctx.strokeStyle(Colour::bytes(255, 0, 0));
    ctx.lineCap(Canvas::LineCap::ROUND);
    ctx.lineJoin(Canvas::LineJoin::ROUND);
    ctx.stroke();

  }

} // namespace otto::engines