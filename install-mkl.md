## Install MKL on macOS

The image from
<http://registrationcenter-download.intel.com/akdlm/irc_nas/tec/13565/m_mkl_2019.0.117.dmg>
does not support macOS 10.11.3.

Use <http://registrationcenter-download.intel.com/akdlm/irc_nas/tec/12185/m_mkl_2017.4.220.dmg>

To install it, double click the dmg file and follow the installation guide
or use the terminal:

```sh
hdiutil attach m_mkl_2017.4.220.dmg
sed -e "s/ACCEPT_EULA=decline/ACCEPT_EULA=accept/" \
    -e "s:PSET_INSTALL_DIR=/opt/intel:PSET_INSTALL_DIR=$HOME/software/mkl:" \
    /Volumes/m_mkl_2017.4.220/m_mkl_2017.4.220.app/Contents/MacOS/silent.cfg \
    > slicent.cfg

sudo /Volumes/m_mkl_2017.4.220/m_mkl_2017.4.220.app/Contents/MacOS/install.sh -s ./silent.cfg

```

Refer to <https://gist.github.com/massich/caa7d8806ac08282f93cea00f247b8e0>
for installing MKL on Linux.

After installation, we have

```
$ ls -l $HOME/software/mkl
total 40
drwxr-xr-x  4 root  wheel  136 Nov 16 22:23 bin
lrwxr-xr-x  1 root  wheel   30 Nov 16 22:23 compilers_and_libraries -> ./compilers_and_libraries_2017
drwxr-xr-x  3 root  wheel  102 Nov 16 22:23 compilers_and_libraries_2017
drwxr-xr-x  5 root  wheel  170 Nov 16 22:22 compilers_and_libraries_2017.5.220
drwxr-xr-x  3 root  wheel  102 Nov 16 22:22 documentation_2017
lrwxr-xr-x  1 root  wheel   33 Nov 16 22:23 lib -> ./compilers_and_libraries/mac/lib
lrwxr-xr-x  1 root  wheel   33 Nov 16 22:23 mkl -> ./compilers_and_libraries/mac/mkl
lrwxr-xr-x  1 root  wheel   31 Nov 16 22:23 parallel_studio_xe_2017 -> ./parallel_studio_xe_2017.5.052
drwxr-xr-x  9 root  wheel  306 Nov 16 22:23 parallel_studio_xe_2017.5.052
drwxr-xr-x  3 root  wheel  102 Nov 16 22:23 samples_2017
lrwxr-xr-x  1 root  wheel   33 Nov 16 22:23 tbb -> ./compilers_and_libraries/mac/tbb

$ ls lib
libiomp5.a          libiomp5.dylib      libiompstubs5.a     libiompstubs5.dylib

$ ls mkl
benchmarks bin        examples   include    interfaces lib        tools

$ ls mkl/lib/
libmkl_avx.dylib          libmkl_intel.a            libmkl_lapack95.a         libmkl_sequential.a       libmkl_vml_mc2.dylib
libmkl_avx2.dylib         libmkl_intel.dylib        libmkl_lapack95_ilp64.a   libmkl_sequential.dylib   libmkl_vml_mc3.dylib
libmkl_avx512.dylib       libmkl_intel_ilp64.a      libmkl_lapack95_lp64.a    libmkl_tbb_thread.a       libmkl_vml_p4m.dylib
libmkl_blas95.a           libmkl_intel_ilp64.dylib  libmkl_mc.dylib           libmkl_tbb_thread.dylib   libmkl_vml_p4m2.dylib
libmkl_blas95_ilp64.a     libmkl_intel_lp64.a       libmkl_mc3.dylib          libmkl_vml_avx.dylib      libmkl_vml_p4m3.dylib
libmkl_blas95_lp64.a      libmkl_intel_lp64.dylib   libmkl_p4m.dylib          libmkl_vml_avx2.dylib     locale
libmkl_core.a             libmkl_intel_thread.a     libmkl_p4m3.dylib         libmkl_vml_avx512.dylib
libmkl_core.dylib         libmkl_intel_thread.dylib libmkl_rt.dylib           libmkl_vml_mc.dylib

$ ls mkl/include/
blas.f90                      mkl_cluster_sparse_solver.fi  mkl_dss.f90                   mkl_service.f90               mkl_version.h
fftw                          mkl_cluster_sparse_solver.h   mkl_dss.fi                    mkl_service.fi                mkl_vml.f90
i_malloc.h                    mkl_df.f90                    mkl_dss.h                     mkl_service.h                 mkl_vml.fi
ia32                          mkl_df.h                      mkl_lapack.fi                 mkl_solvers_ee.fi             mkl_vml.h
intel64                       mkl_df_defines.h              mkl_lapack.h                  mkl_solvers_ee.h              mkl_vml_defines.h
lapack.f90                    mkl_df_functions.h            mkl_lapacke.h                 mkl_sparse_handle.f90         mkl_vml_functions.h
mkl.fi                        mkl_df_types.h                mkl_pardiso.f90               mkl_sparse_handle.fi          mkl_vml_types.h
mkl.h                         mkl_dfti.f90                  mkl_pardiso.fi                mkl_sparse_handle.h           mkl_vsl.f90
mkl_blacs.h                   mkl_dfti.h                    mkl_pardiso.h                 mkl_spblas.f90                mkl_vsl.fi
mkl_blas.fi                   mkl_direct_blas.h             mkl_pblas.h                   mkl_spblas.fi                 mkl_vsl.h
mkl_blas.h                    mkl_direct_call.fi            mkl_poisson.f90               mkl_spblas.h                  mkl_vsl_defines.h
mkl_cblas.h                   mkl_direct_call.h             mkl_poisson.h                 mkl_trans.fi                  mkl_vsl_functions.h
mkl_cdft.f90                  mkl_direct_lapack.h           mkl_rci.f90                   mkl_trans.h                   mkl_vsl_subroutine.fi
mkl_cdft.h                    mkl_direct_types.h            mkl_rci.fi                    mkl_trig_transforms.f90       mkl_vsl_types.h
mkl_cdft_types.h              mkl_dnn.h                     mkl_rci.h                     mkl_trig_transforms.h
mkl_cluster_sparse_solver.f90 mkl_dnn_types.h               mkl_scalapack.h               mkl_types.h

$ ls mkl/examples/
examples_core_c.tgz examples_core_f.tgz examples_f95.tgz

$ sudo tar xvf examples_core_c.tgz
$ ls
cblas               examples_core_c.tgz fftw3xc             pdettc              solvers_eec         vmlc
datafittingc        examples_core_f.tgz lapackc             serv_sdli           spblasc             vslc
dftc                examples_f95.tgz    lapacke             servicefuncsc       transc
dnnc                fftw2xc             pdepoissonc         solverc             versionqueryc

$ ls cblas/
cblas.lst data      makefile  source

$ ls cblas/source/
cblas_caxpbyx.c        cblas_csrotx.c         cblas_drotix.c         cblas_isaminx.c        cblas_ssprx.c          cblas_zgemvx.c
cblas_caxpyix.c        cblas_csscalx.c        cblas_drotmgx.c        cblas_izamaxx.c        cblas_sswapx.c         cblas_zgercx.c
cblas_caxpyx.c         cblas_cswapx.c         cblas_drotmx.c         cblas_izaminx.c        cblas_ssymmx.c         cblas_zgerux.c
cblas_ccopyx.c         cblas_csymmx.c         cblas_drotx.c          cblas_sasumx.c         cblas_ssymvx.c         cblas_zgthrx.c
cblas_cdotc_subx.c     cblas_csyr2kx.c        cblas_dsbmvx.c         cblas_saxpbyx.c        cblas_ssyr2kx.c        cblas_zgthrzx.c
cblas_cdotci_subx.c    cblas_csyrkx.c         cblas_dscalx.c         cblas_saxpyix.c        cblas_ssyr2x.c         cblas_zhbmvx.c
cblas_cdotu_subx.c     cblas_ctbmvx.c         cblas_dsctrx.c         cblas_saxpyx.c         cblas_ssyrkx.c         cblas_zhemmx.c
cblas_cdotui_subx.c    cblas_ctbsvx.c         cblas_dspmvx.c         cblas_scasumx.c        cblas_ssyrx.c          cblas_zhemvx.c
cblas_cgbmvx.c         cblas_ctpmvx.c         cblas_dspr2x.c         cblas_scnrm2x.c        cblas_stbmvx.c         cblas_zher2kx.c
cblas_cgemm3m_batchx.c cblas_ctpsvx.c         cblas_dsprx.c          cblas_scopyx.c         cblas_stbsvx.c         cblas_zher2x.c
cblas_cgemm3mx.c       cblas_ctrmmx.c         cblas_dswapx.c         cblas_sdotix.c         cblas_stpmvx.c         cblas_zherkx.c
cblas_cgemm_batchx.c   cblas_ctrmvx.c         cblas_dsymmx.c         cblas_sdotx.c          cblas_stpsvx.c         cblas_zherx.c
cblas_cgemmtx.c        cblas_ctrsmx.c         cblas_dsymvx.c         cblas_sgbmvx.c         cblas_strmmx.c         cblas_zhpmvx.c
cblas_cgemmx.c         cblas_ctrsvx.c         cblas_dsyr2kx.c        cblas_sgemm_batchx.c   cblas_strmvx.c         cblas_zhpr2x.c
cblas_cgemvx.c         cblas_dasumx.c         cblas_dsyr2x.c         cblas_sgemm_computex.c cblas_strsmx.c         cblas_zhprx.c
cblas_cgercx.c         cblas_daxpbyx.c        cblas_dsyrkx.c         cblas_sgemmtx.c        cblas_strsvx.c         cblas_zrotgx.c
cblas_cgerux.c         cblas_daxpyix.c        cblas_dsyrx.c          cblas_sgemmx.c         cblas_zaxpbyx.c        cblas_zscalx.c
cblas_cgthrx.c         cblas_daxpyx.c         cblas_dtbmvx.c         cblas_sgemvx.c         cblas_zaxpyix.c        cblas_zsctrx.c
cblas_cgthrzx.c        cblas_dcopyx.c         cblas_dtbsvx.c         cblas_sgerx.c          cblas_zaxpyx.c         cblas_zswapx.c
cblas_chbmvx.c         cblas_ddotix.c         cblas_dtpmvx.c         cblas_sgthrx.c         cblas_zcopyx.c         cblas_zsymmx.c
cblas_chemmx.c         cblas_ddotx.c          cblas_dtpsvx.c         cblas_sgthrzx.c        cblas_zdotc_subx.c     cblas_zsyr2kx.c
cblas_chemvx.c         cblas_dgbmvx.c         cblas_dtrmmx.c         cblas_snrm2x.c         cblas_zdotci_subx.c    cblas_zsyrkx.c
cblas_cher2kx.c        cblas_dgemm_batchx.c   cblas_dtrmvx.c         cblas_srotgx.c         cblas_zdotu_subx.c     cblas_ztbmvx.c
cblas_cher2x.c         cblas_dgemm_computex.c cblas_dtrsmx.c         cblas_srotix.c         cblas_zdotui_subx.c    cblas_ztbsvx.c
cblas_cherkx.c         cblas_dgemmtx.c        cblas_dtrsvx.c         cblas_srotmgx.c        cblas_zdrotx.c         cblas_ztpmvx.c
cblas_cherx.c          cblas_dgemmx.c         cblas_dzasumx.c        cblas_srotmx.c         cblas_zdscalx.c        cblas_ztpsvx.c
cblas_chpmvx.c         cblas_dgemvx.c         cblas_dznrm2x.c        cblas_srotx.c          cblas_zgbmvx.c         cblas_ztrmmx.c
cblas_chpr2x.c         cblas_dgerx.c          cblas_icamaxx.c        cblas_ssbmvx.c         cblas_zgemm3m_batchx.c cblas_ztrmvx.c
cblas_chprx.c          cblas_dgthrx.c         cblas_icaminx.c        cblas_sscalx.c         cblas_zgemm3mx.c       cblas_ztrsmx.c
cblas_crotgx.c         cblas_dgthrzx.c        cblas_idamaxx.c        cblas_ssctrx.c         cblas_zgemm_batchx.c   cblas_ztrsvx.c
cblas_cscalx.c         cblas_dnrm2x.c         cblas_idaminx.c        cblas_sspmvx.c         cblas_zgemmtx.c        common_func.c
cblas_csctrx.c         cblas_drotgx.c         cblas_isamaxx.c        cblas_sspr2x.c         cblas_zgemmx.c         mkl_example.h
```

