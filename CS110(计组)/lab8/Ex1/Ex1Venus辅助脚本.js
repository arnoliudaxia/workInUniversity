/*
 * @Author: your name
 * @Date: 2022-04-25 14:53:23
 * @LastEditTime: 2022-04-25 14:53:23
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \lab8\Ex1Venus辅助脚本.js
 */


    var par1 = [1, 8, 4, 1, 32, 0, 0];
    var par2 = [1, 16, 16, 4, 256, 1, 0];
    var par3 = [1, 16, 16, 4, 256, 1, 1];

    function changeParams(CacheParameters) {
        driver.setNumberOfCacheLevels(CacheParameters[0]);
        $("#block-size-val").val(CacheParameters[1]);
        $("#block-size-val").blur();
        $("#numblocks-val").val(CacheParameters[2]);
        $("#numblocks-val").blur();

        var mapMethod = $("#associativity-type");
        mapMethod[0].selectedIndex = CacheParameters[5];
        mapMethod.change();


        var replacePolicy = document.getElementById("replacementPolicy");
        replacePolicy.selectedIndex = CacheParameters[6];
        replacePolicy.onchange();
        if (CacheParameters[3] != -1) {
            $("#associativity-val")[0].value = CacheParameters[3];
            $("#associativity-val").blur();

        }
    }

    var largePannel = $("#cache-tab-view");
    largePannel.prepend('<button type="button" class="button is-primary" onclick="changeParams(par3)">Scenario 3</button>');
    largePannel.prepend('<button type="button" class="button is-primary" onclick="changeParams(par2)">Scenario 2</button>');
    largePannel.prepend('<button type="button" class="button is-primary" onclick="changeParams(par1)">Scenario 1</button>');
    $("#cacheEnabled").click();
    driver.setCacheEnabled(true);


