package com.rkam.swiperefreshlayout;

import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.titanium.proxy.TiViewProxy;
import org.appcelerator.titanium.view.TiUIView;
import org.appcelerator.titanium.TiApplication;

import android.app.Activity;
import android.os.Handler;
import android.os.Message;

@Kroll.proxy(creatableInModule=SwiperefreshlayoutModule.class)
public class SwipeRefreshProxy extends TiViewProxy implements Handler.Callback {

	protected static final int MSG_SET_REFRESHING = KrollProxy.MSG_LAST_ID + 101;

	private static final String TAG = "SwipeRefreshProxy";

	public SwipeRefreshProxy() {
		super();
	}

	@Override
	public TiUIView createView(Activity activity) {
		return new SwipeRefresh(this);
	}
    
	/* Public API */
	
	@Kroll.method
	public void setRefreshing(boolean refreshing) {
        if (TiApplication.isUIThread()) {
            doSetRefreshing(refreshing);
        } else {
            Message message = getMainHandler().obtainMessage(MSG_SET_REFRESHING, refreshing);
            message.sendToTarget();
        }

	}
    
	@Kroll.method @Kroll.getProperty
	public boolean isRefreshing() {
		SwipeRefresh v = (SwipeRefresh) peekView();
		if (v != null) {
			return v.isRefreshing();
		}
		return false;
	}
    
	/* Utilities */
    
	public boolean handleMessage(Message message) {
		switch (message.what) {
			case MSG_SET_REFRESHING: {
				doSetRefreshing((Boolean) message.obj);
				return true;
			}
		}
		
		return super.handleMessage(message);
	}
	
	protected void doSetRefreshing(boolean refreshing) {
		SwipeRefresh v = (SwipeRefresh) peekView();
		if (v != null) {
			v.setRefreshing(refreshing);
		}
	}
}
