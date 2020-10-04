#include "../Inc/lqr_controller.h"

void init_gains_coeff(control_data_t *control_data){
    /* The coefficients are sorted in the following way: Gain 1, Gain 2, Gain 3, Optimal Trajectory*/
    const double coeff0[POLY_DEG+1] = {-0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000868001509274695588003190560506144, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000006734144053942240645165763223097866695, -0.000000000000000000000000000000000000000000000000000000000000000000000000000000017943967053724527790526120972453756926449, 0.000000000000000000000000000000000000000000000000000000000000000000000000000011600941491935255106453433215669137342465324, 0.000000000000000000000000000000000000000000000000000000000000000000000000024003842653456406415201075555759650350223677265, -0.000000000000000000000000000000000000000000000000000000000000000000000018111809768284050761098616789038040361039057944148, -0.000000000000000000000000000000000000000000000000000000000000000000048626795322807690622140144022438412562738932905020920, 0.000000000000000000000000000000000000000000000000000000000000000007420489314715460137826453965576002362709190070801883230, 0.000000000000000000000000000000000000000000000000000000000000094912489417915252510561501393729204256289219371483064906746, 0.000000000000000000000000000000000000000000000000000000000052920131301064704984426808487039401202507286820178230977021240, -0.000000000000000000000000000000000000000000000000000000142328584943567111040099678669599125806190931530978604529693922433, -0.000000000000000000000000000000000000000000000000000206637043647508274878826573874873913387740240970744978496233572370358, 0.000000000000000000000000000000000000000000000000130334867334591797705159920212787647558817394492967999556852539610786702, 0.000000000000000000000000000000000000000000000490489866515998216867458404379428187117827265098035412660415750117880703074, 0.000000000000000000000000000000000000000000026867380644656436850000702522289482657478939067887135595991052719132239096434, -0.000000000000000000000000000000000000000958336406527050599461484506529266000580916845814498770483885341489941271723386135, -0.000000000000000000000000000000000000380110572500376264930409844941662974846208384219693874197621108524730596015191124200, 0.000000000000000000000000000000001846228870037127080708718400229324628612006979121258828532160962041221158639206452239598, 0.000000000000000000000000000000701063223175594818444883139638145152049380684396387992241048156796428280836621271983333248, -0.000000000000000000000000003903941552353450564236090389613619312482757597027505055531398063059663437746049652332658297382, 0.000000000000000000000000921341687636553511160316676520504205771478259592850755826738722497823430579444448085268959403038, 0.000000000000000000006947147284172662813389137056975705843499706683819221137788160747028598507313290610909461975097656250, -0.000000000000000011979567065868153518301726372320952852497657147544385392023968961439095437526702880859375000000000000000, 0.000000000000010700672963404348022988568119097284740871703703768424986719765001907944679260253906250000000000000000000000, -0.000000000006235098773362018059773535637897243634301946979547892624395899474620819091796875000000000000000000000000000000, 0.000000002525183589744375369531118971666051875590852660025120712816715240478515625000000000000000000000000000000000000000, -0.000000720864945346716686813465149036295187556788732763379812240600585937500000000000000000000000000000000000000000000000, 0.000142835180023407189121506521978233195113716647028923034667968750000000000000000000000000000000000000000000000000000000, -0.018733383728017274222343857559280877467244863510131835937500000000000000000000000000000000000000000000000000000000000000, 1.463511559528952288289360694761853665113449096679687500000000000000000000000000000000000000000000000000000000000000000000, -51.561961866915225982666015625000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000};
    const double coeff1[POLY_DEG+1] = {-0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000006929894392832814071182538693, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000054425677379206007206037335008834, -0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000147580672324172961966870355106702292, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000100331692340909445964638598038468649247, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000195868243086689447120388856000378948300240, -0.000000000000000000000000000000000000000000000000000000000000000000000000000161598364605904502187147276156491869346168962, -0.000000000000000000000000000000000000000000000000000000000000000000000000404072398506676206515067526538909826666120859871, 0.000000000000000000000000000000000000000000000000000000000000000000000086490854091420275654937990622632139194420928381487, 0.000000000000000000000000000000000000000000000000000000000000000000813047409216016282255984718926471005315495292041528582, 0.000000000000000000000000000000000000000000000000000000000000000410718808596410661461492078666523948503802150600195847177, -0.000000000000000000000000000000000000000000000000000000000001265563730786173054911937688216365467163965080537859529660211, -0.000000000000000000000000000000000000000000000000000000001740635378171801234129210961440998689837149480322248674685895623, 0.000000000000000000000000000000000000000000000000000001234711655204579968125016756495673589077811760936878899602008173981, 0.000000000000000000000000000000000000000000000000004267072435751004784598937897887922322177137214767349212998926121809032, 0.000000000000000000000000000000000000000000000000072737015794085804779462677452271279489733627755267979893677017158952050, -0.000000000000000000000000000000000000000000008465297853135322357500736794828702651673582632361307947220712812542503981252, -0.000000000000000000000000000000000000000003160441360587192413989116722111570882906058797872118951189497610818218780290818, 0.000000000000000000000000000000000000016330368023997467734965921815608383294826089372673871764039991896698844445218994373, 0.000000000000000000000000000000000006056752556505611966406346547023851785773461950640659821300210634902311926982865525445, -0.000000000000000000000000000000034304097738976319704134761135101278459396491181269269149574300715087513313245211592911188, 0.000000000000000000000000000007851111829510705578820666495154013748892443112294765683215500413871004326292262973097102474, 0.000000000000000000000000060834564747988713024506535044725518125570556422575707177802432965138448167641271879801934119314, -0.000000000000000000000103516827878680129991824792754095721355430168204110044884511251592207337068884953623637557029724121, 0.000000000000000000091231816246328729567882113998767139710960376275921394255766228020831931644352152943611145019531250000, -0.000000000000000052429584971635806537466250536115653976870198260803665468721135312080150470137596130371093750000000000000, 0.000000000000020955153485969207809806340873026377406661670613208237057278893189504742622375488281250000000000000000000000, -0.000000000005914117074991405656726923411466880615115770947198825524537824094295501708984375000000000000000000000000000000, 0.000000001161718600379918641978872919208812253266671632445650175213813781738281250000000000000000000000000000000000000000, -0.000000151542782015878875821166026430231177357654814841225743293762207031250000000000000000000000000000000000000000000000, 0.000011817032803199593347996503023278336286239209584891796112060546875000000000000000000000000000000000000000000000000000, -0.000730571100922361459963083607505041072727181017398834228515625000000000000000000000000000000000000000000000000000000000};
    const double coeff2[POLY_DEG+1] = {-0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000043867245230357029103581055844633, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000344490485188508716783274825893808887, -0.000000000000000000000000000000000000000000000000000000000000000000000000000000000934018022605933039216005802341479060134, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000634836548104500665275673422521919117185366, 0.000000000000000000000000000000000000000000000000000000000000000000000000001239606407908012030174160563013339933812113437, -0.000000000000000000000000000000000000000000000000000000000000000000000001022381835686775337103413729710568651564362721281, -0.000000000000000000000000000000000000000000000000000000000000000000002556981976241690822393193246152569036255741229670767, 0.000000000000000000000000000000000000000000000000000000000000000000546923120911685786160327644613604987256548299448649168, 0.000000000000000000000000000000000000000000000000000000000000005144395586465708263248864187536114495172630520704805496922, 0.000000000000000000000000000000000000000000000000000000000002598957900626994707360105955074991240578447205580992140764591, -0.000000000000000000000000000000000000000000000000000000008007265198030915847867088324688936778103519504737222019995215541, -0.000000000000000000000000000000000000000000000000000011012596304547960875754063524467217261978623179507934965030092573136, 0.000000000000000000000000000000000000000000000000007813424460355518230137224758134701878337662411549720366986823781291171, 0.000000000000000000000000000000000000000000000026996785758019778790415605805228291744047528796217135257388883945860792112, 0.000000000000000000000000000000000000000000000453122545821515609722791732162586456301180955021948760347794437576693762049, -0.000000000000000000000000000000000000000053563190137796305881289862751094969744386557726456685402293821110980208963886471, -0.000000000000000000000000000000000000019976318126433723065385984554453131826161185132290324502967619645553667284221885352, 0.000000000000000000000000000000000103343166980282802940037853931717963151868718028719503570980165018475073893736139637379, 0.000000000000000000000000000000038273453233300523929121401279433260370520484136762154399274416415522512795413584342930219, -0.000000000000000000000000000217101763955207932149619711634519595537333220210248378142003358845087634086679084788329419098, 0.000000000000000000000000049810794839236377681158654986343728815733024177921737193721767596816998174835688928396848496050, 0.000000000000000000000384963770908737199535755590603621468013595183838185176183411054240401938386639812961220741271972656, -0.000000000000000000655353546691688177119597678067537473324012543609835661218010471884554135613143444061279296875000000000, 0.000000000000000577760672934951596605344964105868965680659371953603598015547504473943263292312622070312500000000000000000, -0.000000000000332123470617645369376961526212574756953752053156847523496253415942192077636718750000000000000000000000000000, 0.000000000132776890182980785371730039812513627511814107151622010860592126846313476562500000000000000000000000000000000000, -0.000000037481161968261776657794048621397120513165646116249263286590576171875000000000000000000000000000000000000000000000, 0.000007363662813423413138445849934754505738965235650539398193359375000000000000000000000000000000000000000000000000000000, -0.000960668634241035259042906790938332051155157387256622314453125000000000000000000000000000000000000000000000000000000000, 0.074914650496394216694362455655209487304091453552246093750000000000000000000000000000000000000000000000000000000000000000, -2.626833640295080929405457936809398233890533447265625000000000000000000000000000000000000000000000000000000000000000000000};
    const double coeff3[POLY_DEG+1] = {0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000028201512266827400983745999323449956, -0.000000000000000000000000000000000000000000000000000000000000000000000000000000000169169587081394999722992574816736963843, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000267806258884121013433549049474308717778795, 0.000000000000000000000000000000000000000000000000000000000000000000000000000156310056569105985899288991995874860995901209, -0.000000000000000000000000000000000000000000000000000000000000000000000000420781989593098999410481924748335586374112864584, -0.000000000000000000000000000000000000000000000000000000000000000000000572860174513895973807675225467011036256248527396007, 0.000000000000000000000000000000000000000000000000000000000000000000294721591265893008917159606265125757550845617787456478, 0.000000000000000000000000000000000000000000000000000000000000001462131385430680025992070570814816730592596720193171790698, 0.000000000000000000000000000000000000000000000000000000000001096110591600740018066629549842693785052522113398095235399306, -0.000000000000000000000000000000000000000000000000000000001725731829585179867490660389918973663538734923170165853320743282, -0.000000000000000000000000000000000000000000000000000004483521573247719904542525964273480990676345706714048874017774224721, -0.000000000000000000000000000000000000000000000000001828511307393350097984003197933791219521865641239921753135337682081073, 0.000000000000000000000000000000000000000000000007626773483327769523161411281655730244127601002639531677722015892685518214, 0.000000000000000000000000000000000000000000012890752715884498906150595465213574025309580078273577359118702478738492991177, -0.000000000000000000000000000000000000000003351196781005100066130584894030817234483816568341917229611562328192132993040491, -0.000000000000000000000000000000000000032688157782857599948097673837154255674109177866476450201429364646062551473687276756, -0.000000000000000000000000000000000018742040213220800120872136755681874910336266097597550445659810603981725103805983628575, 0.000000000000000000000000000000065362741029228002330069734823877649438166628309112796605973076331327593535511650537847550, 0.000000000000000000000000000068525746928614100606193437410123075133805238652851087043996671738078293740614038709324518095, -0.000000000000000000000000156682364783303998331950173525814289779487137972400167048695103917373486202002652589726494625211, -0.000000000000000000000107527358253817007694879944590430329595727063973756351966681605453191039600824296940118074417114258, 0.000000000000000000502656163258752008789341001009140755113277120360979919808097626798826240701600909233093261718750000000, -0.000000000000000610156719570548005951499611144859998469357957682351889516780829580966383218765258789062500000000000000000, 0.000000000000414126427426334024000398761411778465681317318303200636364636011421680450439453125000000000000000000000000000, -0.000000000177828483957205990623426351975619290335384192758283461444079875946044921875000000000000000000000000000000000000, 0.000000049665184343479100379224630513672056331131443585036322474479675292968750000000000000000000000000000000000000000000, -0.000008905405334945729625912083649019734821195015683770179748535156250000000000000000000000000000000000000000000000000000, 0.000985068911605107991671936851219015807146206498146057128906250000000000000000000000000000000000000000000000000000000000, -0.064843381998808694022251586375205079093575477600097656250000000000000000000000000000000000000000000000000000000000000000, 3.103069038794299849826074932934716343879699707031250000000000000000000000000000000000000000000000000000000000000000000000, 6.697333443398809649238501151558011770248413085937500000000000000000000000000000000000000000000000000000000000000000000000};
    memcpy(control_data->poly_coeff[0], coeff0, sizeof(coeff0));
    memcpy(control_data->poly_coeff[1], coeff1, sizeof(coeff1));
    memcpy(control_data->poly_coeff[2], coeff2, sizeof(coeff2));
    memcpy(control_data->poly_coeff[3], coeff3, sizeof(coeff3));
}

