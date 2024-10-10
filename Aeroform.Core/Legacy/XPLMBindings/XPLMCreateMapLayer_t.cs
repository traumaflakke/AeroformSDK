//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.2.1
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace Aeroform.Core.Legacy.XPLMBindings {

public class XPLMCreateMapLayer_t : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal XPLMCreateMapLayer_t(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(XPLMCreateMapLayer_t obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(XPLMCreateMapLayer_t obj) {
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

  ~XPLMCreateMapLayer_t() {
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
          XPlaneWrappersPINVOKE.delete_XPLMCreateMapLayer_t(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public int structSize {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_structSize_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_structSize_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string mapToCreateLayerIn {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_mapToCreateLayerIn_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_mapToCreateLayerIn_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int layerType {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_layerType_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_layerType_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_void_p_void__void willBeDeletedCallback {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_willBeDeletedCallback_set(swigCPtr, SWIGTYPE_p_f_p_void_p_void__void.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_willBeDeletedCallback_get(swigCPtr);
      SWIGTYPE_p_f_p_void_p_void__void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_void_p_void__void(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_void_p_q_const__float_p_void_p_void__void prepCacheCallback {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_prepCacheCallback_set(swigCPtr, SWIGTYPE_p_f_p_void_p_q_const__float_p_void_p_void__void.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_prepCacheCallback_get(swigCPtr);
      SWIGTYPE_p_f_p_void_p_q_const__float_p_void_p_void__void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_void_p_q_const__float_p_void_p_void__void(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void drawCallback {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_drawCallback_set(swigCPtr, SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_drawCallback_get(swigCPtr);
      SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void iconCallback {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_iconCallback_set(swigCPtr, SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_iconCallback_get(swigCPtr);
      SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void labelCallback {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_labelCallback_set(swigCPtr, SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_labelCallback_get(swigCPtr);
      SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_f_p_void_p_q_const__float_float_float_int_p_void_p_void__void(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public int showUiToggle {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_showUiToggle_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      int ret = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_showUiToggle_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public string layerName {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_layerName_set(swigCPtr, value);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      string ret = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_layerName_get(swigCPtr);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public SWIGTYPE_p_void refcon {
    set {
      XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_refcon_set(swigCPtr, SWIGTYPE_p_void.getCPtr(value));
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      global::System.IntPtr cPtr = XPlaneWrappersPINVOKE.XPLMCreateMapLayer_t_refcon_get(swigCPtr);
      SWIGTYPE_p_void ret = (cPtr == global::System.IntPtr.Zero) ? null : new SWIGTYPE_p_void(cPtr, false);
      if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public XPLMCreateMapLayer_t() : this(XPlaneWrappersPINVOKE.new_XPLMCreateMapLayer_t(), true) {
    if (XPlaneWrappersPINVOKE.SWIGPendingException.Pending) throw XPlaneWrappersPINVOKE.SWIGPendingException.Retrieve();
  }

}

}