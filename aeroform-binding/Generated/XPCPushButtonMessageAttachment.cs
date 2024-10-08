//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace Aeroform.Unmanaged.XPLMBindings {

public class XPCPushButtonMessageAttachment : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal XPCPushButtonMessageAttachment(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(XPCPushButtonMessageAttachment obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(XPCPushButtonMessageAttachment obj) {
    if (obj != null) {
      if (!obj.swigCMemOwn)
        throw new global::System.ApplicationException("Cannot release ownership as memory is not owned");
      global::System.Runtime.InteropServices.HandleRef ptr = obj.swigCPtr;
      obj.swigCMemOwn = false;
      obj.Dispose();
      return ptr;
    } else {
      return new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
    }
  }

  ~XPCPushButtonMessageAttachment() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          XPlaneWrappersPINVOKE.delete_XPCPushButtonMessageAttachment(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public XPCPushButtonMessageAttachment(SWIGTYPE_p_void inWidget, int inMessage, SWIGTYPE_p_void inParam, XPCListener inListener) : this(XPlaneWrappersPINVOKE.new_XPCPushButtonMessageAttachment(SWIGTYPE_p_void.getCPtr(inWidget), inMessage, SWIGTYPE_p_void.getCPtr(inParam), XPCListener.getCPtr(inListener)), true) {
    if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
  }

  public virtual int HandleWidgetMessage(XPCWidget inObject, int inMessage, SWIGTYPE_p_void inWidget, SWIGTYPE_p_intptr_t inParam1, SWIGTYPE_p_intptr_t inParam2) {
    int ret = XPlaneWrappersPINVOKE.XPCPushButtonMessageAttachment_HandleWidgetMessage(swigCPtr, XPCWidget.getCPtr(inObject), inMessage, SWIGTYPE_p_void.getCPtr(inWidget), SWIGTYPE_p_intptr_t.getCPtr(inParam1), SWIGTYPE_p_intptr_t.getCPtr(inParam2));
    if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
