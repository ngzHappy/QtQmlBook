#include "GLSSTD/glew.h"
#include <QtCore/qglobal.h>

#ifndef EXPORT_SSTD_QT_AND_QML_LIBRARY
#define EXPORT_SSTD_QT_AND_QML_LIBRARY Q_DECL_EXPORT
#endif 

namespace sstd {
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glActiveShaderProgram(GLuint  pipeline, GLuint  program);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glActiveTexture(GLenum  texture);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glAttachShader(GLuint  program, GLuint  shader);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBeginConditionalRender(GLuint  id, GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBeginQuery(GLenum  target, GLuint  id);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBeginQueryIndexed(GLenum  target, GLuint  index, GLuint  id);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBeginTransformFeedback(GLenum  primitiveMode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindAttribLocation(GLuint  program, GLuint  index, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindBuffer(GLenum  target, GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindBufferBase(GLenum  target, GLuint  index, GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindBufferRange(GLenum  target, GLuint  index, GLuint  buffer, GLintptr  offset, GLsizeiptr  size);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindBuffersBase(GLenum  target, GLuint  first, GLsizei  count, GLuint *  buffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindBuffersRange(GLenum  target, GLuint  first, GLsizei  count, GLuint *  buffers, GLintptr *  offsets, GLsizeiptr *  sizes);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindFragDataLocation(GLuint  program, GLuint  color, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindFragDataLocationIndexed(GLuint  program, GLuint  colorNumber, GLuint  index, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindFramebuffer(GLenum  target, GLuint  framebuffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindImageTexture(GLuint  unit, GLuint  texture, GLint  level, GLboolean  layered, GLint  layer, GLenum  access, GLenum  format);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindImageTextures(GLuint  first, GLsizei  count, GLuint *  textures);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindProgramPipeline(GLuint  pipeline);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindRenderbuffer(GLenum  target, GLuint  renderbuffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindSampler(GLuint  unit, GLuint  sampler);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindSamplers(GLuint  first, GLsizei  count, GLuint *  samplers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindTexture(GLenum  target, GLuint  texture);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindTextureUnit(GLuint  unit, GLuint  texture);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindTextures(GLuint  first, GLsizei  count, GLuint *  textures);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindTransformFeedback(GLenum  target, GLuint  id);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindVertexArray(GLuint  array);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindVertexBuffer(GLuint  bindingindex, GLuint  buffer, GLintptr  offset, GLsizei  stride);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBindVertexBuffers(GLuint  first, GLsizei  count, GLuint *  buffers, GLintptr *  offsets, GLsizei *  strides);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendColor(GLfloat  red, GLfloat  green, GLfloat  blue, GLfloat  alpha);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendEquation(GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendEquationSeparate(GLenum  modeRGB, GLenum  modeAlpha);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendEquationSeparatei(GLuint  buf, GLenum  modeRGB, GLenum  modeAlpha);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendEquationi(GLuint  buf, GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendFunc(GLenum  sfactor, GLenum  dfactor);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendFuncSeparate(GLenum  sfactorRGB, GLenum  dfactorRGB, GLenum  sfactorAlpha, GLenum  dfactorAlpha);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendFuncSeparatei(GLuint  buf, GLenum  srcRGB, GLenum  dstRGB, GLenum  srcAlpha, GLenum  dstAlpha);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlendFunci(GLuint  buf, GLenum  src, GLenum  dst);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlitFramebuffer(GLint  srcX0, GLint  srcY0, GLint  srcX1, GLint  srcY1, GLint  dstX0, GLint  dstY0, GLint  dstX1, GLint  dstY1, GLbitfield  mask, GLenum  filter);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBlitNamedFramebuffer(GLuint  readFramebuffer, GLuint  drawFramebuffer, GLint  srcX0, GLint  srcY0, GLint  srcX1, GLint  srcY1, GLint  dstX0, GLint  dstY0, GLint  dstX1, GLint  dstY1, GLbitfield  mask, GLenum  filter);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBufferData(GLenum  target, GLsizeiptr  size, void *  data, GLenum  usage);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBufferStorage(GLenum  target, GLsizeiptr  size, void *  data, GLbitfield  flags);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glBufferSubData(GLenum  target, GLintptr  offset, GLsizeiptr  size, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  _sstd_glCheckFramebufferStatus(GLenum  target);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  _sstd_glCheckNamedFramebufferStatus(GLuint  framebuffer, GLenum  target);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClampColor(GLenum  target, GLenum  clamp);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClear(GLbitfield  mask);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearBufferData(GLenum  target, GLenum  internalformat, GLenum  format, GLenum  type, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearBufferSubData(GLenum  target, GLenum  internalformat, GLintptr  offset, GLsizeiptr  size, GLenum  format, GLenum  type, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearBufferfi(GLenum  buffer, GLint  drawbuffer, GLfloat  depth, GLint  stencil);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearBufferfv(GLenum  buffer, GLint  drawbuffer, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearBufferiv(GLenum  buffer, GLint  drawbuffer, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearBufferuiv(GLenum  buffer, GLint  drawbuffer, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearColor(GLfloat  red, GLfloat  green, GLfloat  blue, GLfloat  alpha);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearDepth(GLdouble  depth);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearDepthf(GLfloat  dd);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearNamedBufferData(GLuint  buffer, GLenum  internalformat, GLenum  format, GLenum  type, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearNamedBufferSubData(GLuint  buffer, GLenum  internalformat, GLintptr  offset, GLsizei  size, GLenum  format, GLenum  type, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearNamedFramebufferfi(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLfloat  depth, GLint  stencil);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearNamedFramebufferfv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearNamedFramebufferiv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearNamedFramebufferuiv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearStencil(GLint  s);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearTexImage(GLuint  texture, GLint  level, GLenum  format, GLenum  type, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClearTexSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  _sstd_glClientWaitSync(GLsync  sync, GLbitfield  flags, GLuint64  timeout);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glClipControl(GLenum  origin, GLenum  depth);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glColorMask(GLboolean  red, GLboolean  green, GLboolean  blue, GLboolean  alpha);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glColorMaski(GLuint  index, GLboolean  r, GLboolean  g, GLboolean  b, GLboolean  a);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompileShader(GLuint  shader);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTexImage1D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLint  border, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTexImage2D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLsizei  height, GLint  border, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTexImage3D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLint  border, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCompressedTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLsizei  imageSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyBufferSubData(GLenum  readTarget, GLenum  writeTarget, GLintptr  readOffset, GLintptr  writeOffset, GLsizeiptr  size);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyImageSubData(GLuint  srcName, GLenum  srcTarget, GLint  srcLevel, GLint  srcX, GLint  srcY, GLint  srcZ, GLuint  dstName, GLenum  dstTarget, GLint  dstLevel, GLint  dstX, GLint  dstY, GLint  dstZ, GLsizei  srcWidth, GLsizei  srcHeight, GLsizei  srcDepth);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyNamedBufferSubData(GLuint  readBuffer, GLuint  writeBuffer, GLintptr  readOffset, GLintptr  writeOffset, GLsizei  size);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTexImage1D(GLenum  target, GLint  level, GLenum  internalformat, GLint  x, GLint  y, GLsizei  width, GLint  border);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTexImage2D(GLenum  target, GLint  level, GLenum  internalformat, GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLint  border);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLint  x, GLint  y, GLsizei  width);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLint  x, GLint  y, GLsizei  width);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCopyTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateBuffers(GLsizei  n, GLuint *  buffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateFramebuffers(GLsizei  n, GLuint *  framebuffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  _sstd_glCreateProgram();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateProgramPipelines(GLsizei  n, GLuint *  pipelines);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateQueries(GLenum  target, GLsizei  n, GLuint *  ids);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateRenderbuffers(GLsizei  n, GLuint *  renderbuffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateSamplers(GLsizei  n, GLuint *  samplers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  _sstd_glCreateShader(GLenum  type);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  _sstd_glCreateShaderProgramv(GLenum  type, GLsizei  count, GLchar * *  strings);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateTextures(GLenum  target, GLsizei  n, GLuint *  textures);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateTransformFeedbacks(GLsizei  n, GLuint *  ids);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCreateVertexArrays(GLsizei  n, GLuint *  arrays);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glCullFace(GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDebugMessageCallback(GLDEBUGPROC  callback, void *  userParam);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDebugMessageControl(GLenum  source, GLenum  type, GLenum  severity, GLsizei  count, GLuint *  ids, GLboolean  enabled);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDebugMessageInsert(GLenum  source, GLenum  type, GLuint  id, GLenum  severity, GLsizei  length, GLchar *  buf);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteBuffers(GLsizei  n, GLuint *  buffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteFramebuffers(GLsizei  n, GLuint *  framebuffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteProgram(GLuint  program);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteProgramPipelines(GLsizei  n, GLuint *  pipelines);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteQueries(GLsizei  n, GLuint *  ids);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteRenderbuffers(GLsizei  n, GLuint *  renderbuffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteSamplers(GLsizei  count, GLuint *  samplers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteShader(GLuint  shader);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteSync(GLsync  sync);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteTextures(GLsizei  n, GLuint *  textures);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteTransformFeedbacks(GLsizei  n, GLuint *  ids);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDeleteVertexArrays(GLsizei  n, GLuint *  arrays);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDepthFunc(GLenum  func);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDepthMask(GLboolean  flag);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDepthRange(GLdouble  nearVal, GLdouble  farVal);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDepthRangeArrayv(GLuint  first, GLsizei  count, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDepthRangeIndexed(GLuint  index, GLdouble  n, GLdouble  f);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDepthRangef(GLfloat  n, GLfloat  f);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDetachShader(GLuint  program, GLuint  shader);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDisable(GLenum  cap);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDisableVertexArrayAttrib(GLuint  vaobj, GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDisableVertexAttribArray(GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDisablei(GLenum  target, GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDispatchCompute(GLuint  num_groups_x, GLuint  num_groups_y, GLuint  num_groups_z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDispatchComputeIndirect(GLintptr  indirect);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawArrays(GLenum  mode, GLint  first, GLsizei  count);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawArraysIndirect(GLenum  mode, void *  indirect);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawArraysInstanced(GLenum  mode, GLint  first, GLsizei  count, GLsizei  instancecount);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawArraysInstancedBaseInstance(GLenum  mode, GLint  first, GLsizei  count, GLsizei  instancecount, GLuint  baseinstance);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawBuffer(GLenum  buf);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawBuffers(GLsizei  n, GLenum *  bufs);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawElements(GLenum  mode, GLsizei  count, GLenum  type, void *  indices);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawElementsBaseVertex(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLint  basevertex);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawElementsIndirect(GLenum  mode, GLenum  type, void *  indirect);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawElementsInstanced(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawElementsInstancedBaseInstance(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount, GLuint  baseinstance);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawElementsInstancedBaseVertex(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount, GLint  basevertex);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawElementsInstancedBaseVertexBaseInstance(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount, GLint  basevertex, GLuint  baseinstance);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawRangeElements(GLenum  mode, GLuint  start, GLuint  end, GLsizei  count, GLenum  type, void *  indices);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawRangeElementsBaseVertex(GLenum  mode, GLuint  start, GLuint  end, GLsizei  count, GLenum  type, void *  indices, GLint  basevertex);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawTransformFeedback(GLenum  mode, GLuint  id);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawTransformFeedbackInstanced(GLenum  mode, GLuint  id, GLsizei  instancecount);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawTransformFeedbackStream(GLenum  mode, GLuint  id, GLuint  stream);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glDrawTransformFeedbackStreamInstanced(GLenum  mode, GLuint  id, GLuint  stream, GLsizei  instancecount);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEnable(GLenum  cap);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEnableVertexArrayAttrib(GLuint  vaobj, GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEnableVertexAttribArray(GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEnablei(GLenum  target, GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEndConditionalRender();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEndQuery(GLenum  target);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEndQueryIndexed(GLenum  target, GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glEndTransformFeedback();
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLsync  _sstd_glFenceSync(GLenum  condition, GLbitfield  flags);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFinish();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFlush();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFlushMappedBufferRange(GLenum  target, GLintptr  offset, GLsizeiptr  length);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFlushMappedNamedBufferRange(GLuint  buffer, GLintptr  offset, GLsizei  length);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFramebufferParameteri(GLenum  target, GLenum  pname, GLint  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFramebufferRenderbuffer(GLenum  target, GLenum  attachment, GLenum  renderbuffertarget, GLuint  renderbuffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFramebufferTexture(GLenum  target, GLenum  attachment, GLuint  texture, GLint  level);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFramebufferTexture1D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFramebufferTexture2D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFramebufferTexture3D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level, GLint  zoffset);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFramebufferTextureLayer(GLenum  target, GLenum  attachment, GLuint  texture, GLint  level, GLint  layer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glFrontFace(GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenBuffers(GLsizei  n, GLuint *  buffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenFramebuffers(GLsizei  n, GLuint *  framebuffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenProgramPipelines(GLsizei  n, GLuint *  pipelines);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenQueries(GLsizei  n, GLuint *  ids);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenRenderbuffers(GLsizei  n, GLuint *  renderbuffers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenSamplers(GLsizei  count, GLuint *  samplers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenTextures(GLsizei  n, GLuint *  textures);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenTransformFeedbacks(GLsizei  n, GLuint *  ids);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenVertexArrays(GLsizei  n, GLuint *  arrays);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenerateMipmap(GLenum  target);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGenerateTextureMipmap(GLuint  texture);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveAtomicCounterBufferiv(GLuint  program, GLuint  bufferIndex, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveAttrib(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLint *  size, GLenum *  type, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveSubroutineName(GLuint  program, GLenum  shadertype, GLuint  index, GLsizei  bufsize, GLsizei *  length, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveSubroutineUniformName(GLuint  program, GLenum  shadertype, GLuint  index, GLsizei  bufsize, GLsizei *  length, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveSubroutineUniformiv(GLuint  program, GLenum  shadertype, GLuint  index, GLenum  pname, GLint *  values);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveUniform(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLint *  size, GLenum *  type, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveUniformBlockName(GLuint  program, GLuint  uniformBlockIndex, GLsizei  bufSize, GLsizei *  length, GLchar *  uniformBlockName);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveUniformBlockiv(GLuint  program, GLuint  uniformBlockIndex, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveUniformName(GLuint  program, GLuint  uniformIndex, GLsizei  bufSize, GLsizei *  length, GLchar *  uniformName);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetActiveUniformsiv(GLuint  program, GLsizei  uniformCount, GLuint *  uniformIndices, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetAttachedShaders(GLuint  program, GLsizei  maxCount, GLsizei *  count, GLuint *  shaders);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  _sstd_glGetAttribLocation(GLuint  program, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetBooleani_v(GLenum  target, GLuint  index, GLboolean *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetBooleanv(GLenum  pname, GLboolean *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetBufferParameteri64v(GLenum  target, GLenum  pname, GLint64 *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetBufferParameteriv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetBufferPointerv(GLenum  target, GLenum  pname, void * *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetBufferSubData(GLenum  target, GLintptr  offset, GLsizeiptr  size, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetCompressedTexImage(GLenum  target, GLint  level, void *  img);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetCompressedTextureImage(GLuint  texture, GLint  level, GLsizei  bufSize, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetCompressedTextureSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLsizei  bufSize, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  _sstd_glGetDebugMessageLog(GLuint  count, GLsizei  bufSize, GLenum *  sources, GLenum *  types, GLuint *  ids, GLenum *  severities, GLsizei *  lengths, GLchar *  messageLog);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetDoublei_v(GLenum  target, GLuint  index, GLdouble *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetDoublev(GLenum  pname, GLdouble *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  _sstd_glGetError();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetFloati_v(GLenum  target, GLuint  index, GLfloat *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetFloatv(GLenum  pname, GLfloat *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  _sstd_glGetFragDataIndex(GLuint  program, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  _sstd_glGetFragDataLocation(GLuint  program, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetFramebufferAttachmentParameteriv(GLenum  target, GLenum  attachment, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetFramebufferParameteriv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  _sstd_glGetGraphicsResetStatus();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetInteger64i_v(GLenum  target, GLuint  index, GLint64 *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetInteger64v(GLenum  pname, GLint64 *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetIntegeri_v(GLenum  target, GLuint  index, GLint *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetIntegerv(GLenum  pname, GLint *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetInternalformati64v(GLenum  target, GLenum  internalformat, GLenum  pname, GLsizei  bufSize, GLint64 *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetInternalformativ(GLenum  target, GLenum  internalformat, GLenum  pname, GLsizei  bufSize, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetMultisamplefv(GLenum  pname, GLuint  index, GLfloat *  val);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetNamedBufferParameteri64v(GLuint  buffer, GLenum  pname, GLint64 *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetNamedBufferParameteriv(GLuint  buffer, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetNamedBufferPointerv(GLuint  buffer, GLenum  pname, void * *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetNamedBufferSubData(GLuint  buffer, GLintptr  offset, GLsizei  size, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetNamedFramebufferAttachmentParameteriv(GLuint  framebuffer, GLenum  attachment, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetNamedFramebufferParameteriv(GLuint  framebuffer, GLenum  pname, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetNamedRenderbufferParameteriv(GLuint  renderbuffer, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetObjectLabel(GLenum  identifier, GLuint  name, GLsizei  bufSize, GLsizei *  length, GLchar *  label);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetObjectPtrLabel(void *  ptr, GLsizei  bufSize, GLsizei *  length, GLchar *  label);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramBinary(GLuint  program, GLsizei  bufSize, GLsizei *  length, GLenum *  binaryFormat, void *  binary);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramInfoLog(GLuint  program, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramInterfaceiv(GLuint  program, GLenum  programInterface, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramPipelineInfoLog(GLuint  pipeline, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramPipelineiv(GLuint  pipeline, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  _sstd_glGetProgramResourceIndex(GLuint  program, GLenum  programInterface, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  _sstd_glGetProgramResourceLocation(GLuint  program, GLenum  programInterface, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  _sstd_glGetProgramResourceLocationIndex(GLuint  program, GLenum  programInterface, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramResourceName(GLuint  program, GLenum  programInterface, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramResourceiv(GLuint  program, GLenum  programInterface, GLuint  index, GLsizei  propCount, GLenum *  props, GLsizei  bufSize, GLsizei *  length, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramStageiv(GLuint  program, GLenum  shadertype, GLenum  pname, GLint *  values);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetProgramiv(GLuint  program, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetQueryIndexediv(GLenum  target, GLuint  index, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetQueryObjecti64v(GLuint  id, GLenum  pname, GLint64 *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetQueryObjectiv(GLuint  id, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetQueryObjectui64v(GLuint  id, GLenum  pname, GLuint64 *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetQueryObjectuiv(GLuint  id, GLenum  pname, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetQueryiv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetRenderbufferParameteriv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetSamplerParameterIiv(GLuint  sampler, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetSamplerParameterIuiv(GLuint  sampler, GLenum  pname, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetSamplerParameterfv(GLuint  sampler, GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetSamplerParameteriv(GLuint  sampler, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetShaderInfoLog(GLuint  shader, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetShaderPrecisionFormat(GLenum  shadertype, GLenum  precisiontype, GLint *  range, GLint *  precision);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetShaderSource(GLuint  shader, GLsizei  bufSize, GLsizei *  length, GLchar *  source);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetShaderiv(GLuint  shader, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY const GLubyte * _sstd_glGetString(GLenum  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY const GLubyte * _sstd_glGetStringi(GLenum  name, GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  _sstd_glGetSubroutineIndex(GLuint  program, GLenum  shadertype, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  _sstd_glGetSubroutineUniformLocation(GLuint  program, GLenum  shadertype, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetSynciv(GLsync  sync, GLenum  pname, GLsizei  bufSize, GLsizei *  length, GLint *  values);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTexImage(GLenum  target, GLint  level, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTexLevelParameterfv(GLenum  target, GLint  level, GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTexLevelParameteriv(GLenum  target, GLint  level, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTexParameterIiv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTexParameterIuiv(GLenum  target, GLenum  pname, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTexParameterfv(GLenum  target, GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTexParameteriv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureImage(GLuint  texture, GLint  level, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureLevelParameterfv(GLuint  texture, GLint  level, GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureLevelParameteriv(GLuint  texture, GLint  level, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureParameterIiv(GLuint  texture, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureParameterIuiv(GLuint  texture, GLenum  pname, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureParameterfv(GLuint  texture, GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureParameteriv(GLuint  texture, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTextureSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTransformFeedbackVarying(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLsizei *  size, GLenum *  type, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTransformFeedbacki64_v(GLuint  xfb, GLenum  pname, GLuint  index, GLint64 *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTransformFeedbacki_v(GLuint  xfb, GLenum  pname, GLuint  index, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetTransformFeedbackiv(GLuint  xfb, GLenum  pname, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  _sstd_glGetUniformBlockIndex(GLuint  program, GLchar *  uniformBlockName);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetUniformIndices(GLuint  program, GLsizei  uniformCount, GLchar * *  uniformNames, GLuint *  uniformIndices);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  _sstd_glGetUniformLocation(GLuint  program, GLchar *  name);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetUniformSubroutineuiv(GLenum  shadertype, GLint  location, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetUniformdv(GLuint  program, GLint  location, GLdouble *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetUniformfv(GLuint  program, GLint  location, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetUniformiv(GLuint  program, GLint  location, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetUniformuiv(GLuint  program, GLint  location, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexArrayIndexed64iv(GLuint  vaobj, GLuint  index, GLenum  pname, GLint64 *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexArrayIndexediv(GLuint  vaobj, GLuint  index, GLenum  pname, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexArrayiv(GLuint  vaobj, GLenum  pname, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexAttribIiv(GLuint  index, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexAttribIuiv(GLuint  index, GLenum  pname, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexAttribLdv(GLuint  index, GLenum  pname, GLdouble *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexAttribPointerv(GLuint  index, GLenum  pname, void * *  pointer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexAttribdv(GLuint  index, GLenum  pname, GLdouble *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexAttribfv(GLuint  index, GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetVertexAttribiv(GLuint  index, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetnCompressedTexImage(GLenum  target, GLint  lod, GLsizei  bufSize, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetnTexImage(GLenum  target, GLint  level, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetnUniformdv(GLuint  program, GLint  location, GLsizei  bufSize, GLdouble *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetnUniformfv(GLuint  program, GLint  location, GLsizei  bufSize, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetnUniformiv(GLuint  program, GLint  location, GLsizei  bufSize, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glGetnUniformuiv(GLuint  program, GLint  location, GLsizei  bufSize, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glHint(GLenum  target, GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateBufferData(GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateBufferSubData(GLuint  buffer, GLintptr  offset, GLsizeiptr  length);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateFramebuffer(GLenum  target, GLsizei  numAttachments, GLenum *  attachments);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateNamedFramebufferData(GLuint  framebuffer, GLsizei  numAttachments, GLenum *  attachments);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateNamedFramebufferSubData(GLuint  framebuffer, GLsizei  numAttachments, GLenum *  attachments, GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateSubFramebuffer(GLenum  target, GLsizei  numAttachments, GLenum *  attachments, GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateTexImage(GLuint  texture, GLint  level);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glInvalidateTexSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsBuffer(GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsEnabled(GLenum  cap);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsEnabledi(GLenum  target, GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsFramebuffer(GLuint  framebuffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsProgram(GLuint  program);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsProgramPipeline(GLuint  pipeline);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsQuery(GLuint  id);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsRenderbuffer(GLuint  renderbuffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsSampler(GLuint  sampler);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsShader(GLuint  shader);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsSync(GLsync  sync);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsTexture(GLuint  texture);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsTransformFeedback(GLuint  id);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glIsVertexArray(GLuint  array);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glLineWidth(GLfloat  width);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glLinkProgram(GLuint  program);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glLogicOp(GLenum  opcode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void * _sstd_glMapBuffer(GLenum  target, GLenum  access);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void * _sstd_glMapBufferRange(GLenum  target, GLintptr  offset, GLsizeiptr  length, GLbitfield  access);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void * _sstd_glMapNamedBuffer(GLuint  buffer, GLenum  access);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void * _sstd_glMapNamedBufferRange(GLuint  buffer, GLintptr  offset, GLsizei  length, GLbitfield  access);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMemoryBarrier(GLbitfield  barriers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMemoryBarrierByRegion(GLbitfield  barriers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMinSampleShading(GLfloat  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMultiDrawArrays(GLenum  mode, GLint *  first, GLsizei *  count, GLsizei  drawcount);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMultiDrawArraysIndirect(GLenum  mode, void *  indirect, GLsizei  drawcount, GLsizei  stride);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMultiDrawElements(GLenum  mode, GLsizei *  count, GLenum  type, void * *  indices, GLsizei  drawcount);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMultiDrawElementsBaseVertex(GLenum  mode, GLsizei *  count, GLenum  type, void * *  indices, GLsizei  drawcount, GLint *  basevertex);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glMultiDrawElementsIndirect(GLenum  mode, GLenum  type, void *  indirect, GLsizei  drawcount, GLsizei  stride);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedBufferData(GLuint  buffer, GLsizei  size, void *  data, GLenum  usage);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedBufferStorage(GLuint  buffer, GLsizei  size, void *  data, GLbitfield  flags);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedBufferSubData(GLuint  buffer, GLintptr  offset, GLsizei  size, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedFramebufferDrawBuffer(GLuint  framebuffer, GLenum  buf);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedFramebufferDrawBuffers(GLuint  framebuffer, GLsizei  n, GLenum *  bufs);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedFramebufferParameteri(GLuint  framebuffer, GLenum  pname, GLint  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedFramebufferReadBuffer(GLuint  framebuffer, GLenum  src);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedFramebufferRenderbuffer(GLuint  framebuffer, GLenum  attachment, GLenum  renderbuffertarget, GLuint  renderbuffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedFramebufferTexture(GLuint  framebuffer, GLenum  attachment, GLuint  texture, GLint  level);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedFramebufferTextureLayer(GLuint  framebuffer, GLenum  attachment, GLuint  texture, GLint  level, GLint  layer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedRenderbufferStorage(GLuint  renderbuffer, GLenum  internalformat, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glNamedRenderbufferStorageMultisample(GLuint  renderbuffer, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glObjectLabel(GLenum  identifier, GLuint  name, GLsizei  length, GLchar *  label);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glObjectPtrLabel(void *  ptr, GLsizei  length, GLchar *  label);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPatchParameterfv(GLenum  pname, GLfloat *  values);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPatchParameteri(GLenum  pname, GLint  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPauseTransformFeedback();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPixelStoref(GLenum  pname, GLfloat  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPixelStorei(GLenum  pname, GLint  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPointParameterf(GLenum  pname, GLfloat  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPointParameterfv(GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPointParameteri(GLenum  pname, GLint  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPointParameteriv(GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPointSize(GLfloat  size);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPolygonMode(GLenum  face, GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPolygonOffset(GLfloat  factor, GLfloat  units);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPopDebugGroup();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPrimitiveRestartIndex(GLuint  index);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramBinary(GLuint  program, GLenum  binaryFormat, void *  binary, GLsizei  length);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramParameteri(GLuint  program, GLenum  pname, GLint  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1d(GLuint  program, GLint  location, GLdouble  v0);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1f(GLuint  program, GLint  location, GLfloat  v0);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1i(GLuint  program, GLint  location, GLint  v0);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1ui(GLuint  program, GLint  location, GLuint  v0);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform1uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2i(GLuint  program, GLint  location, GLint  v0, GLint  v1);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform2uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1, GLdouble  v2);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3i(GLuint  program, GLint  location, GLint  v0, GLint  v1, GLint  v2);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1, GLuint  v2);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform3uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1, GLdouble  v2, GLdouble  v3);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2, GLfloat  v3);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4i(GLuint  program, GLint  location, GLint  v0, GLint  v1, GLint  v2, GLint  v3);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1, GLuint  v2, GLuint  v3);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniform4uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix2x3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix2x3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix2x4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix2x4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix3x2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix3x2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix3x4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix3x4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix4x2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix4x2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix4x3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProgramUniformMatrix4x3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glProvokingVertex(GLenum  mode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glPushDebugGroup(GLenum  source, GLuint  id, GLsizei  length, GLchar *  message);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glQueryCounter(GLuint  id, GLenum  target);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glReadBuffer(GLenum  src);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glReadPixels(GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glReadnPixels(GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, GLsizei  bufSize, void *  data);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glReleaseShaderCompiler();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glRenderbufferStorage(GLenum  target, GLenum  internalformat, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glRenderbufferStorageMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glResumeTransformFeedback();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSampleCoverage(GLfloat  value, GLboolean  invert);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSampleMaski(GLuint  maskNumber, GLbitfield  mask);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSamplerParameterIiv(GLuint  sampler, GLenum  pname, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSamplerParameterIuiv(GLuint  sampler, GLenum  pname, GLuint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSamplerParameterf(GLuint  sampler, GLenum  pname, GLfloat  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSamplerParameterfv(GLuint  sampler, GLenum  pname, GLfloat *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSamplerParameteri(GLuint  sampler, GLenum  pname, GLint  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glSamplerParameteriv(GLuint  sampler, GLenum  pname, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glScissor(GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glScissorArrayv(GLuint  first, GLsizei  count, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glScissorIndexed(GLuint  index, GLint  left, GLint  bottom, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glScissorIndexedv(GLuint  index, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glShaderBinary(GLsizei  count, GLuint *  shaders, GLenum  binaryformat, void *  binary, GLsizei  length);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glShaderSource(GLuint  shader, GLsizei  count, GLchar * *  string, GLint *  length);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glShaderStorageBlockBinding(GLuint  program, GLuint  storageBlockIndex, GLuint  storageBlockBinding);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glStencilFunc(GLenum  func, GLint  ref, GLuint  mask);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glStencilFuncSeparate(GLenum  face, GLenum  func, GLint  ref, GLuint  mask);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glStencilMask(GLuint  mask);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glStencilMaskSeparate(GLenum  face, GLuint  mask);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glStencilOp(GLenum  fail, GLenum  zfail, GLenum  zpass);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glStencilOpSeparate(GLenum  face, GLenum  sfail, GLenum  dpfail, GLenum  dppass);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexBuffer(GLenum  target, GLenum  internalformat, GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexBufferRange(GLenum  target, GLenum  internalformat, GLuint  buffer, GLintptr  offset, GLsizeiptr  size);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexImage1D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLint  border, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexImage2D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLsizei  height, GLint  border, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexImage2DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexImage3D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLint  border, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexImage3DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexParameterIiv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexParameterIuiv(GLenum  target, GLenum  pname, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexParameterf(GLenum  target, GLenum  pname, GLfloat  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexParameterfv(GLenum  target, GLenum  pname, GLfloat *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexParameteri(GLenum  target, GLenum  pname, GLint  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexParameteriv(GLenum  target, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexStorage1D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexStorage2D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexStorage2DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexStorage3D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexStorage3DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureBarrier();
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureBuffer(GLuint  texture, GLenum  internalformat, GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureBufferRange(GLuint  texture, GLenum  internalformat, GLuint  buffer, GLintptr  offset, GLsizei  size);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureParameterIiv(GLuint  texture, GLenum  pname, GLint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureParameterIuiv(GLuint  texture, GLenum  pname, GLuint *  params);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureParameterf(GLuint  texture, GLenum  pname, GLfloat  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureParameterfv(GLuint  texture, GLenum  pname, GLfloat *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureParameteri(GLuint  texture, GLenum  pname, GLint  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureParameteriv(GLuint  texture, GLenum  pname, GLint *  param);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureStorage1D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureStorage2D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureStorage2DMultisample(GLuint  texture, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureStorage3D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureStorage3DMultisample(GLuint  texture, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, void *  pixels);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTextureView(GLuint  texture, GLenum  target, GLuint  origtexture, GLenum  internalformat, GLuint  minlevel, GLuint  numlevels, GLuint  minlayer, GLuint  numlayers);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTransformFeedbackBufferBase(GLuint  xfb, GLuint  index, GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTransformFeedbackBufferRange(GLuint  xfb, GLuint  index, GLuint  buffer, GLintptr  offset, GLsizei  size);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glTransformFeedbackVaryings(GLuint  program, GLsizei  count, GLchar * *  varyings, GLenum  bufferMode);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1d(GLint  location, GLdouble  x);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1dv(GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1f(GLint  location, GLfloat  v0);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1fv(GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1i(GLint  location, GLint  v0);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1iv(GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1ui(GLint  location, GLuint  v0);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform1uiv(GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2d(GLint  location, GLdouble  x, GLdouble  y);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2dv(GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2f(GLint  location, GLfloat  v0, GLfloat  v1);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2fv(GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2i(GLint  location, GLint  v0, GLint  v1);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2iv(GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2ui(GLint  location, GLuint  v0, GLuint  v1);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform2uiv(GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3d(GLint  location, GLdouble  x, GLdouble  y, GLdouble  z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3dv(GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3f(GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3fv(GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3i(GLint  location, GLint  v0, GLint  v1, GLint  v2);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3iv(GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3ui(GLint  location, GLuint  v0, GLuint  v1, GLuint  v2);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform3uiv(GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4d(GLint  location, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4dv(GLint  location, GLsizei  count, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4f(GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2, GLfloat  v3);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4fv(GLint  location, GLsizei  count, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4i(GLint  location, GLint  v0, GLint  v1, GLint  v2, GLint  v3);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4iv(GLint  location, GLsizei  count, GLint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4ui(GLint  location, GLuint  v0, GLuint  v1, GLuint  v2, GLuint  v3);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniform4uiv(GLint  location, GLsizei  count, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformBlockBinding(GLuint  program, GLuint  uniformBlockIndex, GLuint  uniformBlockBinding);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix2dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix2fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix2x3dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix2x3fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix2x4dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix2x4fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix3dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix3fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix3x2dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix3x2fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix3x4dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix3x4fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix4dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix4fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix4x2dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix4x2fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix4x3dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformMatrix4x3fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUniformSubroutinesuiv(GLenum  shadertype, GLsizei  count, GLuint *  indices);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glUnmapBuffer(GLenum  target);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  _sstd_glUnmapNamedBuffer(GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUseProgram(GLuint  program);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glUseProgramStages(GLuint  pipeline, GLbitfield  stages, GLuint  program);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glValidateProgram(GLuint  program);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glValidateProgramPipeline(GLuint  pipeline);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayAttribBinding(GLuint  vaobj, GLuint  attribindex, GLuint  bindingindex);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayAttribFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLboolean  normalized, GLuint  relativeoffset);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayAttribIFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayAttribLFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayBindingDivisor(GLuint  vaobj, GLuint  bindingindex, GLuint  divisor);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayElementBuffer(GLuint  vaobj, GLuint  buffer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayVertexBuffer(GLuint  vaobj, GLuint  bindingindex, GLuint  buffer, GLintptr  offset, GLsizei  stride);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexArrayVertexBuffers(GLuint  vaobj, GLuint  first, GLsizei  count, GLuint *  buffers, GLintptr *  offsets, GLsizei *  strides);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib1d(GLuint  index, GLdouble  x);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib1dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib1f(GLuint  index, GLfloat  x);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib1fv(GLuint  index, GLfloat *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib1s(GLuint  index, GLshort  x);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib1sv(GLuint  index, GLshort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib2d(GLuint  index, GLdouble  x, GLdouble  y);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib2dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib2f(GLuint  index, GLfloat  x, GLfloat  y);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib2fv(GLuint  index, GLfloat *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib2s(GLuint  index, GLshort  x, GLshort  y);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib2sv(GLuint  index, GLshort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib3d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib3dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib3f(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib3fv(GLuint  index, GLfloat *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib3s(GLuint  index, GLshort  x, GLshort  y, GLshort  z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib3sv(GLuint  index, GLshort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4Nbv(GLuint  index, GLbyte *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4Niv(GLuint  index, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4Nsv(GLuint  index, GLshort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4Nub(GLuint  index, GLubyte  x, GLubyte  y, GLubyte  z, GLubyte  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4Nubv(GLuint  index, GLubyte *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4Nuiv(GLuint  index, GLuint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4Nusv(GLuint  index, GLushort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4bv(GLuint  index, GLbyte *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4f(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  z, GLfloat  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4fv(GLuint  index, GLfloat *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4iv(GLuint  index, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4s(GLuint  index, GLshort  x, GLshort  y, GLshort  z, GLshort  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4sv(GLuint  index, GLshort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4ubv(GLuint  index, GLubyte *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4uiv(GLuint  index, GLuint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttrib4usv(GLuint  index, GLushort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribBinding(GLuint  attribindex, GLuint  bindingindex);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribDivisor(GLuint  index, GLuint  divisor);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribFormat(GLuint  attribindex, GLint  size, GLenum  type, GLboolean  normalized, GLuint  relativeoffset);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI1i(GLuint  index, GLint  x);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI1iv(GLuint  index, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI1ui(GLuint  index, GLuint  x);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI1uiv(GLuint  index, GLuint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI2i(GLuint  index, GLint  x, GLint  y);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI2iv(GLuint  index, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI2ui(GLuint  index, GLuint  x, GLuint  y);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI2uiv(GLuint  index, GLuint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI3i(GLuint  index, GLint  x, GLint  y, GLint  z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI3iv(GLuint  index, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI3ui(GLuint  index, GLuint  x, GLuint  y, GLuint  z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI3uiv(GLuint  index, GLuint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4bv(GLuint  index, GLbyte *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4i(GLuint  index, GLint  x, GLint  y, GLint  z, GLint  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4iv(GLuint  index, GLint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4sv(GLuint  index, GLshort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4ubv(GLuint  index, GLubyte *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4ui(GLuint  index, GLuint  x, GLuint  y, GLuint  z, GLuint  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4uiv(GLuint  index, GLuint *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribI4usv(GLuint  index, GLushort *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribIFormat(GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribIPointer(GLuint  index, GLint  size, GLenum  type, GLsizei  stride, void *  pointer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL1d(GLuint  index, GLdouble  x);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL1dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL2d(GLuint  index, GLdouble  x, GLdouble  y);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL2dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL3d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL3dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL4d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribL4dv(GLuint  index, GLdouble *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribLFormat(GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribLPointer(GLuint  index, GLint  size, GLenum  type, GLsizei  stride, void *  pointer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP1ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP1uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP2ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP2uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP3ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP3uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP4ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribP4uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexAttribPointer(GLuint  index, GLint  size, GLenum  type, GLboolean  normalized, GLsizei  stride, void *  pointer);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glVertexBindingDivisor(GLuint  bindingindex, GLuint  divisor);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glViewport(GLint  x, GLint  y, GLsizei  width, GLsizei  height);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glViewportArrayv(GLuint  first, GLsizei  count, GLfloat *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glViewportIndexedf(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  w, GLfloat  h);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glViewportIndexedfv(GLuint  index, GLfloat *  v);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void  _sstd_glWaitSync(GLsync  sync, GLbitfield  flags, GLuint64  timeout);
}

EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glActiveShaderProgram(GLuint  pipeline, GLuint  program) {
    return ::glActiveShaderProgram(pipeline, program);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glActiveTexture(GLenum  texture) {
    return ::glActiveTexture(texture);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glAttachShader(GLuint  program, GLuint  shader) {
    return ::glAttachShader(program, shader);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBeginConditionalRender(GLuint  id, GLenum  mode) {
    return ::glBeginConditionalRender(id, mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBeginQuery(GLenum  target, GLuint  id) {
    return ::glBeginQuery(target, id);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBeginQueryIndexed(GLenum  target, GLuint  index, GLuint  id) {
    return ::glBeginQueryIndexed(target, index, id);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBeginTransformFeedback(GLenum  primitiveMode) {
    return ::glBeginTransformFeedback(primitiveMode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindAttribLocation(GLuint  program, GLuint  index, GLchar *  name) {
    return ::glBindAttribLocation(program, index, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindBuffer(GLenum  target, GLuint  buffer) {
    return ::glBindBuffer(target, buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindBufferBase(GLenum  target, GLuint  index, GLuint  buffer) {
    return ::glBindBufferBase(target, index, buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindBufferRange(GLenum  target, GLuint  index, GLuint  buffer, GLintptr  offset, GLsizeiptr  size) {
    return ::glBindBufferRange(target, index, buffer, offset, size);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindBuffersBase(GLenum  target, GLuint  first, GLsizei  count, GLuint *  buffers) {
    return ::glBindBuffersBase(target, first, count, buffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindBuffersRange(GLenum  target, GLuint  first, GLsizei  count, GLuint *  buffers, GLintptr *  offsets, GLsizeiptr *  sizes) {
    return ::glBindBuffersRange(target, first, count, buffers, offsets, sizes);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindFragDataLocation(GLuint  program, GLuint  color, GLchar *  name) {
    return ::glBindFragDataLocation(program, color, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindFragDataLocationIndexed(GLuint  program, GLuint  colorNumber, GLuint  index, GLchar *  name) {
    return ::glBindFragDataLocationIndexed(program, colorNumber, index, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindFramebuffer(GLenum  target, GLuint  framebuffer) {
    return ::glBindFramebuffer(target, framebuffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindImageTexture(GLuint  unit, GLuint  texture, GLint  level, GLboolean  layered, GLint  layer, GLenum  access, GLenum  format) {
    return ::glBindImageTexture(unit, texture, level, layered, layer, access, format);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindImageTextures(GLuint  first, GLsizei  count, GLuint *  textures) {
    return ::glBindImageTextures(first, count, textures);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindProgramPipeline(GLuint  pipeline) {
    return ::glBindProgramPipeline(pipeline);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindRenderbuffer(GLenum  target, GLuint  renderbuffer) {
    return ::glBindRenderbuffer(target, renderbuffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindSampler(GLuint  unit, GLuint  sampler) {
    return ::glBindSampler(unit, sampler);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindSamplers(GLuint  first, GLsizei  count, GLuint *  samplers) {
    return ::glBindSamplers(first, count, samplers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindTexture(GLenum  target, GLuint  texture) {
    return ::glBindTexture(target, texture);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindTextureUnit(GLuint  unit, GLuint  texture) {
    return ::glBindTextureUnit(unit, texture);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindTextures(GLuint  first, GLsizei  count, GLuint *  textures) {
    return ::glBindTextures(first, count, textures);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindTransformFeedback(GLenum  target, GLuint  id) {
    return ::glBindTransformFeedback(target, id);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindVertexArray(GLuint  array) {
    return ::glBindVertexArray(array);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindVertexBuffer(GLuint  bindingindex, GLuint  buffer, GLintptr  offset, GLsizei  stride) {
    return ::glBindVertexBuffer(bindingindex, buffer, offset, stride);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBindVertexBuffers(GLuint  first, GLsizei  count, GLuint *  buffers, GLintptr *  offsets, GLsizei *  strides) {
    return ::glBindVertexBuffers(first, count, buffers, offsets, strides);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendColor(GLfloat  red, GLfloat  green, GLfloat  blue, GLfloat  alpha) {
    return ::glBlendColor(red, green, blue, alpha);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendEquation(GLenum  mode) {
    return ::glBlendEquation(mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendEquationSeparate(GLenum  modeRGB, GLenum  modeAlpha) {
    return ::glBlendEquationSeparate(modeRGB, modeAlpha);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendEquationSeparatei(GLuint  buf, GLenum  modeRGB, GLenum  modeAlpha) {
    return ::glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendEquationi(GLuint  buf, GLenum  mode) {
    return ::glBlendEquationi(buf, mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendFunc(GLenum  sfactor, GLenum  dfactor) {
    return ::glBlendFunc(sfactor, dfactor);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendFuncSeparate(GLenum  sfactorRGB, GLenum  dfactorRGB, GLenum  sfactorAlpha, GLenum  dfactorAlpha) {
    return ::glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendFuncSeparatei(GLuint  buf, GLenum  srcRGB, GLenum  dstRGB, GLenum  srcAlpha, GLenum  dstAlpha) {
    return ::glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlendFunci(GLuint  buf, GLenum  src, GLenum  dst) {
    return ::glBlendFunci(buf, src, dst);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlitFramebuffer(GLint  srcX0, GLint  srcY0, GLint  srcX1, GLint  srcY1, GLint  dstX0, GLint  dstY0, GLint  dstX1, GLint  dstY1, GLbitfield  mask, GLenum  filter) {
    return ::glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBlitNamedFramebuffer(GLuint  readFramebuffer, GLuint  drawFramebuffer, GLint  srcX0, GLint  srcY0, GLint  srcX1, GLint  srcY1, GLint  dstX0, GLint  dstY0, GLint  dstX1, GLint  dstY1, GLbitfield  mask, GLenum  filter) {
    return ::glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBufferData(GLenum  target, GLsizeiptr  size, void *  data, GLenum  usage) {
    return ::glBufferData(target, size, data, usage);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBufferStorage(GLenum  target, GLsizeiptr  size, void *  data, GLbitfield  flags) {
    return ::glBufferStorage(target, size, data, flags);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glBufferSubData(GLenum  target, GLintptr  offset, GLsizeiptr  size, void *  data) {
    return ::glBufferSubData(target, offset, size, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  sstd::_sstd_glCheckFramebufferStatus(GLenum  target) {
    return ::glCheckFramebufferStatus(target);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  sstd::_sstd_glCheckNamedFramebufferStatus(GLuint  framebuffer, GLenum  target) {
    return ::glCheckNamedFramebufferStatus(framebuffer, target);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClampColor(GLenum  target, GLenum  clamp) {
    return ::glClampColor(target, clamp);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClear(GLbitfield  mask) {
    return ::glClear(mask);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearBufferData(GLenum  target, GLenum  internalformat, GLenum  format, GLenum  type, void *  data) {
    return ::glClearBufferData(target, internalformat, format, type, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearBufferSubData(GLenum  target, GLenum  internalformat, GLintptr  offset, GLsizeiptr  size, GLenum  format, GLenum  type, void *  data) {
    return ::glClearBufferSubData(target, internalformat, offset, size, format, type, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearBufferfi(GLenum  buffer, GLint  drawbuffer, GLfloat  depth, GLint  stencil) {
    return ::glClearBufferfi(buffer, drawbuffer, depth, stencil);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearBufferfv(GLenum  buffer, GLint  drawbuffer, GLfloat *  value) {
    return ::glClearBufferfv(buffer, drawbuffer, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearBufferiv(GLenum  buffer, GLint  drawbuffer, GLint *  value) {
    return ::glClearBufferiv(buffer, drawbuffer, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearBufferuiv(GLenum  buffer, GLint  drawbuffer, GLuint *  value) {
    return ::glClearBufferuiv(buffer, drawbuffer, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearColor(GLfloat  red, GLfloat  green, GLfloat  blue, GLfloat  alpha) {
    return ::glClearColor(red, green, blue, alpha);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearDepth(GLdouble  depth) {
    return ::glClearDepth(depth);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearDepthf(GLfloat  dd) {
    return ::glClearDepthf(dd);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearNamedBufferData(GLuint  buffer, GLenum  internalformat, GLenum  format, GLenum  type, void *  data) {
    return ::glClearNamedBufferData(buffer, internalformat, format, type, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearNamedBufferSubData(GLuint  buffer, GLenum  internalformat, GLintptr  offset, GLsizei  size, GLenum  format, GLenum  type, void *  data) {
    return ::glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearNamedFramebufferfi(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLfloat  depth, GLint  stencil) {
    return ::glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearNamedFramebufferfv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLfloat *  value) {
    return ::glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearNamedFramebufferiv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLint *  value) {
    return ::glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearNamedFramebufferuiv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLuint *  value) {
    return ::glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearStencil(GLint  s) {
    return ::glClearStencil(s);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearTexImage(GLuint  texture, GLint  level, GLenum  format, GLenum  type, void *  data) {
    return ::glClearTexImage(texture, level, format, type, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClearTexSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, void *  data) {
    return ::glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  sstd::_sstd_glClientWaitSync(GLsync  sync, GLbitfield  flags, GLuint64  timeout) {
    return ::glClientWaitSync(sync, flags, timeout);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glClipControl(GLenum  origin, GLenum  depth) {
    return ::glClipControl(origin, depth);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glColorMask(GLboolean  red, GLboolean  green, GLboolean  blue, GLboolean  alpha) {
    return ::glColorMask(red, green, blue, alpha);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glColorMaski(GLuint  index, GLboolean  r, GLboolean  g, GLboolean  b, GLboolean  a) {
    return ::glColorMaski(index, r, g, b, a);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompileShader(GLuint  shader) {
    return ::glCompileShader(shader);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTexImage1D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLint  border, GLsizei  imageSize, void *  data) {
    return ::glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTexImage2D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLsizei  height, GLint  border, GLsizei  imageSize, void *  data) {
    return ::glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTexImage3D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLint  border, GLsizei  imageSize, void *  data) {
    return ::glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLsizei  imageSize, void *  data) {
    return ::glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLsizei  imageSize, void *  data) {
    return ::glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLsizei  imageSize, void *  data) {
    return ::glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLsizei  imageSize, void *  data) {
    return ::glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLsizei  imageSize, void *  data) {
    return ::glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCompressedTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLsizei  imageSize, void *  data) {
    return ::glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyBufferSubData(GLenum  readTarget, GLenum  writeTarget, GLintptr  readOffset, GLintptr  writeOffset, GLsizeiptr  size) {
    return ::glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyImageSubData(GLuint  srcName, GLenum  srcTarget, GLint  srcLevel, GLint  srcX, GLint  srcY, GLint  srcZ, GLuint  dstName, GLenum  dstTarget, GLint  dstLevel, GLint  dstX, GLint  dstY, GLint  dstZ, GLsizei  srcWidth, GLsizei  srcHeight, GLsizei  srcDepth) {
    return ::glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyNamedBufferSubData(GLuint  readBuffer, GLuint  writeBuffer, GLintptr  readOffset, GLintptr  writeOffset, GLsizei  size) {
    return ::glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTexImage1D(GLenum  target, GLint  level, GLenum  internalformat, GLint  x, GLint  y, GLsizei  width, GLint  border) {
    return ::glCopyTexImage1D(target, level, internalformat, x, y, width, border);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTexImage2D(GLenum  target, GLint  level, GLenum  internalformat, GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLint  border) {
    return ::glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLint  x, GLint  y, GLsizei  width) {
    return ::glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLint  x, GLint  y, GLsizei  width) {
    return ::glCopyTextureSubImage1D(texture, level, xoffset, x, y, width);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCopyTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateBuffers(GLsizei  n, GLuint *  buffers) {
    return ::glCreateBuffers(n, buffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateFramebuffers(GLsizei  n, GLuint *  framebuffers) {
    return ::glCreateFramebuffers(n, framebuffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  sstd::_sstd_glCreateProgram() {
    return ::glCreateProgram();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateProgramPipelines(GLsizei  n, GLuint *  pipelines) {
    return ::glCreateProgramPipelines(n, pipelines);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateQueries(GLenum  target, GLsizei  n, GLuint *  ids) {
    return ::glCreateQueries(target, n, ids);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateRenderbuffers(GLsizei  n, GLuint *  renderbuffers) {
    return ::glCreateRenderbuffers(n, renderbuffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateSamplers(GLsizei  n, GLuint *  samplers) {
    return ::glCreateSamplers(n, samplers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  sstd::_sstd_glCreateShader(GLenum  type) {
    return ::glCreateShader(type);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  sstd::_sstd_glCreateShaderProgramv(GLenum  type, GLsizei  count, GLchar * *  strings) {
    return ::glCreateShaderProgramv(type, count, strings);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateTextures(GLenum  target, GLsizei  n, GLuint *  textures) {
    return ::glCreateTextures(target, n, textures);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateTransformFeedbacks(GLsizei  n, GLuint *  ids) {
    return ::glCreateTransformFeedbacks(n, ids);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCreateVertexArrays(GLsizei  n, GLuint *  arrays) {
    return ::glCreateVertexArrays(n, arrays);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glCullFace(GLenum  mode) {
    return ::glCullFace(mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDebugMessageCallback(GLDEBUGPROC  callback, void *  userParam) {
    return ::glDebugMessageCallback(callback, userParam);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDebugMessageControl(GLenum  source, GLenum  type, GLenum  severity, GLsizei  count, GLuint *  ids, GLboolean  enabled) {
    return ::glDebugMessageControl(source, type, severity, count, ids, enabled);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDebugMessageInsert(GLenum  source, GLenum  type, GLuint  id, GLenum  severity, GLsizei  length, GLchar *  buf) {
    return ::glDebugMessageInsert(source, type, id, severity, length, buf);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteBuffers(GLsizei  n, GLuint *  buffers) {
    return ::glDeleteBuffers(n, buffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteFramebuffers(GLsizei  n, GLuint *  framebuffers) {
    return ::glDeleteFramebuffers(n, framebuffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteProgram(GLuint  program) {
    return ::glDeleteProgram(program);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteProgramPipelines(GLsizei  n, GLuint *  pipelines) {
    return ::glDeleteProgramPipelines(n, pipelines);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteQueries(GLsizei  n, GLuint *  ids) {
    return ::glDeleteQueries(n, ids);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteRenderbuffers(GLsizei  n, GLuint *  renderbuffers) {
    return ::glDeleteRenderbuffers(n, renderbuffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteSamplers(GLsizei  count, GLuint *  samplers) {
    return ::glDeleteSamplers(count, samplers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteShader(GLuint  shader) {
    return ::glDeleteShader(shader);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteSync(GLsync  sync) {
    return ::glDeleteSync(sync);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteTextures(GLsizei  n, GLuint *  textures) {
    return ::glDeleteTextures(n, textures);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteTransformFeedbacks(GLsizei  n, GLuint *  ids) {
    return ::glDeleteTransformFeedbacks(n, ids);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDeleteVertexArrays(GLsizei  n, GLuint *  arrays) {
    return ::glDeleteVertexArrays(n, arrays);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDepthFunc(GLenum  func) {
    return ::glDepthFunc(func);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDepthMask(GLboolean  flag) {
    return ::glDepthMask(flag);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDepthRange(GLdouble  nearVal, GLdouble  farVal) {
    return ::glDepthRange(nearVal, farVal);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDepthRangeArrayv(GLuint  first, GLsizei  count, GLdouble *  v) {
    return ::glDepthRangeArrayv(first, count, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDepthRangeIndexed(GLuint  index, GLdouble  n, GLdouble  f) {
    return ::glDepthRangeIndexed(index, n, f);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDepthRangef(GLfloat  n, GLfloat  f) {
    return ::glDepthRangef(n, f);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDetachShader(GLuint  program, GLuint  shader) {
    return ::glDetachShader(program, shader);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDisable(GLenum  cap) {
    return ::glDisable(cap);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDisableVertexArrayAttrib(GLuint  vaobj, GLuint  index) {
    return ::glDisableVertexArrayAttrib(vaobj, index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDisableVertexAttribArray(GLuint  index) {
    return ::glDisableVertexAttribArray(index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDisablei(GLenum  target, GLuint  index) {
    return ::glDisablei(target, index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDispatchCompute(GLuint  num_groups_x, GLuint  num_groups_y, GLuint  num_groups_z) {
    return ::glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDispatchComputeIndirect(GLintptr  indirect) {
    return ::glDispatchComputeIndirect(indirect);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawArrays(GLenum  mode, GLint  first, GLsizei  count) {
    return ::glDrawArrays(mode, first, count);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawArraysIndirect(GLenum  mode, void *  indirect) {
    return ::glDrawArraysIndirect(mode, indirect);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawArraysInstanced(GLenum  mode, GLint  first, GLsizei  count, GLsizei  instancecount) {
    return ::glDrawArraysInstanced(mode, first, count, instancecount);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawArraysInstancedBaseInstance(GLenum  mode, GLint  first, GLsizei  count, GLsizei  instancecount, GLuint  baseinstance) {
    return ::glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawBuffer(GLenum  buf) {
    return ::glDrawBuffer(buf);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawBuffers(GLsizei  n, GLenum *  bufs) {
    return ::glDrawBuffers(n, bufs);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawElements(GLenum  mode, GLsizei  count, GLenum  type, void *  indices) {
    return ::glDrawElements(mode, count, type, indices);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawElementsBaseVertex(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLint  basevertex) {
    return ::glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawElementsIndirect(GLenum  mode, GLenum  type, void *  indirect) {
    return ::glDrawElementsIndirect(mode, type, indirect);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawElementsInstanced(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount) {
    return ::glDrawElementsInstanced(mode, count, type, indices, instancecount);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawElementsInstancedBaseInstance(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount, GLuint  baseinstance) {
    return ::glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawElementsInstancedBaseVertex(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount, GLint  basevertex) {
    return ::glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawElementsInstancedBaseVertexBaseInstance(GLenum  mode, GLsizei  count, GLenum  type, void *  indices, GLsizei  instancecount, GLint  basevertex, GLuint  baseinstance) {
    return ::glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawRangeElements(GLenum  mode, GLuint  start, GLuint  end, GLsizei  count, GLenum  type, void *  indices) {
    return ::glDrawRangeElements(mode, start, end, count, type, indices);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawRangeElementsBaseVertex(GLenum  mode, GLuint  start, GLuint  end, GLsizei  count, GLenum  type, void *  indices, GLint  basevertex) {
    return ::glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawTransformFeedback(GLenum  mode, GLuint  id) {
    return ::glDrawTransformFeedback(mode, id);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawTransformFeedbackInstanced(GLenum  mode, GLuint  id, GLsizei  instancecount) {
    return ::glDrawTransformFeedbackInstanced(mode, id, instancecount);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawTransformFeedbackStream(GLenum  mode, GLuint  id, GLuint  stream) {
    return ::glDrawTransformFeedbackStream(mode, id, stream);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glDrawTransformFeedbackStreamInstanced(GLenum  mode, GLuint  id, GLuint  stream, GLsizei  instancecount) {
    return ::glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEnable(GLenum  cap) {
    return ::glEnable(cap);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEnableVertexArrayAttrib(GLuint  vaobj, GLuint  index) {
    return ::glEnableVertexArrayAttrib(vaobj, index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEnableVertexAttribArray(GLuint  index) {
    return ::glEnableVertexAttribArray(index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEnablei(GLenum  target, GLuint  index) {
    return ::glEnablei(target, index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEndConditionalRender() {
    return ::glEndConditionalRender();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEndQuery(GLenum  target) {
    return ::glEndQuery(target);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEndQueryIndexed(GLenum  target, GLuint  index) {
    return ::glEndQueryIndexed(target, index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glEndTransformFeedback() {
    return ::glEndTransformFeedback();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLsync  sstd::_sstd_glFenceSync(GLenum  condition, GLbitfield  flags) {
    return ::glFenceSync(condition, flags);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFinish() {
    return ::glFinish();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFlush() {
    return ::glFlush();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFlushMappedBufferRange(GLenum  target, GLintptr  offset, GLsizeiptr  length) {
    return ::glFlushMappedBufferRange(target, offset, length);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFlushMappedNamedBufferRange(GLuint  buffer, GLintptr  offset, GLsizei  length) {
    return ::glFlushMappedNamedBufferRange(buffer, offset, length);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFramebufferParameteri(GLenum  target, GLenum  pname, GLint  param) {
    return ::glFramebufferParameteri(target, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFramebufferRenderbuffer(GLenum  target, GLenum  attachment, GLenum  renderbuffertarget, GLuint  renderbuffer) {
    return ::glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFramebufferTexture(GLenum  target, GLenum  attachment, GLuint  texture, GLint  level) {
    return ::glFramebufferTexture(target, attachment, texture, level);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFramebufferTexture1D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level) {
    return ::glFramebufferTexture1D(target, attachment, textarget, texture, level);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFramebufferTexture2D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level) {
    return ::glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFramebufferTexture3D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level, GLint  zoffset) {
    return ::glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFramebufferTextureLayer(GLenum  target, GLenum  attachment, GLuint  texture, GLint  level, GLint  layer) {
    return ::glFramebufferTextureLayer(target, attachment, texture, level, layer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glFrontFace(GLenum  mode) {
    return ::glFrontFace(mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenBuffers(GLsizei  n, GLuint *  buffers) {
    return ::glGenBuffers(n, buffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenFramebuffers(GLsizei  n, GLuint *  framebuffers) {
    return ::glGenFramebuffers(n, framebuffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenProgramPipelines(GLsizei  n, GLuint *  pipelines) {
    return ::glGenProgramPipelines(n, pipelines);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenQueries(GLsizei  n, GLuint *  ids) {
    return ::glGenQueries(n, ids);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenRenderbuffers(GLsizei  n, GLuint *  renderbuffers) {
    return ::glGenRenderbuffers(n, renderbuffers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenSamplers(GLsizei  count, GLuint *  samplers) {
    return ::glGenSamplers(count, samplers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenTextures(GLsizei  n, GLuint *  textures) {
    return ::glGenTextures(n, textures);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenTransformFeedbacks(GLsizei  n, GLuint *  ids) {
    return ::glGenTransformFeedbacks(n, ids);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenVertexArrays(GLsizei  n, GLuint *  arrays) {
    return ::glGenVertexArrays(n, arrays);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenerateMipmap(GLenum  target) {
    return ::glGenerateMipmap(target);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGenerateTextureMipmap(GLuint  texture) {
    return ::glGenerateTextureMipmap(texture);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveAtomicCounterBufferiv(GLuint  program, GLuint  bufferIndex, GLenum  pname, GLint *  params) {
    return ::glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveAttrib(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLint *  size, GLenum *  type, GLchar *  name) {
    return ::glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveSubroutineName(GLuint  program, GLenum  shadertype, GLuint  index, GLsizei  bufsize, GLsizei *  length, GLchar *  name) {
    return ::glGetActiveSubroutineName(program, shadertype, index, bufsize, length, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveSubroutineUniformName(GLuint  program, GLenum  shadertype, GLuint  index, GLsizei  bufsize, GLsizei *  length, GLchar *  name) {
    return ::glGetActiveSubroutineUniformName(program, shadertype, index, bufsize, length, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveSubroutineUniformiv(GLuint  program, GLenum  shadertype, GLuint  index, GLenum  pname, GLint *  values) {
    return ::glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveUniform(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLint *  size, GLenum *  type, GLchar *  name) {
    return ::glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveUniformBlockName(GLuint  program, GLuint  uniformBlockIndex, GLsizei  bufSize, GLsizei *  length, GLchar *  uniformBlockName) {
    return ::glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveUniformBlockiv(GLuint  program, GLuint  uniformBlockIndex, GLenum  pname, GLint *  params) {
    return ::glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveUniformName(GLuint  program, GLuint  uniformIndex, GLsizei  bufSize, GLsizei *  length, GLchar *  uniformName) {
    return ::glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetActiveUniformsiv(GLuint  program, GLsizei  uniformCount, GLuint *  uniformIndices, GLenum  pname, GLint *  params) {
    return ::glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetAttachedShaders(GLuint  program, GLsizei  maxCount, GLsizei *  count, GLuint *  shaders) {
    return ::glGetAttachedShaders(program, maxCount, count, shaders);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  sstd::_sstd_glGetAttribLocation(GLuint  program, GLchar *  name) {
    return ::glGetAttribLocation(program, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetBooleani_v(GLenum  target, GLuint  index, GLboolean *  data) {
    return ::glGetBooleani_v(target, index, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetBooleanv(GLenum  pname, GLboolean *  data) {
    return ::glGetBooleanv(pname, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetBufferParameteri64v(GLenum  target, GLenum  pname, GLint64 *  params) {
    return ::glGetBufferParameteri64v(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetBufferParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glGetBufferParameteriv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetBufferPointerv(GLenum  target, GLenum  pname, void * *  params) {
    return ::glGetBufferPointerv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetBufferSubData(GLenum  target, GLintptr  offset, GLsizeiptr  size, void *  data) {
    return ::glGetBufferSubData(target, offset, size, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetCompressedTexImage(GLenum  target, GLint  level, void *  img) {
    return ::glGetCompressedTexImage(target, level, img);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetCompressedTextureImage(GLuint  texture, GLint  level, GLsizei  bufSize, void *  pixels) {
    return ::glGetCompressedTextureImage(texture, level, bufSize, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetCompressedTextureSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLsizei  bufSize, void *  pixels) {
    return ::glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  sstd::_sstd_glGetDebugMessageLog(GLuint  count, GLsizei  bufSize, GLenum *  sources, GLenum *  types, GLuint *  ids, GLenum *  severities, GLsizei *  lengths, GLchar *  messageLog) {
    return ::glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetDoublei_v(GLenum  target, GLuint  index, GLdouble *  data) {
    return ::glGetDoublei_v(target, index, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetDoublev(GLenum  pname, GLdouble *  data) {
    return ::glGetDoublev(pname, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  sstd::_sstd_glGetError() {
    return ::glGetError();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetFloati_v(GLenum  target, GLuint  index, GLfloat *  data) {
    return ::glGetFloati_v(target, index, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetFloatv(GLenum  pname, GLfloat *  data) {
    return ::glGetFloatv(pname, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  sstd::_sstd_glGetFragDataIndex(GLuint  program, GLchar *  name) {
    return ::glGetFragDataIndex(program, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  sstd::_sstd_glGetFragDataLocation(GLuint  program, GLchar *  name) {
    return ::glGetFragDataLocation(program, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetFramebufferAttachmentParameteriv(GLenum  target, GLenum  attachment, GLenum  pname, GLint *  params) {
    return ::glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetFramebufferParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glGetFramebufferParameteriv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLenum  sstd::_sstd_glGetGraphicsResetStatus() {
    return ::glGetGraphicsResetStatus();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetInteger64i_v(GLenum  target, GLuint  index, GLint64 *  data) {
    return ::glGetInteger64i_v(target, index, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetInteger64v(GLenum  pname, GLint64 *  data) {
    return ::glGetInteger64v(pname, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetIntegeri_v(GLenum  target, GLuint  index, GLint *  data) {
    return ::glGetIntegeri_v(target, index, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetIntegerv(GLenum  pname, GLint *  data) {
    return ::glGetIntegerv(pname, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetInternalformati64v(GLenum  target, GLenum  internalformat, GLenum  pname, GLsizei  bufSize, GLint64 *  params) {
    return ::glGetInternalformati64v(target, internalformat, pname, bufSize, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetInternalformativ(GLenum  target, GLenum  internalformat, GLenum  pname, GLsizei  bufSize, GLint *  params) {
    return ::glGetInternalformativ(target, internalformat, pname, bufSize, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetMultisamplefv(GLenum  pname, GLuint  index, GLfloat *  val) {
    return ::glGetMultisamplefv(pname, index, val);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetNamedBufferParameteri64v(GLuint  buffer, GLenum  pname, GLint64 *  params) {
    return ::glGetNamedBufferParameteri64v(buffer, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetNamedBufferParameteriv(GLuint  buffer, GLenum  pname, GLint *  params) {
    return ::glGetNamedBufferParameteriv(buffer, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetNamedBufferPointerv(GLuint  buffer, GLenum  pname, void * *  params) {
    return ::glGetNamedBufferPointerv(buffer, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetNamedBufferSubData(GLuint  buffer, GLintptr  offset, GLsizei  size, void *  data) {
    return ::glGetNamedBufferSubData(buffer, offset, size, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetNamedFramebufferAttachmentParameteriv(GLuint  framebuffer, GLenum  attachment, GLenum  pname, GLint *  params) {
    return ::glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetNamedFramebufferParameteriv(GLuint  framebuffer, GLenum  pname, GLint *  param) {
    return ::glGetNamedFramebufferParameteriv(framebuffer, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetNamedRenderbufferParameteriv(GLuint  renderbuffer, GLenum  pname, GLint *  params) {
    return ::glGetNamedRenderbufferParameteriv(renderbuffer, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetObjectLabel(GLenum  identifier, GLuint  name, GLsizei  bufSize, GLsizei *  length, GLchar *  label) {
    return ::glGetObjectLabel(identifier, name, bufSize, length, label);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetObjectPtrLabel(void *  ptr, GLsizei  bufSize, GLsizei *  length, GLchar *  label) {
    return ::glGetObjectPtrLabel(ptr, bufSize, length, label);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramBinary(GLuint  program, GLsizei  bufSize, GLsizei *  length, GLenum *  binaryFormat, void *  binary) {
    return ::glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramInfoLog(GLuint  program, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog) {
    return ::glGetProgramInfoLog(program, bufSize, length, infoLog);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramInterfaceiv(GLuint  program, GLenum  programInterface, GLenum  pname, GLint *  params) {
    return ::glGetProgramInterfaceiv(program, programInterface, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramPipelineInfoLog(GLuint  pipeline, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog) {
    return ::glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramPipelineiv(GLuint  pipeline, GLenum  pname, GLint *  params) {
    return ::glGetProgramPipelineiv(pipeline, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  sstd::_sstd_glGetProgramResourceIndex(GLuint  program, GLenum  programInterface, GLchar *  name) {
    return ::glGetProgramResourceIndex(program, programInterface, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  sstd::_sstd_glGetProgramResourceLocation(GLuint  program, GLenum  programInterface, GLchar *  name) {
    return ::glGetProgramResourceLocation(program, programInterface, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  sstd::_sstd_glGetProgramResourceLocationIndex(GLuint  program, GLenum  programInterface, GLchar *  name) {
    return ::glGetProgramResourceLocationIndex(program, programInterface, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramResourceName(GLuint  program, GLenum  programInterface, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLchar *  name) {
    return ::glGetProgramResourceName(program, programInterface, index, bufSize, length, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramResourceiv(GLuint  program, GLenum  programInterface, GLuint  index, GLsizei  propCount, GLenum *  props, GLsizei  bufSize, GLsizei *  length, GLint *  params) {
    return ::glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramStageiv(GLuint  program, GLenum  shadertype, GLenum  pname, GLint *  values) {
    return ::glGetProgramStageiv(program, shadertype, pname, values);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetProgramiv(GLuint  program, GLenum  pname, GLint *  params) {
    return ::glGetProgramiv(program, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetQueryIndexediv(GLenum  target, GLuint  index, GLenum  pname, GLint *  params) {
    return ::glGetQueryIndexediv(target, index, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetQueryObjecti64v(GLuint  id, GLenum  pname, GLint64 *  params) {
    return ::glGetQueryObjecti64v(id, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetQueryObjectiv(GLuint  id, GLenum  pname, GLint *  params) {
    return ::glGetQueryObjectiv(id, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetQueryObjectui64v(GLuint  id, GLenum  pname, GLuint64 *  params) {
    return ::glGetQueryObjectui64v(id, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetQueryObjectuiv(GLuint  id, GLenum  pname, GLuint *  params) {
    return ::glGetQueryObjectuiv(id, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetQueryiv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glGetQueryiv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetRenderbufferParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glGetRenderbufferParameteriv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetSamplerParameterIiv(GLuint  sampler, GLenum  pname, GLint *  params) {
    return ::glGetSamplerParameterIiv(sampler, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetSamplerParameterIuiv(GLuint  sampler, GLenum  pname, GLuint *  params) {
    return ::glGetSamplerParameterIuiv(sampler, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetSamplerParameterfv(GLuint  sampler, GLenum  pname, GLfloat *  params) {
    return ::glGetSamplerParameterfv(sampler, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetSamplerParameteriv(GLuint  sampler, GLenum  pname, GLint *  params) {
    return ::glGetSamplerParameteriv(sampler, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetShaderInfoLog(GLuint  shader, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog) {
    return ::glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetShaderPrecisionFormat(GLenum  shadertype, GLenum  precisiontype, GLint *  range, GLint *  precision) {
    return ::glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetShaderSource(GLuint  shader, GLsizei  bufSize, GLsizei *  length, GLchar *  source) {
    return ::glGetShaderSource(shader, bufSize, length, source);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetShaderiv(GLuint  shader, GLenum  pname, GLint *  params) {
    return ::glGetShaderiv(shader, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY const GLubyte * sstd::_sstd_glGetString(GLenum  name) {
    return ::glGetString(name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY const GLubyte * sstd::_sstd_glGetStringi(GLenum  name, GLuint  index) {
    return ::glGetStringi(name, index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  sstd::_sstd_glGetSubroutineIndex(GLuint  program, GLenum  shadertype, GLchar *  name) {
    return ::glGetSubroutineIndex(program, shadertype, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  sstd::_sstd_glGetSubroutineUniformLocation(GLuint  program, GLenum  shadertype, GLchar *  name) {
    return ::glGetSubroutineUniformLocation(program, shadertype, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetSynciv(GLsync  sync, GLenum  pname, GLsizei  bufSize, GLsizei *  length, GLint *  values) {
    return ::glGetSynciv(sync, pname, bufSize, length, values);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTexImage(GLenum  target, GLint  level, GLenum  format, GLenum  type, void *  pixels) {
    return ::glGetTexImage(target, level, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTexLevelParameterfv(GLenum  target, GLint  level, GLenum  pname, GLfloat *  params) {
    return ::glGetTexLevelParameterfv(target, level, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTexLevelParameteriv(GLenum  target, GLint  level, GLenum  pname, GLint *  params) {
    return ::glGetTexLevelParameteriv(target, level, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTexParameterIiv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glGetTexParameterIiv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTexParameterIuiv(GLenum  target, GLenum  pname, GLuint *  params) {
    return ::glGetTexParameterIuiv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTexParameterfv(GLenum  target, GLenum  pname, GLfloat *  params) {
    return ::glGetTexParameterfv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTexParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glGetTexParameteriv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureImage(GLuint  texture, GLint  level, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels) {
    return ::glGetTextureImage(texture, level, format, type, bufSize, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureLevelParameterfv(GLuint  texture, GLint  level, GLenum  pname, GLfloat *  params) {
    return ::glGetTextureLevelParameterfv(texture, level, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureLevelParameteriv(GLuint  texture, GLint  level, GLenum  pname, GLint *  params) {
    return ::glGetTextureLevelParameteriv(texture, level, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureParameterIiv(GLuint  texture, GLenum  pname, GLint *  params) {
    return ::glGetTextureParameterIiv(texture, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureParameterIuiv(GLuint  texture, GLenum  pname, GLuint *  params) {
    return ::glGetTextureParameterIuiv(texture, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureParameterfv(GLuint  texture, GLenum  pname, GLfloat *  params) {
    return ::glGetTextureParameterfv(texture, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureParameteriv(GLuint  texture, GLenum  pname, GLint *  params) {
    return ::glGetTextureParameteriv(texture, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTextureSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels) {
    return ::glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTransformFeedbackVarying(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLsizei *  size, GLenum *  type, GLchar *  name) {
    return ::glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTransformFeedbacki64_v(GLuint  xfb, GLenum  pname, GLuint  index, GLint64 *  param) {
    return ::glGetTransformFeedbacki64_v(xfb, pname, index, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTransformFeedbacki_v(GLuint  xfb, GLenum  pname, GLuint  index, GLint *  param) {
    return ::glGetTransformFeedbacki_v(xfb, pname, index, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetTransformFeedbackiv(GLuint  xfb, GLenum  pname, GLint *  param) {
    return ::glGetTransformFeedbackiv(xfb, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint  sstd::_sstd_glGetUniformBlockIndex(GLuint  program, GLchar *  uniformBlockName) {
    return ::glGetUniformBlockIndex(program, uniformBlockName);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetUniformIndices(GLuint  program, GLsizei  uniformCount, GLchar * *  uniformNames, GLuint *  uniformIndices) {
    return ::glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLint  sstd::_sstd_glGetUniformLocation(GLuint  program, GLchar *  name) {
    return ::glGetUniformLocation(program, name);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetUniformSubroutineuiv(GLenum  shadertype, GLint  location, GLuint *  params) {
    return ::glGetUniformSubroutineuiv(shadertype, location, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetUniformdv(GLuint  program, GLint  location, GLdouble *  params) {
    return ::glGetUniformdv(program, location, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetUniformfv(GLuint  program, GLint  location, GLfloat *  params) {
    return ::glGetUniformfv(program, location, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetUniformiv(GLuint  program, GLint  location, GLint *  params) {
    return ::glGetUniformiv(program, location, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetUniformuiv(GLuint  program, GLint  location, GLuint *  params) {
    return ::glGetUniformuiv(program, location, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexArrayIndexed64iv(GLuint  vaobj, GLuint  index, GLenum  pname, GLint64 *  param) {
    return ::glGetVertexArrayIndexed64iv(vaobj, index, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexArrayIndexediv(GLuint  vaobj, GLuint  index, GLenum  pname, GLint *  param) {
    return ::glGetVertexArrayIndexediv(vaobj, index, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexArrayiv(GLuint  vaobj, GLenum  pname, GLint *  param) {
    return ::glGetVertexArrayiv(vaobj, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexAttribIiv(GLuint  index, GLenum  pname, GLint *  params) {
    return ::glGetVertexAttribIiv(index, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexAttribIuiv(GLuint  index, GLenum  pname, GLuint *  params) {
    return ::glGetVertexAttribIuiv(index, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexAttribLdv(GLuint  index, GLenum  pname, GLdouble *  params) {
    return ::glGetVertexAttribLdv(index, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexAttribPointerv(GLuint  index, GLenum  pname, void * *  pointer) {
    return ::glGetVertexAttribPointerv(index, pname, pointer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexAttribdv(GLuint  index, GLenum  pname, GLdouble *  params) {
    return ::glGetVertexAttribdv(index, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexAttribfv(GLuint  index, GLenum  pname, GLfloat *  params) {
    return ::glGetVertexAttribfv(index, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetVertexAttribiv(GLuint  index, GLenum  pname, GLint *  params) {
    return ::glGetVertexAttribiv(index, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetnCompressedTexImage(GLenum  target, GLint  lod, GLsizei  bufSize, void *  pixels) {
    return ::glGetnCompressedTexImage(target, lod, bufSize, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetnTexImage(GLenum  target, GLint  level, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels) {
    return ::glGetnTexImage(target, level, format, type, bufSize, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetnUniformdv(GLuint  program, GLint  location, GLsizei  bufSize, GLdouble *  params) {
    return ::glGetnUniformdv(program, location, bufSize, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetnUniformfv(GLuint  program, GLint  location, GLsizei  bufSize, GLfloat *  params) {
    return ::glGetnUniformfv(program, location, bufSize, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetnUniformiv(GLuint  program, GLint  location, GLsizei  bufSize, GLint *  params) {
    return ::glGetnUniformiv(program, location, bufSize, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glGetnUniformuiv(GLuint  program, GLint  location, GLsizei  bufSize, GLuint *  params) {
    return ::glGetnUniformuiv(program, location, bufSize, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glHint(GLenum  target, GLenum  mode) {
    return ::glHint(target, mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateBufferData(GLuint  buffer) {
    return ::glInvalidateBufferData(buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateBufferSubData(GLuint  buffer, GLintptr  offset, GLsizeiptr  length) {
    return ::glInvalidateBufferSubData(buffer, offset, length);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateFramebuffer(GLenum  target, GLsizei  numAttachments, GLenum *  attachments) {
    return ::glInvalidateFramebuffer(target, numAttachments, attachments);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateNamedFramebufferData(GLuint  framebuffer, GLsizei  numAttachments, GLenum *  attachments) {
    return ::glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateNamedFramebufferSubData(GLuint  framebuffer, GLsizei  numAttachments, GLenum *  attachments, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateSubFramebuffer(GLenum  target, GLsizei  numAttachments, GLenum *  attachments, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateTexImage(GLuint  texture, GLint  level) {
    return ::glInvalidateTexImage(texture, level);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glInvalidateTexSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth) {
    return ::glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsBuffer(GLuint  buffer) {
    return ::glIsBuffer(buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsEnabled(GLenum  cap) {
    return ::glIsEnabled(cap);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsEnabledi(GLenum  target, GLuint  index) {
    return ::glIsEnabledi(target, index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsFramebuffer(GLuint  framebuffer) {
    return ::glIsFramebuffer(framebuffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsProgram(GLuint  program) {
    return ::glIsProgram(program);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsProgramPipeline(GLuint  pipeline) {
    return ::glIsProgramPipeline(pipeline);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsQuery(GLuint  id) {
    return ::glIsQuery(id);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsRenderbuffer(GLuint  renderbuffer) {
    return ::glIsRenderbuffer(renderbuffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsSampler(GLuint  sampler) {
    return ::glIsSampler(sampler);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsShader(GLuint  shader) {
    return ::glIsShader(shader);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsSync(GLsync  sync) {
    return ::glIsSync(sync);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsTexture(GLuint  texture) {
    return ::glIsTexture(texture);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsTransformFeedback(GLuint  id) {
    return ::glIsTransformFeedback(id);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glIsVertexArray(GLuint  array) {
    return ::glIsVertexArray(array);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glLineWidth(GLfloat  width) {
    return ::glLineWidth(width);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glLinkProgram(GLuint  program) {
    return ::glLinkProgram(program);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glLogicOp(GLenum  opcode) {
    return ::glLogicOp(opcode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void * sstd::_sstd_glMapBuffer(GLenum  target, GLenum  access) {
    return ::glMapBuffer(target, access);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void * sstd::_sstd_glMapBufferRange(GLenum  target, GLintptr  offset, GLsizeiptr  length, GLbitfield  access) {
    return ::glMapBufferRange(target, offset, length, access);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void * sstd::_sstd_glMapNamedBuffer(GLuint  buffer, GLenum  access) {
    return ::glMapNamedBuffer(buffer, access);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void * sstd::_sstd_glMapNamedBufferRange(GLuint  buffer, GLintptr  offset, GLsizei  length, GLbitfield  access) {
    return ::glMapNamedBufferRange(buffer, offset, length, access);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMemoryBarrier(GLbitfield  barriers) {
    return ::glMemoryBarrier(barriers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMemoryBarrierByRegion(GLbitfield  barriers) {
    return ::glMemoryBarrierByRegion(barriers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMinSampleShading(GLfloat  value) {
    return ::glMinSampleShading(value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMultiDrawArrays(GLenum  mode, GLint *  first, GLsizei *  count, GLsizei  drawcount) {
    return ::glMultiDrawArrays(mode, first, count, drawcount);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMultiDrawArraysIndirect(GLenum  mode, void *  indirect, GLsizei  drawcount, GLsizei  stride) {
    return ::glMultiDrawArraysIndirect(mode, indirect, drawcount, stride);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMultiDrawElements(GLenum  mode, GLsizei *  count, GLenum  type, void * *  indices, GLsizei  drawcount) {
    return ::glMultiDrawElements(mode, count, type, indices, drawcount);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMultiDrawElementsBaseVertex(GLenum  mode, GLsizei *  count, GLenum  type, void * *  indices, GLsizei  drawcount, GLint *  basevertex) {
    return ::glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glMultiDrawElementsIndirect(GLenum  mode, GLenum  type, void *  indirect, GLsizei  drawcount, GLsizei  stride) {
    return ::glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedBufferData(GLuint  buffer, GLsizei  size, void *  data, GLenum  usage) {
    return ::glNamedBufferData(buffer, size, data, usage);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedBufferStorage(GLuint  buffer, GLsizei  size, void *  data, GLbitfield  flags) {
    return ::glNamedBufferStorage(buffer, size, data, flags);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedBufferSubData(GLuint  buffer, GLintptr  offset, GLsizei  size, void *  data) {
    return ::glNamedBufferSubData(buffer, offset, size, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedFramebufferDrawBuffer(GLuint  framebuffer, GLenum  buf) {
    return ::glNamedFramebufferDrawBuffer(framebuffer, buf);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedFramebufferDrawBuffers(GLuint  framebuffer, GLsizei  n, GLenum *  bufs) {
    return ::glNamedFramebufferDrawBuffers(framebuffer, n, bufs);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedFramebufferParameteri(GLuint  framebuffer, GLenum  pname, GLint  param) {
    return ::glNamedFramebufferParameteri(framebuffer, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedFramebufferReadBuffer(GLuint  framebuffer, GLenum  src) {
    return ::glNamedFramebufferReadBuffer(framebuffer, src);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedFramebufferRenderbuffer(GLuint  framebuffer, GLenum  attachment, GLenum  renderbuffertarget, GLuint  renderbuffer) {
    return ::glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedFramebufferTexture(GLuint  framebuffer, GLenum  attachment, GLuint  texture, GLint  level) {
    return ::glNamedFramebufferTexture(framebuffer, attachment, texture, level);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedFramebufferTextureLayer(GLuint  framebuffer, GLenum  attachment, GLuint  texture, GLint  level, GLint  layer) {
    return ::glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedRenderbufferStorage(GLuint  renderbuffer, GLenum  internalformat, GLsizei  width, GLsizei  height) {
    return ::glNamedRenderbufferStorage(renderbuffer, internalformat, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glNamedRenderbufferStorageMultisample(GLuint  renderbuffer, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height) {
    return ::glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glObjectLabel(GLenum  identifier, GLuint  name, GLsizei  length, GLchar *  label) {
    return ::glObjectLabel(identifier, name, length, label);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glObjectPtrLabel(void *  ptr, GLsizei  length, GLchar *  label) {
    return ::glObjectPtrLabel(ptr, length, label);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPatchParameterfv(GLenum  pname, GLfloat *  values) {
    return ::glPatchParameterfv(pname, values);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPatchParameteri(GLenum  pname, GLint  value) {
    return ::glPatchParameteri(pname, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPauseTransformFeedback() {
    return ::glPauseTransformFeedback();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPixelStoref(GLenum  pname, GLfloat  param) {
    return ::glPixelStoref(pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPixelStorei(GLenum  pname, GLint  param) {
    return ::glPixelStorei(pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPointParameterf(GLenum  pname, GLfloat  param) {
    return ::glPointParameterf(pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPointParameterfv(GLenum  pname, GLfloat *  params) {
    return ::glPointParameterfv(pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPointParameteri(GLenum  pname, GLint  param) {
    return ::glPointParameteri(pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPointParameteriv(GLenum  pname, GLint *  params) {
    return ::glPointParameteriv(pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPointSize(GLfloat  size) {
    return ::glPointSize(size);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPolygonMode(GLenum  face, GLenum  mode) {
    return ::glPolygonMode(face, mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPolygonOffset(GLfloat  factor, GLfloat  units) {
    return ::glPolygonOffset(factor, units);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPopDebugGroup() {
    return ::glPopDebugGroup();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPrimitiveRestartIndex(GLuint  index) {
    return ::glPrimitiveRestartIndex(index);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramBinary(GLuint  program, GLenum  binaryFormat, void *  binary, GLsizei  length) {
    return ::glProgramBinary(program, binaryFormat, binary, length);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramParameteri(GLuint  program, GLenum  pname, GLint  value) {
    return ::glProgramParameteri(program, pname, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1d(GLuint  program, GLint  location, GLdouble  v0) {
    return ::glProgramUniform1d(program, location, v0);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glProgramUniform1dv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1f(GLuint  program, GLint  location, GLfloat  v0) {
    return ::glProgramUniform1f(program, location, v0);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glProgramUniform1fv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1i(GLuint  program, GLint  location, GLint  v0) {
    return ::glProgramUniform1i(program, location, v0);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value) {
    return ::glProgramUniform1iv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1ui(GLuint  program, GLint  location, GLuint  v0) {
    return ::glProgramUniform1ui(program, location, v0);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform1uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value) {
    return ::glProgramUniform1uiv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1) {
    return ::glProgramUniform2d(program, location, v0, v1);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glProgramUniform2dv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1) {
    return ::glProgramUniform2f(program, location, v0, v1);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glProgramUniform2fv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2i(GLuint  program, GLint  location, GLint  v0, GLint  v1) {
    return ::glProgramUniform2i(program, location, v0, v1);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value) {
    return ::glProgramUniform2iv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1) {
    return ::glProgramUniform2ui(program, location, v0, v1);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform2uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value) {
    return ::glProgramUniform2uiv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1, GLdouble  v2) {
    return ::glProgramUniform3d(program, location, v0, v1, v2);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glProgramUniform3dv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2) {
    return ::glProgramUniform3f(program, location, v0, v1, v2);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glProgramUniform3fv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3i(GLuint  program, GLint  location, GLint  v0, GLint  v1, GLint  v2) {
    return ::glProgramUniform3i(program, location, v0, v1, v2);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value) {
    return ::glProgramUniform3iv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1, GLuint  v2) {
    return ::glProgramUniform3ui(program, location, v0, v1, v2);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform3uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value) {
    return ::glProgramUniform3uiv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1, GLdouble  v2, GLdouble  v3) {
    return ::glProgramUniform4d(program, location, v0, v1, v2, v3);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4dv(GLuint  program, GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glProgramUniform4dv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2, GLfloat  v3) {
    return ::glProgramUniform4f(program, location, v0, v1, v2, v3);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4fv(GLuint  program, GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glProgramUniform4fv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4i(GLuint  program, GLint  location, GLint  v0, GLint  v1, GLint  v2, GLint  v3) {
    return ::glProgramUniform4i(program, location, v0, v1, v2, v3);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4iv(GLuint  program, GLint  location, GLsizei  count, GLint *  value) {
    return ::glProgramUniform4iv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1, GLuint  v2, GLuint  v3) {
    return ::glProgramUniform4ui(program, location, v0, v1, v2, v3);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniform4uiv(GLuint  program, GLint  location, GLsizei  count, GLuint *  value) {
    return ::glProgramUniform4uiv(program, location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix2dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix2fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix2x3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix2x3dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix2x3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix2x3fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix2x4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix2x4dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix2x4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix2x4fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix3dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix3fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix3x2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix3x2dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix3x2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix3x2fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix3x4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix3x4dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix3x4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix3x4fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix4dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix4fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix4x2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix4x2dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix4x2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix4x2fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix4x3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glProgramUniformMatrix4x3dv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProgramUniformMatrix4x3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glProgramUniformMatrix4x3fv(program, location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glProvokingVertex(GLenum  mode) {
    return ::glProvokingVertex(mode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glPushDebugGroup(GLenum  source, GLuint  id, GLsizei  length, GLchar *  message) {
    return ::glPushDebugGroup(source, id, length, message);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glQueryCounter(GLuint  id, GLenum  target) {
    return ::glQueryCounter(id, target);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glReadBuffer(GLenum  src) {
    return ::glReadBuffer(src);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glReadPixels(GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, void *  pixels) {
    return ::glReadPixels(x, y, width, height, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glReadnPixels(GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, GLsizei  bufSize, void *  data) {
    return ::glReadnPixels(x, y, width, height, format, type, bufSize, data);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glReleaseShaderCompiler() {
    return ::glReleaseShaderCompiler();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glRenderbufferStorage(GLenum  target, GLenum  internalformat, GLsizei  width, GLsizei  height) {
    return ::glRenderbufferStorage(target, internalformat, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glRenderbufferStorageMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height) {
    return ::glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glResumeTransformFeedback() {
    return ::glResumeTransformFeedback();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSampleCoverage(GLfloat  value, GLboolean  invert) {
    return ::glSampleCoverage(value, invert);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSampleMaski(GLuint  maskNumber, GLbitfield  mask) {
    return ::glSampleMaski(maskNumber, mask);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSamplerParameterIiv(GLuint  sampler, GLenum  pname, GLint *  param) {
    return ::glSamplerParameterIiv(sampler, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSamplerParameterIuiv(GLuint  sampler, GLenum  pname, GLuint *  param) {
    return ::glSamplerParameterIuiv(sampler, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSamplerParameterf(GLuint  sampler, GLenum  pname, GLfloat  param) {
    return ::glSamplerParameterf(sampler, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSamplerParameterfv(GLuint  sampler, GLenum  pname, GLfloat *  param) {
    return ::glSamplerParameterfv(sampler, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSamplerParameteri(GLuint  sampler, GLenum  pname, GLint  param) {
    return ::glSamplerParameteri(sampler, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glSamplerParameteriv(GLuint  sampler, GLenum  pname, GLint *  param) {
    return ::glSamplerParameteriv(sampler, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glScissor(GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glScissor(x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glScissorArrayv(GLuint  first, GLsizei  count, GLint *  v) {
    return ::glScissorArrayv(first, count, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glScissorIndexed(GLuint  index, GLint  left, GLint  bottom, GLsizei  width, GLsizei  height) {
    return ::glScissorIndexed(index, left, bottom, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glScissorIndexedv(GLuint  index, GLint *  v) {
    return ::glScissorIndexedv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glShaderBinary(GLsizei  count, GLuint *  shaders, GLenum  binaryformat, void *  binary, GLsizei  length) {
    return ::glShaderBinary(count, shaders, binaryformat, binary, length);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glShaderSource(GLuint  shader, GLsizei  count, GLchar * *  string, GLint *  length) {
    return ::glShaderSource(shader, count, string, length);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glShaderStorageBlockBinding(GLuint  program, GLuint  storageBlockIndex, GLuint  storageBlockBinding) {
    return ::glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glStencilFunc(GLenum  func, GLint  ref, GLuint  mask) {
    return ::glStencilFunc(func, ref, mask);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glStencilFuncSeparate(GLenum  face, GLenum  func, GLint  ref, GLuint  mask) {
    return ::glStencilFuncSeparate(face, func, ref, mask);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glStencilMask(GLuint  mask) {
    return ::glStencilMask(mask);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glStencilMaskSeparate(GLenum  face, GLuint  mask) {
    return ::glStencilMaskSeparate(face, mask);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glStencilOp(GLenum  fail, GLenum  zfail, GLenum  zpass) {
    return ::glStencilOp(fail, zfail, zpass);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glStencilOpSeparate(GLenum  face, GLenum  sfail, GLenum  dpfail, GLenum  dppass) {
    return ::glStencilOpSeparate(face, sfail, dpfail, dppass);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexBuffer(GLenum  target, GLenum  internalformat, GLuint  buffer) {
    return ::glTexBuffer(target, internalformat, buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexBufferRange(GLenum  target, GLenum  internalformat, GLuint  buffer, GLintptr  offset, GLsizeiptr  size) {
    return ::glTexBufferRange(target, internalformat, buffer, offset, size);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexImage1D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLint  border, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexImage2D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLsizei  height, GLint  border, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexImage2DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations) {
    return ::glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexImage3D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLint  border, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexImage3DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations) {
    return ::glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexParameterIiv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glTexParameterIiv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexParameterIuiv(GLenum  target, GLenum  pname, GLuint *  params) {
    return ::glTexParameterIuiv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexParameterf(GLenum  target, GLenum  pname, GLfloat  param) {
    return ::glTexParameterf(target, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexParameterfv(GLenum  target, GLenum  pname, GLfloat *  params) {
    return ::glTexParameterfv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexParameteri(GLenum  target, GLenum  pname, GLint  param) {
    return ::glTexParameteri(target, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
    return ::glTexParameteriv(target, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexStorage1D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width) {
    return ::glTexStorage1D(target, levels, internalformat, width);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexStorage2D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height) {
    return ::glTexStorage2D(target, levels, internalformat, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexStorage2DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations) {
    return ::glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexStorage3D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth) {
    return ::glTexStorage3D(target, levels, internalformat, width, height, depth);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexStorage3DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations) {
    return ::glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureBarrier() {
    return ::glTextureBarrier();
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureBuffer(GLuint  texture, GLenum  internalformat, GLuint  buffer) {
    return ::glTextureBuffer(texture, internalformat, buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureBufferRange(GLuint  texture, GLenum  internalformat, GLuint  buffer, GLintptr  offset, GLsizei  size) {
    return ::glTextureBufferRange(texture, internalformat, buffer, offset, size);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureParameterIiv(GLuint  texture, GLenum  pname, GLint *  params) {
    return ::glTextureParameterIiv(texture, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureParameterIuiv(GLuint  texture, GLenum  pname, GLuint *  params) {
    return ::glTextureParameterIuiv(texture, pname, params);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureParameterf(GLuint  texture, GLenum  pname, GLfloat  param) {
    return ::glTextureParameterf(texture, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureParameterfv(GLuint  texture, GLenum  pname, GLfloat *  param) {
    return ::glTextureParameterfv(texture, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureParameteri(GLuint  texture, GLenum  pname, GLint  param) {
    return ::glTextureParameteri(texture, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureParameteriv(GLuint  texture, GLenum  pname, GLint *  param) {
    return ::glTextureParameteriv(texture, pname, param);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureStorage1D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width) {
    return ::glTextureStorage1D(texture, levels, internalformat, width);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureStorage2D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height) {
    return ::glTextureStorage2D(texture, levels, internalformat, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureStorage2DMultisample(GLuint  texture, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations) {
    return ::glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureStorage3D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth) {
    return ::glTextureStorage3D(texture, levels, internalformat, width, height, depth);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureStorage3DMultisample(GLuint  texture, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations) {
    return ::glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, void *  pixels) {
    return ::glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTextureView(GLuint  texture, GLenum  target, GLuint  origtexture, GLenum  internalformat, GLuint  minlevel, GLuint  numlevels, GLuint  minlayer, GLuint  numlayers) {
    return ::glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTransformFeedbackBufferBase(GLuint  xfb, GLuint  index, GLuint  buffer) {
    return ::glTransformFeedbackBufferBase(xfb, index, buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTransformFeedbackBufferRange(GLuint  xfb, GLuint  index, GLuint  buffer, GLintptr  offset, GLsizei  size) {
    return ::glTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glTransformFeedbackVaryings(GLuint  program, GLsizei  count, GLchar * *  varyings, GLenum  bufferMode) {
    return ::glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1d(GLint  location, GLdouble  x) {
    return ::glUniform1d(location, x);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1dv(GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glUniform1dv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1f(GLint  location, GLfloat  v0) {
    return ::glUniform1f(location, v0);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1fv(GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glUniform1fv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1i(GLint  location, GLint  v0) {
    return ::glUniform1i(location, v0);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1iv(GLint  location, GLsizei  count, GLint *  value) {
    return ::glUniform1iv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1ui(GLint  location, GLuint  v0) {
    return ::glUniform1ui(location, v0);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform1uiv(GLint  location, GLsizei  count, GLuint *  value) {
    return ::glUniform1uiv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2d(GLint  location, GLdouble  x, GLdouble  y) {
    return ::glUniform2d(location, x, y);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2dv(GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glUniform2dv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2f(GLint  location, GLfloat  v0, GLfloat  v1) {
    return ::glUniform2f(location, v0, v1);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2fv(GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glUniform2fv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2i(GLint  location, GLint  v0, GLint  v1) {
    return ::glUniform2i(location, v0, v1);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2iv(GLint  location, GLsizei  count, GLint *  value) {
    return ::glUniform2iv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2ui(GLint  location, GLuint  v0, GLuint  v1) {
    return ::glUniform2ui(location, v0, v1);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform2uiv(GLint  location, GLsizei  count, GLuint *  value) {
    return ::glUniform2uiv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3d(GLint  location, GLdouble  x, GLdouble  y, GLdouble  z) {
    return ::glUniform3d(location, x, y, z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3dv(GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glUniform3dv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3f(GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2) {
    return ::glUniform3f(location, v0, v1, v2);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3fv(GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glUniform3fv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3i(GLint  location, GLint  v0, GLint  v1, GLint  v2) {
    return ::glUniform3i(location, v0, v1, v2);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3iv(GLint  location, GLsizei  count, GLint *  value) {
    return ::glUniform3iv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3ui(GLint  location, GLuint  v0, GLuint  v1, GLuint  v2) {
    return ::glUniform3ui(location, v0, v1, v2);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform3uiv(GLint  location, GLsizei  count, GLuint *  value) {
    return ::glUniform3uiv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4d(GLint  location, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w) {
    return ::glUniform4d(location, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4dv(GLint  location, GLsizei  count, GLdouble *  value) {
    return ::glUniform4dv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4f(GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2, GLfloat  v3) {
    return ::glUniform4f(location, v0, v1, v2, v3);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4fv(GLint  location, GLsizei  count, GLfloat *  value) {
    return ::glUniform4fv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4i(GLint  location, GLint  v0, GLint  v1, GLint  v2, GLint  v3) {
    return ::glUniform4i(location, v0, v1, v2, v3);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4iv(GLint  location, GLsizei  count, GLint *  value) {
    return ::glUniform4iv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4ui(GLint  location, GLuint  v0, GLuint  v1, GLuint  v2, GLuint  v3) {
    return ::glUniform4ui(location, v0, v1, v2, v3);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniform4uiv(GLint  location, GLsizei  count, GLuint *  value) {
    return ::glUniform4uiv(location, count, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformBlockBinding(GLuint  program, GLuint  uniformBlockIndex, GLuint  uniformBlockBinding) {
    return ::glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix2dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix2dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix2fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix2fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix2x3dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix2x3dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix2x3fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix2x3fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix2x4dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix2x4dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix2x4fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix2x4fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix3dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix3dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix3fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix3fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix3x2dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix3x2dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix3x2fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix3x2fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix3x4dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix3x4dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix3x4fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix3x4fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix4dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix4dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix4fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix4fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix4x2dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix4x2dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix4x2fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix4x2fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix4x3dv(GLint  location, GLsizei  count, GLboolean  transpose, GLdouble *  value) {
    return ::glUniformMatrix4x3dv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformMatrix4x3fv(GLint  location, GLsizei  count, GLboolean  transpose, GLfloat *  value) {
    return ::glUniformMatrix4x3fv(location, count, transpose, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUniformSubroutinesuiv(GLenum  shadertype, GLsizei  count, GLuint *  indices) {
    return ::glUniformSubroutinesuiv(shadertype, count, indices);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glUnmapBuffer(GLenum  target) {
    return ::glUnmapBuffer(target);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY GLboolean  sstd::_sstd_glUnmapNamedBuffer(GLuint  buffer) {
    return ::glUnmapNamedBuffer(buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUseProgram(GLuint  program) {
    return ::glUseProgram(program);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glUseProgramStages(GLuint  pipeline, GLbitfield  stages, GLuint  program) {
    return ::glUseProgramStages(pipeline, stages, program);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glValidateProgram(GLuint  program) {
    return ::glValidateProgram(program);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glValidateProgramPipeline(GLuint  pipeline) {
    return ::glValidateProgramPipeline(pipeline);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayAttribBinding(GLuint  vaobj, GLuint  attribindex, GLuint  bindingindex) {
    return ::glVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayAttribFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLboolean  normalized, GLuint  relativeoffset) {
    return ::glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayAttribIFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
    return ::glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayAttribLFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
    return ::glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayBindingDivisor(GLuint  vaobj, GLuint  bindingindex, GLuint  divisor) {
    return ::glVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayElementBuffer(GLuint  vaobj, GLuint  buffer) {
    return ::glVertexArrayElementBuffer(vaobj, buffer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayVertexBuffer(GLuint  vaobj, GLuint  bindingindex, GLuint  buffer, GLintptr  offset, GLsizei  stride) {
    return ::glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexArrayVertexBuffers(GLuint  vaobj, GLuint  first, GLsizei  count, GLuint *  buffers, GLintptr *  offsets, GLsizei *  strides) {
    return ::glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib1d(GLuint  index, GLdouble  x) {
    return ::glVertexAttrib1d(index, x);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib1dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttrib1dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib1f(GLuint  index, GLfloat  x) {
    return ::glVertexAttrib1f(index, x);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib1fv(GLuint  index, GLfloat *  v) {
    return ::glVertexAttrib1fv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib1s(GLuint  index, GLshort  x) {
    return ::glVertexAttrib1s(index, x);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib1sv(GLuint  index, GLshort *  v) {
    return ::glVertexAttrib1sv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib2d(GLuint  index, GLdouble  x, GLdouble  y) {
    return ::glVertexAttrib2d(index, x, y);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib2dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttrib2dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib2f(GLuint  index, GLfloat  x, GLfloat  y) {
    return ::glVertexAttrib2f(index, x, y);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib2fv(GLuint  index, GLfloat *  v) {
    return ::glVertexAttrib2fv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib2s(GLuint  index, GLshort  x, GLshort  y) {
    return ::glVertexAttrib2s(index, x, y);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib2sv(GLuint  index, GLshort *  v) {
    return ::glVertexAttrib2sv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib3d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z) {
    return ::glVertexAttrib3d(index, x, y, z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib3dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttrib3dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib3f(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  z) {
    return ::glVertexAttrib3f(index, x, y, z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib3fv(GLuint  index, GLfloat *  v) {
    return ::glVertexAttrib3fv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib3s(GLuint  index, GLshort  x, GLshort  y, GLshort  z) {
    return ::glVertexAttrib3s(index, x, y, z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib3sv(GLuint  index, GLshort *  v) {
    return ::glVertexAttrib3sv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4Nbv(GLuint  index, GLbyte *  v) {
    return ::glVertexAttrib4Nbv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4Niv(GLuint  index, GLint *  v) {
    return ::glVertexAttrib4Niv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4Nsv(GLuint  index, GLshort *  v) {
    return ::glVertexAttrib4Nsv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4Nub(GLuint  index, GLubyte  x, GLubyte  y, GLubyte  z, GLubyte  w) {
    return ::glVertexAttrib4Nub(index, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4Nubv(GLuint  index, GLubyte *  v) {
    return ::glVertexAttrib4Nubv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4Nuiv(GLuint  index, GLuint *  v) {
    return ::glVertexAttrib4Nuiv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4Nusv(GLuint  index, GLushort *  v) {
    return ::glVertexAttrib4Nusv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4bv(GLuint  index, GLbyte *  v) {
    return ::glVertexAttrib4bv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w) {
    return ::glVertexAttrib4d(index, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttrib4dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4f(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  z, GLfloat  w) {
    return ::glVertexAttrib4f(index, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4fv(GLuint  index, GLfloat *  v) {
    return ::glVertexAttrib4fv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4iv(GLuint  index, GLint *  v) {
    return ::glVertexAttrib4iv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4s(GLuint  index, GLshort  x, GLshort  y, GLshort  z, GLshort  w) {
    return ::glVertexAttrib4s(index, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4sv(GLuint  index, GLshort *  v) {
    return ::glVertexAttrib4sv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4ubv(GLuint  index, GLubyte *  v) {
    return ::glVertexAttrib4ubv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4uiv(GLuint  index, GLuint *  v) {
    return ::glVertexAttrib4uiv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttrib4usv(GLuint  index, GLushort *  v) {
    return ::glVertexAttrib4usv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribBinding(GLuint  attribindex, GLuint  bindingindex) {
    return ::glVertexAttribBinding(attribindex, bindingindex);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribDivisor(GLuint  index, GLuint  divisor) {
    return ::glVertexAttribDivisor(index, divisor);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribFormat(GLuint  attribindex, GLint  size, GLenum  type, GLboolean  normalized, GLuint  relativeoffset) {
    return ::glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI1i(GLuint  index, GLint  x) {
    return ::glVertexAttribI1i(index, x);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI1iv(GLuint  index, GLint *  v) {
    return ::glVertexAttribI1iv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI1ui(GLuint  index, GLuint  x) {
    return ::glVertexAttribI1ui(index, x);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI1uiv(GLuint  index, GLuint *  v) {
    return ::glVertexAttribI1uiv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI2i(GLuint  index, GLint  x, GLint  y) {
    return ::glVertexAttribI2i(index, x, y);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI2iv(GLuint  index, GLint *  v) {
    return ::glVertexAttribI2iv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI2ui(GLuint  index, GLuint  x, GLuint  y) {
    return ::glVertexAttribI2ui(index, x, y);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI2uiv(GLuint  index, GLuint *  v) {
    return ::glVertexAttribI2uiv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI3i(GLuint  index, GLint  x, GLint  y, GLint  z) {
    return ::glVertexAttribI3i(index, x, y, z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI3iv(GLuint  index, GLint *  v) {
    return ::glVertexAttribI3iv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI3ui(GLuint  index, GLuint  x, GLuint  y, GLuint  z) {
    return ::glVertexAttribI3ui(index, x, y, z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI3uiv(GLuint  index, GLuint *  v) {
    return ::glVertexAttribI3uiv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4bv(GLuint  index, GLbyte *  v) {
    return ::glVertexAttribI4bv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4i(GLuint  index, GLint  x, GLint  y, GLint  z, GLint  w) {
    return ::glVertexAttribI4i(index, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4iv(GLuint  index, GLint *  v) {
    return ::glVertexAttribI4iv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4sv(GLuint  index, GLshort *  v) {
    return ::glVertexAttribI4sv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4ubv(GLuint  index, GLubyte *  v) {
    return ::glVertexAttribI4ubv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4ui(GLuint  index, GLuint  x, GLuint  y, GLuint  z, GLuint  w) {
    return ::glVertexAttribI4ui(index, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4uiv(GLuint  index, GLuint *  v) {
    return ::glVertexAttribI4uiv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribI4usv(GLuint  index, GLushort *  v) {
    return ::glVertexAttribI4usv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribIFormat(GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
    return ::glVertexAttribIFormat(attribindex, size, type, relativeoffset);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribIPointer(GLuint  index, GLint  size, GLenum  type, GLsizei  stride, void *  pointer) {
    return ::glVertexAttribIPointer(index, size, type, stride, pointer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL1d(GLuint  index, GLdouble  x) {
    return ::glVertexAttribL1d(index, x);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL1dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttribL1dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL2d(GLuint  index, GLdouble  x, GLdouble  y) {
    return ::glVertexAttribL2d(index, x, y);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL2dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttribL2dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL3d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z) {
    return ::glVertexAttribL3d(index, x, y, z);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL3dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttribL3dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL4d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w) {
    return ::glVertexAttribL4d(index, x, y, z, w);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribL4dv(GLuint  index, GLdouble *  v) {
    return ::glVertexAttribL4dv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribLFormat(GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
    return ::glVertexAttribLFormat(attribindex, size, type, relativeoffset);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribLPointer(GLuint  index, GLint  size, GLenum  type, GLsizei  stride, void *  pointer) {
    return ::glVertexAttribLPointer(index, size, type, stride, pointer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP1ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
    return ::glVertexAttribP1ui(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP1uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value) {
    return ::glVertexAttribP1uiv(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP2ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
    return ::glVertexAttribP2ui(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP2uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value) {
    return ::glVertexAttribP2uiv(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP3ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
    return ::glVertexAttribP3ui(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP3uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value) {
    return ::glVertexAttribP3uiv(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP4ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
    return ::glVertexAttribP4ui(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribP4uiv(GLuint  index, GLenum  type, GLboolean  normalized, GLuint *  value) {
    return ::glVertexAttribP4uiv(index, type, normalized, value);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexAttribPointer(GLuint  index, GLint  size, GLenum  type, GLboolean  normalized, GLsizei  stride, void *  pointer) {
    return ::glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glVertexBindingDivisor(GLuint  bindingindex, GLuint  divisor) {
    return ::glVertexBindingDivisor(bindingindex, divisor);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glViewport(GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
    return ::glViewport(x, y, width, height);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glViewportArrayv(GLuint  first, GLsizei  count, GLfloat *  v) {
    return ::glViewportArrayv(first, count, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glViewportIndexedf(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  w, GLfloat  h) {
    return ::glViewportIndexedf(index, x, y, w, h);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glViewportIndexedfv(GLuint  index, GLfloat *  v) {
    return ::glViewportIndexedfv(index, v);
}
EXPORT_SSTD_QT_AND_QML_LIBRARY void  sstd::_sstd_glWaitSync(GLsync  sync, GLbitfield  flags, GLuint64  timeout) {
    return ::glWaitSync(sync, flags, timeout);
}






















