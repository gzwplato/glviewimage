{ A subset of castle_game_engine/src/base/castleconf.inc,
  defines OpenGLES symbol and CastleGL macro in the same way.
  This file should eventually disappear, once we upgrade glViewImage
  drawing to not use direct OpenGL/OpenGLES commands,
  only CastleGLUtils primitives.
}

{ Whether we use OpenGL ES or normal OpenGL.
  OpenGL ES is generally for mobile devices.
  For testing, you can also use OpenGL ES on normal desktop OSes
  (under Debian, install libegl1-mesa-dev and libgles2-mesa-dev).
  Put "CastleGL" in uses clause to include the appropriate OpenGL API. }
{ $define OpenGLES}
{$ifdef ANDROID} {$define OpenGLES} {$endif}
{$ifdef iOS} {$define OpenGLES} {$endif}
{$ifdef OpenGLES}
  {$define CastleGL := CastleGLES20}
{$else}
  {$define CastleGL := GL, GLU, GLExt}
{$endif}
