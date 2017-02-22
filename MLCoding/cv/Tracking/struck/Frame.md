# Main
- 读取配置文件，初始化了boundingbox(initBB),从groudtruth中得到第一帧目标的位置
- 根据配置文件得到给定的图片的列表范围
- 初始化Tracker(conf),调用Tracker的Reset函数，并在Initizlise函数中传入当前帧和目标位置bb，然后for循环每一帧，读取并归一化大小为默认的３２０＊２４０，Tracker在main中设置为全局的，所以对于每一帧要重置。然后Tracker.track(frame)得到当前帧的bb,并画出bb

# Tracker
