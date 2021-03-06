import smuview
import time

# Connect the demo device (it's just one!)
demo_dev = devices = Session.connect_device("demo")[0]

# Add a user device
user_dev = Session.add_user_device()

# Show tab for demo device
UiProxy.add_device_tab(demo_dev)

# Show tab for user device
UiProxy.add_device_tab(user_dev)

# Sleep 1 second to give the newly connected demo device the chance to create data and the corresponding signals. TODO
time.sleep(1)

# Get device id of user device
user_dev_id = user_dev.id()

# Add a data view to the device tab
UiProxy.add_data_view(user_dev_id, smuview.DockArea.TopDockArea, demo_dev.channels()["A1"].actual_signal())

# Add a control view to the device tab
UiProxy.add_control_view(user_dev_id, smuview.DockArea.TopDockArea, demo_dev.configurables()["A1"])

# Add plot view (1) with a channel to the device tab
plot_view_1 = UiProxy.add_plot_view(user_dev_id, smuview.DockArea.BottomDockArea, demo_dev.channels()["A1"])

# Add a plot view (2) with a signal to the device tab
plot_view_2 = UiProxy.add_plot_view(user_dev_id, smuview.DockArea.BottomDockArea, demo_dev.channels()["A1"].actual_signal());

# Add a x/y plot view (3) with two signals to the device tab
UiProxy.add_plot_view(user_dev_id, smuview.DockArea.BottomDockArea, demo_dev.channels()["A1"].actual_signal(), demo_dev.channels()["A2"].actual_signal())

# Add a power panel view to the device tab
UiProxy.add_power_panel_view(user_dev_id, smuview.DockArea.BottomDockArea, demo_dev.channels()["A1"].actual_signal(), demo_dev.channels()["A2"].actual_signal())

# Add a value panel view to the device tab
UiProxy.add_value_panel_view(user_dev_id, smuview.DockArea.TopDockArea, demo_dev.channels()["A1"])

# Add a value panel view to the device tab
UiProxy.add_value_panel_view(user_dev_id, smuview.DockArea.TopDockArea, demo_dev.channels()["A1"].actual_signal())

# Add a signal to the existing plot view (1)
UiProxy.add_signal_to_plot(user_dev_id, plot_view_1, demo_dev.channels()["A3"].actual_signal())

# Add a signal to the existing plot view (2)
UiProxy.add_signal_to_plot(user_dev_id, plot_view_2, demo_dev.channels()["A3"].actual_signal())

# Add a signal to the existing plot view (3)
# TODO: not working yet
#UiProxy.add_signal_to_plot(user_dev_id, "plot_xy:A1 [V DC]:A2 [V DC]", demo_dev.channels()["A3"].actual_signal())