void compute_control_input(control_data_t *control_data, flight_phase_detection_t *flight_phase_detection){
    if (flight_phase_detection->flight_phase == CONTROL) {

        /* calculate Gains and Reference velocity for given altitude AGL */
        eval_gains_polyfit(control_data);

        /* Calculate Velocity Error */
        compute_reference_error(control_data);

        /* Calculate Control Input */
        control_data->control_input = (float)(-control_data->gains[0] * control_data->reference_error
                - control_data->gains[1] * control_data->integrated_error
                - control_data->gains[2] * (control_data->control_input - OPT_TRAJ_CONTROL_INPUT)
                + control_data->control_input);

        /* Check that the control input is between 0 and 1 */
        control_data->control_input = fmaxf(0, fminf(control_data->control_input, 1));

        /* Compute boundaries for the antiwindup */
        compute_antiwindup_boundaries(control_data);

        /* Compute the integrated error */
        control_data->integrated_error = fmaxf(control_data->lowerboundary_aw, fminf(control_data->integrated_error
        + DELTA_T * control_data->reference_error, control_data->upperboundary_aw));
    }
    else if ((flight_phase_detection->flight_phase == BALLISTIC_DESCENT) && 
            ((flight_phase_detection->mach_regime == SUBSONIC) || (flight_phase_detection->mach_regime == TRANSONIC))) {
        /* actuate airbrakes during ballistic descent to slow down rocket */
        control_data->control_input = 1;
    } else {
        /* This part of the controller is accessed, if the controller should not be operational or if the rocket is the apogee approach phase*/
        /* Airbrakes need to be retracted to prevent entanglement with the parachutes */
        control_data_reset(control_data);
        if (flight_phase_detection->flight_phase == APOGEE_APPROACH || flight_phase_detection->flight_phase == BIAS_RESET) {
            eval_gains_polyfit(control_data);
            compute_reference_error(control_data);
        }
    }
}

/* Does the Polynomial Calculation of the reference velocity */
void eval_gains_polyfit(control_data_t *control_data) {
    /* For Speed */
    double x_placeholder = 0;

    /* Reset gains */
    for (int i = 0; i < NUM_GAINS; i++) {
        control_data->gains[i] = 0;
    }

    /* For loop */
    for (int i = 0; i < POLY_DEG + 1; ++i) {
        x_placeholder = pow(control_data->sf_ref_altitude_AGL, (double)(POLY_DEG - i));
        control_data->gains[0] += control_data->poly_coeff[0][i] * x_placeholder;
        control_data->gains[1] += control_data->poly_coeff[1][i] * x_placeholder;
        control_data->gains[2] += control_data->poly_coeff[2][i] * x_placeholder;
    }
}