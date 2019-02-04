#pragma once

#include "../global/sstd_qt_and_qml_global.hpp"
#include <QtGui/qopenglfunctions.h>
#include <QtGui/qopenglfunctions_4_5_core.h>

/*EXPORT_SSTD_QT_AND_QML_LIBRARY*/
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

namespace sstd {


    inline void  glActiveShaderProgram(GLuint  pipeline, GLuint  program) {
        return sstd::_sstd_glActiveShaderProgram(pipeline, program);
    }
    inline void  glActiveTexture(GLenum  texture) {
        return sstd::_sstd_glActiveTexture(texture);
    }
    inline void  glAttachShader(GLuint  program, GLuint  shader) {
        return sstd::_sstd_glAttachShader(program, shader);
    }
    inline void  glBeginConditionalRender(GLuint  id, GLenum  mode) {
        return sstd::_sstd_glBeginConditionalRender(id, mode);
    }
    inline void  glBeginQuery(GLenum  target, GLuint  id) {
        return sstd::_sstd_glBeginQuery(target, id);
    }
    inline void  glBeginQueryIndexed(GLenum  target, GLuint  index, GLuint  id) {
        return sstd::_sstd_glBeginQueryIndexed(target, index, id);
    }
    inline void  glBeginTransformFeedback(GLenum  primitiveMode) {
        return sstd::_sstd_glBeginTransformFeedback(primitiveMode);
    }
    inline void  glBindAttribLocation(GLuint  program, GLuint  index, const GLchar *  name) {
        return sstd::_sstd_glBindAttribLocation(program, index, const_cast<GLchar *>(name));
    }
    inline void  glBindBuffer(GLenum  target, GLuint  buffer) {
        return sstd::_sstd_glBindBuffer(target, buffer);
    }
    inline void  glBindBufferBase(GLenum  target, GLuint  index, GLuint  buffer) {
        return sstd::_sstd_glBindBufferBase(target, index, buffer);
    }
    inline void  glBindBufferRange(GLenum  target, GLuint  index, GLuint  buffer, GLintptr  offset, GLsizeiptr  size) {
        return sstd::_sstd_glBindBufferRange(target, index, buffer, offset, size);
    }
    inline void  glBindBuffersBase(GLenum  target, GLuint  first, GLsizei  count, const GLuint *  buffers) {
        return sstd::_sstd_glBindBuffersBase(target, first, count, const_cast<GLuint *>(buffers));
    }
    inline void  glBindBuffersRange(GLenum  target, GLuint  first, GLsizei  count, const GLuint *  buffers, const GLintptr *  offsets, const GLsizeiptr *  sizes) {
        return sstd::_sstd_glBindBuffersRange(target, first, count, const_cast<GLuint *>(buffers), const_cast<GLintptr *>(offsets), const_cast<GLsizeiptr *>(sizes));
    }
    inline void  glBindFragDataLocation(GLuint  program, GLuint  color, const GLchar *  name) {
        return sstd::_sstd_glBindFragDataLocation(program, color, const_cast<GLchar *>(name));
    }
    inline void  glBindFragDataLocationIndexed(GLuint  program, GLuint  colorNumber, GLuint  index, const GLchar *  name) {
        return sstd::_sstd_glBindFragDataLocationIndexed(program, colorNumber, index, const_cast<GLchar *>(name));
    }
    inline void  glBindFramebuffer(GLenum  target, GLuint  framebuffer) {
        return sstd::_sstd_glBindFramebuffer(target, framebuffer);
    }
    inline void  glBindImageTexture(GLuint  unit, GLuint  texture, GLint  level, GLboolean  layered, GLint  layer, GLenum  access, GLenum  format) {
        return sstd::_sstd_glBindImageTexture(unit, texture, level, layered, layer, access, format);
    }
    inline void  glBindImageTextures(GLuint  first, GLsizei  count, const GLuint *  textures) {
        return sstd::_sstd_glBindImageTextures(first, count, const_cast<GLuint *>(textures));
    }
    inline void  glBindProgramPipeline(GLuint  pipeline) {
        return sstd::_sstd_glBindProgramPipeline(pipeline);
    }
    inline void  glBindRenderbuffer(GLenum  target, GLuint  renderbuffer) {
        return sstd::_sstd_glBindRenderbuffer(target, renderbuffer);
    }
    inline void  glBindSampler(GLuint  unit, GLuint  sampler) {
        return sstd::_sstd_glBindSampler(unit, sampler);
    }
    inline void  glBindSamplers(GLuint  first, GLsizei  count, const GLuint *  samplers) {
        return sstd::_sstd_glBindSamplers(first, count, const_cast<GLuint *>(samplers));
    }
    inline void  glBindTexture(GLenum  target, GLuint  texture) {
        return sstd::_sstd_glBindTexture(target, texture);
    }
    inline void  glBindTextureUnit(GLuint  unit, GLuint  texture) {
        return sstd::_sstd_glBindTextureUnit(unit, texture);
    }
    inline void  glBindTextures(GLuint  first, GLsizei  count, const GLuint *  textures) {
        return sstd::_sstd_glBindTextures(first, count, const_cast<GLuint *>(textures));
    }
    inline void  glBindTransformFeedback(GLenum  target, GLuint  id) {
        return sstd::_sstd_glBindTransformFeedback(target, id);
    }
    inline void  glBindVertexArray(GLuint  array) {
        return sstd::_sstd_glBindVertexArray(array);
    }
    inline void  glBindVertexBuffer(GLuint  bindingindex, GLuint  buffer, GLintptr  offset, GLsizei  stride) {
        return sstd::_sstd_glBindVertexBuffer(bindingindex, buffer, offset, stride);
    }
    inline void  glBindVertexBuffers(GLuint  first, GLsizei  count, const GLuint *  buffers, const GLintptr *  offsets, const GLsizei *  strides) {
        return sstd::_sstd_glBindVertexBuffers(first, count, const_cast<GLuint *>(buffers), const_cast<GLintptr *>(offsets), const_cast<GLsizei *>(strides));
    }
    inline void  glBlendColor(GLfloat  red, GLfloat  green, GLfloat  blue, GLfloat  alpha) {
        return sstd::_sstd_glBlendColor(red, green, blue, alpha);
    }
    inline void  glBlendEquation(GLenum  mode) {
        return sstd::_sstd_glBlendEquation(mode);
    }
    inline void  glBlendEquationSeparate(GLenum  modeRGB, GLenum  modeAlpha) {
        return sstd::_sstd_glBlendEquationSeparate(modeRGB, modeAlpha);
    }
    inline void  glBlendEquationSeparatei(GLuint  buf, GLenum  modeRGB, GLenum  modeAlpha) {
        return sstd::_sstd_glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
    }
    inline void  glBlendEquationi(GLuint  buf, GLenum  mode) {
        return sstd::_sstd_glBlendEquationi(buf, mode);
    }
    inline void  glBlendFunc(GLenum  sfactor, GLenum  dfactor) {
        return sstd::_sstd_glBlendFunc(sfactor, dfactor);
    }
    inline void  glBlendFuncSeparate(GLenum  sfactorRGB, GLenum  dfactorRGB, GLenum  sfactorAlpha, GLenum  dfactorAlpha) {
        return sstd::_sstd_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    }
    inline void  glBlendFuncSeparatei(GLuint  buf, GLenum  srcRGB, GLenum  dstRGB, GLenum  srcAlpha, GLenum  dstAlpha) {
        return sstd::_sstd_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
    }
    inline void  glBlendFunci(GLuint  buf, GLenum  src, GLenum  dst) {
        return sstd::_sstd_glBlendFunci(buf, src, dst);
    }
    inline void  glBlitFramebuffer(GLint  srcX0, GLint  srcY0, GLint  srcX1, GLint  srcY1, GLint  dstX0, GLint  dstY0, GLint  dstX1, GLint  dstY1, GLbitfield  mask, GLenum  filter) {
        return sstd::_sstd_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
    }
    inline void  glBlitNamedFramebuffer(GLuint  readFramebuffer, GLuint  drawFramebuffer, GLint  srcX0, GLint  srcY0, GLint  srcX1, GLint  srcY1, GLint  dstX0, GLint  dstY0, GLint  dstX1, GLint  dstY1, GLbitfield  mask, GLenum  filter) {
        return sstd::_sstd_glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
    }
    inline void  glBufferData(GLenum  target, GLsizeiptr  size, const void *  data, GLenum  usage) {
        return sstd::_sstd_glBufferData(target, size, const_cast<void *>(data), usage);
    }
    inline void  glBufferStorage(GLenum  target, GLsizeiptr  size, const void *  data, GLbitfield  flags) {
        return sstd::_sstd_glBufferStorage(target, size, const_cast<void *>(data), flags);
    }
    inline void  glBufferSubData(GLenum  target, GLintptr  offset, GLsizeiptr  size, const void *  data) {
        return sstd::_sstd_glBufferSubData(target, offset, size, const_cast<void *>(data));
    }
    inline GLenum  glCheckFramebufferStatus(GLenum  target) {
        return sstd::_sstd_glCheckFramebufferStatus(target);
    }
    inline GLenum  glCheckNamedFramebufferStatus(GLuint  framebuffer, GLenum  target) {
        return sstd::_sstd_glCheckNamedFramebufferStatus(framebuffer, target);
    }
    inline void  glClampColor(GLenum  target, GLenum  clamp) {
        return sstd::_sstd_glClampColor(target, clamp);
    }
    inline void  glClear(GLbitfield  mask) {
        return sstd::_sstd_glClear(mask);
    }
    inline void  glClearBufferData(GLenum  target, GLenum  internalformat, GLenum  format, GLenum  type, const void *  data) {
        return sstd::_sstd_glClearBufferData(target, internalformat, format, type, const_cast<void *>(data));
    }
    inline void  glClearBufferSubData(GLenum  target, GLenum  internalformat, GLintptr  offset, GLsizeiptr  size, GLenum  format, GLenum  type, const void *  data) {
        return sstd::_sstd_glClearBufferSubData(target, internalformat, offset, size, format, type, const_cast<void *>(data));
    }
    inline void  glClearBufferfi(GLenum  buffer, GLint  drawbuffer, GLfloat  depth, GLint  stencil) {
        return sstd::_sstd_glClearBufferfi(buffer, drawbuffer, depth, stencil);
    }
    inline void  glClearBufferfv(GLenum  buffer, GLint  drawbuffer, const GLfloat *  value) {
        return sstd::_sstd_glClearBufferfv(buffer, drawbuffer, const_cast<GLfloat *>(value));
    }
    inline void  glClearBufferiv(GLenum  buffer, GLint  drawbuffer, const GLint *  value) {
        return sstd::_sstd_glClearBufferiv(buffer, drawbuffer, const_cast<GLint *>(value));
    }
    inline void  glClearBufferuiv(GLenum  buffer, GLint  drawbuffer, const GLuint *  value) {
        return sstd::_sstd_glClearBufferuiv(buffer, drawbuffer, const_cast<GLuint *>(value));
    }
    inline void  glClearColor(GLfloat  red, GLfloat  green, GLfloat  blue, GLfloat  alpha) {
        return sstd::_sstd_glClearColor(red, green, blue, alpha);
    }
    inline void  glClearDepth(GLdouble  depth) {
        return sstd::_sstd_glClearDepth(depth);
    }
    inline void  glClearDepthf(GLfloat  dd) {
        return sstd::_sstd_glClearDepthf(dd);
    }
    inline void  glClearNamedBufferData(GLuint  buffer, GLenum  internalformat, GLenum  format, GLenum  type, const void *  data) {
        return sstd::_sstd_glClearNamedBufferData(buffer, internalformat, format, type, const_cast<void *>(data));
    }
    inline void  glClearNamedBufferSubData(GLuint  buffer, GLenum  internalformat, GLintptr  offset, GLsizei  size, GLenum  format, GLenum  type, const void *  data) {
        return sstd::_sstd_glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, const_cast<void *>(data));
    }
    inline void  glClearNamedFramebufferfi(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, GLfloat  depth, GLint  stencil) {
        return sstd::_sstd_glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil);
    }
    inline void  glClearNamedFramebufferfv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, const GLfloat *  value) {
        return sstd::_sstd_glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, const_cast<GLfloat *>(value));
    }
    inline void  glClearNamedFramebufferiv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, const GLint *  value) {
        return sstd::_sstd_glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, const_cast<GLint *>(value));
    }
    inline void  glClearNamedFramebufferuiv(GLuint  framebuffer, GLenum  buffer, GLint  drawbuffer, const GLuint *  value) {
        return sstd::_sstd_glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, const_cast<GLuint *>(value));
    }
    inline void  glClearStencil(GLint  s) {
        return sstd::_sstd_glClearStencil(s);
    }
    inline void  glClearTexImage(GLuint  texture, GLint  level, GLenum  format, GLenum  type, const void *  data) {
        return sstd::_sstd_glClearTexImage(texture, level, format, type, const_cast<void *>(data));
    }
    inline void  glClearTexSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, const void *  data) {
        return sstd::_sstd_glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, const_cast<void *>(data));
    }
    inline GLenum  glClientWaitSync(GLsync  sync, GLbitfield  flags, GLuint64  timeout) {
        return sstd::_sstd_glClientWaitSync(sync, flags, timeout);
    }
    inline void  glClipControl(GLenum  origin, GLenum  depth) {
        return sstd::_sstd_glClipControl(origin, depth);
    }
    inline void  glColorMask(GLboolean  red, GLboolean  green, GLboolean  blue, GLboolean  alpha) {
        return sstd::_sstd_glColorMask(red, green, blue, alpha);
    }
    inline void  glColorMaski(GLuint  index, GLboolean  r, GLboolean  g, GLboolean  b, GLboolean  a) {
        return sstd::_sstd_glColorMaski(index, r, g, b, a);
    }
    inline void  glCompileShader(GLuint  shader) {
        return sstd::_sstd_glCompileShader(shader);
    }
    inline void  glCompressedTexImage1D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLint  border, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTexImage2D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLsizei  height, GLint  border, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTexImage3D(GLenum  target, GLint  level, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLint  border, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, const_cast<void *>(data));
    }
    inline void  glCompressedTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLsizei  imageSize, const void *  data) {
        return sstd::_sstd_glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, const_cast<void *>(data));
    }
    inline void  glCopyBufferSubData(GLenum  readTarget, GLenum  writeTarget, GLintptr  readOffset, GLintptr  writeOffset, GLsizeiptr  size) {
        return sstd::_sstd_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
    }
    inline void  glCopyImageSubData(GLuint  srcName, GLenum  srcTarget, GLint  srcLevel, GLint  srcX, GLint  srcY, GLint  srcZ, GLuint  dstName, GLenum  dstTarget, GLint  dstLevel, GLint  dstX, GLint  dstY, GLint  dstZ, GLsizei  srcWidth, GLsizei  srcHeight, GLsizei  srcDepth) {
        return sstd::_sstd_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
    }
    inline void  glCopyNamedBufferSubData(GLuint  readBuffer, GLuint  writeBuffer, GLintptr  readOffset, GLintptr  writeOffset, GLsizei  size) {
        return sstd::_sstd_glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
    }
    inline void  glCopyTexImage1D(GLenum  target, GLint  level, GLenum  internalformat, GLint  x, GLint  y, GLsizei  width, GLint  border) {
        return sstd::_sstd_glCopyTexImage1D(target, level, internalformat, x, y, width, border);
    }
    inline void  glCopyTexImage2D(GLenum  target, GLint  level, GLenum  internalformat, GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLint  border) {
        return sstd::_sstd_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
    }
    inline void  glCopyTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLint  x, GLint  y, GLsizei  width) {
        return sstd::_sstd_glCopyTexSubImage1D(target, level, xoffset, x, y, width);
    }
    inline void  glCopyTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    }
    inline void  glCopyTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
    }
    inline void  glCopyTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLint  x, GLint  y, GLsizei  width) {
        return sstd::_sstd_glCopyTextureSubImage1D(texture, level, xoffset, x, y, width);
    }
    inline void  glCopyTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height);
    }
    inline void  glCopyTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
    }
    inline void  glCreateBuffers(GLsizei  n, GLuint *  buffers) {
        return sstd::_sstd_glCreateBuffers(n, buffers);
    }
    inline void  glCreateFramebuffers(GLsizei  n, GLuint *  framebuffers) {
        return sstd::_sstd_glCreateFramebuffers(n, framebuffers);
    }
    inline GLuint  glCreateProgram() {
        return sstd::_sstd_glCreateProgram();
    }
    inline void  glCreateProgramPipelines(GLsizei  n, GLuint *  pipelines) {
        return sstd::_sstd_glCreateProgramPipelines(n, pipelines);
    }
    inline void  glCreateQueries(GLenum  target, GLsizei  n, GLuint *  ids) {
        return sstd::_sstd_glCreateQueries(target, n, ids);
    }
    inline void  glCreateRenderbuffers(GLsizei  n, GLuint *  renderbuffers) {
        return sstd::_sstd_glCreateRenderbuffers(n, renderbuffers);
    }
    inline void  glCreateSamplers(GLsizei  n, GLuint *  samplers) {
        return sstd::_sstd_glCreateSamplers(n, samplers);
    }
    inline GLuint  glCreateShader(GLenum  type) {
        return sstd::_sstd_glCreateShader(type);
    }
    inline GLuint  glCreateShaderProgramv(GLenum  type, GLsizei  count, const GLchar * const *  strings) {
        return sstd::_sstd_glCreateShaderProgramv(type, count, const_cast<GLchar * *>(strings));
    }
    inline void  glCreateTextures(GLenum  target, GLsizei  n, GLuint *  textures) {
        return sstd::_sstd_glCreateTextures(target, n, textures);
    }
    inline void  glCreateTransformFeedbacks(GLsizei  n, GLuint *  ids) {
        return sstd::_sstd_glCreateTransformFeedbacks(n, ids);
    }
    inline void  glCreateVertexArrays(GLsizei  n, GLuint *  arrays) {
        return sstd::_sstd_glCreateVertexArrays(n, arrays);
    }
    inline void  glCullFace(GLenum  mode) {
        return sstd::_sstd_glCullFace(mode);
    }
    inline void  glDebugMessageCallback(GLDEBUGPROC  callback, const void *  userParam) {
        return sstd::_sstd_glDebugMessageCallback(callback, const_cast<void *>(userParam));
    }
    inline void  glDebugMessageControl(GLenum  source, GLenum  type, GLenum  severity, GLsizei  count, const GLuint *  ids, GLboolean  enabled) {
        return sstd::_sstd_glDebugMessageControl(source, type, severity, count, const_cast<GLuint *>(ids), enabled);
    }
    inline void  glDebugMessageInsert(GLenum  source, GLenum  type, GLuint  id, GLenum  severity, GLsizei  length, const GLchar *  buf) {
        return sstd::_sstd_glDebugMessageInsert(source, type, id, severity, length, const_cast<GLchar *>(buf));
    }
    inline void  glDeleteBuffers(GLsizei  n, const GLuint *  buffers) {
        return sstd::_sstd_glDeleteBuffers(n, const_cast<GLuint *>(buffers));
    }
    inline void  glDeleteFramebuffers(GLsizei  n, const GLuint *  framebuffers) {
        return sstd::_sstd_glDeleteFramebuffers(n, const_cast<GLuint *>(framebuffers));
    }
    inline void  glDeleteProgram(GLuint  program) {
        return sstd::_sstd_glDeleteProgram(program);
    }
    inline void  glDeleteProgramPipelines(GLsizei  n, const GLuint *  pipelines) {
        return sstd::_sstd_glDeleteProgramPipelines(n, const_cast<GLuint *>(pipelines));
    }
    inline void  glDeleteQueries(GLsizei  n, const GLuint *  ids) {
        return sstd::_sstd_glDeleteQueries(n, const_cast<GLuint *>(ids));
    }
    inline void  glDeleteRenderbuffers(GLsizei  n, const GLuint *  renderbuffers) {
        return sstd::_sstd_glDeleteRenderbuffers(n, const_cast<GLuint *>(renderbuffers));
    }
    inline void  glDeleteSamplers(GLsizei  count, const GLuint *  samplers) {
        return sstd::_sstd_glDeleteSamplers(count, const_cast<GLuint *>(samplers));
    }
    inline void  glDeleteShader(GLuint  shader) {
        return sstd::_sstd_glDeleteShader(shader);
    }
    inline void  glDeleteSync(GLsync  sync) {
        return sstd::_sstd_glDeleteSync(sync);
    }
    inline void  glDeleteTextures(GLsizei  n, const GLuint *  textures) {
        return sstd::_sstd_glDeleteTextures(n, const_cast<GLuint *>(textures));
    }
    inline void  glDeleteTransformFeedbacks(GLsizei  n, const GLuint *  ids) {
        return sstd::_sstd_glDeleteTransformFeedbacks(n, const_cast<GLuint *>(ids));
    }
    inline void  glDeleteVertexArrays(GLsizei  n, const GLuint *  arrays) {
        return sstd::_sstd_glDeleteVertexArrays(n, const_cast<GLuint *>(arrays));
    }
    inline void  glDepthFunc(GLenum  func) {
        return sstd::_sstd_glDepthFunc(func);
    }
    inline void  glDepthMask(GLboolean  flag) {
        return sstd::_sstd_glDepthMask(flag);
    }
    inline void  glDepthRange(GLdouble  nearVal, GLdouble  farVal) {
        return sstd::_sstd_glDepthRange(nearVal, farVal);
    }
    inline void  glDepthRangeArrayv(GLuint  first, GLsizei  count, const GLdouble *  v) {
        return sstd::_sstd_glDepthRangeArrayv(first, count, const_cast<GLdouble *>(v));
    }
    inline void  glDepthRangeIndexed(GLuint  index, GLdouble  n, GLdouble  f) {
        return sstd::_sstd_glDepthRangeIndexed(index, n, f);
    }
    inline void  glDepthRangef(GLfloat  n, GLfloat  f) {
        return sstd::_sstd_glDepthRangef(n, f);
    }
    inline void  glDetachShader(GLuint  program, GLuint  shader) {
        return sstd::_sstd_glDetachShader(program, shader);
    }
    inline void  glDisable(GLenum  cap) {
        return sstd::_sstd_glDisable(cap);
    }
    inline void  glDisableVertexArrayAttrib(GLuint  vaobj, GLuint  index) {
        return sstd::_sstd_glDisableVertexArrayAttrib(vaobj, index);
    }
    inline void  glDisableVertexAttribArray(GLuint  index) {
        return sstd::_sstd_glDisableVertexAttribArray(index);
    }
    inline void  glDisablei(GLenum  target, GLuint  index) {
        return sstd::_sstd_glDisablei(target, index);
    }
    inline void  glDispatchCompute(GLuint  num_groups_x, GLuint  num_groups_y, GLuint  num_groups_z) {
        return sstd::_sstd_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
    }
    inline void  glDispatchComputeIndirect(GLintptr  indirect) {
        return sstd::_sstd_glDispatchComputeIndirect(indirect);
    }
    inline void  glDrawArrays(GLenum  mode, GLint  first, GLsizei  count) {
        return sstd::_sstd_glDrawArrays(mode, first, count);
    }
    inline void  glDrawArraysIndirect(GLenum  mode, const void *  indirect) {
        return sstd::_sstd_glDrawArraysIndirect(mode, const_cast<void *>(indirect));
    }
    inline void  glDrawArraysInstanced(GLenum  mode, GLint  first, GLsizei  count, GLsizei  instancecount) {
        return sstd::_sstd_glDrawArraysInstanced(mode, first, count, instancecount);
    }
    inline void  glDrawArraysInstancedBaseInstance(GLenum  mode, GLint  first, GLsizei  count, GLsizei  instancecount, GLuint  baseinstance) {
        return sstd::_sstd_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
    }
    inline void  glDrawBuffer(GLenum  buf) {
        return sstd::_sstd_glDrawBuffer(buf);
    }
    inline void  glDrawBuffers(GLsizei  n, const GLenum *  bufs) {
        return sstd::_sstd_glDrawBuffers(n, const_cast<GLenum *>(bufs));
    }
    inline void  glDrawElements(GLenum  mode, GLsizei  count, GLenum  type, const void *  indices) {
        return sstd::_sstd_glDrawElements(mode, count, type, const_cast<void *>(indices));
    }
    inline void  glDrawElementsBaseVertex(GLenum  mode, GLsizei  count, GLenum  type, const void *  indices, GLint  basevertex) {
        return sstd::_sstd_glDrawElementsBaseVertex(mode, count, type, const_cast<void *>(indices), basevertex);
    }
    inline void  glDrawElementsIndirect(GLenum  mode, GLenum  type, const void *  indirect) {
        return sstd::_sstd_glDrawElementsIndirect(mode, type, const_cast<void *>(indirect));
    }
    inline void  glDrawElementsInstanced(GLenum  mode, GLsizei  count, GLenum  type, const void *  indices, GLsizei  instancecount) {
        return sstd::_sstd_glDrawElementsInstanced(mode, count, type, const_cast<void *>(indices), instancecount);
    }
    inline void  glDrawElementsInstancedBaseInstance(GLenum  mode, GLsizei  count, GLenum  type, const void *  indices, GLsizei  instancecount, GLuint  baseinstance) {
        return sstd::_sstd_glDrawElementsInstancedBaseInstance(mode, count, type, const_cast<void *>(indices), instancecount, baseinstance);
    }
    inline void  glDrawElementsInstancedBaseVertex(GLenum  mode, GLsizei  count, GLenum  type, const void *  indices, GLsizei  instancecount, GLint  basevertex) {
        return sstd::_sstd_glDrawElementsInstancedBaseVertex(mode, count, type, const_cast<void *>(indices), instancecount, basevertex);
    }
    inline void  glDrawElementsInstancedBaseVertexBaseInstance(GLenum  mode, GLsizei  count, GLenum  type, const void *  indices, GLsizei  instancecount, GLint  basevertex, GLuint  baseinstance) {
        return sstd::_sstd_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, const_cast<void *>(indices), instancecount, basevertex, baseinstance);
    }
    inline void  glDrawRangeElements(GLenum  mode, GLuint  start, GLuint  end, GLsizei  count, GLenum  type, const void *  indices) {
        return sstd::_sstd_glDrawRangeElements(mode, start, end, count, type, const_cast<void *>(indices));
    }
    inline void  glDrawRangeElementsBaseVertex(GLenum  mode, GLuint  start, GLuint  end, GLsizei  count, GLenum  type, const void *  indices, GLint  basevertex) {
        return sstd::_sstd_glDrawRangeElementsBaseVertex(mode, start, end, count, type, const_cast<void *>(indices), basevertex);
    }
    inline void  glDrawTransformFeedback(GLenum  mode, GLuint  id) {
        return sstd::_sstd_glDrawTransformFeedback(mode, id);
    }
    inline void  glDrawTransformFeedbackInstanced(GLenum  mode, GLuint  id, GLsizei  instancecount) {
        return sstd::_sstd_glDrawTransformFeedbackInstanced(mode, id, instancecount);
    }
    inline void  glDrawTransformFeedbackStream(GLenum  mode, GLuint  id, GLuint  stream) {
        return sstd::_sstd_glDrawTransformFeedbackStream(mode, id, stream);
    }
    inline void  glDrawTransformFeedbackStreamInstanced(GLenum  mode, GLuint  id, GLuint  stream, GLsizei  instancecount) {
        return sstd::_sstd_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
    }
    inline void  glEnable(GLenum  cap) {
        return sstd::_sstd_glEnable(cap);
    }
    inline void  glEnableVertexArrayAttrib(GLuint  vaobj, GLuint  index) {
        return sstd::_sstd_glEnableVertexArrayAttrib(vaobj, index);
    }
    inline void  glEnableVertexAttribArray(GLuint  index) {
        return sstd::_sstd_glEnableVertexAttribArray(index);
    }
    inline void  glEnablei(GLenum  target, GLuint  index) {
        return sstd::_sstd_glEnablei(target, index);
    }
    inline void  glEndConditionalRender() {
        return sstd::_sstd_glEndConditionalRender();
    }
    inline void  glEndQuery(GLenum  target) {
        return sstd::_sstd_glEndQuery(target);
    }
    inline void  glEndQueryIndexed(GLenum  target, GLuint  index) {
        return sstd::_sstd_glEndQueryIndexed(target, index);
    }
    inline void  glEndTransformFeedback() {
        return sstd::_sstd_glEndTransformFeedback();
    }
    inline GLsync  glFenceSync(GLenum  condition, GLbitfield  flags) {
        return sstd::_sstd_glFenceSync(condition, flags);
    }
    inline void  glFinish() {
        return sstd::_sstd_glFinish();
    }
    inline void  glFlush() {
        return sstd::_sstd_glFlush();
    }
    inline void  glFlushMappedBufferRange(GLenum  target, GLintptr  offset, GLsizeiptr  length) {
        return sstd::_sstd_glFlushMappedBufferRange(target, offset, length);
    }
    inline void  glFlushMappedNamedBufferRange(GLuint  buffer, GLintptr  offset, GLsizei  length) {
        return sstd::_sstd_glFlushMappedNamedBufferRange(buffer, offset, length);
    }
    inline void  glFramebufferParameteri(GLenum  target, GLenum  pname, GLint  param) {
        return sstd::_sstd_glFramebufferParameteri(target, pname, param);
    }
    inline void  glFramebufferRenderbuffer(GLenum  target, GLenum  attachment, GLenum  renderbuffertarget, GLuint  renderbuffer) {
        return sstd::_sstd_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    }
    inline void  glFramebufferTexture(GLenum  target, GLenum  attachment, GLuint  texture, GLint  level) {
        return sstd::_sstd_glFramebufferTexture(target, attachment, texture, level);
    }
    inline void  glFramebufferTexture1D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level) {
        return sstd::_sstd_glFramebufferTexture1D(target, attachment, textarget, texture, level);
    }
    inline void  glFramebufferTexture2D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level) {
        return sstd::_sstd_glFramebufferTexture2D(target, attachment, textarget, texture, level);
    }
    inline void  glFramebufferTexture3D(GLenum  target, GLenum  attachment, GLenum  textarget, GLuint  texture, GLint  level, GLint  zoffset) {
        return sstd::_sstd_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
    }
    inline void  glFramebufferTextureLayer(GLenum  target, GLenum  attachment, GLuint  texture, GLint  level, GLint  layer) {
        return sstd::_sstd_glFramebufferTextureLayer(target, attachment, texture, level, layer);
    }
    inline void  glFrontFace(GLenum  mode) {
        return sstd::_sstd_glFrontFace(mode);
    }
    inline void  glGenBuffers(GLsizei  n, GLuint *  buffers) {
        return sstd::_sstd_glGenBuffers(n, buffers);
    }
    inline void  glGenFramebuffers(GLsizei  n, GLuint *  framebuffers) {
        return sstd::_sstd_glGenFramebuffers(n, framebuffers);
    }
    inline void  glGenProgramPipelines(GLsizei  n, GLuint *  pipelines) {
        return sstd::_sstd_glGenProgramPipelines(n, pipelines);
    }
    inline void  glGenQueries(GLsizei  n, GLuint *  ids) {
        return sstd::_sstd_glGenQueries(n, ids);
    }
    inline void  glGenRenderbuffers(GLsizei  n, GLuint *  renderbuffers) {
        return sstd::_sstd_glGenRenderbuffers(n, renderbuffers);
    }
    inline void  glGenSamplers(GLsizei  count, GLuint *  samplers) {
        return sstd::_sstd_glGenSamplers(count, samplers);
    }
    inline void  glGenTextures(GLsizei  n, GLuint *  textures) {
        return sstd::_sstd_glGenTextures(n, textures);
    }
    inline void  glGenTransformFeedbacks(GLsizei  n, GLuint *  ids) {
        return sstd::_sstd_glGenTransformFeedbacks(n, ids);
    }
    inline void  glGenVertexArrays(GLsizei  n, GLuint *  arrays) {
        return sstd::_sstd_glGenVertexArrays(n, arrays);
    }
    inline void  glGenerateMipmap(GLenum  target) {
        return sstd::_sstd_glGenerateMipmap(target);
    }
    inline void  glGenerateTextureMipmap(GLuint  texture) {
        return sstd::_sstd_glGenerateTextureMipmap(texture);
    }
    inline void  glGetActiveAtomicCounterBufferiv(GLuint  program, GLuint  bufferIndex, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params);
    }
    inline void  glGetActiveAttrib(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLint *  size, GLenum *  type, GLchar *  name) {
        return sstd::_sstd_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
    }
    inline void  glGetActiveSubroutineName(GLuint  program, GLenum  shadertype, GLuint  index, GLsizei  bufsize, GLsizei *  length, GLchar *  name) {
        return sstd::_sstd_glGetActiveSubroutineName(program, shadertype, index, bufsize, length, name);
    }
    inline void  glGetActiveSubroutineUniformName(GLuint  program, GLenum  shadertype, GLuint  index, GLsizei  bufsize, GLsizei *  length, GLchar *  name) {
        return sstd::_sstd_glGetActiveSubroutineUniformName(program, shadertype, index, bufsize, length, name);
    }
    inline void  glGetActiveSubroutineUniformiv(GLuint  program, GLenum  shadertype, GLuint  index, GLenum  pname, GLint *  values) {
        return sstd::_sstd_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values);
    }
    inline void  glGetActiveUniform(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLint *  size, GLenum *  type, GLchar *  name) {
        return sstd::_sstd_glGetActiveUniform(program, index, bufSize, length, size, type, name);
    }
    inline void  glGetActiveUniformBlockName(GLuint  program, GLuint  uniformBlockIndex, GLsizei  bufSize, GLsizei *  length, GLchar *  uniformBlockName) {
        return sstd::_sstd_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
    }
    inline void  glGetActiveUniformBlockiv(GLuint  program, GLuint  uniformBlockIndex, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
    }
    inline void  glGetActiveUniformName(GLuint  program, GLuint  uniformIndex, GLsizei  bufSize, GLsizei *  length, GLchar *  uniformName) {
        return sstd::_sstd_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
    }
    inline void  glGetActiveUniformsiv(GLuint  program, GLsizei  uniformCount, const GLuint *  uniformIndices, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetActiveUniformsiv(program, uniformCount, const_cast<GLuint *>(uniformIndices), pname, params);
    }
    inline void  glGetAttachedShaders(GLuint  program, GLsizei  maxCount, GLsizei *  count, GLuint *  shaders) {
        return sstd::_sstd_glGetAttachedShaders(program, maxCount, count, shaders);
    }
    inline GLint  glGetAttribLocation(GLuint  program, const GLchar *  name) {
        return sstd::_sstd_glGetAttribLocation(program, const_cast<GLchar *>(name));
    }
    inline void  glGetBooleani_v(GLenum  target, GLuint  index, GLboolean *  data) {
        return sstd::_sstd_glGetBooleani_v(target, index, data);
    }
    inline void  glGetBooleanv(GLenum  pname, GLboolean *  data) {
        return sstd::_sstd_glGetBooleanv(pname, data);
    }
    inline void  glGetBufferParameteri64v(GLenum  target, GLenum  pname, GLint64 *  params) {
        return sstd::_sstd_glGetBufferParameteri64v(target, pname, params);
    }
    inline void  glGetBufferParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetBufferParameteriv(target, pname, params);
    }
    inline void  glGetBufferPointerv(GLenum  target, GLenum  pname, void * *  params) {
        return sstd::_sstd_glGetBufferPointerv(target, pname, params);
    }
    inline void  glGetBufferSubData(GLenum  target, GLintptr  offset, GLsizeiptr  size, void *  data) {
        return sstd::_sstd_glGetBufferSubData(target, offset, size, data);
    }
    inline void  glGetCompressedTexImage(GLenum  target, GLint  level, void *  img) {
        return sstd::_sstd_glGetCompressedTexImage(target, level, img);
    }
    inline void  glGetCompressedTextureImage(GLuint  texture, GLint  level, GLsizei  bufSize, void *  pixels) {
        return sstd::_sstd_glGetCompressedTextureImage(texture, level, bufSize, pixels);
    }
    inline void  glGetCompressedTextureSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLsizei  bufSize, void *  pixels) {
        return sstd::_sstd_glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
    }
    inline GLuint  glGetDebugMessageLog(GLuint  count, GLsizei  bufSize, GLenum *  sources, GLenum *  types, GLuint *  ids, GLenum *  severities, GLsizei *  lengths, GLchar *  messageLog) {
        return sstd::_sstd_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
    }
    inline void  glGetDoublei_v(GLenum  target, GLuint  index, GLdouble *  data) {
        return sstd::_sstd_glGetDoublei_v(target, index, data);
    }
    inline void  glGetDoublev(GLenum  pname, GLdouble *  data) {
        return sstd::_sstd_glGetDoublev(pname, data);
    }
    inline GLenum  glGetError() {
        return sstd::_sstd_glGetError();
    }
    inline void  glGetFloati_v(GLenum  target, GLuint  index, GLfloat *  data) {
        return sstd::_sstd_glGetFloati_v(target, index, data);
    }
    inline void  glGetFloatv(GLenum  pname, GLfloat *  data) {
        return sstd::_sstd_glGetFloatv(pname, data);
    }
    inline GLint  glGetFragDataIndex(GLuint  program, const GLchar *  name) {
        return sstd::_sstd_glGetFragDataIndex(program, const_cast<GLchar *>(name));
    }
    inline GLint  glGetFragDataLocation(GLuint  program, const GLchar *  name) {
        return sstd::_sstd_glGetFragDataLocation(program, const_cast<GLchar *>(name));
    }
    inline void  glGetFramebufferAttachmentParameteriv(GLenum  target, GLenum  attachment, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
    }
    inline void  glGetFramebufferParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetFramebufferParameteriv(target, pname, params);
    }
    inline GLenum  glGetGraphicsResetStatus() {
        return sstd::_sstd_glGetGraphicsResetStatus();
    }
    inline void  glGetInteger64i_v(GLenum  target, GLuint  index, GLint64 *  data) {
        return sstd::_sstd_glGetInteger64i_v(target, index, data);
    }
    inline void  glGetInteger64v(GLenum  pname, GLint64 *  data) {
        return sstd::_sstd_glGetInteger64v(pname, data);
    }
    inline void  glGetIntegeri_v(GLenum  target, GLuint  index, GLint *  data) {
        return sstd::_sstd_glGetIntegeri_v(target, index, data);
    }
    inline void  glGetIntegerv(GLenum  pname, GLint *  data) {
        return sstd::_sstd_glGetIntegerv(pname, data);
    }
    inline void  glGetInternalformati64v(GLenum  target, GLenum  internalformat, GLenum  pname, GLsizei  bufSize, GLint64 *  params) {
        return sstd::_sstd_glGetInternalformati64v(target, internalformat, pname, bufSize, params);
    }
    inline void  glGetInternalformativ(GLenum  target, GLenum  internalformat, GLenum  pname, GLsizei  bufSize, GLint *  params) {
        return sstd::_sstd_glGetInternalformativ(target, internalformat, pname, bufSize, params);
    }
    inline void  glGetMultisamplefv(GLenum  pname, GLuint  index, GLfloat *  val) {
        return sstd::_sstd_glGetMultisamplefv(pname, index, val);
    }
    inline void  glGetNamedBufferParameteri64v(GLuint  buffer, GLenum  pname, GLint64 *  params) {
        return sstd::_sstd_glGetNamedBufferParameteri64v(buffer, pname, params);
    }
    inline void  glGetNamedBufferParameteriv(GLuint  buffer, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetNamedBufferParameteriv(buffer, pname, params);
    }
    inline void  glGetNamedBufferPointerv(GLuint  buffer, GLenum  pname, void * *  params) {
        return sstd::_sstd_glGetNamedBufferPointerv(buffer, pname, params);
    }
    inline void  glGetNamedBufferSubData(GLuint  buffer, GLintptr  offset, GLsizei  size, void *  data) {
        return sstd::_sstd_glGetNamedBufferSubData(buffer, offset, size, data);
    }
    inline void  glGetNamedFramebufferAttachmentParameteriv(GLuint  framebuffer, GLenum  attachment, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params);
    }
    inline void  glGetNamedFramebufferParameteriv(GLuint  framebuffer, GLenum  pname, GLint *  param) {
        return sstd::_sstd_glGetNamedFramebufferParameteriv(framebuffer, pname, param);
    }
    inline void  glGetNamedRenderbufferParameteriv(GLuint  renderbuffer, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetNamedRenderbufferParameteriv(renderbuffer, pname, params);
    }
    inline void  glGetObjectLabel(GLenum  identifier, GLuint  name, GLsizei  bufSize, GLsizei *  length, GLchar *  label) {
        return sstd::_sstd_glGetObjectLabel(identifier, name, bufSize, length, label);
    }
    inline void  glGetObjectPtrLabel(const void *  ptr, GLsizei  bufSize, GLsizei *  length, GLchar *  label) {
        return sstd::_sstd_glGetObjectPtrLabel(const_cast<void *>(ptr), bufSize, length, label);
    }
    inline void  glGetProgramBinary(GLuint  program, GLsizei  bufSize, GLsizei *  length, GLenum *  binaryFormat, void *  binary) {
        return sstd::_sstd_glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
    }
    inline void  glGetProgramInfoLog(GLuint  program, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog) {
        return sstd::_sstd_glGetProgramInfoLog(program, bufSize, length, infoLog);
    }
    inline void  glGetProgramInterfaceiv(GLuint  program, GLenum  programInterface, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetProgramInterfaceiv(program, programInterface, pname, params);
    }
    inline void  glGetProgramPipelineInfoLog(GLuint  pipeline, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog) {
        return sstd::_sstd_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
    }
    inline void  glGetProgramPipelineiv(GLuint  pipeline, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetProgramPipelineiv(pipeline, pname, params);
    }
    inline GLuint  glGetProgramResourceIndex(GLuint  program, GLenum  programInterface, const GLchar *  name) {
        return sstd::_sstd_glGetProgramResourceIndex(program, programInterface, const_cast<GLchar *>(name));
    }
    inline GLint  glGetProgramResourceLocation(GLuint  program, GLenum  programInterface, const GLchar *  name) {
        return sstd::_sstd_glGetProgramResourceLocation(program, programInterface, const_cast<GLchar *>(name));
    }
    inline GLint  glGetProgramResourceLocationIndex(GLuint  program, GLenum  programInterface, const GLchar *  name) {
        return sstd::_sstd_glGetProgramResourceLocationIndex(program, programInterface, const_cast<GLchar *>(name));
    }
    inline void  glGetProgramResourceName(GLuint  program, GLenum  programInterface, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLchar *  name) {
        return sstd::_sstd_glGetProgramResourceName(program, programInterface, index, bufSize, length, name);
    }
    inline void  glGetProgramResourceiv(GLuint  program, GLenum  programInterface, GLuint  index, GLsizei  propCount, const GLenum *  props, GLsizei  bufSize, GLsizei *  length, GLint *  params) {
        return sstd::_sstd_glGetProgramResourceiv(program, programInterface, index, propCount, const_cast<GLenum *>(props), bufSize, length, params);
    }
    inline void  glGetProgramStageiv(GLuint  program, GLenum  shadertype, GLenum  pname, GLint *  values) {
        return sstd::_sstd_glGetProgramStageiv(program, shadertype, pname, values);
    }
    inline void  glGetProgramiv(GLuint  program, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetProgramiv(program, pname, params);
    }
    inline void  glGetQueryIndexediv(GLenum  target, GLuint  index, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetQueryIndexediv(target, index, pname, params);
    }
    inline void  glGetQueryObjecti64v(GLuint  id, GLenum  pname, GLint64 *  params) {
        return sstd::_sstd_glGetQueryObjecti64v(id, pname, params);
    }
    inline void  glGetQueryObjectiv(GLuint  id, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetQueryObjectiv(id, pname, params);
    }
    inline void  glGetQueryObjectui64v(GLuint  id, GLenum  pname, GLuint64 *  params) {
        return sstd::_sstd_glGetQueryObjectui64v(id, pname, params);
    }
    inline void  glGetQueryObjectuiv(GLuint  id, GLenum  pname, GLuint *  params) {
        return sstd::_sstd_glGetQueryObjectuiv(id, pname, params);
    }
    inline void  glGetQueryiv(GLenum  target, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetQueryiv(target, pname, params);
    }
    inline void  glGetRenderbufferParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetRenderbufferParameteriv(target, pname, params);
    }
    inline void  glGetSamplerParameterIiv(GLuint  sampler, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetSamplerParameterIiv(sampler, pname, params);
    }
    inline void  glGetSamplerParameterIuiv(GLuint  sampler, GLenum  pname, GLuint *  params) {
        return sstd::_sstd_glGetSamplerParameterIuiv(sampler, pname, params);
    }
    inline void  glGetSamplerParameterfv(GLuint  sampler, GLenum  pname, GLfloat *  params) {
        return sstd::_sstd_glGetSamplerParameterfv(sampler, pname, params);
    }
    inline void  glGetSamplerParameteriv(GLuint  sampler, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetSamplerParameteriv(sampler, pname, params);
    }
    inline void  glGetShaderInfoLog(GLuint  shader, GLsizei  bufSize, GLsizei *  length, GLchar *  infoLog) {
        return sstd::_sstd_glGetShaderInfoLog(shader, bufSize, length, infoLog);
    }
    inline void  glGetShaderPrecisionFormat(GLenum  shadertype, GLenum  precisiontype, GLint *  range, GLint *  precision) {
        return sstd::_sstd_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
    }
    inline void  glGetShaderSource(GLuint  shader, GLsizei  bufSize, GLsizei *  length, GLchar *  source) {
        return sstd::_sstd_glGetShaderSource(shader, bufSize, length, source);
    }
    inline void  glGetShaderiv(GLuint  shader, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetShaderiv(shader, pname, params);
    }
    inline const GLubyte * glGetString(GLenum  name) {
        return sstd::_sstd_glGetString(name);
    }
    inline const GLubyte * glGetStringi(GLenum  name, GLuint  index) {
        return sstd::_sstd_glGetStringi(name, index);
    }
    inline GLuint  glGetSubroutineIndex(GLuint  program, GLenum  shadertype, const GLchar *  name) {
        return sstd::_sstd_glGetSubroutineIndex(program, shadertype, const_cast<GLchar *>(name));
    }
    inline GLint  glGetSubroutineUniformLocation(GLuint  program, GLenum  shadertype, const GLchar *  name) {
        return sstd::_sstd_glGetSubroutineUniformLocation(program, shadertype, const_cast<GLchar *>(name));
    }
    inline void  glGetSynciv(GLsync  sync, GLenum  pname, GLsizei  bufSize, GLsizei *  length, GLint *  values) {
        return sstd::_sstd_glGetSynciv(sync, pname, bufSize, length, values);
    }
    inline void  glGetTexImage(GLenum  target, GLint  level, GLenum  format, GLenum  type, void *  pixels) {
        return sstd::_sstd_glGetTexImage(target, level, format, type, pixels);
    }
    inline void  glGetTexLevelParameterfv(GLenum  target, GLint  level, GLenum  pname, GLfloat *  params) {
        return sstd::_sstd_glGetTexLevelParameterfv(target, level, pname, params);
    }
    inline void  glGetTexLevelParameteriv(GLenum  target, GLint  level, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetTexLevelParameteriv(target, level, pname, params);
    }
    inline void  glGetTexParameterIiv(GLenum  target, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetTexParameterIiv(target, pname, params);
    }
    inline void  glGetTexParameterIuiv(GLenum  target, GLenum  pname, GLuint *  params) {
        return sstd::_sstd_glGetTexParameterIuiv(target, pname, params);
    }
    inline void  glGetTexParameterfv(GLenum  target, GLenum  pname, GLfloat *  params) {
        return sstd::_sstd_glGetTexParameterfv(target, pname, params);
    }
    inline void  glGetTexParameteriv(GLenum  target, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetTexParameteriv(target, pname, params);
    }
    inline void  glGetTextureImage(GLuint  texture, GLint  level, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels) {
        return sstd::_sstd_glGetTextureImage(texture, level, format, type, bufSize, pixels);
    }
    inline void  glGetTextureLevelParameterfv(GLuint  texture, GLint  level, GLenum  pname, GLfloat *  params) {
        return sstd::_sstd_glGetTextureLevelParameterfv(texture, level, pname, params);
    }
    inline void  glGetTextureLevelParameteriv(GLuint  texture, GLint  level, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetTextureLevelParameteriv(texture, level, pname, params);
    }
    inline void  glGetTextureParameterIiv(GLuint  texture, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetTextureParameterIiv(texture, pname, params);
    }
    inline void  glGetTextureParameterIuiv(GLuint  texture, GLenum  pname, GLuint *  params) {
        return sstd::_sstd_glGetTextureParameterIuiv(texture, pname, params);
    }
    inline void  glGetTextureParameterfv(GLuint  texture, GLenum  pname, GLfloat *  params) {
        return sstd::_sstd_glGetTextureParameterfv(texture, pname, params);
    }
    inline void  glGetTextureParameteriv(GLuint  texture, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetTextureParameteriv(texture, pname, params);
    }
    inline void  glGetTextureSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels) {
        return sstd::_sstd_glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
    }
    inline void  glGetTransformFeedbackVarying(GLuint  program, GLuint  index, GLsizei  bufSize, GLsizei *  length, GLsizei *  size, GLenum *  type, GLchar *  name) {
        return sstd::_sstd_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
    }
    inline void  glGetTransformFeedbacki64_v(GLuint  xfb, GLenum  pname, GLuint  index, GLint64 *  param) {
        return sstd::_sstd_glGetTransformFeedbacki64_v(xfb, pname, index, param);
    }
    inline void  glGetTransformFeedbacki_v(GLuint  xfb, GLenum  pname, GLuint  index, GLint *  param) {
        return sstd::_sstd_glGetTransformFeedbacki_v(xfb, pname, index, param);
    }
    inline void  glGetTransformFeedbackiv(GLuint  xfb, GLenum  pname, GLint *  param) {
        return sstd::_sstd_glGetTransformFeedbackiv(xfb, pname, param);
    }
    inline GLuint  glGetUniformBlockIndex(GLuint  program, const GLchar *  uniformBlockName) {
        return sstd::_sstd_glGetUniformBlockIndex(program, const_cast<GLchar *>(uniformBlockName));
    }
    inline void  glGetUniformIndices(GLuint  program, GLsizei  uniformCount, const GLchar * const *  uniformNames, GLuint *  uniformIndices) {
        return sstd::_sstd_glGetUniformIndices(program, uniformCount, const_cast<GLchar * *>(uniformNames), uniformIndices);
    }
    inline GLint  glGetUniformLocation(GLuint  program, const GLchar *  name) {
        return sstd::_sstd_glGetUniformLocation(program, const_cast<GLchar *>(name));
    }
    inline void  glGetUniformSubroutineuiv(GLenum  shadertype, GLint  location, GLuint *  params) {
        return sstd::_sstd_glGetUniformSubroutineuiv(shadertype, location, params);
    }
    inline void  glGetUniformdv(GLuint  program, GLint  location, GLdouble *  params) {
        return sstd::_sstd_glGetUniformdv(program, location, params);
    }
    inline void  glGetUniformfv(GLuint  program, GLint  location, GLfloat *  params) {
        return sstd::_sstd_glGetUniformfv(program, location, params);
    }
    inline void  glGetUniformiv(GLuint  program, GLint  location, GLint *  params) {
        return sstd::_sstd_glGetUniformiv(program, location, params);
    }
    inline void  glGetUniformuiv(GLuint  program, GLint  location, GLuint *  params) {
        return sstd::_sstd_glGetUniformuiv(program, location, params);
    }
    inline void  glGetVertexArrayIndexed64iv(GLuint  vaobj, GLuint  index, GLenum  pname, GLint64 *  param) {
        return sstd::_sstd_glGetVertexArrayIndexed64iv(vaobj, index, pname, param);
    }
    inline void  glGetVertexArrayIndexediv(GLuint  vaobj, GLuint  index, GLenum  pname, GLint *  param) {
        return sstd::_sstd_glGetVertexArrayIndexediv(vaobj, index, pname, param);
    }
    inline void  glGetVertexArrayiv(GLuint  vaobj, GLenum  pname, GLint *  param) {
        return sstd::_sstd_glGetVertexArrayiv(vaobj, pname, param);
    }
    inline void  glGetVertexAttribIiv(GLuint  index, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetVertexAttribIiv(index, pname, params);
    }
    inline void  glGetVertexAttribIuiv(GLuint  index, GLenum  pname, GLuint *  params) {
        return sstd::_sstd_glGetVertexAttribIuiv(index, pname, params);
    }
    inline void  glGetVertexAttribLdv(GLuint  index, GLenum  pname, GLdouble *  params) {
        return sstd::_sstd_glGetVertexAttribLdv(index, pname, params);
    }
    inline void  glGetVertexAttribPointerv(GLuint  index, GLenum  pname, void * *  pointer) {
        return sstd::_sstd_glGetVertexAttribPointerv(index, pname, pointer);
    }
    inline void  glGetVertexAttribdv(GLuint  index, GLenum  pname, GLdouble *  params) {
        return sstd::_sstd_glGetVertexAttribdv(index, pname, params);
    }
    inline void  glGetVertexAttribfv(GLuint  index, GLenum  pname, GLfloat *  params) {
        return sstd::_sstd_glGetVertexAttribfv(index, pname, params);
    }
    inline void  glGetVertexAttribiv(GLuint  index, GLenum  pname, GLint *  params) {
        return sstd::_sstd_glGetVertexAttribiv(index, pname, params);
    }
    inline void  glGetnCompressedTexImage(GLenum  target, GLint  lod, GLsizei  bufSize, void *  pixels) {
        return sstd::_sstd_glGetnCompressedTexImage(target, lod, bufSize, pixels);
    }
    inline void  glGetnTexImage(GLenum  target, GLint  level, GLenum  format, GLenum  type, GLsizei  bufSize, void *  pixels) {
        return sstd::_sstd_glGetnTexImage(target, level, format, type, bufSize, pixels);
    }
    inline void  glGetnUniformdv(GLuint  program, GLint  location, GLsizei  bufSize, GLdouble *  params) {
        return sstd::_sstd_glGetnUniformdv(program, location, bufSize, params);
    }
    inline void  glGetnUniformfv(GLuint  program, GLint  location, GLsizei  bufSize, GLfloat *  params) {
        return sstd::_sstd_glGetnUniformfv(program, location, bufSize, params);
    }
    inline void  glGetnUniformiv(GLuint  program, GLint  location, GLsizei  bufSize, GLint *  params) {
        return sstd::_sstd_glGetnUniformiv(program, location, bufSize, params);
    }
    inline void  glGetnUniformuiv(GLuint  program, GLint  location, GLsizei  bufSize, GLuint *  params) {
        return sstd::_sstd_glGetnUniformuiv(program, location, bufSize, params);
    }
    inline void  glHint(GLenum  target, GLenum  mode) {
        return sstd::_sstd_glHint(target, mode);
    }
    inline void  glInvalidateBufferData(GLuint  buffer) {
        return sstd::_sstd_glInvalidateBufferData(buffer);
    }
    inline void  glInvalidateBufferSubData(GLuint  buffer, GLintptr  offset, GLsizeiptr  length) {
        return sstd::_sstd_glInvalidateBufferSubData(buffer, offset, length);
    }
    inline void  glInvalidateFramebuffer(GLenum  target, GLsizei  numAttachments, const GLenum *  attachments) {
        return sstd::_sstd_glInvalidateFramebuffer(target, numAttachments, const_cast<GLenum *>(attachments));
    }
    inline void  glInvalidateNamedFramebufferData(GLuint  framebuffer, GLsizei  numAttachments, const GLenum *  attachments) {
        return sstd::_sstd_glInvalidateNamedFramebufferData(framebuffer, numAttachments, const_cast<GLenum *>(attachments));
    }
    inline void  glInvalidateNamedFramebufferSubData(GLuint  framebuffer, GLsizei  numAttachments, const GLenum *  attachments, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, const_cast<GLenum *>(attachments), x, y, width, height);
    }
    inline void  glInvalidateSubFramebuffer(GLenum  target, GLsizei  numAttachments, const GLenum *  attachments, GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glInvalidateSubFramebuffer(target, numAttachments, const_cast<GLenum *>(attachments), x, y, width, height);
    }
    inline void  glInvalidateTexImage(GLuint  texture, GLint  level) {
        return sstd::_sstd_glInvalidateTexImage(texture, level);
    }
    inline void  glInvalidateTexSubImage(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth) {
        return sstd::_sstd_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
    }
    inline GLboolean  glIsBuffer(GLuint  buffer) {
        return sstd::_sstd_glIsBuffer(buffer);
    }
    inline GLboolean  glIsEnabled(GLenum  cap) {
        return sstd::_sstd_glIsEnabled(cap);
    }
    inline GLboolean  glIsEnabledi(GLenum  target, GLuint  index) {
        return sstd::_sstd_glIsEnabledi(target, index);
    }
    inline GLboolean  glIsFramebuffer(GLuint  framebuffer) {
        return sstd::_sstd_glIsFramebuffer(framebuffer);
    }
    inline GLboolean  glIsProgram(GLuint  program) {
        return sstd::_sstd_glIsProgram(program);
    }
    inline GLboolean  glIsProgramPipeline(GLuint  pipeline) {
        return sstd::_sstd_glIsProgramPipeline(pipeline);
    }
    inline GLboolean  glIsQuery(GLuint  id) {
        return sstd::_sstd_glIsQuery(id);
    }
    inline GLboolean  glIsRenderbuffer(GLuint  renderbuffer) {
        return sstd::_sstd_glIsRenderbuffer(renderbuffer);
    }
    inline GLboolean  glIsSampler(GLuint  sampler) {
        return sstd::_sstd_glIsSampler(sampler);
    }
    inline GLboolean  glIsShader(GLuint  shader) {
        return sstd::_sstd_glIsShader(shader);
    }
    inline GLboolean  glIsSync(GLsync  sync) {
        return sstd::_sstd_glIsSync(sync);
    }
    inline GLboolean  glIsTexture(GLuint  texture) {
        return sstd::_sstd_glIsTexture(texture);
    }
    inline GLboolean  glIsTransformFeedback(GLuint  id) {
        return sstd::_sstd_glIsTransformFeedback(id);
    }
    inline GLboolean  glIsVertexArray(GLuint  array) {
        return sstd::_sstd_glIsVertexArray(array);
    }
    inline void  glLineWidth(GLfloat  width) {
        return sstd::_sstd_glLineWidth(width);
    }
    inline void  glLinkProgram(GLuint  program) {
        return sstd::_sstd_glLinkProgram(program);
    }
    inline void  glLogicOp(GLenum  opcode) {
        return sstd::_sstd_glLogicOp(opcode);
    }
    inline void * glMapBuffer(GLenum  target, GLenum  access) {
        return sstd::_sstd_glMapBuffer(target, access);
    }
    inline void * glMapBufferRange(GLenum  target, GLintptr  offset, GLsizeiptr  length, GLbitfield  access) {
        return sstd::_sstd_glMapBufferRange(target, offset, length, access);
    }
    inline void * glMapNamedBuffer(GLuint  buffer, GLenum  access) {
        return sstd::_sstd_glMapNamedBuffer(buffer, access);
    }
    inline void * glMapNamedBufferRange(GLuint  buffer, GLintptr  offset, GLsizei  length, GLbitfield  access) {
        return sstd::_sstd_glMapNamedBufferRange(buffer, offset, length, access);
    }
    inline void  glMemoryBarrier(GLbitfield  barriers) {
        return sstd::_sstd_glMemoryBarrier(barriers);
    }
    inline void  glMemoryBarrierByRegion(GLbitfield  barriers) {
        return sstd::_sstd_glMemoryBarrierByRegion(barriers);
    }
    inline void  glMinSampleShading(GLfloat  value) {
        return sstd::_sstd_glMinSampleShading(value);
    }
    inline void  glMultiDrawArrays(GLenum  mode, const GLint *  first, const GLsizei *  count, GLsizei  drawcount) {
        return sstd::_sstd_glMultiDrawArrays(mode, const_cast<GLint *>(first), const_cast<GLsizei *>(count), drawcount);
    }
    inline void  glMultiDrawArraysIndirect(GLenum  mode, const void *  indirect, GLsizei  drawcount, GLsizei  stride) {
        return sstd::_sstd_glMultiDrawArraysIndirect(mode, const_cast<void *>(indirect), drawcount, stride);
    }
    inline void  glMultiDrawElements(GLenum  mode, const GLsizei *  count, GLenum  type, const void * const *  indices, GLsizei  drawcount) {
        return sstd::_sstd_glMultiDrawElements(mode, const_cast<GLsizei *>(count), type, const_cast<void * *>(indices), drawcount);
    }
    inline void  glMultiDrawElementsBaseVertex(GLenum  mode, const GLsizei *  count, GLenum  type, const void * const *  indices, GLsizei  drawcount, const GLint *  basevertex) {
        return sstd::_sstd_glMultiDrawElementsBaseVertex(mode, const_cast<GLsizei *>(count), type, const_cast<void * *>(indices), drawcount, const_cast<GLint *>(basevertex));
    }
    inline void  glMultiDrawElementsIndirect(GLenum  mode, GLenum  type, const void *  indirect, GLsizei  drawcount, GLsizei  stride) {
        return sstd::_sstd_glMultiDrawElementsIndirect(mode, type, const_cast<void *>(indirect), drawcount, stride);
    }
    inline void  glNamedBufferData(GLuint  buffer, GLsizei  size, const void *  data, GLenum  usage) {
        return sstd::_sstd_glNamedBufferData(buffer, size, const_cast<void *>(data), usage);
    }
    inline void  glNamedBufferStorage(GLuint  buffer, GLsizei  size, const void *  data, GLbitfield  flags) {
        return sstd::_sstd_glNamedBufferStorage(buffer, size, const_cast<void *>(data), flags);
    }
    inline void  glNamedBufferSubData(GLuint  buffer, GLintptr  offset, GLsizei  size, const void *  data) {
        return sstd::_sstd_glNamedBufferSubData(buffer, offset, size, const_cast<void *>(data));
    }
    inline void  glNamedFramebufferDrawBuffer(GLuint  framebuffer, GLenum  buf) {
        return sstd::_sstd_glNamedFramebufferDrawBuffer(framebuffer, buf);
    }
    inline void  glNamedFramebufferDrawBuffers(GLuint  framebuffer, GLsizei  n, const GLenum *  bufs) {
        return sstd::_sstd_glNamedFramebufferDrawBuffers(framebuffer, n, const_cast<GLenum *>(bufs));
    }
    inline void  glNamedFramebufferParameteri(GLuint  framebuffer, GLenum  pname, GLint  param) {
        return sstd::_sstd_glNamedFramebufferParameteri(framebuffer, pname, param);
    }
    inline void  glNamedFramebufferReadBuffer(GLuint  framebuffer, GLenum  src) {
        return sstd::_sstd_glNamedFramebufferReadBuffer(framebuffer, src);
    }
    inline void  glNamedFramebufferRenderbuffer(GLuint  framebuffer, GLenum  attachment, GLenum  renderbuffertarget, GLuint  renderbuffer) {
        return sstd::_sstd_glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer);
    }
    inline void  glNamedFramebufferTexture(GLuint  framebuffer, GLenum  attachment, GLuint  texture, GLint  level) {
        return sstd::_sstd_glNamedFramebufferTexture(framebuffer, attachment, texture, level);
    }
    inline void  glNamedFramebufferTextureLayer(GLuint  framebuffer, GLenum  attachment, GLuint  texture, GLint  level, GLint  layer) {
        return sstd::_sstd_glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer);
    }
    inline void  glNamedRenderbufferStorage(GLuint  renderbuffer, GLenum  internalformat, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glNamedRenderbufferStorage(renderbuffer, internalformat, width, height);
    }
    inline void  glNamedRenderbufferStorageMultisample(GLuint  renderbuffer, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height);
    }
    inline void  glObjectLabel(GLenum  identifier, GLuint  name, GLsizei  length, const GLchar *  label) {
        return sstd::_sstd_glObjectLabel(identifier, name, length, const_cast<GLchar *>(label));
    }
    inline void  glObjectPtrLabel(const void *  ptr, GLsizei  length, const GLchar *  label) {
        return sstd::_sstd_glObjectPtrLabel(const_cast<void *>(ptr), length, const_cast<GLchar *>(label));
    }
    inline void  glPatchParameterfv(GLenum  pname, const GLfloat *  values) {
        return sstd::_sstd_glPatchParameterfv(pname, const_cast<GLfloat *>(values));
    }
    inline void  glPatchParameteri(GLenum  pname, GLint  value) {
        return sstd::_sstd_glPatchParameteri(pname, value);
    }
    inline void  glPauseTransformFeedback() {
        return sstd::_sstd_glPauseTransformFeedback();
    }
    inline void  glPixelStoref(GLenum  pname, GLfloat  param) {
        return sstd::_sstd_glPixelStoref(pname, param);
    }
    inline void  glPixelStorei(GLenum  pname, GLint  param) {
        return sstd::_sstd_glPixelStorei(pname, param);
    }
    inline void  glPointParameterf(GLenum  pname, GLfloat  param) {
        return sstd::_sstd_glPointParameterf(pname, param);
    }
    inline void  glPointParameterfv(GLenum  pname, const GLfloat *  params) {
        return sstd::_sstd_glPointParameterfv(pname, const_cast<GLfloat *>(params));
    }
    inline void  glPointParameteri(GLenum  pname, GLint  param) {
        return sstd::_sstd_glPointParameteri(pname, param);
    }
    inline void  glPointParameteriv(GLenum  pname, const GLint *  params) {
        return sstd::_sstd_glPointParameteriv(pname, const_cast<GLint *>(params));
    }
    inline void  glPointSize(GLfloat  size) {
        return sstd::_sstd_glPointSize(size);
    }
    inline void  glPolygonMode(GLenum  face, GLenum  mode) {
        return sstd::_sstd_glPolygonMode(face, mode);
    }
    inline void  glPolygonOffset(GLfloat  factor, GLfloat  units) {
        return sstd::_sstd_glPolygonOffset(factor, units);
    }
    inline void  glPopDebugGroup() {
        return sstd::_sstd_glPopDebugGroup();
    }
    inline void  glPrimitiveRestartIndex(GLuint  index) {
        return sstd::_sstd_glPrimitiveRestartIndex(index);
    }
    inline void  glProgramBinary(GLuint  program, GLenum  binaryFormat, const void *  binary, GLsizei  length) {
        return sstd::_sstd_glProgramBinary(program, binaryFormat, const_cast<void *>(binary), length);
    }
    inline void  glProgramParameteri(GLuint  program, GLenum  pname, GLint  value) {
        return sstd::_sstd_glProgramParameteri(program, pname, value);
    }
    inline void  glProgramUniform1d(GLuint  program, GLint  location, GLdouble  v0) {
        return sstd::_sstd_glProgramUniform1d(program, location, v0);
    }
    inline void  glProgramUniform1dv(GLuint  program, GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniform1dv(program, location, count, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniform1f(GLuint  program, GLint  location, GLfloat  v0) {
        return sstd::_sstd_glProgramUniform1f(program, location, v0);
    }
    inline void  glProgramUniform1fv(GLuint  program, GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniform1fv(program, location, count, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniform1i(GLuint  program, GLint  location, GLint  v0) {
        return sstd::_sstd_glProgramUniform1i(program, location, v0);
    }
    inline void  glProgramUniform1iv(GLuint  program, GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glProgramUniform1iv(program, location, count, const_cast<GLint *>(value));
    }
    inline void  glProgramUniform1ui(GLuint  program, GLint  location, GLuint  v0) {
        return sstd::_sstd_glProgramUniform1ui(program, location, v0);
    }
    inline void  glProgramUniform1uiv(GLuint  program, GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glProgramUniform1uiv(program, location, count, const_cast<GLuint *>(value));
    }
    inline void  glProgramUniform2d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1) {
        return sstd::_sstd_glProgramUniform2d(program, location, v0, v1);
    }
    inline void  glProgramUniform2dv(GLuint  program, GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniform2dv(program, location, count, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniform2f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1) {
        return sstd::_sstd_glProgramUniform2f(program, location, v0, v1);
    }
    inline void  glProgramUniform2fv(GLuint  program, GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniform2fv(program, location, count, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniform2i(GLuint  program, GLint  location, GLint  v0, GLint  v1) {
        return sstd::_sstd_glProgramUniform2i(program, location, v0, v1);
    }
    inline void  glProgramUniform2iv(GLuint  program, GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glProgramUniform2iv(program, location, count, const_cast<GLint *>(value));
    }
    inline void  glProgramUniform2ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1) {
        return sstd::_sstd_glProgramUniform2ui(program, location, v0, v1);
    }
    inline void  glProgramUniform2uiv(GLuint  program, GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glProgramUniform2uiv(program, location, count, const_cast<GLuint *>(value));
    }
    inline void  glProgramUniform3d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1, GLdouble  v2) {
        return sstd::_sstd_glProgramUniform3d(program, location, v0, v1, v2);
    }
    inline void  glProgramUniform3dv(GLuint  program, GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniform3dv(program, location, count, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniform3f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2) {
        return sstd::_sstd_glProgramUniform3f(program, location, v0, v1, v2);
    }
    inline void  glProgramUniform3fv(GLuint  program, GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniform3fv(program, location, count, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniform3i(GLuint  program, GLint  location, GLint  v0, GLint  v1, GLint  v2) {
        return sstd::_sstd_glProgramUniform3i(program, location, v0, v1, v2);
    }
    inline void  glProgramUniform3iv(GLuint  program, GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glProgramUniform3iv(program, location, count, const_cast<GLint *>(value));
    }
    inline void  glProgramUniform3ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1, GLuint  v2) {
        return sstd::_sstd_glProgramUniform3ui(program, location, v0, v1, v2);
    }
    inline void  glProgramUniform3uiv(GLuint  program, GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glProgramUniform3uiv(program, location, count, const_cast<GLuint *>(value));
    }
    inline void  glProgramUniform4d(GLuint  program, GLint  location, GLdouble  v0, GLdouble  v1, GLdouble  v2, GLdouble  v3) {
        return sstd::_sstd_glProgramUniform4d(program, location, v0, v1, v2, v3);
    }
    inline void  glProgramUniform4dv(GLuint  program, GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniform4dv(program, location, count, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniform4f(GLuint  program, GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2, GLfloat  v3) {
        return sstd::_sstd_glProgramUniform4f(program, location, v0, v1, v2, v3);
    }
    inline void  glProgramUniform4fv(GLuint  program, GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniform4fv(program, location, count, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniform4i(GLuint  program, GLint  location, GLint  v0, GLint  v1, GLint  v2, GLint  v3) {
        return sstd::_sstd_glProgramUniform4i(program, location, v0, v1, v2, v3);
    }
    inline void  glProgramUniform4iv(GLuint  program, GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glProgramUniform4iv(program, location, count, const_cast<GLint *>(value));
    }
    inline void  glProgramUniform4ui(GLuint  program, GLint  location, GLuint  v0, GLuint  v1, GLuint  v2, GLuint  v3) {
        return sstd::_sstd_glProgramUniform4ui(program, location, v0, v1, v2, v3);
    }
    inline void  glProgramUniform4uiv(GLuint  program, GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glProgramUniform4uiv(program, location, count, const_cast<GLuint *>(value));
    }
    inline void  glProgramUniformMatrix2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix2dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix2fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix2x3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix2x3dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix2x3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix2x3fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix2x4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix2x4dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix2x4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix2x4fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix3dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix3fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix3x2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix3x2dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix3x2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix3x2fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix3x4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix3x4dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix3x4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix3x4fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix4dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix4dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix4fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix4fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix4x2dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix4x2dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix4x2fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix4x2fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProgramUniformMatrix4x3dv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glProgramUniformMatrix4x3dv(program, location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glProgramUniformMatrix4x3fv(GLuint  program, GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glProgramUniformMatrix4x3fv(program, location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glProvokingVertex(GLenum  mode) {
        return sstd::_sstd_glProvokingVertex(mode);
    }
    inline void  glPushDebugGroup(GLenum  source, GLuint  id, GLsizei  length, const GLchar *  message) {
        return sstd::_sstd_glPushDebugGroup(source, id, length, const_cast<GLchar *>(message));
    }
    inline void  glQueryCounter(GLuint  id, GLenum  target) {
        return sstd::_sstd_glQueryCounter(id, target);
    }
    inline void  glReadBuffer(GLenum  src) {
        return sstd::_sstd_glReadBuffer(src);
    }
    inline void  glReadPixels(GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, void *  pixels) {
        return sstd::_sstd_glReadPixels(x, y, width, height, format, type, pixels);
    }
    inline void  glReadnPixels(GLint  x, GLint  y, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, GLsizei  bufSize, void *  data) {
        return sstd::_sstd_glReadnPixels(x, y, width, height, format, type, bufSize, data);
    }
    inline void  glReleaseShaderCompiler() {
        return sstd::_sstd_glReleaseShaderCompiler();
    }
    inline void  glRenderbufferStorage(GLenum  target, GLenum  internalformat, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glRenderbufferStorage(target, internalformat, width, height);
    }
    inline void  glRenderbufferStorageMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
    }
    inline void  glResumeTransformFeedback() {
        return sstd::_sstd_glResumeTransformFeedback();
    }
    inline void  glSampleCoverage(GLfloat  value, GLboolean  invert) {
        return sstd::_sstd_glSampleCoverage(value, invert);
    }
    inline void  glSampleMaski(GLuint  maskNumber, GLbitfield  mask) {
        return sstd::_sstd_glSampleMaski(maskNumber, mask);
    }
    inline void  glSamplerParameterIiv(GLuint  sampler, GLenum  pname, const GLint *  param) {
        return sstd::_sstd_glSamplerParameterIiv(sampler, pname, const_cast<GLint *>(param));
    }
    inline void  glSamplerParameterIuiv(GLuint  sampler, GLenum  pname, const GLuint *  param) {
        return sstd::_sstd_glSamplerParameterIuiv(sampler, pname, const_cast<GLuint *>(param));
    }
    inline void  glSamplerParameterf(GLuint  sampler, GLenum  pname, GLfloat  param) {
        return sstd::_sstd_glSamplerParameterf(sampler, pname, param);
    }
    inline void  glSamplerParameterfv(GLuint  sampler, GLenum  pname, const GLfloat *  param) {
        return sstd::_sstd_glSamplerParameterfv(sampler, pname, const_cast<GLfloat *>(param));
    }
    inline void  glSamplerParameteri(GLuint  sampler, GLenum  pname, GLint  param) {
        return sstd::_sstd_glSamplerParameteri(sampler, pname, param);
    }
    inline void  glSamplerParameteriv(GLuint  sampler, GLenum  pname, const GLint *  param) {
        return sstd::_sstd_glSamplerParameteriv(sampler, pname, const_cast<GLint *>(param));
    }
    inline void  glScissor(GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glScissor(x, y, width, height);
    }
    inline void  glScissorArrayv(GLuint  first, GLsizei  count, const GLint *  v) {
        return sstd::_sstd_glScissorArrayv(first, count, const_cast<GLint *>(v));
    }
    inline void  glScissorIndexed(GLuint  index, GLint  left, GLint  bottom, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glScissorIndexed(index, left, bottom, width, height);
    }
    inline void  glScissorIndexedv(GLuint  index, const GLint *  v) {
        return sstd::_sstd_glScissorIndexedv(index, const_cast<GLint *>(v));
    }
    inline void  glShaderBinary(GLsizei  count, const GLuint *  shaders, GLenum  binaryformat, const void *  binary, GLsizei  length) {
        return sstd::_sstd_glShaderBinary(count, const_cast<GLuint *>(shaders), binaryformat, const_cast<void *>(binary), length);
    }
    inline void  glShaderSource(GLuint  shader, GLsizei  count, const GLchar * const *  string, const GLint *  length) {
        return sstd::_sstd_glShaderSource(shader, count, const_cast<GLchar * *>(string), const_cast<GLint *>(length));
    }
    inline void  glShaderStorageBlockBinding(GLuint  program, GLuint  storageBlockIndex, GLuint  storageBlockBinding) {
        return sstd::_sstd_glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
    }
    inline void  glStencilFunc(GLenum  func, GLint  ref, GLuint  mask) {
        return sstd::_sstd_glStencilFunc(func, ref, mask);
    }
    inline void  glStencilFuncSeparate(GLenum  face, GLenum  func, GLint  ref, GLuint  mask) {
        return sstd::_sstd_glStencilFuncSeparate(face, func, ref, mask);
    }
    inline void  glStencilMask(GLuint  mask) {
        return sstd::_sstd_glStencilMask(mask);
    }
    inline void  glStencilMaskSeparate(GLenum  face, GLuint  mask) {
        return sstd::_sstd_glStencilMaskSeparate(face, mask);
    }
    inline void  glStencilOp(GLenum  fail, GLenum  zfail, GLenum  zpass) {
        return sstd::_sstd_glStencilOp(fail, zfail, zpass);
    }
    inline void  glStencilOpSeparate(GLenum  face, GLenum  sfail, GLenum  dpfail, GLenum  dppass) {
        return sstd::_sstd_glStencilOpSeparate(face, sfail, dpfail, dppass);
    }
    inline void  glTexBuffer(GLenum  target, GLenum  internalformat, GLuint  buffer) {
        return sstd::_sstd_glTexBuffer(target, internalformat, buffer);
    }
    inline void  glTexBufferRange(GLenum  target, GLenum  internalformat, GLuint  buffer, GLintptr  offset, GLsizeiptr  size) {
        return sstd::_sstd_glTexBufferRange(target, internalformat, buffer, offset, size);
    }
    inline void  glTexImage1D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLint  border, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTexImage1D(target, level, internalformat, width, border, format, type, const_cast<void *>(pixels));
    }
    inline void  glTexImage2D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLsizei  height, GLint  border, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTexImage2D(target, level, internalformat, width, height, border, format, type, const_cast<void *>(pixels));
    }
    inline void  glTexImage2DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations) {
        return sstd::_sstd_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
    }
    inline void  glTexImage3D(GLenum  target, GLint  level, GLint  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLint  border, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, const_cast<void *>(pixels));
    }
    inline void  glTexImage3DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations) {
        return sstd::_sstd_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
    }
    inline void  glTexParameterIiv(GLenum  target, GLenum  pname, const GLint *  params) {
        return sstd::_sstd_glTexParameterIiv(target, pname, const_cast<GLint *>(params));
    }
    inline void  glTexParameterIuiv(GLenum  target, GLenum  pname, const GLuint *  params) {
        return sstd::_sstd_glTexParameterIuiv(target, pname, const_cast<GLuint *>(params));
    }
    inline void  glTexParameterf(GLenum  target, GLenum  pname, GLfloat  param) {
        return sstd::_sstd_glTexParameterf(target, pname, param);
    }
    inline void  glTexParameterfv(GLenum  target, GLenum  pname, const GLfloat *  params) {
        return sstd::_sstd_glTexParameterfv(target, pname, const_cast<GLfloat *>(params));
    }
    inline void  glTexParameteri(GLenum  target, GLenum  pname, GLint  param) {
        return sstd::_sstd_glTexParameteri(target, pname, param);
    }
    inline void  glTexParameteriv(GLenum  target, GLenum  pname, const GLint *  params) {
        return sstd::_sstd_glTexParameteriv(target, pname, const_cast<GLint *>(params));
    }
    inline void  glTexStorage1D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width) {
        return sstd::_sstd_glTexStorage1D(target, levels, internalformat, width);
    }
    inline void  glTexStorage2D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glTexStorage2D(target, levels, internalformat, width, height);
    }
    inline void  glTexStorage2DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations) {
        return sstd::_sstd_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
    }
    inline void  glTexStorage3D(GLenum  target, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth) {
        return sstd::_sstd_glTexStorage3D(target, levels, internalformat, width, height, depth);
    }
    inline void  glTexStorage3DMultisample(GLenum  target, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations) {
        return sstd::_sstd_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
    }
    inline void  glTexSubImage1D(GLenum  target, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTexSubImage1D(target, level, xoffset, width, format, type, const_cast<void *>(pixels));
    }
    inline void  glTexSubImage2D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, const_cast<void *>(pixels));
    }
    inline void  glTexSubImage3D(GLenum  target, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, const_cast<void *>(pixels));
    }
    inline void  glTextureBarrier() {
        return sstd::_sstd_glTextureBarrier();
    }
    inline void  glTextureBuffer(GLuint  texture, GLenum  internalformat, GLuint  buffer) {
        return sstd::_sstd_glTextureBuffer(texture, internalformat, buffer);
    }
    inline void  glTextureBufferRange(GLuint  texture, GLenum  internalformat, GLuint  buffer, GLintptr  offset, GLsizei  size) {
        return sstd::_sstd_glTextureBufferRange(texture, internalformat, buffer, offset, size);
    }
    inline void  glTextureParameterIiv(GLuint  texture, GLenum  pname, const GLint *  params) {
        return sstd::_sstd_glTextureParameterIiv(texture, pname, const_cast<GLint *>(params));
    }
    inline void  glTextureParameterIuiv(GLuint  texture, GLenum  pname, const GLuint *  params) {
        return sstd::_sstd_glTextureParameterIuiv(texture, pname, const_cast<GLuint *>(params));
    }
    inline void  glTextureParameterf(GLuint  texture, GLenum  pname, GLfloat  param) {
        return sstd::_sstd_glTextureParameterf(texture, pname, param);
    }
    inline void  glTextureParameterfv(GLuint  texture, GLenum  pname, const GLfloat *  param) {
        return sstd::_sstd_glTextureParameterfv(texture, pname, const_cast<GLfloat *>(param));
    }
    inline void  glTextureParameteri(GLuint  texture, GLenum  pname, GLint  param) {
        return sstd::_sstd_glTextureParameteri(texture, pname, param);
    }
    inline void  glTextureParameteriv(GLuint  texture, GLenum  pname, const GLint *  param) {
        return sstd::_sstd_glTextureParameteriv(texture, pname, const_cast<GLint *>(param));
    }
    inline void  glTextureStorage1D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width) {
        return sstd::_sstd_glTextureStorage1D(texture, levels, internalformat, width);
    }
    inline void  glTextureStorage2D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glTextureStorage2D(texture, levels, internalformat, width, height);
    }
    inline void  glTextureStorage2DMultisample(GLuint  texture, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLboolean  fixedsamplelocations) {
        return sstd::_sstd_glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations);
    }
    inline void  glTextureStorage3D(GLuint  texture, GLsizei  levels, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth) {
        return sstd::_sstd_glTextureStorage3D(texture, levels, internalformat, width, height, depth);
    }
    inline void  glTextureStorage3DMultisample(GLuint  texture, GLsizei  samples, GLenum  internalformat, GLsizei  width, GLsizei  height, GLsizei  depth, GLboolean  fixedsamplelocations) {
        return sstd::_sstd_glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
    }
    inline void  glTextureSubImage1D(GLuint  texture, GLint  level, GLint  xoffset, GLsizei  width, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTextureSubImage1D(texture, level, xoffset, width, format, type, const_cast<void *>(pixels));
    }
    inline void  glTextureSubImage2D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLsizei  width, GLsizei  height, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, const_cast<void *>(pixels));
    }
    inline void  glTextureSubImage3D(GLuint  texture, GLint  level, GLint  xoffset, GLint  yoffset, GLint  zoffset, GLsizei  width, GLsizei  height, GLsizei  depth, GLenum  format, GLenum  type, const void *  pixels) {
        return sstd::_sstd_glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, const_cast<void *>(pixels));
    }
    inline void  glTextureView(GLuint  texture, GLenum  target, GLuint  origtexture, GLenum  internalformat, GLuint  minlevel, GLuint  numlevels, GLuint  minlayer, GLuint  numlayers) {
        return sstd::_sstd_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
    }
    inline void  glTransformFeedbackBufferBase(GLuint  xfb, GLuint  index, GLuint  buffer) {
        return sstd::_sstd_glTransformFeedbackBufferBase(xfb, index, buffer);
    }
    inline void  glTransformFeedbackBufferRange(GLuint  xfb, GLuint  index, GLuint  buffer, GLintptr  offset, GLsizei  size) {
        return sstd::_sstd_glTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
    }
    inline void  glTransformFeedbackVaryings(GLuint  program, GLsizei  count, const GLchar * const *  varyings, GLenum  bufferMode) {
        return sstd::_sstd_glTransformFeedbackVaryings(program, count, const_cast<GLchar * *>(varyings), bufferMode);
    }
    inline void  glUniform1d(GLint  location, GLdouble  x) {
        return sstd::_sstd_glUniform1d(location, x);
    }
    inline void  glUniform1dv(GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glUniform1dv(location, count, const_cast<GLdouble *>(value));
    }
    inline void  glUniform1f(GLint  location, GLfloat  v0) {
        return sstd::_sstd_glUniform1f(location, v0);
    }
    inline void  glUniform1fv(GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glUniform1fv(location, count, const_cast<GLfloat *>(value));
    }
    inline void  glUniform1i(GLint  location, GLint  v0) {
        return sstd::_sstd_glUniform1i(location, v0);
    }
    inline void  glUniform1iv(GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glUniform1iv(location, count, const_cast<GLint *>(value));
    }
    inline void  glUniform1ui(GLint  location, GLuint  v0) {
        return sstd::_sstd_glUniform1ui(location, v0);
    }
    inline void  glUniform1uiv(GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glUniform1uiv(location, count, const_cast<GLuint *>(value));
    }
    inline void  glUniform2d(GLint  location, GLdouble  x, GLdouble  y) {
        return sstd::_sstd_glUniform2d(location, x, y);
    }
    inline void  glUniform2dv(GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glUniform2dv(location, count, const_cast<GLdouble *>(value));
    }
    inline void  glUniform2f(GLint  location, GLfloat  v0, GLfloat  v1) {
        return sstd::_sstd_glUniform2f(location, v0, v1);
    }
    inline void  glUniform2fv(GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glUniform2fv(location, count, const_cast<GLfloat *>(value));
    }
    inline void  glUniform2i(GLint  location, GLint  v0, GLint  v1) {
        return sstd::_sstd_glUniform2i(location, v0, v1);
    }
    inline void  glUniform2iv(GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glUniform2iv(location, count, const_cast<GLint *>(value));
    }
    inline void  glUniform2ui(GLint  location, GLuint  v0, GLuint  v1) {
        return sstd::_sstd_glUniform2ui(location, v0, v1);
    }
    inline void  glUniform2uiv(GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glUniform2uiv(location, count, const_cast<GLuint *>(value));
    }
    inline void  glUniform3d(GLint  location, GLdouble  x, GLdouble  y, GLdouble  z) {
        return sstd::_sstd_glUniform3d(location, x, y, z);
    }
    inline void  glUniform3dv(GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glUniform3dv(location, count, const_cast<GLdouble *>(value));
    }
    inline void  glUniform3f(GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2) {
        return sstd::_sstd_glUniform3f(location, v0, v1, v2);
    }
    inline void  glUniform3fv(GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glUniform3fv(location, count, const_cast<GLfloat *>(value));
    }
    inline void  glUniform3i(GLint  location, GLint  v0, GLint  v1, GLint  v2) {
        return sstd::_sstd_glUniform3i(location, v0, v1, v2);
    }
    inline void  glUniform3iv(GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glUniform3iv(location, count, const_cast<GLint *>(value));
    }
    inline void  glUniform3ui(GLint  location, GLuint  v0, GLuint  v1, GLuint  v2) {
        return sstd::_sstd_glUniform3ui(location, v0, v1, v2);
    }
    inline void  glUniform3uiv(GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glUniform3uiv(location, count, const_cast<GLuint *>(value));
    }
    inline void  glUniform4d(GLint  location, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w) {
        return sstd::_sstd_glUniform4d(location, x, y, z, w);
    }
    inline void  glUniform4dv(GLint  location, GLsizei  count, const GLdouble *  value) {
        return sstd::_sstd_glUniform4dv(location, count, const_cast<GLdouble *>(value));
    }
    inline void  glUniform4f(GLint  location, GLfloat  v0, GLfloat  v1, GLfloat  v2, GLfloat  v3) {
        return sstd::_sstd_glUniform4f(location, v0, v1, v2, v3);
    }
    inline void  glUniform4fv(GLint  location, GLsizei  count, const GLfloat *  value) {
        return sstd::_sstd_glUniform4fv(location, count, const_cast<GLfloat *>(value));
    }
    inline void  glUniform4i(GLint  location, GLint  v0, GLint  v1, GLint  v2, GLint  v3) {
        return sstd::_sstd_glUniform4i(location, v0, v1, v2, v3);
    }
    inline void  glUniform4iv(GLint  location, GLsizei  count, const GLint *  value) {
        return sstd::_sstd_glUniform4iv(location, count, const_cast<GLint *>(value));
    }
    inline void  glUniform4ui(GLint  location, GLuint  v0, GLuint  v1, GLuint  v2, GLuint  v3) {
        return sstd::_sstd_glUniform4ui(location, v0, v1, v2, v3);
    }
    inline void  glUniform4uiv(GLint  location, GLsizei  count, const GLuint *  value) {
        return sstd::_sstd_glUniform4uiv(location, count, const_cast<GLuint *>(value));
    }
    inline void  glUniformBlockBinding(GLuint  program, GLuint  uniformBlockIndex, GLuint  uniformBlockBinding) {
        return sstd::_sstd_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
    }
    inline void  glUniformMatrix2dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix2dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix2fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix2fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix2x3dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix2x3dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix2x3fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix2x3fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix2x4dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix2x4dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix2x4fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix2x4fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix3dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix3dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix3fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix3fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix3x2dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix3x2dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix3x2fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix3x2fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix3x4dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix3x4dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix3x4fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix3x4fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix4dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix4dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix4fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix4fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix4x2dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix4x2dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix4x2fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix4x2fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformMatrix4x3dv(GLint  location, GLsizei  count, GLboolean  transpose, const GLdouble *  value) {
        return sstd::_sstd_glUniformMatrix4x3dv(location, count, transpose, const_cast<GLdouble *>(value));
    }
    inline void  glUniformMatrix4x3fv(GLint  location, GLsizei  count, GLboolean  transpose, const GLfloat *  value) {
        return sstd::_sstd_glUniformMatrix4x3fv(location, count, transpose, const_cast<GLfloat *>(value));
    }
    inline void  glUniformSubroutinesuiv(GLenum  shadertype, GLsizei  count, const GLuint *  indices) {
        return sstd::_sstd_glUniformSubroutinesuiv(shadertype, count, const_cast<GLuint *>(indices));
    }
    inline GLboolean  glUnmapBuffer(GLenum  target) {
        return sstd::_sstd_glUnmapBuffer(target);
    }
    inline GLboolean  glUnmapNamedBuffer(GLuint  buffer) {
        return sstd::_sstd_glUnmapNamedBuffer(buffer);
    }
    inline void  glUseProgram(GLuint  program) {
        return sstd::_sstd_glUseProgram(program);
    }
    inline void  glUseProgramStages(GLuint  pipeline, GLbitfield  stages, GLuint  program) {
        return sstd::_sstd_glUseProgramStages(pipeline, stages, program);
    }
    inline void  glValidateProgram(GLuint  program) {
        return sstd::_sstd_glValidateProgram(program);
    }
    inline void  glValidateProgramPipeline(GLuint  pipeline) {
        return sstd::_sstd_glValidateProgramPipeline(pipeline);
    }
    inline void  glVertexArrayAttribBinding(GLuint  vaobj, GLuint  attribindex, GLuint  bindingindex) {
        return sstd::_sstd_glVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
    }
    inline void  glVertexArrayAttribFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLboolean  normalized, GLuint  relativeoffset) {
        return sstd::_sstd_glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset);
    }
    inline void  glVertexArrayAttribIFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
        return sstd::_sstd_glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset);
    }
    inline void  glVertexArrayAttribLFormat(GLuint  vaobj, GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
        return sstd::_sstd_glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset);
    }
    inline void  glVertexArrayBindingDivisor(GLuint  vaobj, GLuint  bindingindex, GLuint  divisor) {
        return sstd::_sstd_glVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
    }
    inline void  glVertexArrayElementBuffer(GLuint  vaobj, GLuint  buffer) {
        return sstd::_sstd_glVertexArrayElementBuffer(vaobj, buffer);
    }
    inline void  glVertexArrayVertexBuffer(GLuint  vaobj, GLuint  bindingindex, GLuint  buffer, GLintptr  offset, GLsizei  stride) {
        return sstd::_sstd_glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
    }
    inline void  glVertexArrayVertexBuffers(GLuint  vaobj, GLuint  first, GLsizei  count, const GLuint *  buffers, const GLintptr *  offsets, const GLsizei *  strides) {
        return sstd::_sstd_glVertexArrayVertexBuffers(vaobj, first, count, const_cast<GLuint *>(buffers), const_cast<GLintptr *>(offsets), const_cast<GLsizei *>(strides));
    }
    inline void  glVertexAttrib1d(GLuint  index, GLdouble  x) {
        return sstd::_sstd_glVertexAttrib1d(index, x);
    }
    inline void  glVertexAttrib1dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttrib1dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttrib1f(GLuint  index, GLfloat  x) {
        return sstd::_sstd_glVertexAttrib1f(index, x);
    }
    inline void  glVertexAttrib1fv(GLuint  index, const GLfloat *  v) {
        return sstd::_sstd_glVertexAttrib1fv(index, const_cast<GLfloat *>(v));
    }
    inline void  glVertexAttrib1s(GLuint  index, GLshort  x) {
        return sstd::_sstd_glVertexAttrib1s(index, x);
    }
    inline void  glVertexAttrib1sv(GLuint  index, const GLshort *  v) {
        return sstd::_sstd_glVertexAttrib1sv(index, const_cast<GLshort *>(v));
    }
    inline void  glVertexAttrib2d(GLuint  index, GLdouble  x, GLdouble  y) {
        return sstd::_sstd_glVertexAttrib2d(index, x, y);
    }
    inline void  glVertexAttrib2dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttrib2dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttrib2f(GLuint  index, GLfloat  x, GLfloat  y) {
        return sstd::_sstd_glVertexAttrib2f(index, x, y);
    }
    inline void  glVertexAttrib2fv(GLuint  index, const GLfloat *  v) {
        return sstd::_sstd_glVertexAttrib2fv(index, const_cast<GLfloat *>(v));
    }
    inline void  glVertexAttrib2s(GLuint  index, GLshort  x, GLshort  y) {
        return sstd::_sstd_glVertexAttrib2s(index, x, y);
    }
    inline void  glVertexAttrib2sv(GLuint  index, const GLshort *  v) {
        return sstd::_sstd_glVertexAttrib2sv(index, const_cast<GLshort *>(v));
    }
    inline void  glVertexAttrib3d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z) {
        return sstd::_sstd_glVertexAttrib3d(index, x, y, z);
    }
    inline void  glVertexAttrib3dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttrib3dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttrib3f(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  z) {
        return sstd::_sstd_glVertexAttrib3f(index, x, y, z);
    }
    inline void  glVertexAttrib3fv(GLuint  index, const GLfloat *  v) {
        return sstd::_sstd_glVertexAttrib3fv(index, const_cast<GLfloat *>(v));
    }
    inline void  glVertexAttrib3s(GLuint  index, GLshort  x, GLshort  y, GLshort  z) {
        return sstd::_sstd_glVertexAttrib3s(index, x, y, z);
    }
    inline void  glVertexAttrib3sv(GLuint  index, const GLshort *  v) {
        return sstd::_sstd_glVertexAttrib3sv(index, const_cast<GLshort *>(v));
    }
    inline void  glVertexAttrib4Nbv(GLuint  index, const GLbyte *  v) {
        return sstd::_sstd_glVertexAttrib4Nbv(index, const_cast<GLbyte *>(v));
    }
    inline void  glVertexAttrib4Niv(GLuint  index, const GLint *  v) {
        return sstd::_sstd_glVertexAttrib4Niv(index, const_cast<GLint *>(v));
    }
    inline void  glVertexAttrib4Nsv(GLuint  index, const GLshort *  v) {
        return sstd::_sstd_glVertexAttrib4Nsv(index, const_cast<GLshort *>(v));
    }
    inline void  glVertexAttrib4Nub(GLuint  index, GLubyte  x, GLubyte  y, GLubyte  z, GLubyte  w) {
        return sstd::_sstd_glVertexAttrib4Nub(index, x, y, z, w);
    }
    inline void  glVertexAttrib4Nubv(GLuint  index, const GLubyte *  v) {
        return sstd::_sstd_glVertexAttrib4Nubv(index, const_cast<GLubyte *>(v));
    }
    inline void  glVertexAttrib4Nuiv(GLuint  index, const GLuint *  v) {
        return sstd::_sstd_glVertexAttrib4Nuiv(index, const_cast<GLuint *>(v));
    }
    inline void  glVertexAttrib4Nusv(GLuint  index, const GLushort *  v) {
        return sstd::_sstd_glVertexAttrib4Nusv(index, const_cast<GLushort *>(v));
    }
    inline void  glVertexAttrib4bv(GLuint  index, const GLbyte *  v) {
        return sstd::_sstd_glVertexAttrib4bv(index, const_cast<GLbyte *>(v));
    }
    inline void  glVertexAttrib4d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w) {
        return sstd::_sstd_glVertexAttrib4d(index, x, y, z, w);
    }
    inline void  glVertexAttrib4dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttrib4dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttrib4f(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  z, GLfloat  w) {
        return sstd::_sstd_glVertexAttrib4f(index, x, y, z, w);
    }
    inline void  glVertexAttrib4fv(GLuint  index, const GLfloat *  v) {
        return sstd::_sstd_glVertexAttrib4fv(index, const_cast<GLfloat *>(v));
    }
    inline void  glVertexAttrib4iv(GLuint  index, const GLint *  v) {
        return sstd::_sstd_glVertexAttrib4iv(index, const_cast<GLint *>(v));
    }
    inline void  glVertexAttrib4s(GLuint  index, GLshort  x, GLshort  y, GLshort  z, GLshort  w) {
        return sstd::_sstd_glVertexAttrib4s(index, x, y, z, w);
    }
    inline void  glVertexAttrib4sv(GLuint  index, const GLshort *  v) {
        return sstd::_sstd_glVertexAttrib4sv(index, const_cast<GLshort *>(v));
    }
    inline void  glVertexAttrib4ubv(GLuint  index, const GLubyte *  v) {
        return sstd::_sstd_glVertexAttrib4ubv(index, const_cast<GLubyte *>(v));
    }
    inline void  glVertexAttrib4uiv(GLuint  index, const GLuint *  v) {
        return sstd::_sstd_glVertexAttrib4uiv(index, const_cast<GLuint *>(v));
    }
    inline void  glVertexAttrib4usv(GLuint  index, const GLushort *  v) {
        return sstd::_sstd_glVertexAttrib4usv(index, const_cast<GLushort *>(v));
    }
    inline void  glVertexAttribBinding(GLuint  attribindex, GLuint  bindingindex) {
        return sstd::_sstd_glVertexAttribBinding(attribindex, bindingindex);
    }
    inline void  glVertexAttribDivisor(GLuint  index, GLuint  divisor) {
        return sstd::_sstd_glVertexAttribDivisor(index, divisor);
    }
    inline void  glVertexAttribFormat(GLuint  attribindex, GLint  size, GLenum  type, GLboolean  normalized, GLuint  relativeoffset) {
        return sstd::_sstd_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
    }
    inline void  glVertexAttribI1i(GLuint  index, GLint  x) {
        return sstd::_sstd_glVertexAttribI1i(index, x);
    }
    inline void  glVertexAttribI1iv(GLuint  index, const GLint *  v) {
        return sstd::_sstd_glVertexAttribI1iv(index, const_cast<GLint *>(v));
    }
    inline void  glVertexAttribI1ui(GLuint  index, GLuint  x) {
        return sstd::_sstd_glVertexAttribI1ui(index, x);
    }
    inline void  glVertexAttribI1uiv(GLuint  index, const GLuint *  v) {
        return sstd::_sstd_glVertexAttribI1uiv(index, const_cast<GLuint *>(v));
    }
    inline void  glVertexAttribI2i(GLuint  index, GLint  x, GLint  y) {
        return sstd::_sstd_glVertexAttribI2i(index, x, y);
    }
    inline void  glVertexAttribI2iv(GLuint  index, const GLint *  v) {
        return sstd::_sstd_glVertexAttribI2iv(index, const_cast<GLint *>(v));
    }
    inline void  glVertexAttribI2ui(GLuint  index, GLuint  x, GLuint  y) {
        return sstd::_sstd_glVertexAttribI2ui(index, x, y);
    }
    inline void  glVertexAttribI2uiv(GLuint  index, const GLuint *  v) {
        return sstd::_sstd_glVertexAttribI2uiv(index, const_cast<GLuint *>(v));
    }
    inline void  glVertexAttribI3i(GLuint  index, GLint  x, GLint  y, GLint  z) {
        return sstd::_sstd_glVertexAttribI3i(index, x, y, z);
    }
    inline void  glVertexAttribI3iv(GLuint  index, const GLint *  v) {
        return sstd::_sstd_glVertexAttribI3iv(index, const_cast<GLint *>(v));
    }
    inline void  glVertexAttribI3ui(GLuint  index, GLuint  x, GLuint  y, GLuint  z) {
        return sstd::_sstd_glVertexAttribI3ui(index, x, y, z);
    }
    inline void  glVertexAttribI3uiv(GLuint  index, const GLuint *  v) {
        return sstd::_sstd_glVertexAttribI3uiv(index, const_cast<GLuint *>(v));
    }
    inline void  glVertexAttribI4bv(GLuint  index, const GLbyte *  v) {
        return sstd::_sstd_glVertexAttribI4bv(index, const_cast<GLbyte *>(v));
    }
    inline void  glVertexAttribI4i(GLuint  index, GLint  x, GLint  y, GLint  z, GLint  w) {
        return sstd::_sstd_glVertexAttribI4i(index, x, y, z, w);
    }
    inline void  glVertexAttribI4iv(GLuint  index, const GLint *  v) {
        return sstd::_sstd_glVertexAttribI4iv(index, const_cast<GLint *>(v));
    }
    inline void  glVertexAttribI4sv(GLuint  index, const GLshort *  v) {
        return sstd::_sstd_glVertexAttribI4sv(index, const_cast<GLshort *>(v));
    }
    inline void  glVertexAttribI4ubv(GLuint  index, const GLubyte *  v) {
        return sstd::_sstd_glVertexAttribI4ubv(index, const_cast<GLubyte *>(v));
    }
    inline void  glVertexAttribI4ui(GLuint  index, GLuint  x, GLuint  y, GLuint  z, GLuint  w) {
        return sstd::_sstd_glVertexAttribI4ui(index, x, y, z, w);
    }
    inline void  glVertexAttribI4uiv(GLuint  index, const GLuint *  v) {
        return sstd::_sstd_glVertexAttribI4uiv(index, const_cast<GLuint *>(v));
    }
    inline void  glVertexAttribI4usv(GLuint  index, const GLushort *  v) {
        return sstd::_sstd_glVertexAttribI4usv(index, const_cast<GLushort *>(v));
    }
    inline void  glVertexAttribIFormat(GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
        return sstd::_sstd_glVertexAttribIFormat(attribindex, size, type, relativeoffset);
    }
    inline void  glVertexAttribIPointer(GLuint  index, GLint  size, GLenum  type, GLsizei  stride, const void *  pointer) {
        return sstd::_sstd_glVertexAttribIPointer(index, size, type, stride, const_cast<void *>(pointer));
    }
    inline void  glVertexAttribL1d(GLuint  index, GLdouble  x) {
        return sstd::_sstd_glVertexAttribL1d(index, x);
    }
    inline void  glVertexAttribL1dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttribL1dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttribL2d(GLuint  index, GLdouble  x, GLdouble  y) {
        return sstd::_sstd_glVertexAttribL2d(index, x, y);
    }
    inline void  glVertexAttribL2dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttribL2dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttribL3d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z) {
        return sstd::_sstd_glVertexAttribL3d(index, x, y, z);
    }
    inline void  glVertexAttribL3dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttribL3dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttribL4d(GLuint  index, GLdouble  x, GLdouble  y, GLdouble  z, GLdouble  w) {
        return sstd::_sstd_glVertexAttribL4d(index, x, y, z, w);
    }
    inline void  glVertexAttribL4dv(GLuint  index, const GLdouble *  v) {
        return sstd::_sstd_glVertexAttribL4dv(index, const_cast<GLdouble *>(v));
    }
    inline void  glVertexAttribLFormat(GLuint  attribindex, GLint  size, GLenum  type, GLuint  relativeoffset) {
        return sstd::_sstd_glVertexAttribLFormat(attribindex, size, type, relativeoffset);
    }
    inline void  glVertexAttribLPointer(GLuint  index, GLint  size, GLenum  type, GLsizei  stride, const void *  pointer) {
        return sstd::_sstd_glVertexAttribLPointer(index, size, type, stride, const_cast<void *>(pointer));
    }
    inline void  glVertexAttribP1ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
        return sstd::_sstd_glVertexAttribP1ui(index, type, normalized, value);
    }
    inline void  glVertexAttribP1uiv(GLuint  index, GLenum  type, GLboolean  normalized, const GLuint *  value) {
        return sstd::_sstd_glVertexAttribP1uiv(index, type, normalized, const_cast<GLuint *>(value));
    }
    inline void  glVertexAttribP2ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
        return sstd::_sstd_glVertexAttribP2ui(index, type, normalized, value);
    }
    inline void  glVertexAttribP2uiv(GLuint  index, GLenum  type, GLboolean  normalized, const GLuint *  value) {
        return sstd::_sstd_glVertexAttribP2uiv(index, type, normalized, const_cast<GLuint *>(value));
    }
    inline void  glVertexAttribP3ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
        return sstd::_sstd_glVertexAttribP3ui(index, type, normalized, value);
    }
    inline void  glVertexAttribP3uiv(GLuint  index, GLenum  type, GLboolean  normalized, const GLuint *  value) {
        return sstd::_sstd_glVertexAttribP3uiv(index, type, normalized, const_cast<GLuint *>(value));
    }
    inline void  glVertexAttribP4ui(GLuint  index, GLenum  type, GLboolean  normalized, GLuint  value) {
        return sstd::_sstd_glVertexAttribP4ui(index, type, normalized, value);
    }
    inline void  glVertexAttribP4uiv(GLuint  index, GLenum  type, GLboolean  normalized, const GLuint *  value) {
        return sstd::_sstd_glVertexAttribP4uiv(index, type, normalized, const_cast<GLuint *>(value));
    }
    inline void  glVertexAttribPointer(GLuint  index, GLint  size, GLenum  type, GLboolean  normalized, GLsizei  stride, const void *  pointer) {
        return sstd::_sstd_glVertexAttribPointer(index, size, type, normalized, stride, const_cast<void *>(pointer));
    }
    inline void  glVertexBindingDivisor(GLuint  bindingindex, GLuint  divisor) {
        return sstd::_sstd_glVertexBindingDivisor(bindingindex, divisor);
    }
    inline void  glViewport(GLint  x, GLint  y, GLsizei  width, GLsizei  height) {
        return sstd::_sstd_glViewport(x, y, width, height);
    }
    inline void  glViewportArrayv(GLuint  first, GLsizei  count, const GLfloat *  v) {
        return sstd::_sstd_glViewportArrayv(first, count, const_cast<GLfloat *>(v));
    }
    inline void  glViewportIndexedf(GLuint  index, GLfloat  x, GLfloat  y, GLfloat  w, GLfloat  h) {
        return sstd::_sstd_glViewportIndexedf(index, x, y, w, h);
    }
    inline void  glViewportIndexedfv(GLuint  index, const GLfloat *  v) {
        return sstd::_sstd_glViewportIndexedfv(index, const_cast<GLfloat *>(v));
    }
    inline void  glWaitSync(GLsync  sync, GLbitfield  flags, GLuint64  timeout) {
        return sstd::_sstd_glWaitSync(sync, flags, timeout);
    }
}
