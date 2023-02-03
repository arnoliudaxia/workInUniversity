
<map>
  <node ID="root" TEXT="Pre_Massive Rigid-Body Simulation">
    <node TEXT="前言" ID="006cad1ad1614207b975a8f70fb4f84e" STYLE="bubble" POSITION="right">
      <node TEXT="主要参考Erin Catto的《Iterative Dynamics with Temporal Coherence》—— 2005" ID="50a3f9f5be8c1862f3deeb85d346ba82" STYLE="fork"/>
      <node TEXT="box2d物理引擎的早期版本" ID="f7ec7e937258bcd0d9af8a3b5fdaae50" STYLE="fork"/>
      <node TEXT="参考其他现代物理引擎，例如bullet和unity" ID="8f66319e98287e2b53715bb423fe2058" STYLE="fork"/>
    </node>
    <node TEXT="大体流程" ID="4db35fe6298f11170096e70c2305d6e6" STYLE="bubble" POSITION="right">
      <node TEXT="" ID="d32aff3e069509ce3e902ac946fc469b" STYLE="fork">
        <node TEXT="在mass spring homework中，只实现了分析。。和更新。。两个部分" ID="b8562e1a284fe9d39b4e4f4eaf8588ba" STYLE="fork"/>
        <node TEXT="为了实现多个物体之间的交互，需要做物体之间的碰撞演算" ID="641b923ff51e8586bb60116640f870fe" STYLE="fork"/>
      </node>
      <node TEXT="" ID="61f41db1caba118bc3820c5a419efea7" STYLE="fork"/>
    </node>
    <node TEXT="碰撞对计算" ID="bd6b72f65c292eef99cbfe32522a18e6" STYLE="bubble" POSITION="right">
      <node TEXT="Broad-Phase 粗略检测" ID="12d9fcba4ef4998593c2995129be2b50" STYLE="fork">
        <node TEXT="Motivation" ID="91358b89108d00966c8e6d1daa1c0377" STYLE="fork"/>
        <node TEXT="使用某种Bounding Volume来表示刚体的碰撞信息,然后用空间划分的方式来保存这些Bounding Volume,就可以再较短的时间内筛选出可能互相碰撞的刚体对." ID="95d124148de5e3d45605d825e1319020" STYLE="fork"/>
        <node TEXT="AABB(axis-aligned bounding boxes), OBB(oriented bounding boxes), Circle/Sphere." ID="73de1f84332c3917c8fc130b22421403" STYLE="fork"/>
      </node>
      <node TEXT="Narrow-Phase 精细检测" ID="c5df0c995ef31b6b77bbcfaff27721b6" STYLE="fork">
        <node TEXT="在Broad-Phase初步的筛选过后,我们选出所有可能会碰撞的几何体对,再对这些几何体进行碰撞检测." ID="87bedd870b464fd1d5f5804a93559046" STYLE="fork"/>
        <node TEXT="凸几何体" ID="3824f0c7df046ddf5e9b946643dad9cd" STYLE="fork">
          <node TEXT="如果在一个几何体内任意两点组成的线段必定落在几何体内,就称这个几何体为凸几何体.与之对应的是凹几何体,计算凹几何体的碰撞往往要复杂的多,几乎所有的碰撞算法都默认以凸几何体为基础." ID="25349faf721b39b487a736a6f133b61c" STYLE="fork"/>
          <node TEXT="对于凹几何体,可以使用QuickHull算法生成一个凸几何体" ID="752802c4ecaef2a292478fc7eed6b592" STYLE="fork"/>
        </node>
        <node TEXT="碰撞检测" ID="8e9dbb6c58a4bf3aafca06f8bc21d440" STYLE="fork">
          <node TEXT="标准几何体" ID="2367d53d95f2cd4945f396f080b8a1df" STYLE="fork">
            <node TEXT="比如两个球形之间,判断两个圆心的距离是否大于半径之和,就能直接计算出是否碰撞." ID="82746007f2edd203424133eacab80b68" STYLE="fork"/>
          </node>
          <node TEXT="凸几何体" ID="0bc5dba68518335ddcfda4ba82515afa" STYLE="fork">
            <node TEXT="Separating Axis Theorem(SAT)" ID="99e0f33ad445f9faca64c12191f10f66" STYLE="fork">
              <node TEXT="若两个物体没有发生碰撞，则总会存在一条直线，能将两个物体分离" ID="8869d6f90df8592fdafd9329a93bdba8" STYLE="fork"/>
              <node TEXT="投影" ID="eddbe263be0335ae63114668137da804" STYLE="fork">
                <node TEXT="两个投影点集合的交集是否为空集 。如果是空集，则存在一条轴，将两个投影点集分隔开，如果是非空集合，则找不到这样的轴。" ID="29bfc83f77686461190875f20063c412" STYLE="fork"/>
                <node TEXT="对x轴和y轴投影之后，全都是非空集合 ，那么，我们可以判定两个矩形发生碰撞。" ID="52383e9102c6b26e6d5da5df7a4e2c8f" STYLE="fork"/>
              </node>
              <node TEXT="对于多边形将两个多边形的顶点投影在 多边形每条边的中垂线上" ID="42ee1e3fd421e8e85bd619fa4e49af97" STYLE="fork">
                <node TEXT="以蓝色多边形的 AB 边开始" ID="13c4819e7beaec47a0e11ce844d54db9" STYLE="fork"/>
                <node TEXT="将两个多边形的所有边进行如上操作" ID="5ce846e7ed1d8ab20b9b60b0bf8a1a6f" STYLE="fork"/>
                <node TEXT="每一个投影都存在红色的重叠部分，意味着可以判断两个多边形 发生碰撞。而我们所标记的红色重叠线段中，长度最小 的线段长度，称为 穿透深度" ID="a1eeb88c08ad8bca7ca1aed64fc1b163" STYLE="fork"/>
                <node TEXT="穿透矢量（Penetration Vector）" ID="efc76b654819f99b8e9c32ab057f127d" STYLE="fork"/>
                <node TEXT="" ID="7dce5b94acb83a2a1763ed2f23a9f768" STYLE="fork"/>
              </node>
            </node>
            <node TEXT="Gilbert-Johnson-Keerthi (GJK)" ID="e033c4b8dee0ef13e87abfa229b7cc43" STYLE="fork"/>
            <node TEXT="Expanding Polytope Algorithm(EPA)" ID="581878d6207067ed51e6c6be85603f55" STYLE="fork"/>
          </node>
        </node>
      </node>
    </node>
    <node TEXT="Constraints" ID="7530ba7ca36f0e49c9eb063120c24914" STYLE="bubble" POSITION="right">
      <node TEXT="介绍" ID="1d291ba9659d93bf7f849be42e5d6669" STYLE="fork">
        <node TEXT="位置约束" ID="160b60df9d24ad4408fa2a2f9f9b6297" STYLE="fork">
          <node TEXT="用 C 表示这个坡道上的位置约束," ID="499c2b0933ac83adbd47025018b755fe" STYLE="fork"/>
          <node TEXT="" ID="41ae07d2574aa8fee0a579c48c121f71" STYLE="fork"/>
        </node>
        <node TEXT="速度约束" ID="5bd6afb4e873506d0a03c26a0f5ca042" STYLE="fork">
          <node TEXT="接触约束(contact constraint)" ID="5f4484826d218c03c8f515bb89471465" STYLE="fork">
            <node TEXT="AB之间必须接触，两个物体的接触点不会沿着接触的法线方向移动." ID="5e72d9ea5c6f7588b634860df012fc16" STYLE="fork">
              <node TEXT="很容易得到位置约束 C 的表示." ID="11f62b885d9bb1e4c5c81b0af0a63abd" STYLE="fork"/>
              <node TEXT="将 C 求导,得到一个速度约束的公式:" ID="2602fccaf5106bc3a941a543a85da6fb" STYLE="fork"/>
            </node>
            <node TEXT="因为我们假设地面是固定的,所以有 $\dot {\bm p}_A = 0$ ,而$\bm p_A$和 $\bm p_B$ 其实是相等的,因此我们化简式子得到: $\dot{C} = \dot{\bm p}_B \cdot \bm n$" ID="4b664d60642568c27c758a2468a449e8" STYLE="fork"/>
            <node TEXT="" ID="2af1ef0de57f60322bab2e8bfc476592" STYLE="fork">
              <node TEXT="这个方法也称为 拉格朗日数乘 " ID="c4efd76973d10bde3b3dab92139a17ec" STYLE="fork"/>
            </node>
            <node TEXT="" ID="95682e9d5afc7b89abc8588ad862bf88" STYLE="fork"/>
            <node TEXT="目标：求解lambda" ID="59787404cf365fddcb3c7da7fade8f18" STYLE="fork">
              <node TEXT="" ID="e7b56a9ec48dfb30386d36278cf10622" STYLE="fork"/>
              <node TEXT="" ID="3fb09faa72ed860a4abc4680e3a1a3f1" STYLE="fork"/>
              <node TEXT="" ID="107c102b6b2066c308f910f7584c1976" STYLE="fork"/>
            </node>
          </node>
          <node TEXT="Slop" ID="8bfe612c9dc409b90b07d7b4dfd1802d" STYLE="fork">
            <node TEXT="方块跌落到地面上后，存在持续穿透并且下跌的现象。" ID="706ed415dd2f69dc5b74df7008f238a6" STYLE="fork">
              <node TEXT="动图：https://picx.zhimg.com/v2-e37abf693ced8407bad8cf0fa784d210_720w.webp?source=d16d100b" ID="dbd1d6850191dc38c3f974b2d3cb5b71" STYLE="fork"/>
            </node>
            <node TEXT="https://zhuanlan.zhihu.com/p/411876276#:~:text=%E4%B8%8B%E8%B7%8C%E7%9A%84%E7%8E%B0%E8%B1%A1%E3%80%82-,Slop,-%E6%88%91%E4%BB%AC%E9%9C%80%E8%A6%81%E5%AF%B9" ID="cf1974c2eb43f4f2946d5f4079c81500" STYLE="fork"/>
          </node>
        </node>
        <node TEXT="全局求解器(Global Solvers)和本地求解器(Local Solvers)" ID="c18f0ffaa3a829a4a37f5fc2670ca4de" STYLE="fork">
          <node TEXT="我们成功对单个约束进行求解.下面问题是,如何对多个约束进行求解?" ID="96c80b1c4b6ff099d7f99544e4fe4302" STYLE="fork"/>
          <node TEXT="同时对多个约束进行求解是一件相当困难得工作,在一个约束上得冲量会影响到其他的约束.如果我们把所有的约束放到一起用全局求解器进行求解,就需要构造一个求解的矩阵.比如现在有100个约束,就要构造100x100的矩阵进行求解,对于大部分游戏来说,这个耗时是无法接受的." ID="e6a4f226d7545cfe82f68c7671bc25f6" STYLE="fork"/>
          <node TEXT="连续冲量(Sequential Impulses)" ID="464e6e651738d8f982f20237316a90a1" STYLE="fork">
            <node TEXT="在游戏中更多地还是用本地求解器来进行约束求解,使用多次迭代的方式求解,这样只需要线性的时间和空间消耗." ID="759b7e1fef451681067514d5fa9b5dbb" STYLE="fork"/>
            <node TEXT="假设现在有一堆堆叠在一起的圆形小球,我们来计算接触约束对小球产生的冲量.在开始求解之前,先给每个小球施加一个重力." ID="cf45015d81ca0bc7597fdc6be0feccfc" STYLE="fork"/>
            <node TEXT="按照任意的顺序来对接触冲量进行求解," ID="3cdc92c28b94e9e622f7064810a3fb6b" STYLE="fork"/>
            <node TEXT="收敛" ID="2c0f2b12beba63a711d05c475992e70a" STYLE="fork">
              <node TEXT="如果只有一个小球放在固定平面上,那只需要一次求解就可以收敛到正确的结果." ID="8ee517508b0eb3db444a9cc17da6d5ec" STYLE="fork"/>
              <node TEXT="两个相同质量的小球堆叠,需要5次迭代达到95%收敛." ID="0f5f0b7b3ea5849aab9abc64e0bd1912" STYLE="fork"/>
              <node TEXT="一个轻点的小球放在重的小球上(1:2),只需要3次迭代就能达到95%收敛." ID="29be952f2ccb1f73e96418b43a425859" STYLE="fork"/>
              <node TEXT="一个重的小球放在轻的小球上(2:1),需要更多的次数达到收敛." ID="fc9787cdaacf9a0d5b341ac152b54285" STYLE="fork"/>
              <node TEXT="多个小球堆叠在一起,也会使需要的迭代次数变多." ID="231785caec70c9ac9c019ff1553c2a79" STYLE="fork"/>
            </node>
            <node TEXT="暖启动(warm starting)" ID="68f44e46cec5c9fcdbcef96c13c4ff1f" STYLE="fork">
              <node TEXT="减少迭代次数" ID="dcb3930d07c08f5078a016d634d0c05c" STYLE="fork"/>
              <node TEXT="帧之间是有连贯性" ID="b4150a3c61d9bce4f6f33c75d9df7a8e" STYLE="fork"/>
              <node TEXT="在一帧计算出累积冲量值后保存起来,在下一帧开始计算之前,从上一帧保存的值开始计算." ID="a5fd8ae741d6069fda18896f59afa2ff" STYLE="fork"/>
              <node TEXT="有一定的副作用的,如果负载出现突变,可能会导致没有足够的时间使结果收敛." ID="2038bcaae81a9c2b8ca1695ca98d1e4c" STYLE="fork"/>
            </node>
          </node>
        </node>
      </node>
      <node TEXT="" ID="51bc8afa512ebb1170126a81f183306d" STYLE="fork">
        <node TEXT="" ID="2b84ad95945b9eb9dfa7a23cc29e160a" STYLE="fork"/>
        <node TEXT="" ID="df405bc2c9966f5ac7eec3609d0f87f7" STYLE="fork"/>
      </node>
      <node TEXT="" ID="b1320edc516f0fda964b888d5ddc83ed" STYLE="fork"/>
    </node>
    <node TEXT="Kinematics" ID="a4726fb18642b27adb82dce5207f721c" STYLE="bubble" POSITION="right">
      <node TEXT="Kinematics" ID="7972d096296431accae31d2f11fbc8f5" STYLE="fork"/>
      <node TEXT="" ID="32db3cdc8c48b39dd7c6f82f9ba129a7" STYLE="fork"/>
      <node TEXT="Newton’s Law" ID="12a071523411db649cd67cf996342c71" STYLE="fork">
        <node TEXT="" ID="0fa50dbae903671650825f40ae721b51" STYLE="fork"/>
      </node>
    </node>
    <node TEXT="Math" ID="d92b792bfe273f8fc7c2d68b38d2564f" STYLE="bubble" POSITION="right">
      <node TEXT="Gauss-Seidel" ID="fc4c84cf090a71af47ef7d5167349581" STYLE="fork">
        <node TEXT="目的" ID="e9dbcc5a5489d665ea2e55a7d028a455" STYLE="fork"/>
        <node TEXT="过程" ID="e978d4ac0d039ea91ff2426a2cf23377" STYLE="fork"/>
      </node>
      <node TEXT="Projected Gauss-Seidel" ID="db09ca88b2e66b3a052267f6ea779f2c" STYLE="fork">
        <node TEXT="" ID="9d4eee99c6dbd264346fdbd6e4174661" STYLE="fork"/>
      </node>
    </node>
    <node TEXT="Other topics" ID="f2785fe40bb59131bac74a17ce0f19e5" STYLE="bubble" POSITION="right">
      <node TEXT="Continuous Collision Detection(CCD)" ID="6bc4b14718f02571526b16da6f6e6d4a" STYLE="fork">
        <node TEXT="运动速度很快微小的物体可能出现无法计算到碰撞的隧穿(tunneling)情况" ID="dac14d26e69aceafdc92251accc220f4" STYLE="fork"/>
        <node TEXT="尝试找到两个本来应该碰撞的几何体的碰撞时间time of impact(TOI),并回到那个时间点处理碰撞." ID="b747145016bbeee14ea0c6bd71a891c6" STYLE="fork"/>
        <node TEXT="将两个几何体间的最短距离通过一个函数来表示,然后求这个函数的跟 f(t)=0 ." ID="4ff39f8ea20a12de5bba69397ba37d74" STYLE="fork"/>
        <node TEXT="比如最简单的求两个圆形的碰撞,将两个圆形的距离用函数描述为 d(t)=||x1(t)−x2(t)||−r1−r2 ,问题就变成求一个二次方程的解." ID="9b73d24d11e6d2930e8124dc0e2846fc" STYLE="fork"/>
        <node TEXT="CCD的计算相当耗时,物理引擎一般默认关闭这个功能,需要用到CCD的地方再打开某个物体的CCD开关." ID="5beba75b613f17ca2612c803cbf99764" STYLE="fork"/>
      </node>
      <node TEXT="Collision Response 碰撞反馈" ID="73a27baa104bca1008d8c1572199166e" STYLE="fork">
        <node TEXT="Constrain的替代方案，直接用物理求解碰撞作用" ID="5b2c056303262d8ee3164b240d490127" STYLE="fork"/>
        <node TEXT="两个理想球体质量分别为 m1 m2 ,碰撞前速度为 v1 v2 ,碰撞后的速度为 u1 u2 ." ID="91372661d99b499b0a2b87f18eb1493c" STYLE="fork"/>
        <node TEXT="弹性碰撞(elastic collision)" ID="b1f56bbefd4b7e7aa518af510af0bd6c" STYLE="fork">
          <node TEXT="动能没有损耗,根据动量守恒和能量守恒可得:" ID="cf09eb47d5e6e54ef3e0a33f0af79b3b" STYLE="fork">
            <node TEXT="$m_1u_1 + m_2u_2 = m_1v_1+m_2v_2$" ID="58486bdc93b1d4c79e2308e5eebb47e2" STYLE="fork"/>
            <node TEXT="$\frac{1}{2}m_1u_1^2 + \frac{1}{2}m_2u_2^2 = \frac{1}{2}m_1v_1^2 + \frac{1}{2}m_2u_2^2$" ID="3def976f1af18ceb5db690acd57236b1" STYLE="fork"/>
          </node>
          <node TEXT="解得:" ID="ff6d5b7b7fbff4ab898d733918176783" STYLE="fork"/>
        </node>
        <node TEXT="非弹性碰撞(inelastic collision)" ID="68faf4d52c61853b68dfb4127122381b" STYLE="fork">
          <node TEXT="恢复系数(coefficient of restitution)" ID="37fbc1716bead3dbf5362a44b926d2df" STYLE="fork">
            <node TEXT="$C_r = \frac{u_1 - u_2}{v_1 - v_2}$" ID="70dd1c2ace53ec381fca5e5d0c0d37fa" STYLE="fork"/>
            <node TEXT="两物体碰撞后分离速度和碰撞前接近速度的比值." ID="d8cb85b40deb465d3b377fad50957817" STYLE="fork"/>
            <node TEXT="对于完全弹性碰撞, Cr=1 ." ID="7331c2cbd11235f64cafd4e5353954f7" STYLE="fork"/>
          </node>
          <node TEXT="" ID="ea6231ee0675f48467b075366cb2e19d" STYLE="fork"/>
          <node TEXT="当 Cr=0 ,构成完全非弹性碰撞,两个物体碰撞后黏着在一起." ID="d4fdb8ea5f93c7ee1b8d5949bc0405ff" STYLE="fork"/>
        </node>
        <node TEXT="对于二维或者三维的情况,只需将每个物体的速度分解为垂直接触面和平行接触面的部分,垂直部分按照上面的方式求解,平行部分就简单地保持不变." ID="a9bd4b2e591b7ec170416fda5b825c23" STYLE="fork"/>
      </node>
    </node>
  </node>
</map>