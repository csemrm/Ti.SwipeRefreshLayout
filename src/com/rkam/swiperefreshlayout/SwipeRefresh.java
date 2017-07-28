package com.rkam.swiperefreshlayout;

import org.appcelerator.titanium.TiApplication;
import org.appcelerator.titanium.view.TiUIView;
import org.appcelerator.titanium.util.TiRHelper;
import org.appcelerator.titanium.util.TiRHelper.ResourceNotFoundException;

import android.support.v4.widget.SwipeRefreshLayout.OnRefreshListener;
import android.view.LayoutInflater;
import android.util.Log;

public class SwipeRefresh extends TiUIView {

	public static final String PROPERTY_VIEW = "view";
	public static final String PROPERTY_COLOR_SCHEME = "colorScheme";
	private static final String TAG = "SwipeRefresh";

	int color1 = 0;
	int color2 = 0;
	int color3 = 0;
	int color4 = 0;
	int layout_swipe_refresh = 0;

	// Constructor for SwipeRefresh
	public SwipeRefresh(final SwipeRefreshProxy proxy) {
		super(proxy);

		try {
			layout_swipe_refresh = TiRHelper.getResource("layout.swipe_refresh");
			color1 = TiRHelper.getResource("color.color1");
			color2 = TiRHelper.getResource("color.color2");
			color3 = TiRHelper.getResource("color.color3");
			color4 = TiRHelper.getResource("color.color4");
		}
		catch (ResourceNotFoundException e) {
			Log.e(TAG, "Resources not found!");
		}

		LayoutInflater inflater = LayoutInflater.from(TiApplication.getInstance());
		MySwipeRefreshLayout layout =
				(MySwipeRefreshLayout) inflater.inflate(layout_swipe_refresh, null, false);

		layout.setOnRefreshListener(new OnRefreshListener() {
			@Override
			public void onRefresh() {
				if (proxy.hasListeners("refreshing")) {
					proxy.fireEvent("refreshing", null);
				}
			}
		});

		setNativeView(layout);
	}

	@Override
	public void add(TiUIView child)
	{
		MySwipeRefreshLayout layout = (MySwipeRefreshLayout) getNativeView();
		layout.setNativeView(child.getNativeView());
		super.add(child);
		layout.setColorSchemeColors(color1, color2, color3, color4);
	}

	public boolean isRefreshing() {
		MySwipeRefreshLayout layout = (MySwipeRefreshLayout) getNativeView();
		if (layout != null) {
			return layout.isRefreshing();
		}
		return false;
	}

	public void setRefreshing(boolean refreshing) {
		MySwipeRefreshLayout layout = (MySwipeRefreshLayout) getNativeView();
		if (layout != null) {
			layout.setRefreshing(refreshing);
		}
	}

	@Override
	public void release() {
		Log.d(TAG, "release");
		MySwipeRefreshLayout layout = (MySwipeRefreshLayout) getNativeView();
		if (layout != null) {
			layout.removeAllViews();
			layout.setRefreshing(false);
			layout.setOnRefreshListener(null);
		}
		super.release();
		proxy = null;
	}

}
